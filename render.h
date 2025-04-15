#ifndef RENDER_H
#define RENDER_H
#include "defs.h"
#include "graphics.h"
void Graphics::render(){
    SDL_RenderClear(renderer);
    if (gameState == START_MENU) Start_Menu();
    else if (gameState == IN_GAME) In_Game();
    else if (gameState == GAME_OVER) Game_Over();
    SDL_RenderPresent(renderer);
}



#endif // RENDER_H
