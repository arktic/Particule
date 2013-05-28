#include "fire.h"

Fire::Fire
    (
        char* _shaderName   , char* _textureName, float _frameTime  , int _nbItemPerFrame   , float _radius,
        Vec3 _center        , int _nbItem       , float _lifeTimeMin    , float _lifeTimeMax,
        float _sizeMin      , float _sizeMax    , float _velocityMin    , float _velocityMax
    ):
    ParticuleGenerateur
        (
            _shaderName     , _textureName, _frameTime     , _nbItemPerFrame       , _radius,
            _center         ,_nbItem        , _lifeTimeMin          , _lifeTimeMax,
            _sizeMin        ,_sizeMax       , _velocityMin          , _velocityMax
        )
{
    ageAtenuationFactor = 0.65;
    ageAtenuationLimit = 0.35;

}

void Fire::fillRandomParticule(Particule* pt) {
    Vec3 pos = getRandomPosition();
    Vec3 c_to_pos = getCenter()-pos;
    float lifeTime = getRandomLifeTime();
    float dcenter = c_to_pos.length();
    if(dcenter > ageAtenuationLimit*getRadius() && dcenter > 1)
        lifeTime = lifeTime* (getRadius()/dcenter)*ageAtenuationFactor;

    pt->set(lifeTime,getRandomSize(),pos , getRandomVelocity(),0); // age is set to 0 by default
}

void Fire::setAtenuation(float _ageAtenuationFactor, float _ageAtenuationLimit ){
    ageAtenuationFactor = _ageAtenuationFactor;
    ageAtenuationLimit = _ageAtenuationLimit;
}

void Fire::render(App *app)
{
    // GL_DEPTH_BUFFER_BIT); //
    glEnable(GL_POINT_SPRITE);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);


    app->useShader( shaderName );
    shaderID = app->getCurrentShaderId();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,textureID);

    // textureID initialization
    glUniform1i(glGetUniformLocation(0, "texId"),0);

    // setting de la position de la caméra dans le shader et du viewport width
    camPos = app->getCamera()->getPosition();
    glGetIntegerv(GL_VIEWPORT, viewport);

    mvp           = glGetUniformLocation( shaderID, "MVP" );
    c             = glGetUniformLocation(shaderID, "center" );
    radius        = glGetUniformLocation(shaderID, "radius" );
    eyePosition   = glGetUniformLocation( shaderID, "eyePosition" );
    viewportWidth = glGetUniformLocation( shaderID, "viewportWidth" );

    app->transmitMVP( mvp );
    glUniform3f(eyePosition, camPos.x, camPos.y, camPos.z);
    glUniform1f(viewportWidth,viewport[2] );
    glUniform1f( radius, getRadius());
    glUniform3f(c, center.x, center.y, center.z );

    t        = glGetAttribLocation( shaderID, "t" );
    ivelocity = glGetAttribLocation( shaderID, "velocity" );
    ageRatio = glGetAttribLocation( shaderID, "ageRatio" );
    position = glGetAttribLocation( shaderID, "position" );
    size     = glGetAttribLocation( shaderID, "size" );

    glEnableVertexAttribArray( t );
    glEnableVertexAttribArray( ivelocity );
    glEnableVertexAttribArray( position );
    glEnableVertexAttribArray( ageRatio );
    glEnableVertexAttribArray( size );


    glVertexAttribPointer( t, 1, GL_FLOAT, GL_FALSE, 0, ages );
    glVertexAttribPointer( ivelocity, 3, GL_FLOAT, GL_FALSE, 0, this->velocity );
    glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, vertices );
    glVertexAttribPointer( size, 1, GL_FLOAT, GL_FALSE, 0, sizes );
    glVertexAttribPointer( ageRatio, 1, GL_FLOAT, GL_FALSE, 0, agesRatio );

    glDrawArrays( GL_POINTS, 0, nbAlive );

    glDisableVertexAttribArray( position );
    glDisableVertexAttribArray( ivelocity );
    glDisableVertexAttribArray( t );
    glDisableVertexAttribArray( size );
    glDisableVertexAttribArray( ageRatio );

    //unbind de la texture
    glBindTexture(GL_TEXTURE_2D,0);
    glDisable(GL_POINT_SPRITE);
    glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
}

void Fire::load(App *app) {
    if(!loaded) {
        if(textureName != NULL)
            textureID = app->createTexture(textureName);
        if(shaderName != NULL)
            app->createShader( shaderName );
        loaded = true;
    }
}

void Fire::unload(App *app) {
    if(loaded) {
        if(textureName != NULL)
            app->deleteTexture(textureID);
        loaded = false;
    }
}

Fire::~Fire(){
}
