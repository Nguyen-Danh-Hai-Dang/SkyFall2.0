#ifndef IN_GAME_H
#define IN_GAME_H
#include "defs.h"
#include "graphics.h"
void Graphics::In_Game()
{
    // Vẽ background đang cuộn
    SDL_Rect bg1 = {0, backgroundY, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect bg2 = {0, backgroundY - SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT};
    // Vẽ 2 ảnh nền để tạo hiệu ứng liền mạch
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &bg1);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &bg2);
    SDL_RenderCopy(renderer, playerTexture, nullptr, &player);
    for (auto& bullet : bullets) {
        SDL_RenderCopy(renderer, bulletTexture, nullptr, &bullet);
    }
    for (auto& enemy : enemies) {
        SDL_RenderCopy(renderer, enemyTextures[enemy.second], nullptr, &enemy.first);
    }
    // Vẽ tất cả các vụ nổ
    for (auto& explosion : explosions) {
        Uint32 currentTime = SDL_GetTicks();
        for (auto& explosion : explosions) {
                Mix_PlayChannel(-1, shootSound, 0); // -1: tự chọn kênh, 0: không lặp
                SDL_RenderCopy(renderer, explosionTexture, nullptr, &explosion.rect);
        }
    }
    // Vẽ điểm số và thanh máu, năng lượng
    SDL_Texture* scoreTexture = renderText("Score: " + std::to_string(score));
    int texW = 0, texH = 0;
    SDL_QueryTexture(scoreTexture, NULL, NULL, &texW, &texH);
    SDL_Rect scoreRect = {10, 10, texW + 20, texH + 20};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 150);
    SDL_RenderFillRect(renderer, &scoreRect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &scoreRect);
    SDL_Rect textRect = {scoreRect.x + 10, scoreRect.y + 10, texW, texH};
    SDL_RenderCopy(renderer, scoreTexture, nullptr, &textRect);
    SDL_DestroyTexture(scoreTexture);
    // Vẽ thanh máu
    int barWidth = 200;
    int barHeight = 20;
    int barX = SCREEN_WIDTH - barWidth - 10;
    int barY = 10;
    SDL_Rect outline = {barX, barY, barWidth, barHeight};
    SDL_Rect fill = {barX, barY, (barWidth * playerHealth) / MAX_HEALTH, barHeight};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &fill);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &outline);
    // Vẽ thanh năng lượng
    SDL_Rect energyBarBg = {SCREEN_WIDTH - 160, 50, 150, 10};
    SDL_Rect energyBarFill = {SCREEN_WIDTH - 160, 50, playerEnergy * 150 / 100, 10};
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderFillRect(renderer, &energyBarBg);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &energyBarFill);
}


#endif // IN_GAME_H
