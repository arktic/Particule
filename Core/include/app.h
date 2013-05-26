#ifndef APP_h
#define APP_h

#define CAM_SPEED 1

#include "GlWindow.h"
#include "ParticuleGenerateur.h"
#include "fire.h"
#include "smoke.h"
#include "camera.h"
#include "fountain.h"
#include "repere.h"
#include "plan.h"
#include "heightMap.h"

class Fire;
class Fountain;
class Smoke;
class Repere;
class Plan;
class HeightMap;

class App : public GlWindow
{
    private:
  //  HeightMap* map;
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
        //App();
        App(QWidget* parent);

        Camera* getCamera() { return cam; }
        Fire* getFire() { return fire;}
        Smoke * getSmoke() { return smoke;}
        Fountain * getFountain() { return fountain;}


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
