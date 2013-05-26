#ifndef PLAN_H
#define PLAN_H


#include "App.h"

class App;
class Plan {
private:
    bool loaded;
    char* shaderName;
    GLuint shaderID;

    GLfloat g_plan[12];
    GLfloat g_planColor[12];
    GLuint g_planInd[5];


public:
    Plan(char* _shaderName = NULL);
    void load(App* app);
    void render(App* app);
};

#endif // PLAN_H
