#ifndef Renderer_H
#define Renderer_H
#include<SDL.h>
struct Render
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool running = false ;
    Render(int width, int height);
    ~Render();
    void Clear();
    void Present();
    bool IsRunning() const;
    void DrawGrid() ;
    void Stop();
};
#endif // Renderer_H
