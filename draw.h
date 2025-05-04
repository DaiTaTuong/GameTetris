
#ifndef DRAW_H
#define DRAW_H

#include <SDL.h>
#include "tetromino.h"

const int BLOCK_SIZE = 30;

void DrawBlock(SDL_Renderer* renderer, int x, int y, SDL_Color color);
void DrawTetromino(SDL_Renderer* renderer, const Tetromino& t);

#endif // DRAW_H
