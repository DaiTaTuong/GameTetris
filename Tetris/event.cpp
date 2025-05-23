
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
        case SDLK_SPACE:
            DropTetromino(current) ;
            break ;
    }
}
    }
}
bool HandleMenuEvents(bool& quit) {
    SDL_Event e;
    while (SDL_WaitEvent(&e)) {
        if (e.type == SDL_QUIT) {
            quit = true;
            return false; // Thoát luôn
        }
        if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN) {
            return true;
        }
    }
    return false;
}

