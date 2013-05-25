#include "App.h"
#include "utils.h"
#include "camera.h"

GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

const GLfloat g_AngleSpeed = 10.0f;


#include <iostream>

#include "ParticuleGenerateur.h"
#include "fire.h"
using namespace std;




GLfloat g_repere[]=
{
     0,0,20
    ,0,0,0
    ,20,0,0
    ,0,0,0
    ,0,20,0
    ,0,0,0
};

GLfloat g_repereColor[]=
{
    1,0,0,
    1,0,0,
    0,1,0,
    0,1,0,
    0,0,1,
    0,0,1,
};

/*----------- plan ------------ */
GLfloat g_plan[]=
{
    -20,0,20
    ,-20,0,-20
     ,20,0,-20
    ,20,0,20
};

GLfloat g_planColor[]=
{
    1,0,0,
    1,0,0,
    0,1,0,
    0,1,0,
};

GLuint g_planInd[] =
{
    0,1,3,2,2
};


App::App()
{
    setWindowTitle(trUtf8("IN55-App"));
    time_ms(&lastTimeFps);
}


bool
App::initializeObjects()
{
    cam = new Camera(20,20,0,0,0,0,0,1,0);

    oldMouse.x = 0;
    oldMouse.y = 0;
    glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );




    fps = 0;

    fire = new Fire("Shaders/fire","Texture/tex2d_fire4-2.png",GEN_FRAMETIME,GEN_ITEMPERFRAME,
                    GEN_RADIUS,GEN_CENTER,
                    GEN_NBPARTICLE,
                    GEN_LIFETIME_MIN,GEN_LIFETIME_MAX,
                    GEN_SIZE_MIN,  GEN_SIZE_MAX,
                    GEN_VELOCITY_MIN, GEN_VELOCITY_MAX);
    createShader( "Shaders/color");
    createShader( "Shaders/plan");
    createShader( fire->getShaderName() );
    textureID = createTexture(fire->getTextureName());

    return true;
}


void
App::render()
{
    fire->update();
    // Initialisation de la caméra
        lookAt( cam->getPosition().x, cam->getPosition().y, cam->getPosition().z,
                cam->getTarget().x, cam->getTarget().y, cam->getTarget().z,
                cam->getVaxe().x, cam->getVaxe().y, cam->getVaxe().z );


    // Rendu des objets
    pushMatrix();
        //rotate( angle1, 0, 1, 0 );
        //rotate( angle2, 1, 0, 0 );
        computeAncillaryMatrices();

        GLint var_id, position,  color;



         glDepthMask( GL_FALSE );            // Disable depth writes
         glEnable(GL_BLEND);                 // Enable Blending
         glBlendFunc(GL_SRC_ALPHA, GL_ONE);


        // repere shit
        useShader( "color" );
        var_id = glGetUniformLocation( getCurrentShaderId(), "MVP" );
        position = glGetAttribLocation( getCurrentShaderId(), "position" );
        color = glGetAttribLocation( getCurrentShaderId(), "color" );

        transmitMVP( var_id );
        glEnableVertexAttribArray( position );
        glEnableVertexAttribArray( color );
                // drawing repere
                glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, g_repere);
                glVertexAttribPointer( color, 3, GL_FLOAT, GL_FALSE, 0, g_repereColor);
                glDrawArrays (GL_LINES, 0 , 6);

         glDisableVertexAttribArray( position );
         glDisableVertexAttribArray( color );


         /*------------- PLAN ------------*/
         //useShader( "plan" );





        /*--------------- particules ---------- */
         glEnable(GL_POINT_SPRITE);
         glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
         glEnable(GL_TEXTURE_2D);
        useShader( "fire" );
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,textureID);

        // textureID initialization
        glUniform1i(glGetUniformLocation(0, "texId"),0);

        // setting de la position de la caméra dans le shader et du viewport width
        Vec3 camPos = cam->getPosition();
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        Vec3 center = fire->getCenter();

        GLint mvp = glGetUniformLocation( getCurrentShaderId(), "MVP" );
        GLint c = glGetUniformLocation(getCurrentShaderId(), "center" );
        GLint radius = glGetUniformLocation(getCurrentShaderId(), "radius" );
        GLint eyePosition = glGetUniformLocation( getCurrentShaderId(), "eyePosition" );
        GLint viewportWidth = glGetUniformLocation( getCurrentShaderId(), "viewportWidth" );

        transmitMVP( mvp );
        glUniform3f(eyePosition, camPos.x, camPos.y, camPos.z);
        glUniform1f(viewportWidth,viewport[2] );
        glUniform1f( radius, fire->getRadius());
        glUniform3f(c, center.x, center.y, center.z );


        GLint t = glGetAttribLocation( getCurrentShaderId(), "t" );
        GLint velocity = glGetAttribLocation( getCurrentShaderId(), "velocity" );
        GLint ageRatio = glGetAttribLocation( getCurrentShaderId(), "ageRatio" );
        position = glGetAttribLocation( getCurrentShaderId(), "position" );
        //color = glGetAttribLocation( getCurrentShaderId(), "color" );
        GLint size = glGetAttribLocation( getCurrentShaderId(), "size" );

        glEnableVertexAttribArray( t );
        glEnableVertexAttribArray( velocity );
        glEnableVertexAttribArray( position );
        glEnableVertexAttribArray( ageRatio );
        //glEnableVertexAttribArray( color );
        glEnableVertexAttribArray( size );


        glVertexAttribPointer( t, 1, GL_FLOAT, GL_FALSE, 0, fire->getAges() );
        glVertexAttribPointer( velocity, 3, GL_FLOAT, GL_FALSE, 0, fire->getVelocity() );
        glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, fire->getVertices() );
        //glVertexAttribPointer( color, 4, GL_FLOAT, GL_FALSE, 0, fire->getColors() );
        glVertexAttribPointer( size, 1, GL_FLOAT, GL_FALSE, 0, fire->getSizes() );
        glVertexAttribPointer( ageRatio, 1, GL_FLOAT, GL_FALSE, 0, fire->getAgesRatio() );


            glDrawArrays( GL_POINTS, 0, fire->getNbAlive() );

        glDisableVertexAttribArray( position );
//        glDisableVertexAttribArray( color );
        glDisableVertexAttribArray( velocity );
        glDisableVertexAttribArray( t );
        glDisableVertexAttribArray( size );
        glDisableVertexAttribArray( ageRatio );

   //     glDepthMask( GL_TRUE );
 //glDisable(GL_BLEND);
 glBlendFunc(GL_ZERO,GL_ONE);
        useShader("Shaders/plan");
        var_id = glGetUniformLocation( getCurrentShaderId(), "MVP" );
        position = glGetAttribLocation( getCurrentShaderId(), "position" );
        color = glGetAttribLocation( getCurrentShaderId(), "color" );
        transmitMVP( var_id );



                // drawing plan
                glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, g_plan);
                glVertexAttribPointer( color, 3, GL_FLOAT, GL_FALSE, 0, g_planColor);
                glEnableVertexAttribArray( position );
                glEnableVertexAttribArray( color );
                glVertexPointer(3,GL_FLOAT,0,g_plan);
                glDrawElements(GL_TRIANGLE_STRIP,5, GL_UNSIGNED_INT,g_planInd);

         glDisableVertexAttribArray( position );
         glDisableVertexAttribArray( color );


        //unbind de la texture
        glBindTexture(GL_TEXTURE_2D,0);
        glDisable(GL_POINT_SPRITE);
        glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
        glDisable(GL_TEXTURE_2D);
    popMatrix();

    // affichage des fps
    printFps();
}


void
App::mouseMoveEvent(QMouseEvent *event){
    cam->orienter(event->x()-oldMouse.x ,event->y()-oldMouse.y);
    oldMouse.x = event->x();
    oldMouse.y = event->y();
}

void
App::keyPressEvent( QKeyEvent* event )
{
    if(event->key() == Qt::Key_Z){
        cam->moveForward(CAM_SPEED);
    }
    if(event->key() == Qt::Key_S){
        cam->moveBackward(CAM_SPEED);
    }
    if(event->key() == Qt::Key_Q){
        cam->moveLeftSide(CAM_SPEED);
    }
    if(event->key() == Qt::Key_D){
        cam->moveRightSide(CAM_SPEED);
    }
    switch( event->key())
    {
        case Qt::Key_Escape:
            close();
            break;

        case Qt::Key_Left:
            angle1 -= g_AngleSpeed;
            break;

        case Qt::Key_Right:
            angle1 += g_AngleSpeed;
            break;

        case Qt::Key_Up:
            angle2 -= g_AngleSpeed;
            break;

        case Qt::Key_Down:
            angle2 += g_AngleSpeed;
            break;

        case Qt::Key_R:
            angle1 = angle2 = 0.0f;
            break;
    }
}

void App::printFps() {
    int64_t currentTime;
    time_ms(&currentTime);
    fps++;
    if( currentTime - lastTimeFps  > 1000)
    {
        std::cout << "fps:" << fps << " nbalive:" << fire->getNbAlive() << std::endl;
        fps = 0;
        time_ms(&lastTimeFps);
    }
}



App::~App() {
    delete fire;
    delete cam;
}
