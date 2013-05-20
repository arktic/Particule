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
private:
    // temps depuis le début de la génération
    float lastFrameTime;

    // une frame correspond à une tentative de génération de nbItemPerFrame particules
    float frameTime;
    int nbItemPerFrame;

	/* rayon du cercle sur lequel sont génerées les particules*/
	float radius;
	
	/* position du centre du cercle */
    Vec3 center;
	
	/* nombre de particules de ce générateur. Les particules 
	sont réutilisées après leurs mort afin que l'on ai toujours 
	le même nombre de particules */
    int nbItem;

	/* nombre de particules vivante actuellement. */
	int nbAlive;

	/* durée de vie minium des particules générées */
    float lifeTimeMin;

	/* durée de vie maximum des particules générées */
    float lifeTimeMax;

    /* norme minimale du vecteur vitesse des particules générées */
    float velocityMin;

    /* norme maximale du vecteur vitesse des particules générées */
    float velocityMax;

    /* tab des vitesses composantes distinctes */
    float* velocity;

	/* taille minimum des particules générées */
    float sizeMin;

	/* taille maximum des particules générées */
    float sizeMax;

	/* 	liste des particules actuellement vivantes, donc les seules dont on doit
		effectuer le rendu */
	vector<Particule*> alive;
    vector<Particule*> dead;

    /* tableau des vertices passé à la cg  (composantes par composantes à la suite)*/
    GLfloat* vertices;
    GLfloat* agesRatio;
    GLfloat* ages;
    GLfloat* colors;
    GLfloat*  sizes;

    Vec3 getRandomPosition();
    Vec3 getRandomVelocity();
    float getRandomLifeTime();
    float getRandomSize();

public:
    ParticuleGenerateur(float _frameTime, int _nbItemPerFrame, float _radius,
                        Vec3 _center, int _nbItem, float _lifeTimeMin, float _lifeTimeMax,
                        float _sizeMin, float _sizeMax, float _velocityMin, float _velocityMax);
	~ParticuleGenerateur();

    void update();
    GLfloat* getVertices();
    GLfloat* getVelocity();
    GLfloat* getColors();
    GLfloat* getAgesRatio();
    GLfloat* getAges();
    GLfloat getRadius();
    GLfloat* getSizes();
    Vec3 getCenter();
    int getNbAlive();
};




#endif
