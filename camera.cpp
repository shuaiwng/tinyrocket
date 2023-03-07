#include "camera.h"


Camera::Camera(){
    mCAMWidth = 1200;
    mCAMHeight = 700;
}

void Camera::watch(GameObject* go, Background* bg){
    int camPosX = go->mPosX+go->mWidth/2 - mCAMWidth/2;
    int camPosY = go->mPosY+go->mHeight/2 - mCAMHeight/2;

    int goRenderX = mCAMWidth/2 - go->mWidth/2;
    int goRenderY = mCAMHeight/2 - go->mHeight/2;
    int bgRenderX = camPosX;
    int bgRenderY = camPosY;
    if (camPosX < 0){goRenderX = go->mPosX; bgRenderX = 0;}
    if (camPosY < 0){goRenderY = go->mPosY; bgRenderY = 0;}
    if (camPosX+mCAMWidth > bg->mWidth){
        goRenderX = mCAMWidth - (bg->mWidth-go->mPosX);
        bgRenderX = bg->mWidth - mCAMWidth;
    }
    if (camPosY+mCAMHeight > bg->mHeight){
        goRenderY = mCAMHeight - (bg->mHeight-go->mPosY);
        bgRenderY= bg->mHeight - mCAMHeight;
    }

    bg->render(bgRenderX, bgRenderY);
    go->render(goRenderX, goRenderY);
}