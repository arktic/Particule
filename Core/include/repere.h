#ifndef REPERE_H
#define REPERE_H

#include "App.h"

class App;
class Repere {
private:
    bool loaded;
    char* shaderName;
    GLuint shaderID;

    GLfloat g_repere[18];
    GLfloat g_repereColor[18];

public:
    Repere(char* _shaderName);
    void load(App* app);
    void render(App* app);
};

#endif // REPERE_H
