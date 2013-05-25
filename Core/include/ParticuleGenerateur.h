#ifndef _PARTICULE_GENERATEUR_H_
#define _PARTICULE_GENERATEUR_H_


#include <vector>
#include "Vectors.h"
#include "Particule.h"
#include <GL/glew.h>

#define DEFAULT_RADIUS 100
#define DEFAULT_CENTER Vec3i(0,0,0)
#define DEFAULT_NB_ITEM 100
#define DEFAULT_LIFETIME_MIN 100
#define DEFAULT_LIFETIME_MAX 500
#define DEFAULT_SIZE_MIN 10
#define DEFAULT_SIZE_MAX 100


using namespace std;

/* 	Cette classe permet de génerer des particules avec certaines propriétés.
	La forme de ce générateur est par défault un cercle dans le plan XoY */
class ParticuleGenerateur {
protected:
    char*       shaderName;
    char*       textureName;
    // temps depuis le début de la génération
    int64_t       lastFrameTime;

    int elapsedTime;

    // une frame correspond à une tentative de génération de nbItemPerFrame particules
    int64_t       frameTime;
    int         nbItemPerFrame;

	/* rayon du cercle sur lequel sont génerées les particules*/
    float        radius;
	
	/* position du centre du cercle */
    Vec3        center;
	
	/* nombre de particules de ce générateur. Les particules 
	sont réutilisées après leurs mort afin que l'on ai toujours 
	le même nombre de particules */
    int         nbItem;

	/* nombre de particules vivante actuellement. */
    int         nbAlive;

	/* durée de vie minium des particules générées */
    float       lifeTimeMin;

	/* durée de vie maximum des particules générées */
    float       lifeTimeMax;

    /* norme minimale du vecteur vitesse des particules générées */
    float       velocityMin;

    /* norme maximale du vecteur vitesse des particules générées */
    float       velocityMax;

    /* tab des vitesses composantes distinctes */
    float*      velocity;

	/* taille minimum des particules générées */
    float       sizeMin;

	/* taille maximum des particules générées */
    float       sizeMax;

    virtual void addParticle(void);
    void updateParticle(int &elapsedTime);
    virtual void fillRandomParticule(Particule* pt);
    virtual void fillCGA(int &i, vector<Particule*>::iterator &it);

	/* 	liste des particules actuellement vivantes, donc les seules dont on doit
		effectuer le rendu */
    vector<Particule*> alive;
    vector<Particule*> dead;

    /* tableau des vertices passé à la cg  (composantes par composantes à la suite)*/
    GLfloat*    vertices;
    GLfloat*    agesRatio;
    GLfloat*    ages;
    GLfloat*    colors;
    GLfloat*    sizes;

    Vec3        getRandomPosition();
    Vec3        getRandomVelocity();
    float       getRandomLifeTime();
    float       getRandomSize();

public:
    ParticuleGenerateur
        (
            char* _shaderName   , char* _textureName, int64_t _frameTime  , int _nbItemPerFrame   , float _radius ,
            Vec3 _center        , int _nbItem       , float _lifeTimeMin    , float _lifeTimeMax    ,
            float _sizeMin      , float _sizeMax    , float _velocityMin    , float _velocityMax
        );
	~ParticuleGenerateur();


    void update();
    GLfloat*    getVertices()         { return vertices           ;}
    GLfloat*    getVelocity()         { return velocity           ;}
    GLfloat*    getColors()           { return colors             ;}
    GLfloat*    getAgesRatio()        { return agesRatio          ;}
    GLfloat*    getAges()             { return ages               ;}
    GLfloat*    getSizes()            { return sizes              ;}

    GLfloat     getRadius()           { return radius             ;}
    Vec3        getCenter()           { return center             ;}
    char*       getShaderName()       { return shaderName         ;}
    char*       getTextureName()       { return textureName         ;}
    int         getNbItemPerFrame()   { return nbItemPerFrame     ;}
    int         getNbAlive()          { return nbAlive            ;}
    int         getNbItem()           { return nbItem             ;}
    float       getFrameTime()        { return frameTime          ;}
    float       getLifeTimeMin()      { return lifeTimeMin        ;}
    float       getLifeTimeMax()      { return lifeTimeMax        ;}
    float       getVelocityMin()      { return lifeTimeMin        ;}
    float       getVelocityMax()      { return lifeTimeMax        ;}
    float       getSizeMin()          { return sizeMin            ;}
    float       getSizeMax()          { return sizeMax            ;}

    void        setRadius(GLfloat radius_)              { radius = radius_                  ;}
    void        setCenter(Vec3 center_)                 { center = center_                  ;}
    void        setNbItemPerFrame(int nbItemPerFrame_)  { nbItemPerFrame = nbItemPerFrame_  ;}
    void        setNbItem(int nbParticule)              { nbItem = nbParticule              ;}
    void        setFrameTime(int frameTime_)            { frameTime = frameTime_            ;}
    void        setLifeTimeMin(float lifeTimeMin_)      { lifeTimeMin = lifeTimeMin_        ;}
    void        setLifeTimeMax(float lifeTimeMax_)      { lifeTimeMax = lifeTimeMax_        ;}
    void        setVelocityMin(float velocityMin_)      { velocityMin = velocityMin_        ;}
    void        setVelocityMax(float velocityMax_)      { velocityMax = velocityMax_        ;}
    void        setSizeMin(float sizeMin_)              { sizeMin = sizeMin_                ;}
    void        setSizeMax(float sizeMax_)              {  sizeMax = sizeMax_               ;}


};




#endif
