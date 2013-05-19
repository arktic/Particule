#ifndef APP_h
#define APP_h

#define GEN_FRAMETIME 100
#define GEN_ITEMPERFRAME 5
#define GEN_NBPARTICLE 1

#define GEN_LIFETIME_MIN 2000
#define GEN_LIFETIME_MAX 4000

#define GEN_SIZE_MIN 20
#define GEN_SIZE_MAX 30

#define GEN_VELOCITY_MIN 10
#define GEN_VELOCITY_MAX 50

#define GEN_RADIUS 30
#define GEN_CENTER Vec3(0,0,0)


#include "GlWindow.h"
#include "ParticuleGenerateur.h"

class App : public GlWindow
{
    private:
    ParticuleGenerateur* gen;

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
