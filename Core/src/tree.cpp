
#include "tree.h"
#include "App.h"

#include "GL/glew.h"


Tree::Tree(char * _shaderName,
           Vec3 _position,
           unsigned int _trunk_height,
           unsigned int _trunk_width ,
           unsigned int _foliage_height,
           unsigned int _foliage_width) :
    shaderName(_shaderName),
    position(_position),
    trunk_height(_trunk_height),
    trunk_width(_trunk_width),
    foliage_height(_foliage_height),
    foliage_width(_foliage_width),
    loaded(false)
{
        vertices = new GLfloat[48];
        colors = new GLfloat[48];

        calculateVertices();
}



void Tree::calculateVertices() {
    /* trunk */

    /* trunk base */
    vertices[0] = position.x - trunk_width/2;
    vertices[1] = position.y;
    vertices[2] = position.z - trunk_width/2;

    vertices[3] = position.x - trunk_width/2;
    vertices[4] = position.y;
    vertices[5] = position.z + trunk_width/2;

    vertices[6] = position.x + trunk_width/2;
    vertices[7] = position.y;
    vertices[8] = position.z + trunk_width/2;

    vertices[9] = position.x + trunk_width/2;
    vertices[10] = position.y;
    vertices[11] = position.z - trunk_width/2;

    /* trunk head */
    vertices[12] = position.x - trunk_width/2;
    vertices[13] = position.y + trunk_height;
    vertices[14] = position.z - trunk_width/2;

    vertices[15] = position.x - trunk_width/2;
    vertices[16] = position.y + trunk_height;
    vertices[17] = position.z + trunk_width/2;

    vertices[18] = position.x + trunk_width/2;
    vertices[19] = position.y + trunk_height;
    vertices[20] = position.z + trunk_width/2;

    vertices[21] = position.x + trunk_width/2;
    vertices[22] = position.y + trunk_height;
    vertices[23] = position.z - trunk_width/2;



    /* foliage */
    /* foliage base */
    vertices[24] = position.x - foliage_width/2;
    vertices[25] = position.y + trunk_height;
    vertices[26] = position.z - foliage_width/2;

    vertices[27] = position.x - foliage_width/2;
    vertices[28] = position.y + trunk_height;
    vertices[29] = position.z + foliage_width/2;

    vertices[30] = position.x + foliage_width/2;
    vertices[31] = position.y + trunk_height;
    vertices[32] = position.z + foliage_width/2;

    vertices[33] = position.x + foliage_width/2;
    vertices[34] = position.y + trunk_height;
    vertices[35] = position.z - foliage_width/2;

    /* foliage head */
    vertices[36] = position.x - foliage_width/2;
    vertices[37] = position.y + foliage_height + trunk_height;
    vertices[38] = position.z - foliage_width/2;

    vertices[39] = position.x - foliage_width/2;
    vertices[40] = position.y + foliage_height + trunk_height;;
    vertices[41] = position.z + foliage_width/2;

    vertices[42] = position.x + foliage_width/2;
    vertices[43] = position.y + foliage_height + trunk_height;;
    vertices[44] = position.z + foliage_width/2;

    vertices[45] = position.x + foliage_width/2;
    vertices[46] = position.y + foliage_height + trunk_height;;
    vertices[47] = position.z - foliage_width/2;




    /* colors */
    int i =0;
    for(i=0; i<16;i++) {
        if(i<8) {
            colors[3*i] = 0.5;
            colors[3*i+1] = 0.2509;
            colors[3*i+2] = 0;
        }
        else{
            colors[3*i] = 0;
            colors[3*i+1] = 0.7;
            colors[3*i+2] = 0;
        }
    }

    /* indices */

    indices_trunk[0] = 0 ;
    indices_trunk[1] = 4 ;
    indices_trunk[2] = 1 ;
    indices_trunk[3] = 5;
    indices_trunk[4] = 2;
    indices_trunk[5] = 6;
    indices_trunk[6] = 3;
    indices_trunk[7] = 7;
    indices_trunk[8] = 0;
    indices_trunk[9] = 4;

    indices_trunk_base[0] = 0;
    indices_trunk_base[1] = 1;
    indices_trunk_base[2] = 3;
    indices_trunk_base[3] = 2;



    indices_foliage[0] = 0 +8 ;
    indices_foliage[1] = 4 +8;
    indices_foliage[2] = 1 +8;
    indices_foliage[3] = 5+8;
    indices_foliage[4] = 2+8;
    indices_foliage[5] = 6+8;
    indices_foliage[6] = 3+8;
    indices_foliage[7] = 7+8;
    indices_foliage[8] = 0+8;
    indices_foliage[9] = 4+8;

    indices_foliage_base[0] = 8 ;
    indices_foliage_base[1] = 9;
    indices_foliage_base[2] = 11;
    indices_foliage_base[3] = 10;

    indices_foliage_top[0] = 8 +4;
    indices_foliage_top[1] = 9+4;
    indices_foliage_top[2] = 11+4;
    indices_foliage_top[3] = 10+4;
}


void Tree::load(App* app) {
    if(!loaded) {
        app->createShader(shaderName);
        loaded = true;
    }
}



void Tree::render(App* app) {
    glDisable(GL_BLEND);


    glEnable(GL_DEPTH_TEST);

    app->useShader(shaderName);
    GLint shaderID = app->getCurrentShaderId();
    GLint var_id = glGetUniformLocation( shaderID, "MVP" );
    GLint position = glGetAttribLocation( shaderID, "position" );
    GLint color = glGetAttribLocation( shaderID, "color" );
    app->transmitMVP( var_id );

    glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer( color, 3, GL_FLOAT, GL_FALSE, 0, colors);
    glEnableVertexAttribArray( position );
    glEnableVertexAttribArray( color );

    glDrawElements(GL_TRIANGLE_STRIP,10, GL_UNSIGNED_INT,indices_trunk);
    glDrawElements(GL_TRIANGLE_STRIP,4, GL_UNSIGNED_INT,indices_trunk_base);

    glDrawElements(GL_TRIANGLE_STRIP,10, GL_UNSIGNED_INT,indices_foliage);
    glDrawElements(GL_TRIANGLE_STRIP,4, GL_UNSIGNED_INT,indices_foliage_base);
    glDrawElements(GL_TRIANGLE_STRIP,4, GL_UNSIGNED_INT,indices_foliage_top);

    glDisableVertexAttribArray( position );
    glDisableVertexAttribArray( color );
    glDisable(GL_DEPTH_TEST);
   }

