#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H
#define MAP_SIZE 5.0

#include "App.h"
#include <QVector>
#include <QVector3D>
#include <QGLWidget>


class App;
class HeightMap:public QGLWidget {
private:
    bool loaded;
    char* path; // texure path
    char* shaderName;
    GLuint mvp;

    QVector<GLuint> m_indices;
    QVector<QVector3D>  m_vertexarray;
    QVector<QVector3D>  m_vertices;

    int vertices_by_x;
    int vertices_by_z;
    int quads_by_x;
    int quads_by_z;

public:
    HeightMap(char* _path, char* _shaderName);
    void load(App *app);
    void render(App *app);
};

#endif // HEIGHTMAP_H
