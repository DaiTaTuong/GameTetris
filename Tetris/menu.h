#ifndef MENU_H
#define MENU_H
#include<SDL_ttf.h>
#include "renderer.h"

enum GameState {
    MENU,
    PLAYING,
    EXIT
};

struct Menu {
    SDL_Rect startButton;
    TTF_Font* font = nullptr;

    void init();
    void render(Render& render);
    void handleEvent(SDL_Event& e, GameState& state);
};
#endif // MENU_H
