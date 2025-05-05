#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "defs.h"
#include<ctime>
#include "renderer.h"
#include "event.h"
#include "draw.h"
#include "logic.h"
using namespace std ;

int main(int argc, char* argv[])
{
    Render render(SCREEN_WIDTH, SCREEN_HEIGHT);
    Tetromino current;

    Uint32 lastFallTime = SDL_GetTicks(); // lastFallTime không thay đổi theo thời gian, chỉ thay đổi khi bên trong if là đúng
    const Uint32 fallDelay = 500;

    while (render.IsRunning()) {
        Uint32 currentTime = SDL_GetTicks(); // currentTime thay đổi theo thời gian bởi vì nằm trong while(render.isRunning), được gọi liên tục.

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
        cout << current.x << " " << current.y << endl ;
    }

    return 0;
}
