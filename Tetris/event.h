#ifndef EVENT_H
#define EVENT_H
#include "renderer.h"
#include<SDL.h>
#include "tetromino.h"
#include "logic.h"
void HandleEvent(Render& render, Tetromino& current);
bool HandleMenuEvents(bool& quit);
#endif // EVENT_H
