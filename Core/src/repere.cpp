#include "repere.h"
#include "App.h"

Repere::Repere(char* _shaderName):loaded(false) {
    g_repere[0]     =  0;    g_repere[1]    =  0;    g_repere[2]     = 20;
    g_repere[3]     =  0;    g_repere[4]    =  0;    g_repere[5]     = 0;
    g_repere[6]     = 20;   g_repere[7]     =  0;    g_repere[8]     = 0;
    g_repere[9]     =  0;   g_repere[10]    =  0;    g_repere[11]    = 0;
    g_repere[12]    =  0;   g_repere[13]    = 20;    g_repere[14]    = 0;
    g_repere[15]    =  0;   g_repere[16]    =  0;    g_repere[17]    = 0;

    g_repereColor[0]     =  1;    g_repereColor[1]    =  0;    g_repereColor[2]     = 0;
    g_repereColor[3]     =  1;    g_repereColor[4]    =  0;    g_repereColor[5]     = 0;
    g_repereColor[6]     =  0;   g_repereColor[7]     =  1;    g_repereColor[8]     = 0;
    g_repereColor[9]     =  0;   g_repereColor[10]    =  1;    g_repereColor[11]    = 0;
    g_repereColor[12]    =  0;   g_repereColor[13]    = 0;    g_repereColor[14]    = 1;
    g_repereColor[15]    =  0;   g_repereColor[16]    =  0;    g_repereColor[17]    = 1;

    shaderName = _shaderName;
}

void Repere::load(App* app){
    if(!loaded){
        if(shaderName != NULL)
            app->createShader(shaderName);
        loaded = true;
    }
}

void Repere::render(App* app){
    glDepthMask( GL_FALSE );
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    app->useShader(shaderName );
    shaderID = app->getCurrentShaderId();

    GLint var_id, position,  color;
    var_id = glGetUniformLocation( shaderID, "MVP" );
    position = glGetAttribLocation( shaderID, "position" );
    color = glGetAttribLocation( shaderID, "color" );

    app->transmitMVP( var_id );
    glEnableVertexAttribArray( position );
    glEnableVertexAttribArray( color );

    glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, g_repere);
    glVertexAttribPointer( color, 3, GL_FLOAT, GL_FALSE, 0, g_repereColor);

    glDrawArrays (GL_LINES, 0 , 6);

    glDisableVertexAttribArray( position );
    glDisableVertexAttribArray( color );
    glDisable(GL_BLEND);

}
