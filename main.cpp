#include "camera.h"
 
int main(int argc, char ** argv)
{
    bool quit = false;
    SDL_Event event;

    int W_WIDTH = 1200;
    int W_HEIGHT = 700;
 
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
 
    SDL_Window* window = SDL_CreateWindow("tinyrocket",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W_WIDTH, W_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    GameObject goPlane(renderer, "assets/rocket.png");
    Background bg(renderer, "assets/bg.png");
    Camera cam;

    SDL_SetRenderDrawColor(renderer, 50, 70, 150, 255);

    while (!quit){
        while (SDL_PollEvent(&event) != 0){
            switch (event.type){
                case SDL_QUIT:
                    quit = true;
                    break;
            }
            goPlane.handleEvent(event);
        }
        goPlane.move();
        SDL_RenderClear(renderer);

        cam.watch(&goPlane, &bg);

        SDL_RenderPresent(renderer);
    }
 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
 
    return 0;
}