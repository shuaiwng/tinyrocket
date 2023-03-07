#include "background.h"

void Background::init(SDL_Renderer* renderer, std::string path){
    mWidth = 12000;
    mHeight = 2000;
    mCAMWidth = 1200;
    mCAMHeight = 700;

    mClip = { 0, 0, mCAMWidth, mCAMWidth };
    mRenderer = renderer;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    mTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
	SDL_FreeSurface( loadedSurface );
}

void Background::render(int posx, int posy){
    SDL_Rect dstrect = {0, 0, mCAMWidth, mCAMHeight};
    mClip = { posx, posy, mCAMWidth, mCAMHeight };
    SDL_RenderCopyEx(mRenderer, mTexture, &mClip, &dstrect, 0, NULL, SDL_FLIP_NONE);
}