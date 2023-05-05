#ifndef _H_BACKGROUND
#define _H_BACKGROUND

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Background{
public:
    int mWidth, mHeight;
    int mCAMWidth, mCAMHeight;

    SDL_Renderer* mRenderer;
    SDL_Texture* mTexture;
    SDL_Rect mClip;

    Background(SDL_Renderer* renderer, std::string path);
    void render(int, int);
};

#endif