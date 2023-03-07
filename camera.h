#ifndef _H_CAMERA
#define _H_CAMERA

#include "gameobject.h"
#include "background.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Camera{
public:
    int mCAMWidth, mCAMHeight;

    Camera();
    void watch(GameObject* go, Background* bg);
};


#endif