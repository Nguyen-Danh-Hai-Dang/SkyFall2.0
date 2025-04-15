#ifndef SHOOT_H
#define SHOOT_H
#include "defs.h"
#include "graphics.h"
void Graphics::shoot()
{
    if (playerEnergy > 0) {
                Uint32 currentTime = SDL_GetTicks();
                static Uint32 lastShotTime = 0;
                if (currentTime - lastShotTime >= 200) {
                    SDL_Rect leftBullet = {player.x + player.w / 4, player.y + 20, 30, 60};
                    SDL_Rect rightBullet = {player.x + player.w * 3 / 4 - 30, player.y + 20, 30, 60};
                    bullets.push_back(leftBullet);
                    bullets.push_back(rightBullet);
                    lastShotTime = currentTime;
                    Mix_PlayChannel(-1, shootSound, 0);
                }
                if (!energyDepleting) {
                        energyDepleting = true;
                        energyDepleteStart = currentTime;
                }
                int elapsed = currentTime - energyDepleteStart;
                playerEnergy = ENERGY_MAX - (elapsed * ENERGY_MAX / ENERGY_DECREASE_DURATION);
                if (playerEnergy < 0) playerEnergy = 0;
                recoverStart = 0;
        }
        else {
                Uint32 now = SDL_GetTicks();
                energyDepleting = false;
                energyDepleteStart = 0;
                if (recoverStart == 0) recoverStart = now;
                if (now - recoverStart >= ENERGY_RECOVER_DELAY && playerEnergy < ENERGY_MAX) {
                        int recoverElapsed = now - (recoverStart + ENERGY_RECOVER_DELAY);
                        playerEnergy = (recoverElapsed * ENERGY_MAX) / ENERGY_RECOVER_DURATION;
                        if (playerEnergy > ENERGY_MAX) playerEnergy = ENERGY_MAX;
                }
        }
}



#endif // SHOOT_H
