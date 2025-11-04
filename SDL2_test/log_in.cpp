#include "SDL2_test.h"

const int SCREEN_WIDTH = 1250;
const int SCREEN_HEIGHT = 650;
#define textFadeInOut(window, renderer, font, text, textColor) textFadeInOut_1(window, renderer, font, text, textColor)
int textFadeInOut_1(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color textColor) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == NULL) {
        printf("Failed to render text surface! TTF_Error: %s\n", TTF_GetError());
        return 1;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
        printf("Failed to create texture from surface! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Rect textRect;
    textRect.x = (SCREEN_WIDTH - textSurface->w) / 2;
    textRect.y = (SCREEN_HEIGHT - textSurface->h) / 2;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    Uint32 startTime = SDL_GetTicks();
    Uint32 currentTime = 0;
    float alpha = 0.0f;
    int direction = 1;

    int l = 0;
    SDL_Event Event;
    bool running = true;
    while (running)
    {
        l = 0;
        SDL_Event e;
        if (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        currentTime = SDL_GetTicks();
        if (currentTime - startTime > 16)
        {
            alpha += direction * 0.01f;

            if (alpha >= 1.0f || alpha <= 0.0f) {
                direction *= -1;
                l = 1;
            }
            if (l == 0)
            {
                textColor.a = (Uint8)(alpha * 255);
                SDL_SetTextureAlphaMod(textTexture, textColor.a);

                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_RenderPresent(renderer);
            }
            
            while (SDL_PollEvent(&Event))
            {
                switch (Event.type)
                {
                case SDL_QUIT:
                    QUIT();
                    running = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (Event.button.x >= textRect.x && Event.button.x <= textRect.x + textRect.w && Event.button.y >= textRect.y && Event.button.y <= textRect.y + textRect.h)
                    {
                        running = 0;
                    }
                    break;
                default:
                    break;
                }
            }

            startTime = currentTime;
        }
        while (SDL_PollEvent(&Event))
        {
            switch (Event.type)
            {
            case SDL_QUIT:
                QUIT();
                running = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (Event.button.x >= textRect.x && Event.button.x <= textRect.x + textRect.w && Event.button.y >= textRect.y && Event.button.y <= textRect.y + textRect.h)
                {
                    running = 0;
                }
                break;
            default:
                break;
            }
        }
    }

    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);

    return 0;
}
