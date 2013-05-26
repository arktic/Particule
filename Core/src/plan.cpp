#include "plan.h"
#include "App.h"

Plan::Plan(char *_shaderName):loaded(false){

    g_plan[0]     =  -20;    g_plan[1]    =  0;    g_plan[2]     = 20;
    g_plan[3]     =  -20;    g_plan[4]    =  0;    g_plan[5]     = -20;
    g_plan[6]     = 20;   g_plan[7]     =  0;    g_plan[8]     = -20;
    g_plan[9]     =  20;   g_plan[10]    =  0;    g_plan[11]    = 20;

    g_planColor[0]     =  1;    g_planColor[1]    =  0;    g_planColor[2]     = 0;
    g_planColor[3]     =  1;    g_planColor[4]    =  0;    g_planColor[5]     = 0;
    g_planColor[6]     =  0;   g_planColor[7]     =  1;    g_planColor[8]     = 0;
    g_planColor[9]     =  0;   g_planColor[10]    =  1;    g_planColor[11]    = 0;

    g_planInd[0]    =  0;
    g_planInd[1]    =  1;
    g_planInd[2]    =  3;
    g_planInd[3]    =  2;
    g_planInd[4]    =  2;

    shaderName = _shaderName;
}

void Plan::load(App *app){
    if(!loaded){
        if(shaderName != NULL)
            app->createShader(shaderName);
        loaded = true;
    }
}

void Plan::render(App *app){
    glEnable(GL_BLEND);
    glBlendFunc(GL_ZERO,GL_ONE);
    app->useShader(shaderName);
    shaderID = app->getCurrentShaderId();
    GLint var_id = glGetUniformLocation( shaderID, "MVP" );
    GLint position = glGetAttribLocation( shaderID, "position" );
    GLint color = glGetAttribLocation( shaderID, "color" );
    app->transmitMVP( var_id );

    glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, g_plan);
    glVertexAttribPointer( color, 3, GL_FLOAT, GL_FALSE, 0, g_planColor);
    glEnableVertexAttribArray( position );
    glEnableVertexAttribArray( color );
    glVertexPointer(3,GL_FLOAT,0,g_plan);
    // drawing plan
    glDrawElements(GL_TRIANGLE_STRIP,5, GL_UNSIGNED_INT,g_planInd);

    glDisableVertexAttribArray( position );
    glDisableVertexAttribArray( color );
    glDisable(GL_BLEND);
}
