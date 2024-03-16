#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>

#undef main

// 定义存档文件名前缀和数量
#define SAVE_FILE "F:\\gamesave.dat"
#define NUM_SAVES 3

// 游戏数据结构
typedef struct {
    int playerHealth;
    int playerScore;
    int s2;
    // 其他游戏数据
} GameData;

bool isPaused = false;
int currentSave = 1; // 当前选中的存档编号

SDL_Texture *pause_texture=NULL;
SDL_Surface *pause_surface=NULL;
SDL_Renderer *pause_rdr=NULL;
SDL_Rect rect={0,0,1250,650};



SDL_Rect rects[]={{100,100,200,50},{100,200,200,50},{100,300,200,50}};


void drawHighlightedSave(int i){
    //rect[i]变化图标，变亮
    SDL_Surface* normalImage_1_Surface = SDL_LoadBMP("normal_image.bmp");
    SDL_Surface* highlightImage_1_Surface = SDL_LoadBMP("highlight_image.bmp");
    SDL_Texture* normalImageTexture = SDL_CreateTextureFromSurface(pause_rdr, normalImage_1_Surface);
    SDL_Texture* highlightImageTexture = SDL_CreateTextureFromSurface(pause_rdr, highlightImage_1_Surface);

   if (1) {
            SDL_RenderCopy(pause_rdr, highlightImageTexture, NULL, &rects[i]);
        } else {
            SDL_RenderCopy(pause_rdr, normalImageTexture, NULL, &rects[i]);
        }
        SDL_RenderPresent(pause_rdr);

}

void drawUnhighlightedSave(int i){
    //rect[i]变化图标，变暗
}

void pauseGame(SDL_Renderer *renderer) {
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 200, 0, 0, 200); // 半透明黑色背景
    SDL_RenderFillRect(renderer, &rect);
    // 绘制暂停界面

    pause_surface=IMG_Load("1.jpg");//暂停界面
    pause_texture=SDL_CreateTextureFromSurface(pause_rdr,pause_surface);
    SDL_RenderCopy(pause_rdr,pause_texture,NULL,&rect);
    SDL_RenderPresent(pause_rdr);

   /* for (int i = 1; i <= NUM_SAVES; i++) {
        if (i == currentSave) {
            drawHighlightedSave(i);
        }
        else{drawUnhighlightedSave(i);}
    }*/

    // 刷新显示
    SDL_RenderPresent(renderer);
}

void loadGame(GameData *data, int saveNum) {
    char fileName[20];
    sprintf(fileName, "%s%d.dat", SAVE_FILE, saveNum);

    FILE *file = fopen(fileName, "rb");
    if (file) {
        fread(data, sizeof(GameData), 1, file);
        fclose(file);
    }
}

void saveGame(GameData data, int saveNum) {
    char fileName[20];
    sprintf(fileName, "%s%d.dat", SAVE_FILE, saveNum);

    FILE *file = fopen(fileName, "wb");
    if (file) {
        fwrite(&data, sizeof(GameData), 1, file);
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    // 初始化游戏数据
    GameData gameData;

    SDL_Window *window = SDL_CreateWindow("Pause Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1250, 650, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;
    SDL_Event event;
    Uint32 starttime=0;
    Uint32 endtime=0;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } 
             if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                starttime = SDL_GetTicks();
                if(starttime-endtime>1000){
                isPaused = !isPaused;
                printf("pausing\n");
                pauseGame(renderer);
                printf("选择你的存档\n");}
                }
                if (isPaused==true) {


                    // 在暂停界面时处理按键事件
                     if (event.key.keysym.sym == SDLK_ESCAPE){
                        endtime = SDL_GetTicks();
                        
                        if(endtime-starttime>100){
                        printf("impausing\n");
                        isPaused=!isPaused;
                        }
                     }
                    if (event.key.keysym.sym == SDLK_k) {
                        //esc 退出游戏
                        
                        printf("quit\n");
                        quit = true;
                        return 0;
                    }
                    if (event.key.keysym.sym == SDLK_s) {
                        //s 保存当前游戏存档
                        saveGame(gameData, currentSave);
                        printf("游戏存档 %d 成功\n", currentSave);
                        printf("目前血量：%d,目前成绩：%d",gameData.playerHealth,gameData.playerScore);
                    }
                    if (event.key.keysym.sym == SDLK_l) {
                        //l 加载选中的存档
                        loadGame(&gameData, currentSave);
                        printf("加载游戏存档 %d\n", currentSave);
                        printf("目前血量：%d,目前成绩：%d",gameData.playerHealth,gameData.playerScore);
                    }
                    if (event.key.keysym.sym == SDLK_UP) {
                        // 上移选中的存档
                        currentSave = (currentSave == 1) ? NUM_SAVES : currentSave - 1;
                        printf("选择存档%d\n",currentSave);
                        drawHighlightedSave(currentSave);
                    }
                    if (event.key.keysym.sym == SDLK_DOWN) {
                        // 下移选中的存档
                        currentSave = (currentSave == NUM_SAVES) ? 1 : currentSave + 1;
                        printf("选择存档%d\n",currentSave);
                        drawUnhighlightedSave(currentSave);
                    }
                    if(event.key.keysym.sym==SDLK_q){
                        gameData.playerScore++;
                        printf("score=%d\n",gameData.playerScore);
                    }

                }
            }
    }

        // 游戏逻辑更新和渲染
        if (!isPaused) {
            // 处理游戏逻辑
            // ...

            // 渲染游戏画面
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // 白色背景
            SDL_RenderClear(renderer);
            // 绘制游戏元素
            // ...

            SDL_RenderPresent(renderer);
        } else {
            // 在暂停界面时暂停游戏逻辑和渲染
            SDL_Delay(16);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
操作说明：
在游戏运行时，按下 ESC 键可以暂停游戏，再次按下 ESC 键可以恢复游戏。
在暂停状态下，按下 S 键可以保存当前游戏状态到选定的存档文件。
在暂停状态下，按下 L 键可以加载选定的存档文件来继续游戏。
在暂停状态下，使用 上/下 方向键可以选择不同的存档文件进行保存或加载。
在暂停状态下，使用 Q 键可以增加playerscore值。
