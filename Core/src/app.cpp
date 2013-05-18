#include "app.h"


GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

const GLfloat g_AngleSpeed = 10.0f;


#include <iostream>

using namespace std;


GLfloat g_TabVertices[]=
{
        5,6,2,
        6,4,1,
        10,14,3,
        36,10,33,
        36,21,4,
        10,10,18
};

GLfloat g_repere[]=
{
     0,0,100
    ,0,0,0
    ,100,0,0
    ,0,0,0
    ,0,100,0
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
}


bool
App::initializeObjects()
{
    // Fond gris
    glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
    glEnable( GL_DEPTH_TEST );

    // Chargement des shaders
    createShader( "Shaders/color" );

    return true;
}


void
App::render()
{
    // Initialisation de la cam�ra
        lookAt( 0, 10, 30, 0, 0, 0 );
        glPointSize(50);

    // Rendu des objets
    pushMatrix();
        rotate( angle1, 0, 1, 0 );
        rotate( angle2, 1, 0, 0 );
        computeAncillaryMatrices();

        useShader( "color" );
        GLint var_id = glGetUniformLocation( getCurrentShaderId(), "MVP" );
        transmitMVP( var_id );

        GLint var1 = glGetAttribLocation( getCurrentShaderId(), "position" );
        glEnableVertexAttribArray( var1 );
                GLint var2 = glGetAttribLocation( getCurrentShaderId(), "color" );
                glEnableVertexAttribArray( var2 );
                // drawing repere
                glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, g_repere);
                glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, g_repereColor);
                glDrawArrays (GL_LINES, 0 , 6);

                // drawing point
        glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, g_TabVertices );
        glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, g_TabColors );
                glDrawArrays( GL_POINTS, 0, 6 );
                glDisableVertexAttribArray( var1 );
                glDisableVertexAttribArray( var2 );
    popMatrix();
        pushMatrix();
            useShader( "color" );
            var_id = glGetUniformLocation( getCurrentShaderId(), "MVP" );
            transmitMVP( var_id );

            var1 = glGetAttribLocation( getCurrentShaderId(), "position" );
            glEnableVertexAttribArray( var1 );
            var2 = glGetAttribLocation( getCurrentShaderId(), "color" );
            glEnableVertexAttribArray( var2 );
            // drawing repere
            glVertexAttribPointer( var1, 3, GL_FLOAT, GL_FALSE, 0, g_repere);
            glVertexAttribPointer( var2, 3, GL_FLOAT, GL_FALSE, 0, g_repereColor);
            glDrawArrays (GL_LINES, 0 , 6);
            glDisableVertexAttribArray( var1 );
            glDisableVertexAttribArray( var2 );
        popMatrix();
}


void
App::keyPressEvent( QKeyEvent* event )
{
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
