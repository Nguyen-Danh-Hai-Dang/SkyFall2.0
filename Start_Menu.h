#ifndef START_MENU_H
#define START_MENU_H
#include "defs.h"
#include "graphics.h"
void Graphics::Start_Menu()
{
    SDL_RenderCopy(renderer, startMenuImage, nullptr, nullptr);
    renderButton("Start", startButtonRect);
    Mix_PlayMusic(bgMusic, -1);
}

#endif // START_MENU_H
