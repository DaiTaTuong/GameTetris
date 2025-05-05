
#ifndef DRAW_H
#define DRAW_H

#include <SDL.h>
#include "tetromino.h"
#include "logic.h"
const int BLOCK_SIZE = 30;

void DrawBlock(SDL_Renderer* renderer, int x, int y, SDL_Color color);
void DrawTetromino(SDL_Renderer* renderer, const Tetromino& t);
void DrawBoard(SDL_Renderer* renderer) ;
#endif // DRAW_H
