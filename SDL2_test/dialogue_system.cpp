#include "SDL2_test.h"
#include "pause_menu.h"

//test�?以删�?
//SDL_Rect fridge = { 100,124,120,160 };
//SDL_Rect wash = { 400,215,150,60 };
//SDL_Rect kitchen = { 628,234,60,40 };

Uint8* audio_buf;
Uint32 audio_len;
Uint32 audio_pos = 0;
SDL_AudioDeviceID device_id;//以上四个音量�?�?

SDL_Rect dialogue = { 150,400,1100,180 };//
SDL_Rect character = { 20,440,120,120 };
bool show_dialog = true;

int dialoguetime = 0;//记录到�??几�??
int clicktime = 0;



int show_instruction(SDL_Renderer* renderer, char* book1, char* book2, char* next, char* before, char* yes) {//输入book1book2和翻�?
int quit = 0;
    while (quit == 0) {
        SDL_Rect instruction = { 250,100,750,500 };
        SDL_Rect nextrect = { 950,560,30,20 };
        SDL_Rect beforerect = { 300,560,30,20 };//翻页�?
        SDL_Rect yesrect = { 900,500,50,20 };//�?
        SDL_Surface* imageSurface = IMG_Load(book1);//�?�?�?
        SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        SDL_FreeSurface(imageSurface);
        SDL_RenderCopy(renderer, imageTexture, NULL, &instruction);

        SDL_Surface* imageSurface1 = IMG_Load(next);//翻页�?
        SDL_Texture* imageTexture1 = SDL_CreateTextureFromSurface(renderer, imageSurface1);
        SDL_FreeSurface(imageSurface1);
        SDL_RenderCopy(renderer, imageTexture1, NULL, &nextrect);

        SDL_Surface* imageSurface3 = IMG_Load(before);//翻页�?
        SDL_Texture* imageTexture3 = SDL_CreateTextureFromSurface(renderer, imageSurface3);
        SDL_FreeSurface(imageSurface3);
        SDL_RenderCopy(renderer, imageTexture3, NULL, &beforerect);

        SDL_Surface* imageSurface2 = IMG_Load(book2);//�?二�??
        SDL_Texture* imageTexture2 = SDL_CreateTextureFromSurface(renderer, imageSurface2);
        SDL_FreeSurface(imageSurface2);

        SDL_Surface* imageSurface4 = IMG_Load(yes);//�?二�??
        SDL_Texture* imageTexture4 = SDL_CreateTextureFromSurface(renderer, imageSurface4);
        SDL_FreeSurface(imageSurface4);

        SDL_RenderPresent(renderer);
        SDL_Event event;
        while (1) {

            if (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                    return 0;
                }

            }
            if (SDL_PollEvent(&event)) {//测试�?
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d",
                        event.button.x, event.button.y, event.button.button, event.button.clicks);
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        SDL_Point pt1 = { event.button.x, event.button.y };
                        if (book2 != NULL) {
                            if (SDL_PointInRect(&pt1, &nextrect)) {
                                SDL_RenderCopy(renderer, imageTexture2, NULL, &instruction);
                                SDL_RenderCopy(renderer, imageTexture3, NULL, &beforerect);
                                SDL_RenderCopy(renderer, imageTexture1, NULL, &nextrect);
                                SDL_RenderCopy(renderer, imageTexture4, NULL, &yesrect);
                                SDL_RenderPresent(renderer);
                            }
                            if (SDL_PointInRect(&pt1, &beforerect)) {
                                SDL_RenderCopy(renderer, imageTexture, NULL, &instruction);
                                SDL_RenderCopy(renderer, imageTexture3, NULL, &beforerect);
                                SDL_RenderCopy(renderer, imageTexture1, NULL, &nextrect);
                                SDL_RenderPresent(renderer);
                            }
                            if (SDL_PointInRect(&pt1, &yesrect)) {
                                quit = 1;
                            }
                        }
                    }
                }
            }
        }
        SDL_DestroyTexture(imageTexture);
        SDL_DestroyTexture(imageTexture1);
        SDL_DestroyTexture(imageTexture2);
        SDL_DestroyTexture(imageTexture3);
        SDL_DestroyTexture(imageTexture4);
    }

}



int drawtext(SDL_Renderer* renderer, char* a, int x, int y) {//基本的显示文�?

    TTF_Font* font = TTF_OpenFont("1.ttf", 28);
    if (!font)
    {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return -1;
    }
    SDL_Color color = { 0,0,0 };
    SDL_Surface* text1_surface = TTF_RenderUTF8_Blended(font, a, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, text1_surface);
    SDL_FreeSurface(text1_surface);

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

int drawtext1(SDL_Renderer* renderer, char* a, int x, int y) {//基本的显示文�?

    TTF_Font* font = TTF_OpenFont("1.ttf", 32);
    if (!font)
    {
        SDL_Log("TTF_OpenFont failed: %s", TTF_GetError());
        return -1;
    }
    SDL_Color color = { 0,0,0 };
    SDL_Surface* text1_surface = TTF_RenderUTF8_Blended(font, a, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, text1_surface);
    SDL_FreeSurface(text1_surface);

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


void renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if (surface == NULL) {
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        SDL_FreeSurface(surface);
        return;
    }

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

    SDL_Rect dstRect = { x, y, texW, texH };
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

}







int word_appear(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, int wdsize, const char* text, int x, int y, int speed, char* a, char* b, char* name)

//wdsize:字体大小；text：a/b/c；x就输80，y：�?�字符串a：y=450，b：y=475；c：y=500,；speed越小速度越快，其实speed

{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    font = TTF_OpenFont("1.ttf", wdsize);
    if (font == NULL) {
        // 处理字体加载失败的情�?
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return -1;
    }
    SDL_Color color = { 0, 0, 0 };
    SDL_Event event;
    int i = 0;
    int textLength = strlen(text);
    while (i <= textLength && show_dialog == true) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                presentstate = 0;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    int p = Pause();
                    if (p == -1) presentstate = 0;
                }
                if (event.key.keysym.sym == SDLK_SPACE) {
                    show_dialog = false;
                    clicktime = 1;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Point pt1 = { event.button.x, event.button.y };
                    if (SDL_PointInRect(&pt1, &dialogue)) {
                        show_dialog = false;
                        clicktime = 1;
                    }
                }
                break;
            }
        }

        drawtext1(renderer, name, 290, 420);
        if (dialoguetime == 1) {
            //drawtext(renderer,a,80,450);
            drawtext(renderer, b, 290, 460);
        }
        /*if(dialoguetime==2){
            drawtext(renderer,a,80,450);
            drawtext(renderer,b,80,475);
        }*/
        char currentText[200];
        strncpy_s(currentText, text, i);
        currentText[i] = '\0';

        renderText(renderer, font, currentText, x, y, color);

        SDL_RenderPresent(renderer);

        // 控制文字出现的�?
        SDL_Delay(speed);
        if (i <= textLength) {
            i++;
        }
    }
    dialoguetime++;
}


void callback(void* userdata, Uint8* stream, int len)
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

void init_audio() {
    SDL_AudioSpec audio_spec;


    // 1. 导入WAV
    SDL_LoadWAV("speak.wav", &audio_spec, &audio_buf, &audio_len);

    // 2. 定义�?放回调函�?
    audio_spec.userdata = (void*)"这是外部传进来的数据";
    audio_spec.callback = callback;

    // 3. 打开音�?��?��??
    device_id = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);
    if (device_id == 0) {
        printf("Failed to open audio: %s\n", SDL_GetError());
    }
    else {
        printf("Audio device opened successfully!\n");
    }
    // 4. �?始播�?
    SDL_PauseAudioDevice(device_id, 0);
    printf("1");
}


void initphoto(SDL_Window* window, SDL_Renderer* renderer){ //�?以删去，test�?�?

    /*SDL_RenderClear(renderer);
    SDL_Surface *imageSurface1 = IMG_Load("bg_kitchen_0.png");
    SDL_Texture *imageTexture1 = SDL_CreateTextureFromSurface(renderer, imageSurface1);
    SDL_FreeSurface(imageSurface1);
    SDL_RenderCopy(renderer, imageTexture1, NULL, NULL);
    SDL_RenderPresent(renderer);*/

}
void initcharacter(SDL_Window* window, SDL_Renderer* renderer, char* picture) {
    SDL_Surface* imageSurface1 = IMG_Load(picture);
    SDL_Texture* imageTexture1 = SDL_CreateTextureFromSurface(renderer, imageSurface1);
    SDL_FreeSurface(imageSurface1);
    SDL_RenderCopy(renderer, imageTexture1, NULL, &character);
    SDL_Surface* imageSurface = IMG_Load("dialog.png");
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    SDL_RenderCopy(renderer, imageTexture, NULL, &dialogue);
    SDL_RenderPresent(renderer);
}




int present(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, char* a, char* b, char* name, char* picture) {//a，b，c，是三句话，分别�?�?
    //写的时�?�就用这�?函数就�?�，用法应�?�写在最下面了，要是没了就自己琢磨吧�?
    if(presentstate == 1)
    {
        SDL_Event event;
        clicktime = 0;
        bool clear = true;
        bool quit = true;
        show_dialog = true;
        while (quit && presentstate ==1) {

            

            while (show_dialog && presentstate == 1) {
                if (SDL_PollEvent(&event)) {
                    switch (event.type) {
                    case SDL_QUIT:
                        presentstate = 0;
                    }
                }
                init_audio();
                SDL_Delay(100);
                initcharacter(window, renderer, picture);

                word_appear(window, renderer, font, 28, a, 290, 460, 60, a, b, name);
                word_appear(window, renderer, font, 28, b, 290, 485, 60, a, b, name);
                //word_appear(window, renderer, font, 28, c, 80, 500,60,a,b,c);
                clicktime = 1;
                show_dialog = false;


            }
            if (show_dialog == false && clicktime == 1) {
                SDL_PauseAudioDevice(device_id, 1);
                SDL_CloseAudioDevice(device_id);
                drawtext(renderer, a, 290, 460);
                drawtext(renderer, b, 290, 485);
            }
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                    presentstate = 0;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        int p = Pause();
                        if (p == -1) presentstate = 0;
                    }
                    if (event.key.keysym.sym == SDLK_SPACE) {
                        initphoto(window, renderer);
                        clicktime = 2;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        SDL_Point pt1 = { event.button.x, event.button.y };
                        if (SDL_PointInRect(&pt1, &dialogue)) {
                            initphoto(window, renderer);
                            clicktime = 2;
                        }
                    }
                    break;
                }
            }
            if (clicktime == 2) {
                quit = false;
            }
        }
        return 1;
    }
    if (presentstate == 0)
    {
        return 0;
    }
    if (presentstate == 2)
    {
        return 2;
    }

}




//以下示例**********


//int main(int argc, char* argv[]) {
//
//    SDL_Init(SDL_INIT_AUDIO);
//    SDL_Window* window = SDL_CreateWindow("Typewriter Effect", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1250, 650, 0);
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    TTF_Font* font;
//    if (TTF_Init() < 0) {
//  
// SDL_Log("TTF_Init failed:%s", SDL_GetError());
//  
// return -1;
//    }
//    char a[100] = { "i am ljy ,this is a fridge" };
//    char d[100] = { "i am dc ,this is not a fridge ,genius,damn" };
//    char e[100] = { "i am wcy , this is a firdge" };
//    char f[100] = { "i am wzm ,i agree with dc" };
//    //�?行最�?0�?字�?
//    char b[100] = { "" };
//    char c[100] = { "dragon" };
//    initphoto(window, renderer);
//    SDL_Event event;
//    while (1) {
//
//  
// if (SDL_PollEvent(&event)) {
//  
// switch (event.type) {
//  
// case SDL_QUIT:
//  
// return 0;
//  
// }
//
//  
// }
//  
// present(window, renderer, font, a, b, c, "ljy.png");//�?有这里用�?
//  
// present(window, renderer, font, d, b, c, "dc.png");//�?有这里用�?
//  
// present(window, renderer, font, e, b, c, "wcy.png");//�?有这里用�?
//  
//show_instruction(renderer,"ljy.png","wcy.png","wzm.png","dc.png","dialog.png");
//  
// present(window, renderer, font, f, b, c, "wzm.png");//�?有这里用�?
//
//
//    }
//
//    return 0;
//}
//用法：先写三�?字�?�串组abc，再写一�?人物图片，然后在事件侦测里�?�察交互（应该和碰撞箱结合，但我没玩明白那个函数），然后利用present函数，简单明了没啥可关注的（看不懂就不是我的�?�?