
#include "smoke.h"
#include <iostream>
#include "utils.h"
#include "App.h"

Smoke::Smoke
    (char* _shaderName   , char* _textureName,  float _frameTime  , float _radius,
        Vec3 _center        , int _nbItem       , float _lifeTimeMin    , float _lifeTimeMax,
        float _sizeMin      , float _sizeMax    , float _velocityMin    , float _velocityMax,
        float _sizeMaxCoef
    , int _itemPerFrameMax, int _itemPerFrameMin, int _updateNbItemTimer, int _nbItemPerFrame   ):
    ParticuleGenerateur
        (
            _shaderName     , _textureName , _frameTime     , _nbItemPerFrame       , _radius,
            _center         ,_nbItem        , _lifeTimeMin          , _lifeTimeMax,
            _sizeMin        ,_sizeMax       , _velocityMin          , _velocityMax
        )
{
    sizeMaxCoef = _sizeMaxCoef;
    itemPerFrameMax = _itemPerFrameMax;
    itemPerFrameMin = _itemPerFrameMin;

    lastUpdateNbItem = 0;
    updateNbItemTimer = _updateNbItemTimer;
    nbItemPerFrame = getRandomItemPerFrame();
}

void Smoke::fillCGA(int &i, vector<Particule*>::iterator &it)
{
    Vec3 pos = (*it)->getPosition();
    vertices[3*i  ]   = pos.x;
    vertices[3*i+1] = pos.y;
    vertices[3*i+2] = pos.z;

    pos = (*it)->getVelocity();

    velocity[3*i]   = pos.x;
    velocity[3*i+1] = pos.y;
    velocity[3*i+2] = pos.z;

    agesRatio[i] = (*it)->getAge()/((*it)->getLifeTime());
    ages[i] = (*it)->getAge();
    sizes[i] = (float)(*it)->getSize();
}

void Smoke::addParticle(){
    int nbPtcBroughtBackToLife = 0;
    lastUpdateNbItem += elapsedTime;
    if(lastUpdateNbItem > updateNbItemTimer)
    {
        nbItemPerFrame = getRandomItemPerFrame();
        lastUpdateNbItem = 0;

    while(dead.size() > 0 && nbPtcBroughtBackToLife < nbItemPerFrame) {
        Particule* pt = dead.back();
        dead.pop_back();
        fillRandomParticule(pt);
        alive.push_back(pt);
        nbAlive++;
        nbPtcBroughtBackToLife++;
    }
    }
}

int Smoke::getRandomItemPerFrame() {
    return getBoundedRandom(itemPerFrameMin, itemPerFrameMax);
}

void Smoke::fillRandomParticule(Particule* pt){
    pt->set(getRandomLifeTime(),radius*5,getRandomCenteredPosition(),getRandomVelocity(),0);
}

Vec3 Smoke::getRandomCenteredPosition() {
    Vec3 out;
    out.x = getBoundedRandom(center.x-2, center.x+2);
    out.y = getBoundedRandom(center.y, center.y);
    out.z = getBoundedRandom(center.z-2, center.z+2);
    return out;
}

void
Smoke::load(App *app){
    if(!loaded) {
        if(shaderName != NULL)
            app->createShader(shaderName);
        if(textureName != NULL)
            textureID = app->createTexture(textureName);
        loaded  = true;
    }
}

void
Smoke::unload(App *app){
    if(loaded) {
        if(textureName != NULL)
            app->deleteTexture(textureID);
        loaded = false;
    }
}

void
Smoke::render(App *app){
    glEnable(GL_POINT_SPRITE);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,textureID);

    app->useShader( shaderName );
    shaderID = app->getCurrentShaderId();

    // textureID initialization
    glUniform1i(glGetUniformLocation(0, "texId"),0);

    // setting de la position de la caméra dans le shader et du viewport width
    Vec3 camPos = app->getCamera()->getPosition();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    GLint mvp = glGetUniformLocation( shaderID, "MVP" );
    GLint eyePosition = glGetUniformLocation( shaderID, "eyePosition" );
    GLint viewportWidth = glGetUniformLocation( shaderID, "viewportWidth" );
    GLint sizeCoef = glGetUniformLocation (shaderID, "sizeCoef");

    app->transmitMVP( mvp );
    glUniform3f(eyePosition, camPos.x, camPos.y, camPos.z);
    glUniform1f(viewportWidth,viewport[2] );
    glUniform1f( sizeCoef, sizeMaxCoef);

    GLint t = glGetAttribLocation( shaderID, "t" );
    GLint velocity = glGetAttribLocation( shaderID, "velocity" );
    GLint ageRatio = glGetAttribLocation( shaderID, "ageRatio" );
    GLint position = glGetAttribLocation( shaderID, "position" );
    GLint size = glGetAttribLocation( shaderID, "size" );

    glEnableVertexAttribArray( t );
    glEnableVertexAttribArray( velocity );
    glEnableVertexAttribArray( position );
    glEnableVertexAttribArray( ageRatio );
    glEnableVertexAttribArray( size );


    glVertexAttribPointer( t, 1, GL_FLOAT, GL_FALSE, 0, ages );
    glVertexAttribPointer( velocity, 3, GL_FLOAT, GL_FALSE, 0, this->velocity );
    glVertexAttribPointer( position, 3, GL_FLOAT, GL_FALSE, 0, vertices );
    glVertexAttribPointer( size, 1, GL_FLOAT, GL_FALSE, 0, sizes );
    glVertexAttribPointer( ageRatio, 1, GL_FLOAT, GL_FALSE, 0, agesRatio );


    glDrawArrays( GL_POINTS, 0, nbAlive );

    glDisableVertexAttribArray( position );
    glDisableVertexAttribArray( velocity );
    glDisableVertexAttribArray( t );
    glDisableVertexAttribArray( size );
    glDisableVertexAttribArray( ageRatio );

    //unbind de la texture
    glBindTexture(GL_TEXTURE_2D,0);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_POINT_SPRITE);
    glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glDisable(GL_TEXTURE_2D);
}
