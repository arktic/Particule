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
#include "tree.h"

#include <vector>

class Fire;
class Fountain;
class Smoke;
class Repere;
class Plan;
class HeightMap;
class Tree;
class Camera;

class App : public GlWindow
{
    Q_OBJECT
    private:
    HeightMap* map;
    Repere* repere;
    Plan* plan;
    Fire* fire;
    Smoke* smoke;
    Fountain* fountain;
    std::vector<Tree *> trees;

    bool enableTree;
    float fps;
    int64_t lastTimeFps;

    Camera* cam;

    int textureID;
    int smoke_textureID;
    Vec2 oldMouse;

    void printFps();

	public:
        App(QWidget* parent);

        Camera* getCamera() { return cam; }
        Fire* getFire() { return fire;}
        Smoke * getSmoke() { return smoke;}
        Fountain * getFountain() { return fountain;}

        void createFire();
        void deleteFire();
        void deleteAndCreateFire();

        void createFountain();
        void deleteFountain();
        void deleteAndCreateFountain();


        void createSmoke();
        void deleteSmoke();
        void deleteAndCreateSmoke();


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

        int getFps() { return fps;}
        bool getEnableTree() { return enableTree; }
        void setEnableTree(bool value) {enableTree = value; }

        void notifyFpsChanged(int fps);

signals:
        void onFpsChanged(int fps);
};


#endif
