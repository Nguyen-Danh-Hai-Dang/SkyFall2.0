#ifndef UPDATE_H
#define UPDATE_H
#include "defs.h"
#include "graphics.h"
void Graphics::update() {
    if (gameState == IN_GAME) {
        if (moveLeft) player.x -= PLAYER_SPEED;
        if (moveRight) player.x += PLAYER_SPEED;
        if (player.x < 0) player.x = 0;
        if (player.x + player.w > SCREEN_WIDTH) player.x = SCREEN_WIDTH - player.w;
        if (player.y < 0) player.y = 0;
        if (player.y + player.h > SCREEN_HEIGHT) player.y = SCREEN_HEIGHT - player.h;
        backgroundY += 5;
        if (backgroundY >= SCREEN_HEIGHT) { backgroundY = 0;}
        shoot();
    }
    for (auto& bullet : bullets) bullet.y -= BULLET_SPEED;
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
        [](SDL_Rect& b) { return b.y < 0; }), bullets.end());
    for (auto& enemy : enemies) enemy.first.y += ENEMY_SPEED;
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
        [](std::pair<SDL_Rect, int>& e) { return e.first.y > SCREEN_HEIGHT; }), enemies.end());
    if (rand() % 100 < ENEMY_SPAWN_RATE && enemies.size() < MAX_ENEMIES) {
            int type = rand() % 3;
            SDL_Rect newEnemy = {rand() % (SCREEN_WIDTH - 100), 0, 100, 100};
            enemies.push_back({newEnemy, type});
    }
    for (auto bulletIt = bullets.begin(); bulletIt != bullets.end(); ) {
        bool bulletRemoved = false;
        for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
            if (SDL_HasIntersection(&(*bulletIt), &(enemyIt->first))) {
                explosions.push_back({enemyIt->first, SDL_GetTicks()});
                bulletIt = bullets.erase(bulletIt);
                enemyIt = enemies.erase(enemyIt);
                score += 10;
                bulletRemoved = true;
                break;
            } else {
                ++enemyIt;
            }
        }
        if (!bulletRemoved) ++bulletIt;
    }
    for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ) {
        if (SDL_HasIntersection(&(enemyIt->first), &player)) {
            explosions.push_back({enemyIt->first, SDL_GetTicks()});
            enemyIt = enemies.erase(enemyIt);
            playerHealth--;
            if (playerHealth <= 0) {
                if (score > highScore) highScore = score;
                    gameState = GAME_OVER;
            }
        } else {
            ++enemyIt;
        }
    }
    Uint32 now = SDL_GetTicks();
    explosions.erase(std::remove_if(explosions.begin(), explosions.end(),
        [now](Explosion& ex) { return now - ex.startTime > EXPLOSION_DURATION; }), explosions.end());
}
#endif // UPDATE_H
