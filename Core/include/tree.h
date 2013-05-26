#ifndef TREE_H
#define TREE_H

#include "Vectors.h"
#include "App.h"

class Tree {
    bool loaded;
    unsigned int trunk_height, trunk_width, foliage_height, foliage_depth, foliage_width;
    Vec3 position;
    char* shaderName;
    GLfloat*    vertices;
    GLfloat* colors;

    GLint indices_trunk[10];
    GLint indices_foliage[10];

    GLint indices_trunk_base[4];
    GLint indices_foliage_base[4];
    GLint indices_foliage_top[4];


public:
    Tree(char * _shaderName,
         Vec3 _position,
         unsigned int _trunk_height,
         unsigned int _trunk_width ,
         unsigned int _foliage_height,
         unsigned int _foliage_width);

    void render(App* app);

    void load(App* app);

    void calculateVertices();
};


#endif // TREE_H
