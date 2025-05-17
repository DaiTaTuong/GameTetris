#include<iostream>
#include "defs.h"
#include "renderer.h"
#include<SDL_image.h>
#include<SDL_ttf.h>

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
        std::cerr << "Texture Error:" << SDL_GetError() << std::endl ;
    }
    if (TTF_Init() == -1) {
    std::cerr << "TTF Error: " << TTF_GetError() << std::endl;
}


    running = true;
}

Render::~Render() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture) ;
    TTF_Quit() ;
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
void Render::CreateMenu(SDL_Renderer* renderer1, SDL_Texture*& texture1)
{
    font = TTF_OpenFont("Roboto.ttf", 48);
    if (!font)
    {
        std::cerr << "Could not open Font: " << TTF_GetError() << std::endl;
        return;
    }

    texture1 = IMG_LoadTexture(renderer1, "Menu.png");
    if (!texture1)
    {
        std::cerr << "Could not load background image: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_RenderClear(renderer1);
    SDL_RenderCopy(renderer1, texture1, NULL, NULL);

    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Nicee", textColor);
    if (!textSurface)
    {
        std::cerr << "Could not create text surface: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer1, textSurface);
    if (!textTexture)
    {
        std::cerr << "Could not create text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        return;
    }

    int textWidth = textSurface->w;
    int textHeight = textSurface->h;
    SDL_FreeSurface(textSurface);

    SDL_Rect textRect = {230, 150, textWidth, textHeight};
    SDL_RenderCopy(renderer1, textTexture, NULL, &textRect);

    SDL_RenderPresent(renderer1);

    SDL_DestroyTexture(textTexture);

    TTF_CloseFont(font) ;
}






