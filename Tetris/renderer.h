#ifndef Renderer_H
#define Renderer_H
#include<SDL.h>
#include<SDL_ttf.h>
#include<string>
#include<SDL_mixer.h>
struct Render
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr ;
    TTF_Font* font = nullptr ;
    Mix_Music* backGroundMusic = nullptr ;
    bool running = false ;
    Render(int width, int height);
    ~Render();
    void Clear();
    void Present();
    bool IsRunning() const;
    void DrawGrid() ;
    void DrawBox(int x, int y, int w, int h, SDL_Color borderColor, SDL_Color fillColor) ;
    void RenderText(const std::string& text, int x, int y) ;
    void DrawSidePanels() ;
    void Stop();
    void CreateMenu(SDL_Renderer* renderer, SDL_Texture*& texture1) ;
};
#endif // Renderer_H
