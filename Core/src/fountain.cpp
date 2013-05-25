
#include "fountain.h"
#include "utils.h"
#include "App.h"

Fountain::Fountain(
    char* _shaderName   , char* _textureName, int64_t _frameTime  , int _nbItemPerFrame   , float _radius,
    Vec3 _center        , int _nbItem       , float _lifeTimeMin    , float _lifeTimeMax,
    float _sizeMin      , float _sizeMax    , float _velocityMin    , float _velocityMax, Vec3 _direction
):
ParticuleGenerateur
    (
        _shaderName     , _textureName, _frameTime     , _nbItemPerFrame       , _radius,
        _center         ,_nbItem        , _lifeTimeMin          , _lifeTimeMax,
        _sizeMin        ,_sizeMax       , _velocityMin          , _velocityMax
        ), direction(_direction)
{
}



Vec3
Fountain::getRandomVelocity() {
    return Vec3(direction)* getBoundedRandom(velocityMin, velocityMax);
}

void
Fountain::load(App *app){
    if(!loaded) {
        if(shaderName != NULL)
            app->createShader(shaderName);
        if(textureName != NULL)
            textureID = app->createTexture(textureName);
        loaded  = true;
    }
}

void
Fountain::unload(App *app){
    if(loaded) {
        if(textureName != NULL)
            app->deleteTexture(textureID);
        loaded = false;
    }
}

void
Fountain::render(App *app){
    glEnable(GL_POINT_SPRITE);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glDisable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    app->useShader( shaderName );
    shaderID = app->getCurrentShaderId();
    // setting de la position de la caméra dans le shader et du viewport width
    Vec3 camPos = app->getCamera()->getPosition();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    GLint mvp = glGetUniformLocation( shaderID, "MVP" );
    GLint eyePosition = glGetUniformLocation( shaderID, "eyePosition" );
    GLint viewportWidth = glGetUniformLocation( shaderID, "viewportWidth" );

    app->transmitMVP( mvp );
    glUniform3f(eyePosition, camPos.x, camPos.y, camPos.z);
    glUniform1f(viewportWidth,viewport[2] );


    GLint t = glGetAttribLocation( shaderID, "t" );
    GLint velocity = glGetAttribLocation( shaderID, "velocity" );
    GLint position = glGetAttribLocation( shaderID, "position" );
    GLint size = glGetAttribLocation( shaderID, "size" );

    glEnableVertexAttribArray( t );
    glEnableVertexAttribArray( velocity );
    glEnableVertexAttribArray( position );
    glEnableVertexAttribArray( size );


    glVertexAttribPointer( t, 1, GL_FLOAT, GL_FALSE, 0, ages );
    glVertexAttribPointer( velocity, 3, GL_FLOAT, GL_FALSE, 0, this->velocity );
    glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, vertices );
    glVertexAttribPointer( size, 1, GL_FLOAT, GL_FALSE, 0, sizes );


    glDrawArrays( GL_POINTS, 0, nbAlive );

    glDisableVertexAttribArray( position );
    glDisableVertexAttribArray( velocity );
    glDisableVertexAttribArray( t );
    glDisableVertexAttribArray( size );

    glDisable(GL_POINT_SPRITE);
    glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glDisable(GL_DEPTH_TEST);

}
