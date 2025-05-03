#include "event.h"
void HandleEvent(Render& render) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            render.Stop();
        }
    }
}
