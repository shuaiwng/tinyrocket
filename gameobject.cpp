#include "gameobject.h"

void GameObject::init(SDL_Renderer* renderer, std::string path){
    mPosX = 1000;
    mPosY = 500;
    mWidth = 64;
    mHeight = 64;
    mVel = 13;
    mVelX = mVelY = 0;
    mVelDefault = 1;

    mFaceRight = true;
    mFlip = SDL_FLIP_NONE;
    mBGWidth = 12000;
    mBGHeight = 2000;

    mClip = { 0, 0, mWidth, mHeight };
    mRenderer = renderer;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    mTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
	SDL_FreeSurface( loadedSurface );
}

void GameObject::handleEvent( SDL_Event& e )
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 ){
        switch( e.key.keysym.sym ){
            case SDLK_w: mVelY -= mVel; break;
            case SDLK_s: mVelY += mVel; break;
            case SDLK_a: mVelX -= mVel; break;
            case SDLK_d: mVelX += mVel; break;
            case SDLK_u: turnaround(); break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 ){
        switch( e.key.keysym.sym ){
            case SDLK_w: mVelY += mVel; break;
            case SDLK_s: mVelY -= mVel; break;
            case SDLK_a: mVelX += mVel; break;
            case SDLK_d: mVelX -= mVel; break;
        }
    }
}

void GameObject::move(){
    mPosX += mVelDefault;

    mPosX += mVelX;
    mPosY += mVelY;
    if (mPosX<0){mPosX=0;}
    if (mPosY<0){mPosY=0;}
    if (mPosX+mWidth>mBGWidth){mPosX=mBGWidth-mWidth;}
    if (mPosY+mHeight>mBGHeight){mPosY=mBGHeight-mHeight;}
}

void GameObject::render(int posx, int posy){
    SDL_Rect dstrect = {posx, posy, mWidth, mHeight};
    SDL_RenderCopyEx(mRenderer, mTexture, &mClip, &dstrect, 0, NULL, mFlip);
}

void GameObject::turnaround(){
    mFaceRight = !mFaceRight;
    mVelDefault *= -1;
    if (mFaceRight){
        mFlip = SDL_FLIP_NONE;
    }else{
        mFlip = SDL_FLIP_HORIZONTAL;
    }
}