#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "defs.h"
#include<ctime>
#include "renderer.h"
#include "event.h"
#include "draw.h"
using namespace std ;

int main(int argc, char* argv[])
{
    Render render(SCREEN_WIDTH, SCREEN_HEIGHT);
    Tetromino current;

    Uint32 lastFallTime = SDL_GetTicks();
    const Uint32 fallDelay = 500;

    while (render.IsRunning()) {
        Uint32 currentTime = SDL_GetTicks();

        // Gọi MoveDown sau mỗi 500ms
        if (currentTime - lastFallTime > fallDelay) {
            current.MoveDown();
            lastFallTime = currentTime;
        }

        HandleEvent(render, current);
        render.Clear();
        render.DrawGrid();
        DrawTetromino(render.renderer, current);
        render.Present();
        SDL_Delay(16);

    }

    return 0;
}
