#include "App.h"
#include "utils.h"
#include "camera.h"
#include "ParticuleGenerateur.h"
#include "fire.h"
#include "smoke.h"
#include "fountain.h"
#include "repere.h"
#include "plan.h"

#include <vector>
#include <iostream>
#include <algorithm>


GLfloat angle1 = 30.0f;
GLfloat angle2 = 20.0f;

const GLfloat g_AngleSpeed = 10.0f;




using namespace std;





bool
App::initializeObjects()
{
    cam = new Camera(20,20,0,0,0,0,0,1,0);
    map = new HeightMap("Texture/heightmap.png","Shaders/map");
    map->load(this);
    oldMouse.x = 0;
    oldMouse.y = 0;
    glClearColor( 0.0f, 0.635294f, 0.90980f, 1.0f );
    fps = 0;

    repere = new Repere("Shaders/color");
    repere->load(this);

    plan = new Plan("Shaders/plan","Texture/tex2d_herbe.png");
    plan->load(this);

    smoke = new Smoke("Shaders/smoke",SMOKE_TEXTURE,SMOKE_FRAMETIME,
                      SMOKE_RADIUS,SMOKE_CENTER,
                      SMOKE_NBPARTICLE,
                      SMOKE_LIFETIME_MIN,SMOKE_LIFETIME_MAX,
                      SMOKE_SIZE_MIN,  SMOKE_SIZE_MAX,
                      SMOKE_VELOCITY_MIN, SMOKE_VELOCITY_MAX,SMOKE_SIZE_COEF,
                      SMOKE_FRAME_MIN, SMOKE_FRAME_MAX, SMOKE_GENTIME);
    smoke->load(this);

    fire = new Fire("Shaders/fire","Texture/tex2d_fire4-2.png",FIRE_FRAMETIME,FIRE_ITEMPERFRAME,
                    FIRE_RADIUS,FIRE_CENTER,
                    FIRE_NBPARTICLE,
                    FIRE_LIFETIME_MIN,FIRE_LIFETIME_MAX,
                    FIRE_SIZE_MIN,  FIRE_SIZE_MAX,
                    FIRE_VELOCITY_MIN, FIRE_VELOCITY_MAX);
    fire->load(this);
    fountain = new Fountain("Shaders/fountain",NULL,FOUNTAIN_FRAMETIME,FOUNTAIN_ITEMPERFRAME,
                    FOUNTAIN_RADIUS,FOUNTAIN_CENTER,
                    FOUNTAIN_NBPARTICLE,
                    FOUNTAIN_LIFETIME_MIN,FOUNTAIN_LIFETIME_MAX,
                    FOUNTAIN_SIZE_MIN,  FOUNTAIN_SIZE_MAX,
                    FOUNTAIN_VELOCITY_MIN, FOUNTAIN_VELOCITY_MAX, FOUNTAIN_DIRECTION);
    fountain->load(this);

    trees.push_back(new Tree("Shaders/tree",Vec3(-10,0,10),10,5,10,10));
    trees.push_back(new Tree("Shaders/tree",Vec3(-10,0,30),10,5,10,10));
    trees.push_back(new Tree("Shaders/tree",Vec3(-10,0,-10),10,5,10,10));

    trees.push_back(new Tree("Shaders/tree",Vec3(-30,0,10),10,5,10,10));
    trees.push_back(new Tree("Shaders/tree",Vec3(-30,0,30),10,5,10,10));
    trees.push_back(new Tree("Shaders/tree",Vec3(-30,0,-10),10,5,10,10));


    trees.push_back(new Tree("Shaders/tree",Vec3(20,0,30),10,5,10,10));
    trees.push_back(new Tree("Shaders/tree",Vec3(20,0,60),10,5,10,10));
    trees.push_back(new Tree("Shaders/tree",Vec3(20,0,-20),10,5,10,10));

    std::vector<Tree*>::iterator tree = trees.begin();
    while(tree != trees.end()) {
        (*tree)->load(this);
        ++tree;
    }


    return true;
}


void
App::render()
{
    // Initialisation de la caméra
        lookAt( cam->getPosition().x, cam->getPosition().y, cam->getPosition().z,
                cam->getTarget().x, cam->getTarget().y, cam->getTarget().z,
                cam->getVaxe().x, cam->getVaxe().y, cam->getVaxe().z );


    // Rendu des objets
    pushMatrix();
       // rotate( angle1, 0, 1, 0 );
       // rotate( angle2, 1, 0, 0 );
        computeAncillaryMatrices();

//        /*------------- repere ------------*/
//        repere->render(this);

//        /*-------------- plan ------------*/
        plan->render(this);

        /*-------------- trees ------------*/
        std::vector<Tree*>::iterator tree = trees.begin();
        while(tree != trees.end()) {
            (*tree)->render(this);
            ++tree;
        }

//        /*--------------- Smoke ---------- */
        smoke->update();
        smoke->render(this);




//        /*--------------- fire ---------- */
        fire->update();
        fire->render(this);

//        /*--------------- fountain ---------- */

        fountain->update();
        fountain->render(this);
      //  map->render(this);



        // affichage des fps
        printFps();
}


void
App::mouseMoveEvent(QMouseEvent *event){
    cam->orienter(event->x()-oldMouse.x ,event->y()-oldMouse.y);
    oldMouse.x = event->x();
    oldMouse.y = event->y();
}

void App::mousePressEvent(QMouseEvent * event) {
    oldMouse.x = event->x();
    oldMouse.y = event->y();
}

void
App::keyPressEvent( QKeyEvent* event )
{
    if(event->key() == Qt::Key_Z){
        cam->moveForward(CAM_SPEED);
    }
    if(event->key() == Qt::Key_S){
        cam->moveBackward(CAM_SPEED);
    }
    if(event->key() == Qt::Key_Q){
        cam->moveLeftSide(CAM_SPEED);
    }
    if(event->key() == Qt::Key_D){
        cam->moveRightSide(CAM_SPEED);
    }
    switch( event->key())
    {
        case Qt::Key_Escape:
            close();
            break;

        case Qt::Key_Left:
            angle1 -= g_AngleSpeed;
            break;

        case Qt::Key_Right:
            angle1 += g_AngleSpeed;
            break;

        case Qt::Key_Up:
            angle2 -= g_AngleSpeed;
            break;

        case Qt::Key_Down:
            angle2 += g_AngleSpeed;
            break;

        case Qt::Key_R:
            angle1 = angle2 = 0.0f;
            break;
    }
}

void App::printFps() {
    int64_t currentTime;
    time_ms(&currentTime);
    fps++;
    if( currentTime - lastTimeFps  > 1000)
    {
        notifyFpsChanged(fps);
        //std::cout << "fps:" << fps << " nbalive:" << fire->getNbAlive() << std::endl;
        fps = 0;
        time_ms(&lastTimeFps);
    }
}



App::~App() {
    delete repere;
    delete plan;
    smoke->unload(this);
    delete smoke;
    fire->unload(this);
    delete fire;
    fountain->unload(this);
    delete fountain;
    plan->unload(this);
    delete cam;
}


App::App(QWidget*) : trees() {
 time_ms(&lastTimeFps);
}


void App::notifyFpsChanged(int fps) {
    emit onFpsChanged(fps);
}
