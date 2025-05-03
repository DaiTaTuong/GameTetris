#include<iostream>
#include "defs.h"
#include "renderer.h"
using namespace std ;

Render::Render(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow(SCREEN_TITLE,
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window Error: " << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer Error: " << SDL_GetError() << std::endl;
        return;
    }

    running = true;
}

Render::~Render() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Render::Clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Render::Present() {
    SDL_RenderPresent(renderer);
}
bool Render::IsRunning() const {
    return running;
}
void Render::Stop() {
    running = false;
}
void Render::DrawGrid() {
    const int cols = 10;
    const int rows = 20;
    const int cellSize = 30;
    const int gridWidth = cols * cellSize;
    const int gridHeight = rows * cellSize;
    const int offsetX = (SCREEN_WIDTH - gridWidth) / 2;
    const int offsetY = 20;

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

    // Vẽ đường dọc
    for (int i = 0; i <= cols; ++i) {
        int x = offsetX + i * cellSize;
        SDL_RenderDrawLine(renderer, x, offsetY, x, offsetY + gridHeight);
    }

    // Vẽ đường ngang
    for (int i = 0; i <= rows; ++i) {
        int y = offsetY + i * cellSize;
        SDL_RenderDrawLine(renderer, offsetX, y, offsetX + gridWidth, y);
    }
}



