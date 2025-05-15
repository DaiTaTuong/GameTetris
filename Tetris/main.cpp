#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "defs.h"
#include<ctime>
#include "renderer.h"
#include "event.h"
#include "draw.h"
#include "logic.h"

int main(int argc, char* argv[])
{
    Render render(SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Texture* menuTexture = nullptr ;
     render.CreateMenu(render.renderer, menuTexture);

    // Chờ người chơi nhấn phím hoặc chuột để bắt đầu
    bool quit = false;
    if (!HandleMenuEvents(quit)) {
        // Nếu người chơi nhấn nút đóng cửa sổ
        return 0;
    }
    Tetromino current;
    Uint32 lastFallTime = SDL_GetTicks() ;
    const Uint32 fallDelay = 500;

    while (render.IsRunning()) {
        MoveTetromino(current,lastFallTime,fallDelay) ;
        HandleEvent(render, current);
        render.Clear();
        render.DrawGrid();
        DrawTetromino(render.renderer, current);
        DrawBoard(render.renderer) ;
        render.Present();
        SDL_Delay(10);
    }

    return 0;
}
