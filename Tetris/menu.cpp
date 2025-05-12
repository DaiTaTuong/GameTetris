#include "menu.h"
#include <iostream>

void Menu::init() {
    startButton = {200, 300, 200, 60}; // nút giữa màn hình 600x640

    font = TTF_OpenFont("Roboto.ttf", 48);
    if (!font) {
        std::cerr << "Font load error: " << TTF_GetError() << std::endl;
    }
}

void Menu::render(Render& render) {
    render.Clear();

    // Vẽ tiêu đề "TETRIS"
    if (font) {
        SDL_Color white = {255, 255, 255, 255};
        SDL_Surface* titleSurface = TTF_RenderText_Solid(font, "TETRIS", white);
        SDL_Texture* titleTexture = SDL_CreateTextureFromSurface(render.renderer, titleSurface);
        int tw, th;
        SDL_QueryTexture(titleTexture, nullptr, nullptr, &tw, &th);
        SDL_Rect titleRect = {(600 - tw) / 2, 100, tw, th};
        SDL_RenderCopy(render.renderer, titleTexture, nullptr, &titleRect);
        SDL_FreeSurface(titleSurface);
        SDL_DestroyTexture(titleTexture);
    }

    // Vẽ nút "Bắt đầu"
    render.DrawBox(startButton.x, startButton.y, startButton.w, startButton.h,
                   {255, 255, 255, 255}, {70, 130, 180, 255});

    // Chữ "Bắt đầu"
    if (font) {
        SDL_Color black = {0, 0, 0, 255};
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Bắt đầu", black);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(render.renderer, textSurface);
        int tw, th;
        SDL_QueryTexture(textTexture, nullptr, nullptr, &tw, &th);
        SDL_Rect textRect = {
            startButton.x + (startButton.w - tw) / 2,
            startButton.y + (startButton.h - th) / 2,
            tw, th
        };
        SDL_RenderCopy(render.renderer, textTexture, nullptr, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    render.Present();
}
void Menu::handleEvent(SDL_Event& e, GameState& state) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x = e.button.x;
        int y = e.button.y;

        if (x >= startButton.x && x <= startButton.x + startButton.w &&
            y >= startButton.y && y <= startButton.y + startButton.h) {
            state = GameState::PLAYING;
        }
    }
}


