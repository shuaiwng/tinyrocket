#ifndef _H_GAMEOBJECT
#define _H_GAMEOBJECT

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class GameObject{
public:
    int mPosX, mPosY;
    int mWidth, mHeight;
    int mVelX, mVelY;
    int mVel, mVelDefault;
    bool mFaceRight;
    int mBGWidth, mBGHeight;

    SDL_Renderer* mRenderer;
    SDL_Texture* mTexture;
    SDL_Rect mClip;
    SDL_RendererFlip mFlip;

    void init(SDL_Renderer* renderer, std::string path);
    void handleEvent(SDL_Event& e);
    void move();
    void render(int posx, int posy);
    void turnaround();
};

#endif