#include "heightMap.h"
#include <QImage>
#include <QVector>
#include <QVector3D>
#include <qgl.h>
#include <qglcolormap.h>
#include <iostream>

HeightMap::HeightMap(char *_path, char* _shaderName){
    path = _path;
    shaderName = _shaderName;
    QImage img = QImage(QString(path));

    vertices_by_x = img.width();
    vertices_by_z = img.height();
    quads_by_x = vertices_by_x - 1;
    quads_by_z = vertices_by_z - 1;

    std::cout << "map width" << vertices_by_x << std::endl;
    std::cout << "map height" << vertices_by_z << std::endl;

    QVector3D vertice;
    for(int z = 0; z < vertices_by_z; ++z)
    {
        for(int x = 0; x < vertices_by_x; ++x)
        {
            QRgb color = img.pixel(x, z);

            vertice.setX((MAP_SIZE * x / vertices_by_x) - MAP_SIZE / 2);
            vertice.setY(2.0 * qGray(color) / 255);
            vertice.setZ((MAP_SIZE * z / vertices_by_z) - MAP_SIZE / 2);

            m_vertices.push_back(vertice);
        }
    }

    for (int z = 0; z < quads_by_z; ++z)
        {
            for (int x = 0; x < quads_by_x; ++x)
            {
                int i = z * vertices_by_x + x;

                m_vertexarray.push_back(m_vertices[i]);
                m_vertexarray.push_back(m_vertices[i+vertices_by_x]);
                m_vertexarray.push_back(m_vertices[i+1]);

                m_vertexarray.push_back(m_vertices[i+1]);
                m_vertexarray.push_back(m_vertices[i+vertices_by_x]);
                m_vertexarray.push_back(m_vertices[i+1+vertices_by_x]);
            }
        }


}

void HeightMap::render(App *app){
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

   /* cout << "useshader" << app->useShader(shaderName) << endl;
    mvp  = glGetUniformLocation( app->getCurrentShaderId(), "mvp" );
    app->transmitMVP(mvp);
*/
    glColor3f(1,0,0);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, m_vertexarray.constData());

    glDrawArrays(GL_PATCHES, 0, m_vertexarray.size());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_DEPTH_TEST);
}

void HeightMap::load(App *app){
    if(!loaded){
        if(shaderName != NULL)
            cout << "create shader << " << app->createShader(shaderName) << endl;
        loaded = true;
    }
}
