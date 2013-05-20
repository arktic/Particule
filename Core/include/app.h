#ifndef APP_h
#define APP_h

#define GEN_FRAMETIME 33
#define GEN_ITEMPERFRAME 400
#define GEN_NBPARTICLE 10000

#define GEN_LIFETIME_MIN 1000
#define GEN_LIFETIME_MAX 3000

#define GEN_SIZE_MIN 0
#define GEN_SIZE_MAX 5

#define GEN_VELOCITY_MIN 1
#define GEN_VELOCITY_MAX 3

#define GEN_RADIUS 4
#define GEN_CENTER Vec3(0,0,0)

#define GEN_POINT_SIZE 6


#include "GlWindow.h"
#include "ParticuleGenerateur.h"

class App : public GlWindow
{
    private:
    ParticuleGenerateur* gen;
    float fps;
    int64_t lastTimeFps;

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

		void keyPressEvent(QKeyEvent *);
};


#endif
