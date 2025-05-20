#include<iostream>
#include "defs.h"
#include "renderer.h"
#include<SDL_image.h>
#include<SDL_ttf.h>
#include "logic.h"
#include "draw.h"
#include<SDL_mixer.h>
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
    font = TTF_OpenFont("Roboto.ttf", 24);
    if (!font)
    {
        std::cerr << "Could not open Font: " << TTF_GetError() << std::endl;
        return;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    std::cerr << "SDL_mixer could not open: " << Mix_GetError() << std::endl;
}
    backGroundMusic = Mix_LoadMUS("SoundTetris.mp3") ;
    if (!backGroundMusic) {
    std::cerr << "Không thể tải nhạc nền: " << Mix_GetError() << std::endl;
} else {
    Mix_PlayMusic(backGroundMusic, -1);
}
    running = true;
}

Render::~Render() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture) ;
    TTF_CloseFont(font) ;
    TTF_Quit() ;
    Mix_FreeMusic(backGroundMusic) ;
    Mix_CloseAudio() ;
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
void Render::RenderText(const std::string& text, int x, int y) {
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstRect = {x, y, surface->w, surface->h};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    SDL_DestroyTexture(texture);
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
    DrawMiniTetromino(renderer, nextTetromino, nextX + 20, boxY1 + 20);

    RenderText("Next", nextX + 40, boxY1 + 10);
    // Vẽ khung "Score"
    DrawBox(nextX, boxY2, boxWidth, boxHeight,
            {255, 255, 255, 255}, {20, 20, 20, 255});
    RenderText("Score", nextX + 40, boxY2 + 10);
    RenderText(std::to_string(score), nextX + 40, boxY2 + 50);
    // Vẽ khung "Hold"
    DrawBox(holdX, boxY1, boxWidth, boxHeight,
            {255, 255, 255, 255}, {20, 20, 20, 255});
    RenderText("Hold", holdX + 50, boxY1 + 10);
    DrawMiniTetromino(renderer, heldTetromino, holdX + 40, boxY1 + 30 ) ;

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
    texture1 = IMG_LoadTexture(renderer1, "Menu.png");
    if (!texture1)
    {
        std::cerr << "Could not load background image: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_RenderClear(renderer1);
    SDL_RenderCopy(renderer1, texture1, NULL, NULL);


    SDL_RenderPresent(renderer1);


}






