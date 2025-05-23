#include "draw.h"
    const int offsetY = 20;
    const int offsetX = 150 ;
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
                int px = offsetX + (t.x + j) * BLOCK_SIZE;
                int py = offsetY+ (t.y + i) * BLOCK_SIZE;
                DrawBlock(renderer, px, py, color);
            }
        }
    }
}
void DrawBoard(SDL_Renderer* renderer) {
    for (int y = 0; y < BOARD_ROWS; ++y) {
        for (int x = 0; x < BOARD_COLS; ++x) {
            if (board[y][x]) {
                SDL_Color color = {128, 128, 128}; // Màu xám cho khối cố định
                int px = x * BLOCK_SIZE + offsetX;
                int py = y * BLOCK_SIZE + offsetY;
                DrawBlock(renderer, px, py, color);
            }
        }
    }
}
void DrawMiniTetromino(SDL_Renderer* renderer, const Tetromino& t, int startX, int startY, int cellSize) {
    SDL_Color color = GetTetrominoColor(t);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (t.shape[i][j]) {
                int px = startX + j * cellSize;
                int py = startY + i * cellSize;
                SDL_Rect rect = {px, py, cellSize, cellSize};

                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
                SDL_RenderFillRect(renderer, &rect);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // viền đen
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
}

