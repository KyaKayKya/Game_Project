#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>
#include <stdio.h>
#undef main

void renderText(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y, SDL_Color color) {
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    if (surface == NULL) {
        return;
    }
    
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        SDL_FreeSurface(surface);
        return;
    }
    
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    
    SDL_Rect dstRect = {x, y, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

int word_appear(SDL_Window *window,SDL_Renderer *renderer,TTF_Font *font,int wdsize,const char *text,int x,int y)/*window,render,font,文字大小，文字内容，位置的x，y。
注意创建函数时要先创建Window，renderer，font，例子如下：
    SDL_Window *window = SDL_CreateWindow("Typewriter Effect", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font *font;
    
    char a[100]={"hello,world!"};
    word_appear(window,renderer,font,28,a,100,100);*/
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    font = TTF_OpenFont("1.ttf", wdsize);
    if (font == NULL) {
        // 处理字体加载失败的情况
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }
    SDL_Color color = {255, 255, 255};
    SDL_Event event;
    int i = 0;
    int textLength = strlen(text);
    while (i <= textLength) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        char currentText[i+1];
        strncpy(currentText, text, i);
        currentText[i] = '\0';
        
        renderText(renderer, font, currentText, x, y, color);
        
        SDL_RenderPresent(renderer);
        
        // 控制文字出现的速度
        SDL_Delay(200);
        if (i < textLength) {
            i++;
        }
        
        // 检查退出事件
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                i = textLength;  // 终止循环
            }
        }
    }
}

int main(int argc,char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    SDL_Window *window = SDL_CreateWindow("Typewriter Effect", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font *font;
    
    char a[100]={"hello,world!"};
    word_appear(window,renderer,font,28,a,100,100);
    
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}
