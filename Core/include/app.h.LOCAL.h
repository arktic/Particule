#ifndef APP_h
#define APP_h

#define CAM_SPEED 0.5

#define GEN_FRAMETIME 33
#define GEN_ITEMPERFRAME 1000
#define GEN_NBPARTICLE 50000

#define GEN_LIFETIME_MIN 1000
#define GEN_LIFETIME_MAX 3000

#define GEN_SIZE_MIN 2
#define GEN_SIZE_MAX 4

#define GEN_VELOCITY_MIN 1
#define GEN_VELOCITY_MAX 3

#define GEN_RADIUS 4
#define GEN_CENTER Vec3(0,0,0)



#define GEN_POINT_SIZE 2

#define GEN_TEXTURE_FIRE "Texture/tex2d_fire4-2.png"


#include "GlWindow.h"
#include "ParticuleGenerateur.h"
#include "fire.h"
#include "camera.h"
class App : public GlWindow
{
    private:
    ParticuleGenerateur* gen;
    Fire* fire;
    float fps;
    int64_t lastTimeFps;

    Camera* cam;
    int textureID;

    void printFps();

	public:
		App();

		/*!
		*\brief Initialization des objets.
		*/
		bool initializeObjects();

		/*!
		*\brief Rendu de la sc?ne.
		*/
		void render();

        virtual ~App();
        void mouseMoveEvent(QMouseEvent *);
		void keyPressEvent(QKeyEvent *);
};


#endif
