#define _CRT_SECURE_NO_WARNINGS

#include "test2.h"
#include "SDL2_test.h"

SDL_Event event;  
SDL_Texture* images[IMAGE_COUNT];  
int currentFrame = 0;  

//int presentstate;

SDL_Rect instruction={411,153,360,73};
SDL_Rect quit={411,305,360,73};
SDL_Rect back={411,457,360,73};

SDL_Rect rect1={235,137,181,43};
SDL_Rect rect2={233,233,184,42};
SDL_Rect rect3={235,308,184,44};
SDL_Rect rect4={236,395,182,44};
SDL_Rect rect5={236,479,182,44};
SDL_Rect rect6={760,135,182,44};
SDL_Rect rectquit={760,480,182,44};

int photo;
  
bool initSDL() {  
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {  
        fprintf(stderr, "Error: SDL_Init() failed: %s\n", SDL_GetError());  
        return false;  
    }  
  
/*    window = SDL_CreateWindow("BMP to Video", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,  
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN); */ 
    if (!window) {  
        fprintf(stderr, "Error: SDL_CreateWindow() failed: %s\n", SDL_GetError());  
        SDL_Quit();  
        return false;  
    }  
  
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);  
    if (!renderer) {  
        fprintf(stderr, "Error: SDL_CreateRenderer() failed: %s\n", SDL_GetError());  
        SDL_DestroyWindow(window);  
        SDL_Quit();  
        return false;  
    }  
  
    return true;  
}  
  
bool loadImages() {  
    char imagePath[150];  
    for (int i = 0; i < IMAGE_COUNT; ++i) {  
        sprintf(imagePath, "photo/Image%d.bmp", i + 1);  
        images[i] = IMG_LoadTexture(renderer, imagePath);  
        if (!images[i]) {  
            fprintf(stderr, "Error: IMG_LoadTexture() failed for %s: %s\n", imagePath, IMG_GetError());  
            return false;  
        }  
    }  
    return true;  
}  

void closeSDL_1() {  
    currentFrame = 0;
    for (int i = 0; i < IMAGE_COUNT; ++i) {  
        SDL_DestroyTexture(images[i]);  
    }  
    //SDL_DestroyRenderer(renderer);  
    //SDL_DestroyWindow(window);  
    //SDL_Quit();  
    //IMG_Quit();  
}  

int show_instruction(SDL_Renderer *renderer,char *next,char *before, char *yes){//输入book1book2和翻页

    SDL_Rect instruction={0,0,1250,650};
    SDL_Rect nextrect={950,560,30,30};
    SDL_Rect beforerect={300,560,30,30};//翻页的
    SDL_Rect yesrect={900,500,50,20};//退出键
    SDL_Rect back={1115,70,30,30};

    SDL_Surface *imageSurfacedirectory = IMG_Load("photo/main.png");//目录
    SDL_Texture *imageTexturedirectory = SDL_CreateTextureFromSurface(renderer, imageSurfacedirectory);

    SDL_Surface *imageSurfaceback = IMG_Load("photo/back.png");//第一张
    SDL_Texture *imageTextureback = SDL_CreateTextureFromSurface(renderer, imageSurfaceback);

    SDL_Surface *imageSurface1 = IMG_Load("photo/timemachine.png");//第一张
    SDL_Texture *imageTexture1 = SDL_CreateTextureFromSurface(renderer, imageSurface1);
    
    SDL_Surface *imageSurfacenext = IMG_Load(next);//翻页的
    SDL_Texture *imageTexturenext = SDL_CreateTextureFromSurface(renderer, imageSurfacenext);

    SDL_Surface *imageSurfacebefore = IMG_Load(before);//翻页的
    SDL_Texture *imageTexturebefore = SDL_CreateTextureFromSurface(renderer, imageSurfacebefore);

    SDL_Surface *imageSurface2 = IMG_Load("photo/boss1-1.png");//第二张
    SDL_Texture *imageTexture2 = SDL_CreateTextureFromSurface(renderer, imageSurface2);

    SDL_Surface *imageSurface2_1 = IMG_Load("photo/boss1-2.png");//第二张
    SDL_Texture *imageTexture2_1 = SDL_CreateTextureFromSurface(renderer, imageSurface2_1);

    SDL_Surface *imageSurface3 = IMG_Load("photo/20seconds.png");//第三张
    SDL_Texture *imageTexture3 = SDL_CreateTextureFromSurface(renderer, imageSurface3);

    SDL_Surface *imageSurface4 = IMG_Load("photo/parkour.png");//第四张
    SDL_Texture *imageTexture4 = SDL_CreateTextureFromSurface(renderer, imageSurface4);

    SDL_Surface *imageSurface5 = IMG_Load("photo/boss2-save.png");//第5张
    SDL_Texture *imageTexture5 = SDL_CreateTextureFromSurface(renderer, imageSurface5);
    
    SDL_Surface *imageSurface5_2 = IMG_Load("photo/boss2-2save.png");//第5张
    SDL_Texture *imageTexture5_2 = SDL_CreateTextureFromSurface(renderer, imageSurface5_2);

    SDL_Surface *imageSurface6 = IMG_Load("photo/bomb.png");//第6张
    SDL_Texture *imageTexture6 = SDL_CreateTextureFromSurface(renderer, imageSurface6);


    SDL_Surface *imageSurfaceexit = IMG_Load(yes);//退出
    SDL_Texture *imageTextureexit = SDL_CreateTextureFromSurface(renderer, imageSurfaceexit);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, imageTexturedirectory, NULL, &instruction);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    bool quit=true;
    while(quit){

        if (SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                return 0;
            }
        
        }
    if (SDL_PollEvent(&event)){//测试所用交互，出现对话
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                /*SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d",
                event.button.x, event.button.y, event.button.button, event.button.clicks); */
                if (event.button.button == SDL_BUTTON_LEFT) {
                    SDL_Point pt1 = {event.button.x, event.button.y};
                    if(SDL_PointInRect(&pt1,&rectquit)){
                        quit=false;
                    }
                    if(SDL_PointInRect(&pt1,&back)){
                        SDL_RenderCopy(renderer, imageTexturedirectory, NULL, &instruction);
                        SDL_RenderPresent(renderer);
                    }
                    
                    if(SDL_PointInRect(&pt1,&rect1)){
                        SDL_RenderCopy(renderer, imageTexture1, NULL, &instruction);
                        SDL_RenderCopy(renderer, imageTextureback, NULL, &back);                      
                        SDL_RenderPresent(renderer);

                    }
                    if(SDL_PointInRect(&pt1,&rect2)){
                        SDL_RenderCopy(renderer, imageTexture2, NULL, &instruction);
                        SDL_RenderCopy(renderer, imageTexturenext, NULL, &nextrect);
                        SDL_RenderCopy(renderer, imageTextureback, NULL, &back);
                        SDL_RenderPresent(renderer);
                        photo=2;
                        
                    }
                    if(photo==2){
                        if(SDL_PointInRect(&pt1,&nextrect)){
                            SDL_RenderCopy(renderer, imageTexture2_1, NULL, &instruction);
                            SDL_RenderCopy(renderer, imageTexturebefore, NULL, &beforerect);
                            SDL_RenderCopy(renderer, imageTextureback, NULL, &back);
                            SDL_RenderPresent(renderer);
                        }
                        if(SDL_PointInRect(&pt1,&beforerect)){
                            SDL_RenderCopy(renderer, imageTexture2, NULL, &instruction);
                            SDL_RenderCopy(renderer, imageTexturenext, NULL, &nextrect);
                            SDL_RenderCopy(renderer, imageTextureback, NULL, &back);
                            SDL_RenderPresent(renderer);
                        }
                    }
                    if(SDL_PointInRect(&pt1,&rect3)){
                        SDL_RenderCopy(renderer, imageTexture3, NULL, &instruction);
                        SDL_RenderCopy(renderer, imageTextureback, NULL, &back);
                       SDL_RenderPresent(renderer);
                    }
                    if(SDL_PointInRect(&pt1,&rect4)){
                        SDL_RenderCopy(renderer, imageTexture4, NULL, &instruction);
                        SDL_RenderCopy(renderer, imageTextureback, NULL, &back);
                        SDL_RenderPresent(renderer);
                    }
                    if(SDL_PointInRect(&pt1,&rect5)){
                        SDL_RenderCopy(renderer, imageTexture5, NULL, &instruction);
                        SDL_RenderCopy(renderer, imageTexturenext, NULL, &nextrect);
                        SDL_RenderCopy(renderer, imageTextureback, NULL, &back);                       
                        SDL_RenderPresent(renderer);
                        photo=5;

                    }
                    if(photo==5){
                        if(SDL_PointInRect(&pt1,&nextrect)){
                            SDL_RenderCopy(renderer, imageTexture5_2, NULL, &instruction);
                            SDL_RenderCopy(renderer, imageTexturebefore, NULL, &beforerect);
                            SDL_RenderCopy(renderer, imageTextureback, NULL, &back);
                            SDL_RenderPresent(renderer);
                        }
                        if(SDL_PointInRect(&pt1,&beforerect)){
                            SDL_RenderCopy(renderer, imageTexture5, NULL, &instruction);
                            SDL_RenderCopy(renderer, imageTexturenext, NULL, &nextrect);
                            SDL_RenderCopy(renderer, imageTextureback, NULL, &back);
                            SDL_RenderPresent(renderer);
                        }
                    }
                    if(SDL_PointInRect(&pt1,&rect6)){
                        SDL_RenderCopy(renderer, imageTexture6, NULL, &instruction);
                        SDL_RenderCopy(renderer, imageTextureback, NULL, &back);
                        SDL_RenderPresent(renderer);
                    }




                }     
            }
        }
    }
    SDL_FreeSurface(imageSurface3);
    SDL_FreeSurface(imageSurface1);
    SDL_FreeSurface(imageSurface2);
    SDL_DestroyTexture(imageTexture3);
    SDL_DestroyTexture(imageTexture1);
    SDL_DestroyTexture(imageTexture2);
    
}
  
int Pause() {  
    if (!initSDL() || !loadImages()) {  
        fprintf(stderr, "Failed to initialize SDL or load images.\n");  
        return 1;  
    }  
  


 

    Uint32 frameStart, frameTime;
    int k=1; 
    bool quit1=true;
    while (quit1) {  
       
  
        frameStart = SDL_GetTicks();  
  
        // 清除屏幕  
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  
        SDL_RenderClear(renderer);  
  
        // 渲染当前帧的图像  
        SDL_RenderCopy(renderer, images[currentFrame], NULL, NULL);  
        SDL_RenderPresent(renderer);  
        while (SDL_PollEvent(&event)) {  
            if (event.type == SDL_QUIT) {  
                goto quit;
            }
            /*if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                goto end;
            }*/
            if(event.type == SDL_MOUSEBUTTONUP){
                    //SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d", 
                    //    event.button.x, event.button.y, event.button.button, event.button.clicks);
                    SDL_Point pt = {event.button.x, event.button.y};
                    if(SDL_PointInRect(&pt,&instruction)){
                        show_instruction(renderer,(char *)"photo/aRRow_4.png", (char*)"photo/aRRow_3.png", (char*)"photo/main.png");
                        //quit1=false;
                    }
                    if(SDL_PointInRect(&pt,&quit)){
                        goto end;
                    }
                    if(SDL_PointInRect(&pt,&back)){
                        goto quit;
                    }



            }

            
        }  
  
        // 更新当前帧  
        if(currentFrame<IMAGE_COUNT&&k==1){
            currentFrame = (currentFrame + 1) % IMAGE_COUNT;
            }
        if(currentFrame>=IMAGE_COUNT-1){currentFrame=100;
        k=2;}
        if(currentFrame<IMAGE_COUNT&&k==2){
            currentFrame = (currentFrame + 1) % IMAGE_COUNT;
        }  
  
        // 控制帧率  
        frameTime = SDL_GetTicks() - frameStart;  
        if (frameTime < 1000 / FRAME_RATE) {  
            SDL_Delay(2000 / FRAME_RATE - frameTime);  
        }  

    }  

    



    
    
quit:
    closeSDL();
    return -1;
  
end:  
    closeSDL();  
    return 0; 
    



    
    


  

}

//bool isPaused = false;//是否暂停
//Uint32 starttime = 0;
//Uint32 endtime = 0;
//SDL_Event event_pause;
//void pauseture() {
//    while (SDL_PollEvent(&event_pause)) {
//        if (event_pause.type == SDL_QUIT)//退出 
//        {
//            //退出
//        }
//        if (event_pause.type == SDL_KEYDOWN)//键盘操作 
//        {
//            if (event_pause.key.keysym.sym == SDLK_ESCAPE) {
//                starttime = SDL_GetTicks();
//                if (starttime - endtime > 100)//侦测两次esc之间时间
//                {
//                    isPaused = !isPaused;
//                    printf("pausing\n");
//                    Pause();
//                    printf("选择你的存档\n");
//                }
//            }
//            if (isPaused == true) {
//                // 在暂停界面时处理按键事件
//                if (event_pause.key.keysym.sym == SDLK_ESCAPE) {
//                    endtime = SDL_GetTicks();
//                    if (endtime - starttime > 100)
//                    {
//                        printf("impausing\n");
//                        isPaused = !isPaused;//退出暂停界面
//                    }
//                }
//            }
//        }
//    }
//}
