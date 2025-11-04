#include "Run Game.h"
#include "SDL2_test.h"
#include "test2.h"

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <stdbool.h>
//#include<stdio.h>
//#include<stdlib.h>
#define FR 40 // 帧率Frame Rate
#define FT 1000 / FR
// 定义屏幕宽度和高度
#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 650
//#undef main
// 加载图片并创建纹理
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path) {
    SDL_Surface* surface = SDL_LoadBMP(path);
    if (!surface) {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// 全局变量声明
//SDL_Window* window = NULL;
//SDL_Renderer* renderer = NULL;
SDL_Texture* bird_texture = NULL;
SDL_Texture* pipe_texture = NULL;
SDL_Rect HP = { 0,SCREEN_HEIGHT - 25,SCREEN_WIDTH,25 };

SDL_Surface* Shifter_BackGroundSurface_rUn = NULL;
SDL_Texture* Shifter_BackGroundTexture_rUn = NULL;
SDL_Rect fUll_scReeN_rUn = { 0,0,1250,650 };
TTF_Font* font_rUn = NULL;

//Uint8* audio_buf;
//Uint32 audio_len;
//Uint32 audio_pos = 0;
//SDL_AudioDeviceID device_id;//以上四个音量所需
int time_rUn = 0;
#define time time_rUn
int bird_x = 150;
int bird_y = 300;
int bird_velocity = 0;
int top_pipe_height;
int bottom_pipe_height;
int top_pipe_height2;
int bottom_pipe_height2;
int cout;
int pipe_x = SCREEN_WIDTH;
int pipe_x2;
int life;
int tu_x1 = 0;
int tu_x2 = 1250;
int wide;
int gethurt;
int pipe_velocity = 25;
int birdh = 75;
int birdl = 45;
// 生成随机高度的管道
int dialogue_first_run = 0;

//int presentstate;

char rUn_Ellie[10] = { "Ellie" };
char Blank_rUn[100] = { 0 };
char dialogur_rUn_1[100] = { "Press SPACEBAR to jump! Pay attention to the gaps in the laser and rush through it!" };

int generate_pipe_height() {
    // 随机生成一个高度，范围可以根据需求自行调整
    return rand() % 541 + 10; // 假设管道高度范围在之间
}





// 初始化函数
void initialize() {
    //SDL_Init(SDL_INIT_VIDEO);  // 初始化SDL视频模块
    //IMG_Init(IMG_INIT_PNG);     // 初始化SDL_image库，用于加载png图像
    //// 创建窗口和渲染器
    //window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 加载小鸟纹理和管道纹理
    bird_y = 300;
    pipe_velocity = 25;
    Shifter_BackGroundSurface_rUn = IMG_Load("assets/Ingame/FULL BLACK.png");
    Shifter_BackGroundTexture_rUn = SDL_CreateTextureFromSurface(renderer, Shifter_BackGroundSurface_rUn);
    bird_texture = IMG_LoadTexture(renderer, "assets/Ingame/player1.png");
    pipe_texture = IMG_LoadTexture(renderer, "assets/Ingame/lay.png");
    font_rUn = TTF_OpenFont("assets/Font/Allan-Regular.ttf", 50);
}
//void callback(void* userdata, Uint8* stream, int len)
//{
//    int remain = audio_len - audio_pos;
//    if (remain > len)
//    {
//        SDL_memcpy(stream, audio_buf + audio_pos, len);
//        audio_pos += len;
//    }
//    else
//    {
//        SDL_memcpy(stream, audio_buf + audio_pos, remain);
//        audio_pos = 0;
//    }
//
//}

//void init_audio() {
//    SDL_AudioSpec audio_spec;
//
//
//    // 1. 导入WAV文件
//    SDL_LoadWAV("load.wav", &audio_spec, &audio_buf, &audio_len);
//
//    // 2. 定义播放回调函数
//    audio_spec.userdata = (void*)"这是外部传进来的数据";
//    audio_spec.callback = callback;
//
//    // 3. 打开音频设备
//    device_id = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);
//    if (device_id == 0) {
//        printf("Failed to open audio: %s\n", SDL_GetError());
//    }
//    else {
//        printf("Audio device opened successfully!\n");
//    }
//    // 4. 开始播放
//    SDL_PauseAudioDevice(device_id, 0);
//    printf("1");
//}
// 更新函数
void update() {
    bird_y += bird_velocity;  // 更新小鸟的垂直位置
    bird_velocity += 1;       // 模拟重力加速度
    if (bird_y >= SCREEN_HEIGHT - birdh - 25)bird_y = SCREEN_HEIGHT - birdh - 25;
    if (bird_y <= 0) {
        bird_velocity = -bird_velocity; bird_y = 0;
    }
    pipe_x -= pipe_velocity;  // 更新管道的水平位置
    if (pipe_x < -100) {       // 如果管道移出屏幕左侧，重新设置管道位置
        pipe_x = SCREEN_WIDTH;
    }
}
int meet(int bird_x, int pipe_x, int pipe_x2, int top_pipe_height, int bottom_pipe_height, int top_pipe_height2, int bottom_pipe_height2) {
    if (bird_x >= pipe_x - birdl && bird_x <= pipe_x + 100) {
        if (bird_y <= top_pipe_height)return 60;
        else if (bird_y + birdh >= SCREEN_HEIGHT - bottom_pipe_height - 25)return 60;
        else return 0;
    }
    else
        if (bird_x >= pipe_x2 - birdl && bird_x <= pipe_x2 + 100) {
            if (bird_y <= top_pipe_height2)return 60;
            else if (bird_y + birdh >= SCREEN_HEIGHT - bottom_pipe_height2 - 25)return 60;
            else return 0;
        }
        else if (bird_x<pipe_x - birdl || bird_x>pipe_x + 100 || bird_x<pipe_x2 - birdl || bird_x>pipe_x2 + 100)return 0;

}
// 渲染函数
void render() {
    SDL_RenderClear(renderer);  // 清空渲染器
    // 绘制背景
    SDL_Surface* backgroundSurface = IMG_Load("tu2.png");  // 加载背景图片
    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);  // 创建背景纹理
    SDL_Rect backgroundRect = { tu_x1, 0, SCREEN_WIDTH, SCREEN_HEIGHT };  // 定义背景矩形区域
    SDL_Rect backgroundRect2 = { tu_x2, 0, SCREEN_WIDTH, SCREEN_HEIGHT };  // 定义背景矩形区域
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);  // 将背景纹理渲染到屏幕上
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect2);  // 将背景纹理渲染到屏幕上
    SDL_DestroyTexture(backgroundTexture);  // 销毁背景纹理
    SDL_FreeSurface(backgroundSurface);  // 释放背景表面


    // 绘制小鸟
    SDL_Rect bird_rect = { bird_x, bird_y, birdl, birdh };  // 定义小鸟的矩形区域
    SDL_RenderCopy(renderer, bird_texture, NULL, &bird_rect);  // 将小鸟纹理渲染到屏幕上

    // 绘制顶部管道

    SDL_Rect top_pipe_rect = { pipe_x, 0, 100, top_pipe_height };  // 定义顶部管道的矩形区域
    SDL_RenderCopy(renderer, pipe_texture, NULL, &top_pipe_rect);  // 将管道纹理渲染到屏幕上

    // 绘制底部管道
    SDL_Rect bottom_pipe_rect = { pipe_x, SCREEN_HEIGHT - bottom_pipe_height - 25, 100, bottom_pipe_height };  // 定义底部管道的矩形区域
    SDL_RenderCopy(renderer, pipe_texture, NULL, &bottom_pipe_rect);  // 将管道纹理渲染到屏幕上
    //绘制血条
    wide = life;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色
    HP.w = wide * 42;
    SDL_RenderFillRect(renderer, &HP);
    // 绘制心心
    SDL_Surface* xinSurface = IMG_Load("xin.png");  // 加载背景图片
    SDL_Texture* xinTexture = SDL_CreateTextureFromSurface(renderer, xinSurface);  // 创建背景纹理
    SDL_Rect xinRect = { 1008,SCREEN_HEIGHT - 25,25, 25 };  // 定义背景矩形区域
    SDL_RenderCopy(renderer, xinTexture, NULL, &xinRect);  // 将背景纹理渲染到屏幕上
    SDL_DestroyTexture(xinTexture);  // 销毁背景纹理
    SDL_FreeSurface(xinSurface);  // 释放背景表面

    SDL_RenderPresent(renderer);  // 更新屏幕显示
}
void render2() {
    SDL_RenderClear(renderer);  // 清空渲染器
    // 绘制背景
    SDL_Surface* backgroundSurface = IMG_Load("tu2.png");  // 加载背景图片
    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);  // 创建背景纹理
    SDL_Rect backgroundRect = { tu_x1, 0, SCREEN_WIDTH, SCREEN_HEIGHT };  // 定义背景矩形区域
    SDL_Rect backgroundRect2 = { tu_x2, 0, SCREEN_WIDTH, SCREEN_HEIGHT };  // 定义背景矩形区域
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);  // 将背景纹理渲染到屏幕上
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect2);  // 将背景纹理渲染到屏幕上
    SDL_DestroyTexture(backgroundTexture);  // 销毁背景纹理
    SDL_FreeSurface(backgroundSurface);  // 释放背景表面

    // 绘制小鸟
    SDL_Rect bird_rect = { bird_x, bird_y, birdl, birdh };  // 定义小鸟的矩形区域
    SDL_RenderCopy(renderer, bird_texture, NULL, &bird_rect);  // 将小鸟纹理渲染到屏幕上

    // 绘制顶部管道

    SDL_Rect top_pipe_rect = { pipe_x, 0, 100, top_pipe_height };  // 定义顶部管道的矩形区域
    SDL_RenderCopy(renderer, pipe_texture, NULL, &top_pipe_rect);  // 将管道纹理渲染到屏幕上

    // 绘制底部管道
    SDL_Rect bottom_pipe_rect = { pipe_x, SCREEN_HEIGHT - bottom_pipe_height - 25, 100, bottom_pipe_height };  // 定义底部管道的矩形区域
    SDL_RenderCopy(renderer, pipe_texture, NULL, &bottom_pipe_rect);  // 将管道纹理渲染到屏幕上
    // 绘制顶部管道

    SDL_Rect top_pipe_rect2 = { pipe_x2, 0, 100, top_pipe_height2 };  // 定义顶部管道的矩形区域
    SDL_RenderCopy(renderer, pipe_texture, NULL, &top_pipe_rect2);  // 将管道纹理渲染到屏幕上
    // 绘制底部管道
    SDL_Rect bottom_pipe_rect2 = { pipe_x2, SCREEN_HEIGHT - bottom_pipe_height2 - 25, 100, bottom_pipe_height2 };  // 定义底部管道的矩形区域
    SDL_RenderCopy(renderer, pipe_texture, NULL, &bottom_pipe_rect2);  // 将管道纹理渲染到屏幕上
    //绘制血条
    wide = life;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // 红色
    HP.w = wide * 42;
    SDL_RenderFillRect(renderer, &HP);
    // 绘制心心
    SDL_Surface* xinSurface = IMG_Load("xin.png");  // 加载背景图片
    SDL_Texture* xinTexture = SDL_CreateTextureFromSurface(renderer, xinSurface);  // 创建背景纹理
    SDL_Rect xinRect = { 1008,SCREEN_HEIGHT - 25,25, 25 };  // 定义背景矩形区域
    SDL_RenderCopy(renderer, xinTexture, NULL, &xinRect);  // 将背景纹理渲染到屏幕上
    SDL_DestroyTexture(xinTexture);  // 销毁背景纹理
    SDL_FreeSurface(xinSurface);  // 释放背景表面
    SDL_RenderPresent(renderer);  // 更新屏幕显示

}
// 清理函数
void cleanup() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);  // 更新屏幕显示
    SDL_DestroyTexture(bird_texture);  // 销毁小鸟纹理
    SDL_DestroyTexture(pipe_texture);  // 销毁管道纹理
    //SDL_DestroyRenderer(renderer);     // 销毁渲染器
    //SDL_DestroyWindow(window);         // 销毁窗口
    //IMG_Quit();                        // 关闭SDL_image库
    //SDL_Quit();                        // 关闭SDL
}

// 主函数
int run_forest_run(){
    initialize();  // 初始化游戏
    pipe_x = SCREEN_WIDTH;
    pipe_x2 = SCREEN_WIDTH;
    life = 24;
    time = 0;
    //init_audio();
    Uint64 start_t, end_t;
    int delay;
    bool running = true;
    while (running) {

        // start to get time
        start_t = SDL_GetTicks64();

        SDL_Event event;
        // SDL_RenderPresent(renderer);  // 更新屏幕显示
        if (pipe_x == SCREEN_WIDTH)cout = generate_pipe_height();
        if (cout >= 600)cout = generate_pipe_height();
        top_pipe_height = cout;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;  // 如果接收到退出事件，停止游戏循环
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    if (bird_velocity >= 0) {
                        bird_velocity = -10;  // 处理空格键按下事件，使小鸟向上跳
                    }
                    else bird_velocity -= 8;
                }
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    Pause();
                }
                        
            }
        }
        update();  // 更新游戏状态
        if (time++ <= 625) {
            bottom_pipe_height = 440 - top_pipe_height;
            gethurt = meet(bird_x, pipe_x, pipe_x2, top_pipe_height, bottom_pipe_height, top_pipe_height2, bottom_pipe_height2);
            if (!gethurt) {
                gethurt = meet(bird_x, pipe_x, pipe_x2, top_pipe_height, bottom_pipe_height, top_pipe_height2, bottom_pipe_height2);
            }
            if (gethurt == 60) {
                life--;
            }
            if (gethurt)gethurt--;
            tu_x1 -= 10;
            tu_x2 -= 10;
            if (tu_x1 <= -1250)tu_x1 = 0;
            if (tu_x2 <= 0)tu_x2 = 1250;
            render();  // 渲染游戏画面
            if (!dialogue_first_run)
            {
                SDL_RenderCopy(renderer, Shifter_BackGroundTexture_rUn, NULL, &fUll_scReeN_rUn);
                SDL_RenderPresent(renderer);
                present(window, renderer, font_rUn, dialogur_rUn_1, Blank_rUn, rUn_Ellie, (char*)"Avatars/Ellie.png");
                if (presentstate == 0)
                {
                    cleanup();  // 游戏结束，执行清理操作
                    return 0;
                }
                dialogue_first_run = 1;
            }
        }
        else if (time > 625 && time <= 2500) {
            bottom_pipe_height = 470 - top_pipe_height;
            gethurt = meet(bird_x, pipe_x, pipe_x2, top_pipe_height, bottom_pipe_height, top_pipe_height2, bottom_pipe_height2);
            if (!gethurt) {
                gethurt = meet(bird_x, pipe_x, pipe_x2, top_pipe_height, bottom_pipe_height, top_pipe_height2, bottom_pipe_height2);
            }
            if (gethurt == 60) {
                life--;
            }
            if (gethurt)gethurt--;
            top_pipe_height2 = 200;
            bottom_pipe_height2 = 250;
            pipe_velocity = 15;
            if (pipe_x >= -100 && pipe_x <= 650) {
                pipe_x2 = pipe_x + 600;
            }
            else {
                pipe_x2 = pipe_x - 750;
            }
            pipe_x2 -= pipe_velocity;  // 更新管道的水平位置
            tu_x1 -= 10;
            tu_x2 -= 10;
            if (tu_x1 <= -1250)tu_x1 = 0;
            if (tu_x2 <= 0)tu_x2 = 1250;
            render2();
            time++;
        }
        else if (time > 2500) {
            //win!!
            cleanup();
            return 1;
        }
        if (life < 0) {//GAME OVER!!
            cleanup();
            return -1;
        }
        end_t = SDL_GetTicks64();
        delay = FT - (end_t - start_t);
        if (delay > 0)
        {
            SDL_Delay(delay);
        }
        else
        {
            SDL_Delay(10);
        }
        //SDL_Delay(16);  // 控制帧率，避免过快渲染
    }
    cleanup();  // 游戏结束，执行清理操作
    return 0;
}
