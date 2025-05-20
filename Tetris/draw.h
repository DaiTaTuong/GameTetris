#ifndef DRAW_H
#define DRAW_H

#include <SDL.h>
#include "tetromino.h"
#include "logic.h"
const int BLOCK_SIZE = 30;

void DrawBlock(SDL_Renderer* renderer, int x, int y, SDL_Color color);
void DrawTetromino(SDL_Renderer* renderer, const Tetromino& t);
void DrawBoard(SDL_Renderer* renderer) ;
void DrawMiniTetromino(SDL_Renderer* renderer, const Tetromino& t, int startX, int startY, int cellSize = 20);

#endif // DRAW_H
