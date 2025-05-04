#include "event.h"
void HandleEvent(Render& render, Tetromino& current) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            render.Stop();
        }
            if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    current.MoveLeft();
                    break;
                case SDLK_RIGHT:
                    current.MoveRight();
                    break;
                case SDLK_DOWN:
                    current.MoveDown();
                    break;
                case SDLK_z:
                    current.RotateCounterClockwise();
                    break;
                case SDLK_UP:
                    current.RotateClockwise();
                    break;
        }
    }
}
}



