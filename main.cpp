#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "defs.h"
#include<ctime>
#include "renderer.h"
#include "event.h"
using namespace std ;
int main(int argc, char* argv[])
{
    Render render(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (render.IsRunning()) {
        HandleEvent(render);
        render.Clear();
        render.DrawGrid() ;
        render.Present();
    }

    return 0;
}
