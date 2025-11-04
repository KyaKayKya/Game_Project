#include "3.h"
#include "test2.h"
#include "SDL2_test.h"

Component component;

SDL_Texture* backgroundImage = NULL;
SDL_Surface* Game_Over_BackGroundSurface_Puzz3 = NULL;
SDL_Texture* Game_Over_BackGroundTexture_Puzz3 = NULL;

// 定义所有元件
Component switches[5];
Component wires[3];
Component andGates[2];
Component orGates[3];

bool aright = false;
bool bleft = false;
bool bright = false;
bool cright = false;
bool dleft = false;
bool dright = false;
bool eright = false;
bool andawire = false;
bool andcd = false;
bool orab = false;
bool orbwire = false;//or xia mian chu lu
bool orde = false;

bool wireleft_and = false;
bool dwire = false;
bool wirefinish = false;

SDL_Rect aright1 = { 403,230,5,70 };//aright
SDL_Rect bleft1 = { 431,293,50,5 };//bleft
SDL_Rect bright1 = { 544,302,5,54 };//bright
SDL_Rect cright1 = { 580,230,5,52 };//cright
SDL_Rect cright2 = { 607,329,5,20 };//cright
SDL_Rect dright1 = { 664,230,5,48 };//dright
SDL_Rect dleft1 = { 629,302,5,48 };//dleft
SDL_Rect eright1 = { 696,290,45,5 };//eright
SDL_Rect wireleft_and1 = { 438,457,80,5 };//andawire电线前面
SDL_Rect wireleft_and2 = { 591,458,160,5 };//andawire电线后面
SDL_Rect dwire1 = { 567,325,5,22 };//dwire
SDL_Rect orfinishdown1 = { 566,485,190,5 };//orbwire
SDL_Rect orde1 = { 677,364,100,5 };//orde
SDL_Rect andcd1 = { 627,432,100,5 };//andcd

SDL_Rect buttomrect;

SDL_Rect fUll_sCrEEnP3 = { 0,0,1250,650 };

int bACk_tO_lASt_sCeNe_Puzz3 = 0;
int transparency_Gm_Ov_P3 = 0;

//int presentstate;

void iNIt_Puzz3()
{
    int i;
    bACk_tO_lASt_sCeNe_Puzz3 = 0;
    transparency_Gm_Ov_P3 = 0;
    aright = false;
    bleft = false;
    bright = false;
    cright = false;
    dleft = false;
    dright = false;
    eright = false;
    andawire = false;
    andcd = false;
    orab = false;
    orbwire = false;//or xia mian chu lu
    orde = false;

    wireleft_and = false;
    dwire = false;
    wirefinish = false;
    for (i = 0; i < 5; i++)
    {
        switches[i].state = false;
    }
    for (i = 0; i < 3; i++)
    {
        wires[i].state = true;
    }
    for (i = 0; i < 2; i++)
    {
        andGates[i].state = false;
    }
    for (i = 0; i < 3; i++)
    {
        orGates[i].state = false;
    }
}

// 初始化SDL
bool initSDL_1() {
    // 初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // 创建窗口
    /*window = SDL_CreateWindow("Circuit Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);*/
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    // 创建渲染器
    /*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);*/
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}



// 加载背景图片
bool loadBackgroundImage() {
    SDL_Surface* surface = SDL_LoadBMP("bomb.bmp");
    if (surface == NULL) {
        printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    backgroundImage = SDL_CreateTextureFromSurface(renderer, surface);
    if (backgroundImage == NULL) {
        printf("Unable to create texture from image! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    SDL_FreeSurface(surface);
    return true;
}



// 渲染元件
void renderComponent(Component component) {
    // 根据元件类型和状态设置颜色
    switch (component.type) {
    case SWITCH:
        SDL_SetRenderDrawColor(renderer, component.state ? 0x00 : 0xFF, component.state ? 0xFF : 0x00, 0x00, 0xFF);
        break;
    case WIRE:
        SDL_SetRenderDrawColor(renderer, component.state ? 0x00 : 0xFF, component.state ? 0xFF : 0x00, 0x00, 0xFF);
        break;
    case AND_GATE:
        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF); // AND门默认为蓝色
        break;
    case OR_GATE:
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
        break;
    default:
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    SDL_RenderFillRect(renderer, &component.rect);
}



// 检查鼠标点击事件
void checkMouseClick(int mouseX, int mouseY) {
    // 检查是否点击到开关
    for (int i = 0; i < 5; i++) {
        if (mouseX >= switches[i].rect.x && mouseX <= switches[i].rect.x + switches[i].rect.w &&
            mouseY >= switches[i].rect.y && mouseY <= switches[i].rect.y + switches[i].rect.h) {
            // 点击到开关时切换状态
            switches[i].state = !switches[i].state;
            if (i == 0 && switches[i].state == true) {
                aright = true;

            }
            if (i == 0 && switches[i].state == false) {
                aright = false;

            }


            if (i == 1 && switches[i].state == true) {
                bright = true;
                bleft = true;

            }
            if (i == 1 && switches[i].state == false) {
                bright = false;
                bleft = false;

            }
            if (i == 2 && switches[i].state == true) {
                cright = true;

            }
            if (i == 2 && switches[i].state == false) {
                cright = false;

            }
            if (i == 3 && switches[i].state == true) {
                dright = true;
                dleft = true;

            }
            if (i == 3 && switches[i].state == false) {
                dright = false;
                dleft = false;

            }
            if (i == 4 && switches[i].state == true) {
                eright = true;

            }
            if (i == 4 && switches[i].state == false) {
                eright = false;

            }

        }
    }

    // 检查是否点击到电线
    for (int i = 0; i < 3; i++) {
        if (mouseX >= wires[i].rect.x && mouseX <= wires[i].rect.x + wires[i].rect.w &&
            mouseY >= wires[i].rect.y && mouseY <= wires[i].rect.y + wires[i].rect.h) {
            // 点击到电线时断开电线
            wires[i].state = false;
        }
    }
}

void renderphoto() {
    // 清空渲染器
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundImage, NULL, NULL);
    SDL_Event e;
    int randomx, randomy;
    // 处理事件
   /*if(SDL_PollEvent(&e) != 0) {

        if (e.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX, mouseY;
            SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d",
                    e.button.x, e.button.y, e.button.button, e.button.clicks);
            SDL_GetMouseState(&mouseX, &mouseY);
            checkMouseClick(mouseX, mouseY);
            SDL_Point pt = {e.button.x, e.button.y};

            int time=0;

            if(SDL_PointInRect(&pt,&buttomrect)&&time==1){
                SDL_RenderClear(renderer);
                while(randomx<8||randomx>197){
                    randomx=rand()%200;
                }
                while(randomy<20||randomx>624){
                    randomy=rand()%624;
                }

                SDL_Rect buttomrect={randomx,randomy,50,50};
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
                SDL_RenderFillRect(renderer,&buttomrect);
            }
             if(time==0){
                    randomx=50;
                    randomy=50;
                    SDL_Rect buttomrect={randomx,randomy,100,100};
                    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
                    SDL_RenderFillRect(renderer,&buttomrect);
                    time=1;
                }
        }
    }*/



    // 绘制元件
    for (int i = 0; i < 5; i++) {
        renderComponent(switches[i]); // 绘制开关
    }


    for (int i = 0; i < 3; i++) {
        renderComponent(wires[i]); // 绘制开关
    }// 绘制开关

    for (int i = 0; i < 2; i++) {
        renderComponent(andGates[i]); // 绘制AND门
    }

    for (int i = 0; i < 3; i++) {
        renderComponent(orGates[i]); // 绘制OR门
    }




    // 更新屏幕
    SDL_RenderPresent(renderer);
}
void renderwire() {
    if (aright == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &aright1);
        SDL_RenderPresent(renderer);
    }
    if (bleft == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &bleft1);
        SDL_RenderPresent(renderer);
    }
    if (bright == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &bright1);
        SDL_RenderPresent(renderer);

    }
    if (cright == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &cright1);
        SDL_RenderFillRect(renderer, &cright2);
        SDL_RenderPresent(renderer);

    }
    if (dright == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &dright1);
        SDL_RenderPresent(renderer);

    }
    if (dleft == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &dleft1);
        SDL_RenderPresent(renderer);

    }
    if (eright == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &eright1);
        SDL_RenderPresent(renderer);

    }
    if (andawire == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &wireleft_and1);
        SDL_RenderPresent(renderer);

    }
    if (andawire == true && wirefinish == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &wireleft_and2);
        SDL_RenderPresent(renderer);

    }
    if (dwire == true && dleft == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &dwire1);
        SDL_RenderPresent(renderer);

    }
    if (orbwire == true && bright == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &orfinishdown1);
        SDL_RenderPresent(renderer);

    }
    if (andawire == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &wireleft_and1);
        SDL_RenderPresent(renderer);

    }
    if (andawire == true && wires[1].state == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &wireleft_and2);
        SDL_RenderPresent(renderer);

    }
    if (orde == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &orde1);
        SDL_RenderPresent(renderer);

    }
    if (andcd == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &andcd1);
        SDL_RenderPresent(renderer);

    }
    if (bright == false && dwire == true && dleft == true) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &orfinishdown1);
        SDL_RenderPresent(renderer);
    }
}

//// 在游戏循环中绘制电路图形
//int gameLoop() {
//    bool running = true;
//
//    // 加载背景图片
//    if (!loadBackgroundImage()) {
//        return;
//    }
//    int randomx, randomy;
//
//
//    // 游戏主循环
//    while (running) {
//        SDL_Event e;
//
//        // 处理事件
//        while (SDL_PollEvent(&e) != 0) {
//            if (e.type == SDL_QUIT) {
//                running = false;
//            }
//
//            else if (e.key.keysym.sym == SDLK_ESCAPE)
//            {
//                Pause();
//            }
//
//            else if (e.type == SDL_MOUSEBUTTONDOWN) {
//                int mouseX, mouseY;
//                SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d",
//                    e.button.x, e.button.y, e.button.button, e.button.clicks);
//                SDL_GetMouseState(&mouseX, &mouseY);
//                checkMouseClick(mouseX, mouseY);
//                SDL_Point pt = { e.button.x, e.button.y };
//
//
//
//
//                //orab
//                if (aright == true && bleft == false) {
//                    orab = true;
//                }
//                if (aright == false && bleft == true) {
//                    orab = true;
//                }
//                if (aright == true && bleft == true) {
//                    orab = false;
//                }
//                if (aright == false && bleft == false) {
//                    orab = false;
//                }
//                //wireleft
//                if (wires[2].state == true) {
//                    wireleft_and = true;
//                }
//                if (wires[2].state == false) {
//                    wireleft_and = false;
//                }
//                //andawire
//                if (wireleft_and == true && orab == true) {
//                    andawire = true;
//                }
//                else {
//                    andawire = false;
//                }
//
//                if (wires[0].state == true && switches[3].state == true) {
//                    dwire = true;
//                }
//                if (wires[0].state == false) {
//                    dwire = false;
//                }
//                //orbwire
//                if (bright == true && dwire == false || bright == false && dwire == true && dright == true) {
//                    orbwire = true;
//                }
//                else {
//                    orbwire = false;
//                }
//                //orde
//                if (dright == true && eright == false || dright == false && eright == true) {
//                    orde = true;
//                }
//                else {
//                    orde = false;
//                }
//                //andcd
//                if (cright == true && dleft == true) {
//                    andcd = true;
//                }
//                else {
//                    andcd = false;
//                }
//                //wirefinish
//                if (wires[1].state == true) {
//                    wirefinish == true;
//                }
//                if (wires[1].state == false) {
//                    wirefinish == false;
//                }
//
//                if (orbwire == true) {
//                    SDL_Delay(400);
//                    printf("lose");
//                    return 3;
//                    running = false;
//                    
//                }
//
//
//
//                if (wires[1].state == true && andawire == true && orde == true && andcd == true && orbwire == false) {
//                    printf("win");
//                    return 1;
//                    running = false;
//                    
//                }
//            }
//        }
//        renderwire();
//        renderphoto();
//
//    }
//}

int Puzzle3() {
    // 初始化SDL
    initSDL();
    Game_Over_BackGroundSurface_Puzz3 = IMG_Load("assets/Ingame/GameOver.png"); // GW
    Game_Over_BackGroundTexture_Puzz3 = SDL_CreateTextureFromSurface(renderer, Game_Over_BackGroundSurface_Puzz3);
    // 初始化所有元件的位置和状态
    // 开关
    switches[0].x = 360;
    switches[0].y = 212;
    switches[0].type = SWITCH;
    switches[0].state = false;
    switches[0].rect = { switches[0].x, switches[0].y, 20, 40 };



    switches[1].x = 444;
    switches[1].y = 212;
    switches[1].type = SWITCH;
    switches[1].state = false;
    switches[1].rect = { switches[1].x, switches[1].y, 20, 40 };

    switches[2].x = 535;
    switches[2].y = 212;
    switches[2].type = SWITCH;
    switches[2].state = false;
    switches[2].rect = { switches[2].x, switches[2].y, 20, 40 };

    switches[3].x = 620;
    switches[3].y = 212;
    switches[3].type = SWITCH;
    switches[3].state = false;
    switches[3].rect = { switches[3].x, switches[3].y, 20, 40 };

    switches[4].x = 708;
    switches[4].y = 212;
    switches[4].type = SWITCH;
    switches[4].state = false;
    switches[4].rect = { switches[4].x, switches[4].y, 20, 40 };

    // 电线
    wires[0].x = 583;
    wires[0].y = 315;
    wires[0].type = WIRE;
    wires[0].state = true;
    wires[0].rect = { wires[0].x, wires[0].y, 45, 10 };

    wires[1].x = 529;
    wires[1].y = 453;
    wires[1].type = WIRE;
    wires[1].state = true;
    wires[1].rect = { wires[1].x, wires[1].y, 45, 10 };

    wires[2].x = 413;
    wires[2].y = 146;
    wires[2].type = WIRE;
    wires[2].state = true;
    wires[2].rect = { wires[2].x, wires[2].y, 65,30 };

    // AND门
    andGates[0].x = 410;
    andGates[0].y = 390;
    andGates[0].type = AND_GATE;
    andGates[0].state = false;
    andGates[0].rect = { andGates[0].x, andGates[0].y, 33, 30 };

    andGates[1].x = 600;
    andGates[1].y = 375;
    andGates[1].type = AND_GATE;
    andGates[1].state = false;
    andGates[1].rect = { andGates[1].x, andGates[1].y, 33, 30 };

    // OR门
    orGates[0].x = 398;
    orGates[0].y = 324;
    orGates[0].type = OR_GATE;
    orGates[0].state = false;
    orGates[0].rect = { orGates[0].x, orGates[0].y, 34, 14 };

    orGates[1].x = 535;
    orGates[1].y = 379;
    orGates[1].type = OR_GATE;
    orGates[1].state = false;
    orGates[1].rect = { orGates[1].x, orGates[1].y, 33, 14 };

    orGates[2].x = 659;
    orGates[2].y = 324;
    orGates[2].type = OR_GATE;
    orGates[2].state = false;
    orGates[2].rect = { orGates[2].x, orGates[2].y, 35, 14 };

    bool running = true;

    // 加载背景图片
    loadBackgroundImage();
    int randomx, randomy;

    // 运行游戏循环
    // 游戏主循环
    while (running) {
        SDL_Event e;

        // 处理事件
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }

            else if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                Pause();
            }

            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_Log("SDL_MOUSEBUTTONDOWN x = %d, y = %d, button = %d, clicks = %d",
                    e.button.x, e.button.y, e.button.button, e.button.clicks);
                SDL_GetMouseState(&mouseX, &mouseY);
                checkMouseClick(mouseX, mouseY);
                SDL_Point pt = { e.button.x, e.button.y };




                //orab
                if (aright == true && bleft == false) {
                    orab = true;
                }
                if (aright == false && bleft == true) {
                    orab = true;
                }
                if (aright == true && bleft == true) {
                    orab = false;
                }
                if (aright == false && bleft == false) {
                    orab = false;
                }
                //wireleft
                if (wires[2].state == true) {
                    wireleft_and = true;
                }
                if (wires[2].state == false) {
                    wireleft_and = false;
                }
                //andawire
                if (wireleft_and == true && orab == true) {
                    andawire = true;
                }
                else {
                    andawire = false;
                }

                if (wires[0].state == true && switches[3].state == true) {
                    dwire = true;
                }
                if (wires[0].state == false) {
                    dwire = false;
                }
                //orbwire
                if (bright == true && dwire == false || bright == false && dwire == true && dright == true) {
                    orbwire = true;
                }
                else {
                    orbwire = false;
                }
                //orde
                if (dright == true && eright == false || dright == false && eright == true) {
                    orde = true;
                }
                else {
                    orde = false;
                }
                //andcd
                if (cright == true && dleft == true) {
                    andcd = true;
                }
                else {
                    andcd = false;
                }
                //wirefinish
                if (wires[1].state == true) {
                    wirefinish == true;
                }
                if (wires[1].state == false) {
                    wirefinish == false;
                }

                if (orbwire == true) {
                    SDL_Delay(400);
                    printf("lose");

                    while (!bACk_tO_lASt_sCeNe_Puzz3)
                    {
                        if (transparency_Gm_Ov_P3 < 223)
                            transparency_Gm_Ov_P3++;
                        SDL_SetTextureAlphaMod(Game_Over_BackGroundTexture_Puzz3, transparency_Gm_Ov_P3);
                        SDL_RenderCopy(renderer, Game_Over_BackGroundTexture_Puzz3, NULL, &fUll_sCrEEnP3);
                        SDL_RenderPresent(renderer);
                        while (SDL_PollEvent(&e))
                        {
                            if (e.type == SDL_QUIT)
                            {
                                iNIt_Puzz3();
                                SDL_DestroyTexture(backgroundImage);
                                SDL_DestroyTexture(Game_Over_BackGroundTexture_Puzz3);
                                SDL_FreeSurface(Game_Over_BackGroundSurface_Puzz3);
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 设置背景色
                                SDL_RenderClear(renderer);
                                return 0;
                            }
                            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
                                bACk_tO_lASt_sCeNe_Puzz3 = 1;
                        }
                    }

                    iNIt_Puzz3();
                    SDL_DestroyTexture(Game_Over_BackGroundTexture_Puzz3);
                    SDL_FreeSurface(Game_Over_BackGroundSurface_Puzz3);
                    SDL_DestroyTexture(backgroundImage);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 设置背景色
                    SDL_RenderClear(renderer);
                    return 3;
                    //running = false;

                }



                if (wires[1].state == true && andawire == true && orde == true && andcd == true && orbwire == false) {
                    printf("win");
                    iNIt_Puzz3();
                    SDL_DestroyTexture(Game_Over_BackGroundTexture_Puzz3);
                    SDL_FreeSurface(Game_Over_BackGroundSurface_Puzz3);
                    SDL_DestroyTexture(backgroundImage);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 设置背景色
                    SDL_RenderClear(renderer);
                    return 1;
                    //running = false;

                }
            }
        }
        renderwire();
        renderphoto();

    }

    // 清理资源
    iNIt_Puzz3();
    SDL_DestroyTexture(backgroundImage);
    SDL_DestroyTexture(Game_Over_BackGroundTexture_Puzz3);
    SDL_FreeSurface(Game_Over_BackGroundSurface_Puzz3);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // 设置背景色
    SDL_RenderClear(renderer);
    return 0;
}