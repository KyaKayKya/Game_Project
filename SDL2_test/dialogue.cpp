#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>
#include "SDL2_test.h"

//test可以删去
SDL_Rect fridge={100,124,120,160};
SDL_Rect wash={400,215,150,60};
SDL_Rect kitchen={628,234,60,40};

Uint8 *audio_buf;
Uint32 audio_len;
Uint32 audio_pos = 0;
SDL_AudioDeviceID device_id;//以上四个音量所需

SDL_Rect dialogue={150,400,1200,200};//对话框的位置
SDL_Rect character={20,440,120,120};
bool show_dialog = true;

int dialoguetime=0;//记录到第几行
int clicktime=0;





int drawtext(SDL_Renderer *renderer,char *a,int x,int y){//基本的显示文字
    

      TTF_Font *font=TTF_OpenFont("1.ttf",28);
      if (!font)
    {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return -1;
    }
    SDL_Color color = {0,0,0};
    SDL_Surface *text1_surface = TTF_RenderUTF8_Blended(font, a, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, text1_surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

    SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = texW;
	dstrect.h = texH;

    
	SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_RenderPresent(renderer);



    return 0;
}


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
    
}







int word_appear(SDL_Window *window,SDL_Renderer *renderer,TTF_Font *font,int wdsize,const char *text,int x,int y,int speed,char *a,char *b, char *c)

    //wdsize:字体大小；text：a/b/c；x就输80，y：对字符串a：y=450，b：y=475；c：y=500,；speed越小速度越快，其实speed代表帧率
    
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
    SDL_Color color = {0, 0, 0};
    SDL_Event event;
    int i = 0;
    int textLength = strlen(text);

    SDL_Surface *imageSurface = IMG_Load("dialog.png");
    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    while (i <= textLength&&show_dialog==true) {

        if (SDL_PollEvent(&event)){
            if (event.type == SDL_MOUSEBUTTONDOWN) {
               /* SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d", 
                event.button.x, event.button.y, event.button.button, event.button.clicks);*/
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Point pt1 = {event.button.x, event.button.y};
                    if (SDL_PointInRect(&pt1, &dialogue)) {
                        show_dialog=false;
                        clicktime=1;
                         // 点击对话框区域以退出循环
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderCopy(renderer, imageTexture, NULL, &dialogue);
        if(dialoguetime==1){
            drawtext(renderer,a, 250,450);
        }
        if(dialoguetime==2){
            drawtext(renderer,a, 250,450);
            drawtext(renderer,b, 250,475);
        }
        char currentText[200];
        strncpy(currentText, text, i);
        currentText[i] = '\0';
        
        renderText(renderer, font, currentText, x, y, color);
        
        SDL_RenderPresent(renderer);
        
        // 控制文字出现的速度
        SDL_Delay(speed);
        if (i <= textLength) {
            i++;  
        }      
    }
    dialoguetime++;
}

  
void callback(void *userdata, Uint8 * stream, int len)
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

void init_audio(){
    SDL_AudioSpec audio_spec;

    
    // 1. 导入WAV文件
    SDL_LoadWAV("speak.wav", &audio_spec, &audio_buf, &audio_len);

    // 2. 定义播放回调函数
    audio_spec.userdata = (void *)"这是外部传进来的数据";
    audio_spec.callback = callback;
    
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


void initphoto(SDL_Window *window,SDL_Renderer *renderer)//可以删去，test所用
{

  /*  SDL_RenderClear(renderer);
    SDL_Surface *imageSurface1 = IMG_Load("bg_kitchen_0.png");
    SDL_Texture *imageTexture1 = SDL_CreateTextureFromSurface(renderer, imageSurface1);
    SDL_RenderCopy(renderer, imageTexture1, NULL, NULL);
    SDL_RenderPresent(renderer);*/

}
void initcharacter(SDL_Window *window,SDL_Renderer *renderer,char *picture){
    SDL_Surface *imageSurface1 = IMG_Load(picture);
    SDL_Texture *imageTexture1 = SDL_CreateTextureFromSurface(renderer, imageSurface1);
    SDL_RenderCopy(renderer, imageTexture1, NULL, &character);
    SDL_RenderPresent(renderer);
}




void present(SDL_Window *window,SDL_Renderer *renderer,TTF_Font *font,char *a,char *b,char *c,char *picture){//a，b，c，是三句话，分别填写
    //写的时候就用这个函数就行，用法应该写在最下面了，要是没了就自己琢磨吧（
    SDL_Event event;
    clicktime=0;
    bool clear=true;
    bool quit=true;
    show_dialog=true;
    while(quit){

    if (SDL_PollEvent(&event)){
        switch(event.type){
                case SDL_QUIT:
                quit=false;
                }
        
        }
    
    while (show_dialog) {

            init_audio();
            SDL_Delay(100);
            initcharacter(window,renderer,picture);
            word_appear(window, renderer, font, 28, a, 250, 450,60,a,b,c);
            word_appear(window, renderer, font, 28, b, 250, 475,60,a,b,c);
            word_appear(window, renderer, font, 28, c, 250, 500,60,a,b,c);
            clicktime=1;
            show_dialog=false;
    }
    if(show_dialog==false&&clicktime==1){
        SDL_PauseAudioDevice(device_id, 1);
        drawtext(renderer,a,250,450);
        drawtext(renderer,b,250,475);
        drawtext(renderer,c,250,500);
        SDL_CloseAudioDevice(device_id);
    }
    /*if (SDL_PollEvent(&event)&&clicktime==0){
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Point pt1 = {event.button.x, event.button.y};
                    if (SDL_PointInRect(&pt1, &dialogue)) {
                        clear=false;
                        clicktime=1;
                         // 点击对话框区域以退出循环
                    }
                }
            }
        }*/
    if (SDL_PollEvent(&event)){
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                /*SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d", 
                event.button.x, event.button.y, event.button.button, event.button.clicks);*/
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Point pt1 = {event.button.x, event.button.y};
                    if (SDL_PointInRect(&pt1, &dialogue)) {
                        initphoto(window,renderer);
                        clicktime=2;
                         // 点击对话框区域以退出循环
                    }
                }
            }
        }
    if(clicktime==2){
        quit=false;
    }
    }

}




//以下示例**********


//int main(int argc,char *argv[]) {
//            
//    SDL_Init(SDL_INIT_AUDIO);
//    SDL_Window *window = SDL_CreateWindow("Typewriter Effect", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
//    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    TTF_Font *font;
//    if(TTF_Init()<0){
//        SDL_Log("TTF_Init failed:%s",SDL_GetError());
//    return -1;
//      }
//    char a[100] = {"i am ljy ,this is a fridge"};
//    char d[100] = {"i am dc ,this is not a fridge ,genius,damn"};
//    char e[100] = {"i am wcy , this is a firdge"};
//    char f[100] = {"i am wzm ,i agree with dc"};
//    //一行最多50个字符（包括有空格）不然容易超出范围
//    char b[100]={0};
//    char c[100]={0};
//    initphoto (window,renderer);
//        SDL_Event event;
//    while(1){
//
//        if (SDL_PollEvent(&event)){
//            switch(event.type){
//                case SDL_QUIT:
//                return 0;
//            }
//        
//        }
//    if (SDL_PollEvent(&event)){//测试所用交互，出现对话
//            if (event.type == SDL_MOUSEBUTTONDOWN) {
//                SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d", 
//                event.button.x, event.button.y, event.button.button, event.button.clicks);
//                if (event.button.button == SDL_BUTTON_LEFT) {
//                    SDL_Point pt1 = {event.button.x, event.button.y};
//                    if (SDL_PointInRect(&pt1, &fridge)) {
//                        present(window,renderer,font,a,b,c,"ljy.png");//只有这里用了
//                        present(window,renderer,font,d,b,c,"dc.png");//只有这里用了
//                        present(window,renderer,font,d,b,c,"dc.png");//只有这里用了
//                        present(window,renderer,font,e,b,c,"wcy.png");//只有这里用了
//                        present(window,renderer,font,f,b,c,"wzm.png");//只有这里用了
//                    }
//                }
//            }
//        }
//    }
//
//    return 0;
//}
//用法：先写三个字符串组abc，再写一个人物图片，然后在事件侦测里观察交互（应该和碰撞箱结合，但我没玩明白那个函数），然后利用present函数，简单明了没啥可关注的（看不懂就不是我的问题