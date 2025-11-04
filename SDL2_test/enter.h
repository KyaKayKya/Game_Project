#ifndef _ENTER_H_
#define _ENTER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#undef main

extern SDL_Window* Puzzle1_Window;
extern SDL_Renderer* Puzzle1_Renderer;
extern int presentstate;
//SDL_Window *win=NULL;
SDL_Surface *surf=NULL;
//SDL_Renderer *rdr=NULL;
TTF_Font *font=NULL;
SDL_Texture *imageTexture = NULL;

Uint8 *audio_buf_1;
Uint32 audio_len_1;
Uint32 audio_pos_1 = 0;
SDL_AudioDeviceID device_id_1;//以上四个音量所需

int flag=0;




#define SAVE_FILE "S/gamesave.dat"
#define NUM_SAVES 3
#define win Puzzle1_Window
#define rdr Puzzle1_Renderer
#define init_audio() init_audio_1();
#define audio_buf audio_buf_1
#define audio_len audio_len_1
#define audio_pos audio_pos_1
#define device_id device_id_1
// 游戏数据结构
typedef struct {
    int playerplacex;
    int playerplacey;
    int map;
    int disk;
    bool s2;
    bool ID;
    int is_time_machine_dialogue;
    int boss1_result;
    int boss2_result;
    int lose_count;
    int parkour_result;
    // 其他游戏数据
} GameData;

GameData gameData;
int currentSave = 1; // 当前选中的存档编号


void loadGame(GameData *data, int saveNum) {
    char fileName[20];
    sprintf(fileName, "%s%d.dat", SAVE_FILE, saveNum);

    FILE *file = fopen(fileName, "rb");
    if (file) {
        fread(data, sizeof(GameData), 1, file);
        fclose(file);
    }
}
//保存游戏数据
void saveGame(GameData data, int saveNum) {
    char fileName[20];
    sprintf(fileName, "%s%d.dat", SAVE_FILE, saveNum);

    FILE *file = fopen(fileName, "wb");
    if (file) {
        fwrite(&data, sizeof(GameData), 1, file);
        fclose(file);
    }
}








int setwindows(){//创建窗口以及初始化
    if( SDL_Init(SDL_INIT_EVERYTHING)<0){
    SDL_Log("Init failed:%s",SDL_GetError());
    return -1;
   }

    //win=SDL_CreateWindow("hello",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
    //1250,650,SDL_WINDOW_RESIZABLE);
    if(NULL==win){
        SDL_Log("SDL_CreateWindow failed:%s",SDL_GetError());
        return -1;
    }

    surf=SDL_GetWindowSurface(win);   
    if(NULL==surf){
        SDL_Log("SDL_GetWindowSurface failed:%s",SDL_GetError());
        return -1;
    }

    /*rdr=SDL_CreateRenderer(win,-1,0);*/
    if(NULL==rdr){
        SDL_Log("SDL_CreateRenderer failed:%s",SDL_GetError());
        return -1;
    }
          if(TTF_Init()<0){
        SDL_Log("TTF_Init failed:%s",SDL_GetError());
    return -1;
      } 

      font=TTF_OpenFont("2.ttf",20);
      if (!font)
    {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return -1;
    }
    return 0;
}

void renderTextOneByOne(char *text) {
    SDL_Color textColor = {255, 255, 255}; 
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
    
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(rdr, textSurface);
    
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
    
    SDL_Rect dstRect = {350, 200, 500, 100}; // 文字的初始位置
    
    SDL_RenderClear(rdr);
    
    for (int i = 0; i <= strlen(text); i++) {
        
        SDL_Rect clip = {0, 0, i * textWidth / strlen(text), textHeight};
        SDL_RenderClear(rdr);
        SDL_RenderCopy(rdr, textTexture, &clip, &dstRect);
        
        SDL_RenderPresent(rdr);
        SDL_Delay(100); // 控制文字速度
    }

    SDL_Delay(1000);
    SDL_RenderClear(rdr);
    SDL_Delay(1000);
    
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

SDL_Texture* loadTexture(const char *path) {
    // 加载图片
    SDL_Surface* surface = SDL_LoadBMP(path);
    if (surface == NULL) {
        printf("图片加载失败: %s\n", SDL_GetError());
        return NULL;
    }

    // 创建纹理
    SDL_Texture* texture = SDL_CreateTextureFromSurface(rdr, surface);
    SDL_FreeSurface(surface);
    if (texture == NULL) {
        printf("纹理创建失败: %s\n", SDL_GetError());
        return NULL;
    }

    return texture;
}

void closeSDL() {
    // 释放资源
    SDL_DestroyTexture(imageTexture);
    //SDL_DestroyRenderer(rdr);
    //SDL_DestroyWindow(win);
    //SDL_Quit();
}

int initphoto(){
    imageTexture = loadTexture("enter.bmp");
    if (imageTexture == NULL) {
        closeSDL();
        return -1;
    }

    // 渐变透明度
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        // 清除屏幕
        SDL_SetRenderDrawColor(rdr, 0, 0, 0, 0xFF);
        SDL_RenderClear(rdr);

        // 设置透明度
        SDL_SetTextureAlphaMod(imageTexture, alpha);

        // 绘制图片
        SDL_RenderCopy(rdr, imageTexture, NULL, NULL);

        // 更新屏幕
        SDL_RenderPresent(rdr);

        // 等待一段时间
        SDL_Delay(50);
    }
}
void callback_1(void *userdata, Uint8 * stream, int len)
{
    int remain = audio_len - audio_pos;
    if (remain > len)
    {
        SDL_memcpy(stream, audio_buf + audio_pos, len);
        audio_pos += len;
    }
    else
    {
        SDL_memcpy(stream, audio_buf + audio_pos, remain);
        audio_pos = 0;
    }
    
}

void init_audio_1(){
    SDL_AudioSpec audio_spec;

    
    // 1. 导入WAV文件
    SDL_LoadWAV("load.wav", &audio_spec, &audio_buf, &audio_len);

    // 2. 定义播放回调函数
    audio_spec.userdata = (void *)"这是外部传进来的数据";
    audio_spec.callback = callback_1;
    
    // 3. 打开音频设备
    device_id = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);
    if (device_id == 0) {
    printf("Failed to open audio: %s\n", SDL_GetError());
} else {
    printf("Audio device opened successfully!\n");
}
    // 4. 开始播放
    SDL_PauseAudioDevice(device_id, 0);
    printf("1");
}

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
    textRect.x = 535;
    textRect.y = 450;
    textRect.w = 1.5*textSurface->w;
    textRect.h = 1.5*textSurface->h;

    Uint32 startTime = SDL_GetTicks();
    Uint32 currentTime = 0;
    float alpha = 0.0f;
    int direction = 1;

    int l = 0;
    SDL_Event event;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                saveGame(gameData, currentSave);
                printf("存档 %d 保存成功\n", currentSave);
                printf("目前人物位置x：%d,目前人物位置y：%d，地图:%d\n",gameData.playerplacex,gameData.playerplacey,gameData.map);
                running = false;
                break;
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                /*saveGame(gameData, currentSave);
                printf("存档 %d 保存成功\n", currentSave);
                printf("目前人物位置x：%d,目前人物位置y：%d，地图:%d\n",gameData.playerplacex,gameData.playerplacey,gameData.map);*/
                SDL_PauseAudioDevice(device_id, 1);
                SDL_RenderClear(rdr);
                running=false;

            }
        }
        l = 0;

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
                SDL_RenderCopy(rdr, imageTexture, NULL, NULL);
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                SDL_RenderPresent(renderer);
            }
            
           

            startTime = currentTime;
        }
    }

    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);

    return 0;
}


int Load_IN() {
    if (setwindows() != 0) {
        return -1;
    }
    // 加载图片
    renderTextOneByOne((char *)"Virtual Visionaries");

    init_audio();
    initphoto();


    loadGame(&gameData, currentSave);
    printf("存档 %d 加载成功\n", currentSave);
    printf("目前人物位置x：%d,目前人物位置y：%d，地图:%d\n",gameData.playerplacex,gameData.playerplacey,gameData.map);


    char entertext[]="press enter";
    SDL_Color color={100,100,100};
    SDL_Event event;
    textFadeInOut(win,rdr,font,entertext,color);
    //// 等待窗口关闭
    //while (SDL_PollEvent(&event))
    //    {
    //        if (event.type == SDL_QUIT) {
    //            saveGame(gameData, currentSave);
    //            printf("存档 %d 保存成功\n", currentSave);
    //            printf("目前人物位置x：%d,目前人物位置y：%d，地图:%d\n",gameData.playerplacex,gameData.playerplacey,gameData.map);
    //            return 1;
    //    }
    //}

    Mix_HaltMusic();
    closeSDL();
    return 0;
}

#endif
