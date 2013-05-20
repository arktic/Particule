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
    0,0,1
};

GLfloat g_TabColors[]=
{
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1
};


App::App()
{
    setWindowTitle(trUtf8("IN55-App"));
    time_ms(&lastTimeFps);
}


bool
App::initializeObjects()
{
    // Fond gris
    cam = new Camera(20,20,0,0,0,0,0,1,0);
    oldMouse.x = 0;
    oldMouse.y = 0;
    glClearColor( 0.f, 0.f, 0.f, 1.0f );
    glEnable( GL_DEPTH_TEST );

    fps = 0;
    // Chargement des shaders
    createShader( "Shaders/color" );

    fire = new Fire("Shaders/fire",GEN_FRAMETIME,GEN_ITEMPERFRAME,
                    GEN_RADIUS,GEN_CENTER,
                    GEN_NBPARTICLE,
                    GEN_LIFETIME_MIN,GEN_LIFETIME_MAX,
                    GEN_SIZE_MIN,  GEN_SIZE_MAX,
                    GEN_VELOCITY_MIN, GEN_VELOCITY_MAX);
    createShader( fire->getShaderName() );
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

        useShader( "color" );
        GLint var_id = glGetUniformLocation( getCurrentShaderId(), "MVP" );
        GLint position = glGetAttribLocation( getCurrentShaderId(), "position" );
        GLint color = glGetAttribLocation( getCurrentShaderId(), "color" );

        transmitMVP( var_id );
        glEnableVertexAttribArray( position );
        glEnableVertexAttribArray( color );
                // drawing repere

                glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, g_repere);
                glVertexAttribPointer( color, 3, GL_FLOAT, GL_FALSE, 0, g_repereColor);
                glDrawArrays (GL_LINES, 0 , 6);

         glDisableVertexAttribArray( position );
         glDisableVertexAttribArray( color );

        // drawing particules
         glEnable(GL_POINT_SPRITE);
         glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
        useShader( "fire" );
        var_id = glGetUniformLocation( getCurrentShaderId(), "MVP" );
        transmitMVP( var_id );

        GLint c = glGetUniformLocation(getCurrentShaderId(), "center" );
        GLint radius = glGetUniformLocation(getCurrentShaderId(), "radius" );
        glUniform1f( radius, fire->getRadius());

        Vec3 center = fire->getCenter();
        glUniform3f(	c, center.x, center.y, center.z );

        GLint t = glGetAttribLocation( getCurrentShaderId(), "t" );
        GLint velocity = glGetAttribLocation( getCurrentShaderId(), "velocity" );
        GLint ageRatio = glGetAttribLocation( getCurrentShaderId(), "ageRatio" );
        position = glGetAttribLocation( getCurrentShaderId(), "position" );
        color = glGetAttribLocation( getCurrentShaderId(), "color" );
        GLint size = glGetAttribLocation( getCurrentShaderId(), "size" );

        glEnableVertexAttribArray( t );
        glEnableVertexAttribArray( velocity );
        glEnableVertexAttribArray( position );
        glEnableVertexAttribArray( ageRatio );
        glEnableVertexAttribArray( color );
        glEnableVertexAttribArray( size );

        glVertexAttribPointer( t, 1, GL_FLOAT, GL_FALSE, 0, fire->getAges() );
        glVertexAttribPointer( velocity, 3, GL_FLOAT, GL_FALSE, 0, fire->getVelocity() );
        glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, fire->getVertices() );
        glVertexAttribPointer( color, 3, GL_FLOAT, GL_FALSE, 0, fire->getColors() );
        glVertexAttribPointer( size, 1, GL_FLOAT, GL_FALSE, 0, fire->getSizes() );
        glVertexAttribPointer( ageRatio, 1, GL_FLOAT, GL_FALSE, 0, fire->getAgesRatio() );

                glDrawArrays( GL_POINTS, 0, fire->getNbAlive() );

        glDisableVertexAttribArray( position );
        glDisableVertexAttribArray( color );
        glDisableVertexAttribArray( velocity );
        glDisableVertexAttribArray( t );
        glDisableVertexAttribArray( size );
        glDisableVertexAttribArray( ageRatio );
    popMatrix();
    glDisable(GL_POINT_SPRITE);
    glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
    // affichage des fps
    printFps();
}


void
App::mouseMoveEvent(QMouseEvent *event){
    //Vec2 offset( - this->width()*0.5 , event->y() - this->height()*0.5);
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
