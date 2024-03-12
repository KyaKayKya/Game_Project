#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

#undef main

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int textFadeInOut(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color textColor) {
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

    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        currentTime = SDL_GetTicks();
        alpha += direction * 0.01f;

        if (alpha >= 1.0f || alpha <= 0.0f) {
            direction *= -1;
        }
        SDL_Delay(16);
        textColor.a = (Uint8)(alpha * 255);
        SDL_SetTextureAlphaMod(textTexture, textColor.a);

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    TTF_Font* font = NULL;
    SDL_Color textColor = {255, 255, 255, 255};

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        printf("TTF could not initialize! TTF_Error: %s\n", TTF_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Text Fade In/Out", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    font = TTF_OpenFont("1.ttf", 24);
    if (font == NULL) {
        printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
        return 1;
    }

    textFadeInOut(window, renderer, font, "Click on the screen to start", textColor);

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
