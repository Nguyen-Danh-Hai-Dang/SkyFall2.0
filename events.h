#ifndef EVENTS_H
#define EVENTS_H
#include "defs.h"
#include "graphics.h"
void Graphics::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (gameState == START_MENU) {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    if (mouseX >= startButtonRect.x && mouseX <= startButtonRect.x + startButtonRect.w &&
                        mouseY >= startButtonRect.y && mouseY <= startButtonRect.y + startButtonRect.h) {
                            gameState = IN_GAME;
                    }
            }
            else
                if (gameState == GAME_OVER)
                {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    if (mouseX >= RestartButtonRect.x && mouseX <= RestartButtonRect.x + RestartButtonRect.w &&
                        mouseY >= RestartButtonRect.y && mouseY <= RestartButtonRect.y + RestartButtonRect.h) {
                        resetGame();
                        gameState = IN_GAME;
                    }
                }
        }
        else
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_RETURN) {
                    if (gameState == START_MENU) {
                        gameState = IN_GAME;
                    }
                    else
                        if (gameState == GAME_OVER) {
                            resetGame();
                            gameState = IN_GAME;
                    }
                }
                if (event.key.keysym.sym == SDLK_LEFT) moveLeft = true;
                if (event.key.keysym.sym == SDLK_RIGHT) moveRight = true;
        }
        else
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_LEFT) moveLeft = false;
                if (event.key.keysym.sym == SDLK_RIGHT) moveRight = false;
            }
    }
}


#endif // EVENTS_H
