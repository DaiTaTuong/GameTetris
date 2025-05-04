
#include "draw.h"

SDL_Color GetTetrominoColor(const Tetromino& t) {
    switch (t.type) {
        case I: return {0, 255, 255};     // Cyan
        case O: return {255, 255, 0};     // Yellow
        case T: return {128, 0, 128};     // Purple
        case S: return {0, 255, 0};       // Green
        case Z: return {255, 0, 0};       // Red
        case J: return {0, 0, 255};       // Blue
        case L: return {255, 165, 0};     // Orange
        default: return {200, 200, 200};  // Fallback
    }
}

void DrawBlock(SDL_Renderer* renderer, int x, int y, SDL_Color color) {
    SDL_Rect rect = { x, y, BLOCK_SIZE, BLOCK_SIZE };

    // Fill block
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
    SDL_RenderFillRect(renderer, &rect);

    // Draw border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black border
    SDL_RenderDrawRect(renderer, &rect);
}

void DrawTetromino(SDL_Renderer* renderer, const Tetromino& t) {
    SDL_Color color = GetTetrominoColor(t);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (t.shape[i][j]) {
                int px = (t.x + j) * BLOCK_SIZE;
                int py = (t.y + i) * BLOCK_SIZE;
                DrawBlock(renderer, px, py, color);
            }
        }
    }
}
