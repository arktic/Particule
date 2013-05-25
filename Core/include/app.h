#ifndef APP_h
#define APP_h

#define CAM_SPEED 0.5

#include "GlWindow.h"
#include "ParticuleGenerateur.h"
#include "fire.h"
#include "smoke.h"
#include "camera.h"
#include "fountain.h"
#include "repere.h"
#include "plan.h"

class Fire;
class Fountain;
class Smoke;
class Repere;
class Plan;

class App : public GlWindow
{
    private:
    Repere* repere;
    Plan* plan;
    Fire* fire;
    Smoke* smoke;
    Fountain* fountain;

    float fps;
    int64_t lastTimeFps;

    Camera* cam;

    int textureID;
    int smoke_textureID;
    Vec2 oldMouse;

    void printFps();

	public:
		App();
        Camera* getCamera() { return cam; }
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
        void mousePressEvent(QMouseEvent *);
		void keyPressEvent(QKeyEvent *);
};


#endif
