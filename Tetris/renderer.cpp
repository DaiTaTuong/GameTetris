#include<iostream>
#include "defs.h"
#include "renderer.h"
#include<SDL_image.h>
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
    texture = IMG_LoadTexture(renderer, "ChatNgu.png") ;
    if(!texture)
    {
        std::cerr << "BackGround Error:" << SDL_GetError() << std::endl ;
    }

    running = true;
}

Render::~Render() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture) ;
    SDL_Quit();
}

void Render::Clear() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture,nullptr,nullptr) ;
}
void Render::DrawBox(int x, int y, int w, int h, SDL_Color borderColor, SDL_Color fillColor) {
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);
    SDL_RenderDrawRect(renderer, &rect);
}

void Render::DrawSidePanels() {
    // Thông số kích thước
    const int boxWidth = 150;
    const int boxHeight = 120;
    const int margin = 20;
    const int spacing = 20;
    const int offsetX = (SCREEN_WIDTH - 10 * 30) / 2;

    // Tọa độ các khung
    int nextX = offsetX + 10 * 30 + margin;
    int holdX = offsetX - boxWidth - margin;
    int boxY1 = 50;
    int boxY2 = boxY1 + boxHeight + spacing;
    int boxY3 = boxY2 + boxHeight + spacing;

    // Vẽ khung "Next"
    DrawBox(nextX, boxY1, boxWidth, boxHeight,
            {255, 255, 255, 255}, {20, 20, 20, 255});

    // Vẽ khung "Score"
    DrawBox(nextX, boxY2, boxWidth, boxHeight,
            {255, 255, 255, 255}, {20, 20, 20, 255});

    // Vẽ khung "Hold"
    DrawBox(holdX, boxY1, boxWidth, boxHeight,
            {255, 255, 255, 255}, {20, 20, 20, 255});
}
void Render::Present() {
    DrawSidePanels() ;
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

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Vẽ đường dọc
    for (int i = 0; i <= cols; i++) {
        int x = offsetX + i * cellSize;
        SDL_RenderDrawLine(renderer, x, offsetY, x, offsetY + gridHeight);
    }

    // Vẽ đường ngang
    for (int i = 0; i <= rows; i++) {
        int y = offsetY + i * cellSize;
        SDL_RenderDrawLine(renderer, offsetX, y, offsetX + gridWidth, y);
    }
}





