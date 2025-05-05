#include "event.h"
#include "logic.h"
void HandleEvent(Render& render, Tetromino& current) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            render.Stop();
        }
if (event.type == SDL_KEYDOWN) {
    Tetromino temp = current;  // Tạo bản sao tạm thời của khối tetromino hiện tại

    switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            temp.MoveLeft();
            if (IsValidPosition(temp)) current.MoveLeft();
            break;
        case SDLK_RIGHT:
            temp.MoveRight();
            if (IsValidPosition(temp)) current.MoveRight();
            break;
        case SDLK_DOWN:
            temp.MoveDown();
            if (IsValidPosition(temp)) current.MoveDown();
            break;
        case SDLK_z:
            temp.RotateCounterClockwise();
            if (IsValidPosition(temp)) current.RotateCounterClockwise();
            break;
        case SDLK_UP:
            temp.RotateClockwise();
            if (IsValidPosition(temp)) current.RotateClockwise();
            break;
    }
}
    }
}


        /*
            if (event.type == SDL_KEYDOWN ) {
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

*/

