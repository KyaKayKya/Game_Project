#ifndef _ENTER_H_
#define _ENTER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <direct.h>
#include <math.h>
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
SDL_AudioDeviceID device_id_1;//以上四个音量�?�?

int flag=0;




#define SAVE_FILE "S/save"
#define NUM_SAVES 3
#define win Puzzle1_Window
#define rdr Puzzle1_Renderer
#define init_audio() init_audio_1();
#define audio_buf audio_buf_1
#define audio_len audio_len_1
#define audio_pos audio_pos_1
#define device_id device_id_1
// 
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
    // 对话状�?�标志（防�?��?�档后重�?�?
    int enter_is_dialogue;
    int tough_enough_dialogue;
    int dialogue_aFTEr_pLAne;
    int dialogue_Lamy;
    int rOCk_hOLe_dialogue;
    int dialogue_beFOre_Puzz3;
    int map5_is_dialogue;
    int dialogue_Emma;
    int dialogue_Wyvern;
} GameData;

GameData gameData;
int currentSave = 1; // 当前选中的存档编�?

void loadGame(GameData *data, int saveNum) {
    char fileName[20];
    sprintf(fileName, "%s%d.dat", SAVE_FILE, saveNum);

    FILE *file = fopen(fileName, "rb");
    if (file) {
        fread(data, sizeof(GameData), 1, file);
        fclose(file);
    }
}
//
void saveGame(GameData data, int saveNum) {
    char fileName[20];
    sprintf(fileName, "%s%d.dat", SAVE_FILE, saveNum);

    _mkdir("S");  // �?保存档目录存�?
    FILE *file = fopen(fileName, "wb");
    if (file) {
        fwrite(&data, sizeof(GameData), 1, file);
        fclose(file);
    }
}








int setwindows(){
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
    
    SDL_Rect dstRect = {350, 200, 500, 100}; // 文字的初始位�?    
    SDL_RenderClear(rdr);
    
    for (int i = 0; i <= strlen(text); i++) {
        
        SDL_Rect clip = {0, 0, i * textWidth / strlen(text), textHeight};
        SDL_RenderClear(rdr);
        SDL_RenderCopy(rdr, textTexture, &clip, &dstRect);
        
        SDL_RenderPresent(rdr);
        SDL_Delay(100); // 控制文字�
    }

    SDL_Delay(1000);
    SDL_RenderClear(rdr);
    SDL_Delay(1000);
    
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

SDL_Texture* loadTexture(const char *path) {
    // 
    SDL_Surface* surface = SDL_LoadBMP(path);
    if (surface == NULL) {
        printf("图片加载失败: %s\n", SDL_GetError());
        return NULL;
    }

    // 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(rdr, surface);
    SDL_FreeSurface(surface);
    if (texture == NULL) {
        printf("纹理创建失败: %s\n", SDL_GetError());
        return NULL;
    }

    return texture;
}

void closeSDL() {
    // 
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

    // 渐变透明�?
    for (int alpha = 0; alpha <= 255; alpha += 5) {
        // 
        SDL_SetRenderDrawColor(rdr, 0, 0, 0, 0xFF);
        SDL_RenderClear(rdr);

        // 设置透明�?
        SDL_SetTextureAlphaMod(imageTexture, alpha);

        // 
        SDL_RenderCopy(rdr, imageTexture, NULL, NULL);

        // 
        SDL_RenderPresent(rdr);

        // 等待�?段时�?
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

    
    // 1. 导入WAV
    SDL_LoadWAV("load.wav", &audio_spec, &audio_buf, &audio_len);

    // 2. 定义�?放回调函�?
    audio_spec.userdata = (void *)"这是外部传进来的数据";
    audio_spec.callback = callback_1;
    
    // 3. Open audio device
    device_id = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);
    if (device_id == 0) {
    printf("Failed to open audio: %s\n", SDL_GetError());
} else {
    printf("Audio device opened successfully!\n");
}
    // 4. �?始播�?
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
                printf("�?前人物位置x�?d,�?前人物位置y�?d，地�?%d\n",gameData.playerplacex,gameData.playerplacey,gameData.map);
                running = false;
                break;
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                /*saveGame(gameData, currentSave);
                printf("存档 %d 保存成功\n", currentSave);
                printf("�?前人物位置x�?d,�?前人物位置y�?d，地�?%d\n",gameData.playerplacex,gameData.playerplacey,gameData.map);*/
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


// ---- How to Play overlay (called from mainMenu) ---------------------
static void mm_howToPlay() {
    TTF_Font* titleF = TTF_OpenFont("2.ttf", 36);
    TTF_Font* bodyF  = TTF_OpenFont("2.ttf", 22);
    if (!titleF) titleF = font;
    if (!bodyF)  bodyF  = font;
    SDL_Color white  = {255, 255, 255, 255};
    SDL_Color yellow = {255, 220,  60, 255};
    SDL_Color grey   = {160, 160, 160, 255};
    const char* lines[] = {
        "WASD / Arrow Keys       Move character",
        "Space / Left Click      Advance dialogue",
        "ESC                     Open pause menu",
        "Mouse                   Interact / select options",
    };
    const int NL = 4;
    int done = 0;
    while (!done) {
        SDL_SetRenderDrawColor(rdr, 6, 10, 20, 255);
        SDL_RenderClear(rdr);
        SDL_SetRenderDrawBlendMode(rdr, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(rdr, 10, 18, 34, 255);
        SDL_Rect ov = {0, 0, 1250, 650};
        SDL_RenderFillRect(rdr, &ov);
        SDL_SetRenderDrawColor(rdr, 18, 30, 56, 255);
        SDL_Rect band = {0, 70, 1250, 110};
        SDL_RenderFillRect(rdr, &band);
        SDL_SetRenderDrawColor(rdr, 14, 22, 42, 255);
        SDL_Rect band2 = {0, 500, 1250, 150};
        SDL_RenderFillRect(rdr, &band2);
        SDL_Rect panel = {295, 125, 660, 400};
        SDL_SetRenderDrawColor(rdr, 12, 18, 40, 240);
        SDL_RenderFillRect(rdr, &panel);
        SDL_SetRenderDrawColor(rdr, 255, 220, 60, 255);
        SDL_RenderDrawRect(rdr, &panel);
        SDL_SetRenderDrawBlendMode(rdr, SDL_BLENDMODE_NONE);
        SDL_Surface* ts = TTF_RenderText_Solid(titleF, "HOW  TO  PLAY", yellow);
        if (ts) {
            SDL_Rect tr = {625 - ts->w/2, 155, ts->w, ts->h};
            SDL_Texture* tt = SDL_CreateTextureFromSurface(rdr, ts);
            SDL_FreeSurface(ts);
            if (tt) { SDL_RenderCopy(rdr, tt, NULL, &tr); SDL_DestroyTexture(tt); }
        }
        SDL_SetRenderDrawColor(rdr, 80, 100, 150, 255);
        SDL_RenderDrawLine(rdr, 325, 212, 920, 212);
        for (int i = 0; i < NL; i++) {
            SDL_Surface* bs = TTF_RenderText_Solid(bodyF, lines[i], white);
            if (bs) {
                SDL_Rect br = {625 - bs->w/2, 235 + i*55, bs->w, bs->h};
                SDL_Texture* bt = SDL_CreateTextureFromSurface(rdr, bs);
                SDL_FreeSurface(bs);
                if (bt) { SDL_RenderCopy(rdr, bt, NULL, &br); SDL_DestroyTexture(bt); }
            }
        }
        SDL_Surface* hs = TTF_RenderText_Solid(bodyF, "Press any key to return", grey);
        if (hs) {
            SDL_Rect hr = {625 - hs->w/2, 478, hs->w, hs->h};
            SDL_Texture* ht = SDL_CreateTextureFromSurface(rdr, hs);
            SDL_FreeSurface(hs);
            if (ht) { SDL_RenderCopy(rdr, ht, NULL, &hr); SDL_DestroyTexture(ht); }
        }
        SDL_RenderPresent(rdr);
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT || ev.type == SDL_KEYDOWN || ev.type == SDL_MOUSEBUTTONDOWN)
                done = 1;
        }
        SDL_Delay(16);
    }
    if (titleF != font) TTF_CloseFont(titleF);
    if (bodyF  != font) TTF_CloseFont(bodyF);
}

// ---- Grand Main Menu -------------------------------------------------
static int mainMenu() {
    const char* items[] = { "START  GAME", "HOW  TO  PLAY", "EXIT" };
    const int N = 3;
    TTF_Font* titleF = TTF_OpenFont("2.ttf", 62);
    TTF_Font* itemF  = TTF_OpenFont("2.ttf", 36);
    TTF_Font* hintF  = TTF_OpenFont("2.ttf", 18);
    TTF_Font* subF   = TTF_OpenFont("2.ttf", 20);
    if (!titleF) titleF = font;
    if (!itemF)  itemF  = font;
    if (!hintF)  hintF  = font;
    if (!subF)   subF   = font;
    SDL_Color white   = {255, 255, 255, 255};
    SDL_Color yellow  = {255, 220,  60, 255};
    SDL_Color grey    = {150, 150, 150, 255};
    SDL_Color dimgrey = { 90,  90,  90, 255};
    int sel = 0, done = 0, result = 0;
    Uint32 t0 = SDL_GetTicks();
    while (!done) {
        int mx = 0, my = 0;
        SDL_GetMouseState(&mx, &my);
        float t = (float)(SDL_GetTicks() - t0) * 0.001f;
        SDL_SetRenderDrawColor(rdr, 6, 10, 20, 255);
        SDL_RenderClear(rdr);
        SDL_SetRenderDrawBlendMode(rdr, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(rdr, 10, 18, 34, 255);
        SDL_Rect ov = {0, 0, 1250, 650};
        SDL_RenderFillRect(rdr, &ov);
        SDL_SetRenderDrawColor(rdr, 18, 30, 56, 255);
        SDL_Rect topBand = {0, 72, 1250, 116};
        SDL_RenderFillRect(rdr, &topBand);
        SDL_SetRenderDrawColor(rdr, 12, 22, 42, 255);
        SDL_Rect bottomBand = {0, 510, 1250, 140};
        SDL_RenderFillRect(rdr, &bottomBand);
        SDL_SetRenderDrawColor(rdr, 20, 30, 54, 210);
        SDL_Rect centerPanel = {180, 92, 890, 430};
        SDL_RenderFillRect(rdr, &centerPanel);
        // Left accent bar
        SDL_SetRenderDrawColor(rdr, 255, 220, 60, 170);
        SDL_Rect lbar = {88, 108, 4, 440};
        SDL_RenderFillRect(rdr, &lbar);
        SDL_SetRenderDrawBlendMode(rdr, SDL_BLENDMODE_NONE);
        // Pulsing title
        float pulse = 0.75f + 0.25f * (float)sin((double)(t * 1.4f));
        SDL_Color titleCol = {
            (Uint8)(int)(215 + 40 * pulse),
            (Uint8)(int)(195 + 25 * pulse),
            (Uint8)(int)(50  + 50 * pulse),
            255
        };
        SDL_Surface* ts = TTF_RenderText_Solid(titleF, "VIRTUAL  VISIONARIES", titleCol);
        if (ts) {
            SDL_Rect tr = {625 - ts->w/2, 108, ts->w, ts->h};
            SDL_Texture* tt = SDL_CreateTextureFromSurface(rdr, ts);
            SDL_FreeSurface(ts);
            if (tt) { SDL_RenderCopy(rdr, tt, NULL, &tr); SDL_DestroyTexture(tt); }
        }
        SDL_Surface* ss = TTF_RenderText_Solid(subF, "A  Sci-Fi  Adventure", grey);
        if (ss) {
            SDL_Rect sr = {625 - ss->w/2, 188, ss->w, ss->h};
            SDL_Texture* st = SDL_CreateTextureFromSurface(rdr, ss);
            SDL_FreeSurface(ss);
            if (st) { SDL_RenderCopy(rdr, st, NULL, &sr); SDL_DestroyTexture(st); }
        }
        SDL_SetRenderDrawColor(rdr, 70, 80, 110, 255);
        SDL_RenderDrawLine(rdr, 380, 225, 1020, 225);
        // Menu items
        const int ITEM_CX = 625, ITEM_Y0 = 278, ITEM_GAP = 88;
        for (int i = 0; i < N; i++) {
            int iy = ITEM_Y0 + i * ITEM_GAP;
            int tw = 0, th = 0;
            TTF_SizeText(itemF, items[i], &tw, &th);
            int ix = ITEM_CX - tw / 2;
            // Mouse hover
            if (mx >= ix && mx < ix + tw && my >= iy && my < iy + th)
                sel = i;
            if (sel == i) {
                SDL_SetRenderDrawBlendMode(rdr, SDL_BLENDMODE_BLEND);
                SDL_SetRenderDrawColor(rdr, 255, 220, 60, 28);
                SDL_Rect hbox = {ix - 22, iy - 8, tw + 44, th + 16};
                SDL_RenderFillRect(rdr, &hbox);
                SDL_SetRenderDrawColor(rdr, 255, 220, 60, 100);
                SDL_RenderDrawRect(rdr, &hbox);
                SDL_SetRenderDrawBlendMode(rdr, SDL_BLENDMODE_NONE);
                SDL_SetRenderDrawColor(rdr, 255, 220, 60, 255);
                SDL_RenderDrawLine(rdr, ix - 30, iy + th/2, ix - 8, iy + th/2);
                SDL_Surface* is_ = TTF_RenderText_Solid(itemF, items[i], yellow);
                if (is_) {
                    SDL_Rect ir = {ix, iy, is_->w, is_->h};
                    SDL_Texture* it_ = SDL_CreateTextureFromSurface(rdr, is_);
                    SDL_FreeSurface(is_);
                    if (it_) { SDL_RenderCopy(rdr, it_, NULL, &ir); SDL_DestroyTexture(it_); }
                }
            } else {
                SDL_Surface* is_ = TTF_RenderText_Solid(itemF, items[i], grey);
                if (is_) {
                    SDL_Rect ir = {ix, iy, is_->w, is_->h};
                    SDL_Texture* it_ = SDL_CreateTextureFromSurface(rdr, is_);
                    SDL_FreeSurface(is_);
                    if (it_) { SDL_RenderCopy(rdr, it_, NULL, &ir); SDL_DestroyTexture(it_); }
                }
            }
        }
        // Bottom hint
        SDL_Surface* hs = TTF_RenderText_Solid(hintF, "[  UP / DOWN  ]  Navigate       [  ENTER / CLICK  ]  Confirm", dimgrey);
        if (hs) {
            SDL_Rect hr = {625 - hs->w/2, 600, hs->w, hs->h};
            SDL_Texture* ht = SDL_CreateTextureFromSurface(rdr, hs);
            SDL_FreeSurface(hs);
            if (ht) { SDL_RenderCopy(rdr, ht, NULL, &hr); SDL_DestroyTexture(ht); }
        }
        SDL_RenderPresent(rdr);
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) { done = 1; result = -1; }
            if (ev.type == SDL_KEYDOWN) {
                switch (ev.key.keysym.sym) {
                    case SDLK_UP: case SDLK_w:
                        sel = (sel - 1 + N) % N; break;
                    case SDLK_DOWN: case SDLK_s:
                        sel = (sel + 1) % N; break;
                    case SDLK_RETURN: case SDLK_SPACE:
                        if (sel == 0) { done = 1; result = 0; }
                        else if (sel == 1) { mm_howToPlay(); }
                        else { done = 1; result = -1; }
                        break;
                    case SDLK_ESCAPE: done = 1; result = -1; break;
                }
            }
            if (ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT) {
                if (sel == 0) { done = 1; result = 0; }
                else if (sel == 1) { mm_howToPlay(); }
                else { done = 1; result = -1; }
            }
        }
        SDL_Delay(16);
    }
    if (titleF != font) TTF_CloseFont(titleF);
    if (itemF  != font) TTF_CloseFont(itemF);
    if (hintF  != font) TTF_CloseFont(hintF);
    if (subF   != font) TTF_CloseFont(subF);
    return result;
}

// ---- helper: render text centred at (cx, y) -------------------------
static void acct_renderText(TTF_Font* fnt, const char* text, SDL_Color col, int cx, int y) {
    if (!fnt || !text || !rdr) return;
    SDL_Surface* s = TTF_RenderText_Solid(fnt, text, col);
    if (!s) return;
    SDL_Rect r;
    r.x = cx - s->w / 2;
    r.y = y;
    r.w = s->w;
    r.h = s->h;
    SDL_Texture* t = SDL_CreateTextureFromSurface(rdr, s);
    SDL_FreeSurface(s);
    if (!t) return;
    SDL_RenderCopy(rdr, t, NULL, &r);
    SDL_DestroyTexture(t);
}

// ---- account / save-slot selection screen ----------------------------
// Returns the chosen slot number (1-3), or -1 on SDL_QUIT.
static int selectAccount() {
    static const char* mapNames[] = {
        "Entrance", "Forest", "Circuit Puzzle", "Forest", "Forest",
        "Boss: Lamy", "Forest", "Forest", "Canyon", "Canyon",
        "Cliff", "Ruins", "Sky Bridge", "Deep Forest", "Temple", "Final Area"
    };
    const int MAP_NAMES_COUNT = 16;

    // Detect which slots have data
    int hasData[4] = {0, 0, 0, 0};  // index 1-3 used
    GameData slotData[4];
    memset(slotData, 0, sizeof(slotData));
    {
        char fname[64];
        for (int i = 1; i <= NUM_SAVES; i++) {
            snprintf(fname, sizeof(fname), "%s%d.dat", SAVE_FILE, i);
            FILE* fp = fopen(fname, "rb");
            if (fp) {
                if (fread(&slotData[i], sizeof(GameData), 1, fp) == 1)
                    hasData[i] = 1;
                fclose(fp);
            }
        }
    }

    // Colours
    SDL_Color white   = {255, 255, 255, 255};
    SDL_Color grey    = {180, 180, 180, 255};
    SDL_Color yellow  = {255, 220,  60, 255};
    SDL_Color red_col = {220,  60,  60, 255};
    SDL_Color green_c = { 60, 200, 120, 255};

    // Fonts
    TTF_Font* bigF = TTF_OpenFont("2.ttf", 44);
    TTF_Font* midF = TTF_OpenFont("2.ttf", 26);
    if (!bigF) bigF = font;
    if (!midF) midF = font;

    // Card layout: 3 cards, 330x240 each, gap 35, centred in 1250px window
    const int CARD_W = 330, CARD_H = 240;
    const int GAP    = 35;
    const int TOTAL_W = 3 * CARD_W + 2 * GAP;   // 1060
    const int START_X = (1250 - TOTAL_W) / 2;    // ~95
    const int CARD_Y  = 200;

    // Delete button: 24x24 in top-right of each card
    const int DEL_SZ  = 24;

    int quit = 0, chosen = 0;

    while (!chosen && !quit) {
        // --- Get mouse position for hover ---
        int mx = 0, my = 0;
        SDL_GetMouseState(&mx, &my);

        SDL_SetRenderDrawColor(rdr, 18, 18, 30, 255);
        SDL_RenderClear(rdr);

        // Title
        acct_renderText(bigF, "SELECT SAVE SLOT", white, 1250 / 2, 80);
        acct_renderText(midF, "Click a slot to start. Click X to delete.", grey, 1250 / 2, 145);

        for (int i = 1; i <= NUM_SAVES; i++) {
            int cx = START_X + (i - 1) * (CARD_W + GAP);

            // Hover detect
            SDL_Rect cardRect;
            cardRect.x = cx; cardRect.y = CARD_Y;
            cardRect.w = CARD_W; cardRect.h = CARD_H;
            int hovered = (mx >= cx && mx < cx + CARD_W &&
                           my >= CARD_Y && my < CARD_Y + CARD_H);

            // Card background
            if (hasData[i])
                SDL_SetRenderDrawColor(rdr, 25, 50, 90, 255);
            else
                SDL_SetRenderDrawColor(rdr, 25, 75, 45, 255);
            SDL_RenderFillRect(rdr, &cardRect);

            // Border
            if (hovered)
                SDL_SetRenderDrawColor(rdr, 255, 220, 60, 255);
            else
                SDL_SetRenderDrawColor(rdr, 80, 100, 140, 255);
            SDL_RenderDrawRect(rdr, &cardRect);

            // Slot label
            char label[32];
            snprintf(label, sizeof(label), "SLOT  %d", i);
            acct_renderText(bigF, label, hovered ? yellow : white, cx + CARD_W / 2, CARD_Y + 14);

            // Separator line
            SDL_SetRenderDrawColor(rdr, 80, 100, 140, 255);
            SDL_RenderDrawLine(rdr, cx + 10, CARD_Y + 68, cx + CARD_W - 10, CARD_Y + 68);

            if (hasData[i]) {
                // Map name
                int mIdx = slotData[i].map;
                const char* mName = (mIdx >= 0 && mIdx < MAP_NAMES_COUNT)
                                     ? mapNames[mIdx] : "Unknown";
                char loc[64];
                snprintf(loc, sizeof(loc), "Map: %s", mName);
                acct_renderText(midF, loc, grey, cx + CARD_W / 2, CARD_Y + 82);

                // Boss states
                char b1[40], b2[40];
                snprintf(b1, sizeof(b1), "Boss 1: %s",
                         slotData[i].boss1_result ? "Defeated" : "Pending");
                snprintf(b2, sizeof(b2), "Boss 2: %s",
                         slotData[i].boss2_result ? "Defeated" : "Pending");
                acct_renderText(midF, b1, grey, cx + CARD_W / 2, CARD_Y + 118);
                acct_renderText(midF, b2, grey, cx + CARD_W / 2, CARD_Y + 150);

                // Disk count
                char dk[32];
                snprintf(dk, sizeof(dk), "Disks: %d", slotData[i].disk);
                acct_renderText(midF, dk, grey, cx + CARD_W / 2, CARD_Y + 182);

                // Action label
                acct_renderText(midF, "[ CONTINUE ]", hovered ? yellow : green_c,
                                cx + CARD_W / 2, CARD_Y + CARD_H - 30);

                // Delete button (top-right)
                SDL_Rect delBtn;
                delBtn.x = cx + CARD_W - DEL_SZ - 6;
                delBtn.y = CARD_Y + 6;
                delBtn.w = DEL_SZ;
                delBtn.h = DEL_SZ;
                int delHov = (mx >= delBtn.x && mx < delBtn.x + DEL_SZ &&
                              my >= delBtn.y && my < delBtn.y + DEL_SZ);
                SDL_SetRenderDrawColor(rdr, delHov ? 255 : 180, 40, 40, 255);
                SDL_RenderFillRect(rdr, &delBtn);
                SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);
                SDL_RenderDrawRect(rdr, &delBtn);
                acct_renderText(font, "X", white,
                                delBtn.x + DEL_SZ / 2, delBtn.y + 3);
            } else {
                // Empty slot
                acct_renderText(midF, "(empty)", grey, cx + CARD_W / 2, CARD_Y + 120);
                acct_renderText(midF, "[ NEW GAME ]", hovered ? yellow : green_c,
                                cx + CARD_W / 2, CARD_Y + CARD_H - 30);
            }
        }

        SDL_RenderPresent(rdr);

        // --- Event handling ---
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) {
                quit = 1;
                break;
            }
            if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE) {
                quit = 1;
                break;
            }
            if (ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT) {
                int bx = ev.button.x, by = ev.button.y;
                for (int i = 1; i <= NUM_SAVES; i++) {
                    int cx = START_X + (i - 1) * (CARD_W + GAP);

                    // Check delete button first (only for existing saves)
                    if (hasData[i]) {
                        SDL_Rect delBtn;
                        delBtn.x = cx + CARD_W - DEL_SZ - 6;
                        delBtn.y = CARD_Y + 6;
                        delBtn.w = DEL_SZ;
                        delBtn.h = DEL_SZ;
                        if (bx >= delBtn.x && bx < delBtn.x + DEL_SZ &&
                            by >= delBtn.y && by < delBtn.y + DEL_SZ) {
                            char fname[64];
                            snprintf(fname, sizeof(fname), "%s%d.dat", SAVE_FILE, i);
                            remove(fname);
                            hasData[i] = 0;
                            memset(&slotData[i], 0, sizeof(GameData));
                            break;
                        }
                    }

                    // Check card click
                    if (bx >= cx && bx < cx + CARD_W &&
                        by >= CARD_Y && by < CARD_Y + CARD_H) {
                        chosen = i;
                        break;
                    }
                }
            }
        }

        SDL_Delay(16);
    }

    if (bigF != font) TTF_CloseFont(bigF);
    if (midF != font) TTF_CloseFont(midF);

    return quit ? -1 : chosen;
}

int Load_IN() {
    if (setwindows() != 0) {
        return -1;
    }
    renderTextOneByOne((char *)"Virtual Visionaries");
    init_audio();
    initphoto();

    // Splash "press enter"
    char entertext[] = "press enter";
    SDL_Color color = {100, 100, 100, 255};
    textFadeInOut(win, rdr, font, entertext, color);

    // Grand main menu
    int menuResult = mainMenu();
    if (menuResult != 0) {
        Mix_HaltMusic();
        closeSDL();
        return 1;
    }

    // Account / save-slot selection
    int chosen = selectAccount();
    if (chosen <= 0) {
        Mix_HaltMusic();
        closeSDL();
        return 1;
    }
    currentSave = chosen;
    loadGame(&gameData, currentSave);
    printf("Loaded slot %d: map=%d pos=(%d,%d)\n",
           currentSave, gameData.map,
           gameData.playerplacex, gameData.playerplacey);

    Mix_HaltMusic();
    closeSDL();
    return 0;
}

#endif
