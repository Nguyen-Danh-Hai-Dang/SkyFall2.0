#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include "defs.h"
#include "graphics.h"
#include "events.h"
#include "update.h"
#include "render.h"
#include "renderButton.h"
#include "shoot.h"
#include "Start_Menu.h"
#include "In_Game.h"
#include "Game_Over.h"

int main(int argc, char* argv[]) {
    Graphics graphics;
    graphics.init();
    SDL_Log("Game started");
    while (running) {
        Uint32 frameStart = SDL_GetTicks();
        graphics.handleEvents();
        graphics.update();
        graphics.render();
        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < 16) SDL_Delay(16 - frameTime);
    }
    graphics.closeAudio();
    graphics.cleanup();
    SDL_Log("Game exited cleanly");
    return 0;
}

