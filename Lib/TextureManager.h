#pragma once

#include "SDL2/SDL.h"
#include <string>
#include <iostream>

class TextureManager {

private:
    TextureManager() = default;

    static TextureManager *instance;

public:
    static TextureManager *getInstance();

    void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);

    SDL_Texture *LoadImage(SDL_Renderer *renderer, const std::string &file);

};

