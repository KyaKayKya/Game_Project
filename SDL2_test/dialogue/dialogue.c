#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>
#undef main

Uint8 *audio_buf;
Uint32 audio_len;
Uint32 audio_pos = 0;
SDL_AudioDeviceID device_id;//以上四个音量所需
SDL_Rect dialogue={20,400,600,200};//对话框的位置
bool show_dialog = true;

int dialoguetime=0;//记录到第几行
char a[100] = "this is a test and welcome to our game and this is";
    //一行50
char b[100]="a dialogue and i have not done it yet,you can also";
char c[100]="use mouse to skip";//直接在这改三句话，如果不足三行直接输入空格

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







int word_appear(SDL_Window *window,SDL_Renderer *renderer,TTF_Font *font,int wdsize,const char *text,int x,int y,int speed)

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
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Point pt1 = {event.button.x, event.button.y};
                    if (SDL_PointInRect(&pt1, &dialogue)) {
                        show_dialog=false;
                         // 点击对话框区域以退出循环
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, imageTexture, NULL, &dialogue);
        if(dialoguetime==1){
            drawtext(renderer,a,80,450);
        }
        if(dialoguetime==2){
            drawtext(renderer,a,80,450);
            drawtext(renderer,b,80,475);
        }
        char currentText[i+1];
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


void present(SDL_Window *window,SDL_Renderer *renderer,TTF_Font *font){//写的时候就用这个函数就行
//注意在文字出现的过程中不能点击
    SDL_Event event;
    bool clear=true;

    bool quit=true;
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
            word_appear(window, renderer, font, 28, a, 80, 450,60);
            word_appear(window, renderer, font, 28, b, 80, 475,60);
            word_appear(window, renderer, font, 28, c, 80, 500,60);
            show_dialog=false;
        
    
    }
    if(show_dialog==false){
        drawtext(renderer,a,80,450);
        drawtext(renderer,b,80,475);
        drawtext(renderer,c,80,500);
    }
    if (SDL_PollEvent(&event)){
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Point pt1 = {event.button.x, event.button.y};
                    if (SDL_PointInRect(&pt1, &dialogue)) {
                        clear=false;
                         // 点击对话框区域以退出循环
                    }
                }
            }
        }
    if(clear==false){
        SDL_RenderClear(renderer);
    }
    }

}


//以下示例**********


int main(int argc,char *argv[]) {
            
    SDL_Init(SDL_INIT_AUDIO);
    SDL_Window *window = SDL_CreateWindow("Typewriter Effect", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font *font;
    if(TTF_Init()<0){
        SDL_Log("TTF_Init failed:%s",SDL_GetError());
    return -1;
      }

    present(window,renderer,font);

    return 0;
}