#ifndef RENDERBUTTON_H
#define RENDERBUTTON_H
#include "defs.h"
#include "graphics.h"
void Graphics::renderButton(const std::string& text, SDL_Rect rect) {
    // Render chữ
    SDL_Texture* textTexture = renderText(text);
    int texW, texH;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &texW, &texH);

    SDL_Rect textRect = {
        rect.x + (rect.w - texW) / 2,
        rect.y + (rect.h - texH) / 2,
        texW, texH
    };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    SDL_DestroyTexture(textTexture);
}

#endif // RENDERBUTTON_H
