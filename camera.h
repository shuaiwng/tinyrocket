#ifndef _H_CAMERA
#define _H_CAMERA

#include "gameobject.h"
#include "background.h"

class Camera{
public:
    int mCAMWidth, mCAMHeight;

    Camera();
    void watch(GameObject* go, Background* bg);
};


#endif