#ifndef GAME_OVER_H
#define GAME_OVER_H
#include "defs.h"
#include "graphics.h"
void Graphics::Game_Over(){
    // Vẽ màn hình kết thúc
    SDL_RenderCopy(renderer, gameOverImage, nullptr, nullptr);
    // Vẽ điểm số cao nhất
    std::string highScoreText = "High Score: " + std::to_string(highScore);
    SDL_Texture* highScoreTexture = renderText(highScoreText);
    int hsW, hsH;
    SDL_QueryTexture(highScoreTexture, NULL, NULL, &hsW, &hsH);
    SDL_Rect hsRect = {SCREEN_WIDTH / 2 - hsW / 2, SCREEN_HEIGHT / 2 - 100, hsW, hsH};
    SDL_RenderCopy(renderer, highScoreTexture, nullptr, &hsRect);
    SDL_DestroyTexture(highScoreTexture);
    // Vẽ điểm số hiện tại
    std::string currentScoreText = "Your Score: " + std::to_string(score);
    SDL_Texture* currentScoreTexture = renderText(currentScoreText);
    int csW, csH;
    SDL_QueryTexture(currentScoreTexture, NULL, NULL, &csW, &csH);
    SDL_Rect csRect = {SCREEN_WIDTH / 2 - csW / 2, SCREEN_HEIGHT / 2 - 50, csW, csH};
    SDL_RenderCopy(renderer, currentScoreTexture, nullptr, &csRect);
    SDL_DestroyTexture(currentScoreTexture);
    //Vẽ nút Restart
    renderButton("Restart", RestartButtonRect);
}



#endif // GAME_OVER_H
