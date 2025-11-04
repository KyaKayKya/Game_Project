#include "test2.h"
#include "SDL2_test.h"
#include "BOSS.h"

#define FR 50 // 帧率Frame Rate
#define FT 1000 / FR
// extern SDL_Window* Puzzle1_Window;
// extern SDL_Renderer* Puzzle1_Renderer;
// SDL_Window* win = Puzzle1_Window;
// SDL_Renderer* rdr1 = Puzzle1_Renderer;
/*#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#undef main

#define W 1250
#define H 650

#define win Puzzle1_Window
#define rdr1 Puzzle1_Renderer*/
// SDL_Window* win = NULL;
// SDL_Renderer* rdr1 = NULL;
int quit = 0, moveUp = 0, moveDown = 0, moveLeft = 0, moveRight = 0;
int fight = 1;
int i = 0;
int ct = 1;
int image_index = 1;
int atk_Scd = 0;
int Get_hUrt = 0;
int Py_Hp = 100;
int Bs_Hp = 100;
int atk_Dly = 30;
int atk_Num = 0;
int atk_Round = 0;
int atk_Mod = 1;
int Star_Position = 0;
int Get_Star = 0;
int Num_of_Stars = 0;
int Frog_shouldStop = 0;
int count_of_Frog = 0;
int iS_tHere_froG_OR_NOT = 0;
int Stop_frOG = 0;
int Delay_Aft_Destroy_F = 0;
int ct_fOr_wAll = 0;
int coUNt_oF_hEAl = 0;
SDL_Surface* surfboss[4] = { 0 };
SDL_Texture* txtboss[4] = { 0 };
SDL_Surface* surfwall = NULL;
SDL_Texture* txtwall = NULL;
SDL_Surface* surffloor = NULL;
SDL_Texture* txtfloor = NULL;
SDL_Surface* surftt = NULL;
SDL_Texture* txttt = NULL;
SDL_Surface* surffly[3] = { 0 };
SDL_Texture* txtfly[3] = { 0 };
SDL_Surface* surfhp = NULL;
SDL_Texture* txthp = NULL;
SDL_Surface* surfpyr[2] = { 0 };
SDL_Texture* txtpyr[2] = { 0 };
SDL_Surface* surfstar = NULL;
SDL_Texture* txtstar = NULL;
SDL_Surface* surfid[4] = { 0 };
SDL_Texture* txtid[4] = { 0 };
SDL_Surface* surffg[3] = { 0 };
SDL_Texture* txtfg[3] = { 0 };
SDL_Surface* surf_background = NULL;
SDL_Texture* txt_background = NULL;
SDL_Surface* surf_hEAlEr[4] = { 0 };
SDL_Texture* txt_hEAlEr[4] = { 0 };
SDL_Surface* Shifter_BackGroundSurface_bOSs1 = NULL;
SDL_Texture* Shifter_BackGroundTexture_bOSs1 = NULL;
SDL_Surface* surf_Dialogue_pic_1[6] = { 0 };
SDL_Texture* txt_Dialogue_pic_1[6] = { 0 };
SDL_Surface* Game_Over_BackGroundSurface_bOSs1 = NULL;
SDL_Texture* Game_Over_BackGroundTexture_bOSs1 = NULL;
SDL_Rect Player = { 500, 275, 10, 10 };  // 玩家
SDL_Rect Bottum1 = { 600, 300, 50, 50 }; // 进入战斗
SDL_Rect BoSs = { 436, 0, 378, 240 };
SDL_Rect wall_L = { 200, -650, 100, 650 };
SDL_Rect wall_R = { 950, -650, 100, 650 };
SDL_Rect Floor = { 300, 250, 650, 380 };
SDL_Rect TestTExt = { 432, 500, 386, 92 };
SDL_Rect Fly1 = { 365, 265, 20, 20 };
SDL_Rect Fly2 = { 615, 265, 20, 20 };
SDL_Rect Fly3 = { 915, 265, 20, 20 };
SDL_Rect Fly4 = { 365, 50, 20, 20 };
SDL_Rect Fly5 = { 615, 50, 20, 20 };
SDL_Rect Fly6 = { 915, 50, 20, 20 };
SDL_Rect Health_Bar_Remain_BOSS = { 325, 240, 600, 10 };
SDL_Rect Health_Bar_Loss_BOSS = { 325, 240, 0, 10 };
SDL_Rect Health_Bar_Remain = { 300, 630, 650, 20 };
SDL_Rect Health_Bar_Loss = { 300, 630, 0, 20 };
SDL_Rect Health_Bar = { 300, 630, 650, 20 };
SDL_Rect ID_CaRd = { 100, 110, 80, 80 };
SDL_Rect rECt_hEAlEr = { 100, 220, 80, 80 };
SDL_Rect FroG01 = { 250, 315, 50, 50 };
SDL_Rect FroG02 = { 250, 560, 50, 50 };
SDL_Rect FroG03 = { 950, 450, 50, 50 };
SDL_Rect Stars[9] = { {330, 260, 30, 30}, {610, 260, 30, 30}, {890, 260, 30, 30}, {330, 425, 30, 30}, {610, 425, 30, 30}, {890, 425, 30, 30}, {330, 595, 30, 30}, {610, 595, 30, 30}, {890, 595, 30, 30} };
SDL_Rect rects_of_Laser[3];
SDL_Rect fUll_sCrEEn = { 0, 0, 1250, 650 };
SDL_Rect rECt_dialogue_pic_1 = { 289, 40, 672, 350 };
Mix_Music* BOSS_BGM = NULL;
TTF_Font* font_bOSs1 = NULL;
char file_fOr_bOSs[50] = { 0 };
char IDCardfile[50] = { 0 };
int F_mOve_X[6] = { 0 }, F_mOve_Y[6] = { 0 };
int V_of_Fg[3] = { 4, 5, 6 };
int dAmaGe_F[6] = { 0 };

int bACk_tO_lASt_sCeNe_bOSs1 = 0;
int transparency_Gm_Ov_1 = 0;

int bOSs1_iS_dialogue_1 = 0;//first enter
int bOSs1_iS_dialogue_2 = 0;//3rd round

//int presentstate;

char Blank_bOSs1[100] = { 0 };
char bOSs1_Ellie[10] = { "Ellie" };
char bOSs1_DC[10] = { "DC" };
char bOSs1_Prince[10] = { "Prince" };
char bOSs1_Emma[10] = { "Emma" };
char bOSs1_Wyvern[10] = { "Wyvern" };
char dia1_1[100] = { "What is that...? It seems that he can use mechanical creatures!" };
char dia1_2[100] = { "He will use mechanical flies to attack! Flies appear in three colors: red, green, and blue." };
char dia1_3[100] = { "Pay attention to their attack patterns and avoid being touched!" };
char dia1_4[100] = { "Those flies are too small and too flexible! We cannot directly destroy them." };
char dia1_5[100] = { "With those flies around, we also find it difficult to get close to Wyvern." };
char dia1_6[100] = { "Let's dodge the attack first, we will find a way to counterattack!" };
char dia1_7[100] = { "Use \"W\", \"A\", \"S\", \"D\" to move around! His attacks will come wave after wave!" };
char dia1_8[100] = { "After a wave of attacks ends, press the SPACEBAR to enter the next round!" };
char dia1_9[100] = { "If you got hurt, I will heal you! But it takes time." };
char dia1_10[100] = { "I can only heal you again after three rounds of the last treatment!" };
char dia1_11[100] = { "Anyway, this is a big favor! Let us defeat him!" };
char dia2_1[100] = { "Prince, do you still have the ID card I instructed you to keep? Take it out, it has its place now!" };
char dia2_2[100] = { "Wait... Alright it\'s here. How to use it???" };
char dia2_3[100] = { "We just discovered scattered energy around the field, refreshing in the form of stars nearby." };
char dia2_3_2[100] = { "Picking up them can recharge ID cards." };
char dia2_4[100] = { "After picking up three stars, pressing \"E\" between turns can unleash the hidden ability" };
char dia2_4_2[100] = { "of ID cards!" };
char dia2_5[100] = { "Hidden ability??? What is that?" };
char dia2_6[100] = { "Abandoned mechanical frogs are hidden in the walls on both sides." };
char dia2_7[100] = { "I don\'t know why, but ID cards seem to be able to remotely control them!" };
char dia2_8[100] = { "Three frogs will emit lasers of red, green, and blue colors every once in a while." };
char dia2_9[100] = { "If the corresponding colored fly touches the laser, it will be destroyed!" };
char dia2_10[100] = { "Those frogs... they did not pass the laboratory uniform set of safety tests!" };
char dia2_11[100] = { "Be careful, those lasers will hurt you too!" }; 
char dia2_12[100] = { "Plus, once the frog is summoned, Wyvern will lose the ability to actively retrieve the flies!" };
char dia2_13[100] = { "Take care to dodge the attack in the chaotic scene and guide the fly into the laser!" };
char dia2_14[100] = { "The flies he holds are limited! Destroy all the flies, he will lose his ability to fight." };
char dia2_15[100] = { "The total number of flies is displayed in the form of a health bar!" };
char dia2_16[100] = { "Ha... Things are getting worse, isn't it? Come and show me what you\'ve got!" };

void iNIt_bOSs1()
{
    bACk_tO_lASt_sCeNe_bOSs1 = 0;
    transparency_Gm_Ov_1 = 0;
    Py_Hp = 100;
    Bs_Hp = 100;
    Mix_PauseMusic();
    Fly1.x = 365;
    Fly1.y = 265;
    Fly2.x = 615;
    Fly2.y = 265;
    Fly3.x = 915;
    Fly3.y = 265;
    Fly4.x = 365;
    Fly4.y = 50;
    Fly5.x = 615;
    Fly5.y = 50;
    Fly6.x = 915;
    Fly6.y = 50;
    FroG01.x = 250;
    FroG01.y = 315;
    FroG02.x = 250;
    FroG02.y = 560;
    FroG03.x = 950;
    FroG03.y = 450;
    Health_Bar_Remain.x = 300;
    Health_Bar_Remain.w = 650;
    Health_Bar_Loss.w = 0;
    Health_Bar_Remain_BOSS.x = 325;
    Health_Bar_Remain_BOSS.w = 600;
    Health_Bar_Loss_BOSS.w = 0;
    iS_tHere_froG_OR_NOT = 0;
    image_index = 1;
    atk_Dly = 30;
    atk_Num = 0;
    atk_Round = 0;
    atk_Scd = 0;
    Get_Star = 0;
    dAmaGe_F[0] = 0;
    dAmaGe_F[1] = 0;
    dAmaGe_F[2] = 0;
    dAmaGe_F[3] = 0;
    dAmaGe_F[4] = 0;
    dAmaGe_F[5] = 0;
    count_of_Frog = 0;
    Stop_frOG = 0;
    Num_of_Stars = 0;
    Get_hUrt = 0;
    bOSs1_iS_dialogue_1 = 0;
    bOSs1_iS_dialogue_2 = 0;
}

void cLaEn_All_iN_bOSs1()
{
    for (i = 0; i < 6; i++)
    {
        SDL_FreeSurface(surf_Dialogue_pic_1[i]);
        SDL_DestroyTexture(txt_Dialogue_pic_1[i]);
    }
    for (i = 0; i < 4; i++)
    {
        SDL_FreeSurface(surf_hEAlEr[i]);
        SDL_DestroyTexture(txt_hEAlEr[i]);
    }
    for (i = 0; i < 3; i++)
    {
        SDL_FreeSurface(surffg[i]);
        SDL_DestroyTexture(txtfg[i]);
    }
    for (i = 0; i < 2; i++)
    {
        SDL_FreeSurface(surfboss[i]);
        SDL_DestroyTexture(txtboss[i]);
    }
    for (i = 0; i < 3; i++)
    {
        SDL_FreeSurface(surffly[i]);
        SDL_DestroyTexture(txtfly[i]);
    }
    for (i = 0; i < 4; i++)
    {
        SDL_FreeSurface(surfid[i]);
        SDL_DestroyTexture(txtid[i]);
    }
    SDL_FreeSurface(Shifter_BackGroundSurface_bOSs1);
    SDL_DestroyTexture(Shifter_BackGroundTexture_bOSs1);
    SDL_FreeSurface(surf_background);
    SDL_DestroyTexture(txt_background);
    SDL_FreeSurface(surftt);
    SDL_DestroyTexture(txttt);
    SDL_FreeSurface(surfstar);
    SDL_DestroyTexture(txtstar);
    SDL_FreeSurface(surfpyr[0]);
    SDL_DestroyTexture(txtpyr[0]);
    SDL_FreeSurface(surfpyr[1]);
    SDL_DestroyTexture(txtpyr[1]);
    SDL_FreeSurface(surfhp);
    SDL_DestroyTexture(txthp);
    SDL_FreeSurface(surfwall);
    SDL_DestroyTexture(txtwall);
    SDL_FreeSurface(surffloor);
    SDL_DestroyTexture(txtfloor);
    SDL_FreeSurface(Game_Over_BackGroundSurface_bOSs1);
    SDL_DestroyTexture(Game_Over_BackGroundTexture_bOSs1);
}

int Boss(int ct) // Boss图像
{
    if (ct >= 1 && ct <= 5)
    {
        SDL_RenderCopy(rdr1, txtboss[0], NULL, &BoSs);
    }
    if (ct >= 6 && ct <= 10)
    {
        SDL_RenderCopy(rdr1, txtboss[1], NULL, &BoSs);
    }
    if (ct >= 11 && ct <= 15)
    {
        SDL_RenderCopy(rdr1, txtboss[2], NULL, &BoSs);
    }
    if (ct >= 16 && ct <= 20)
    {
        SDL_RenderCopy(rdr1, txtboss[3], NULL, &BoSs);
    }
    if (ct == 20)
    {
        return 1;
    }
    else
    {
        ct++;
        return ct;
    }
}

int Random_atk_Mod(int atk_Round) // 伪随机
{
    if (atk_Round == 0)
        return 0;
    else if (atk_Round == 1)
        return 1;
    else
        return (Player.x * Player.y) / (atk_Round + 1) % 2;
}

int Random_Star_Position(int atk_Round) // 伪随机
{
    return (10 * Player.x * atk_Round + 1) / (Player.y) % 9;
}

int fROg(int count_of_Frog, int Stop_frOG) // 青蛙
{
    int i;
    int* rectsY[3] = { &FroG01.y, &FroG02.y, &FroG03.y };
    rects_of_Laser[0].x = 300;
    rects_of_Laser[1].x = 300;
    rects_of_Laser[2].x = 950;
    if (Stop_frOG)
    {
        for (i = 0; i < 3; i++)
        {
            rects_of_Laser[i].y = *rectsY[i] + 20;
        }
        if (Stop_frOG <= 50 && Stop_frOG > 25)
        {
            for (i = 0; i < 2; i++)
            {
                rects_of_Laser[i].y = *rectsY[i] + 15;
                rects_of_Laser[i].w = ((50 - Stop_frOG) * 26);
                rects_of_Laser[i].h = 20;
            }
            rects_of_Laser[2].y = *rectsY[2] + 15;
            rects_of_Laser[2].w = ((50 - Stop_frOG) * 26);
            rects_of_Laser[2].x -= ((50 - Stop_frOG) * 26);
            rects_of_Laser[2].h = 20;
        }
        if (Stop_frOG <= 25)
        {
            for (i = 0; i < 2; i++)
            {
                rects_of_Laser[2].x = 300;
                rects_of_Laser[i].y = *rectsY[i] + 5;
                rects_of_Laser[i].w = 650;
                rects_of_Laser[i].h = 40;
            }
            rects_of_Laser[2].y = *rectsY[i] + 5;
            rects_of_Laser[2].w = 650;
            rects_of_Laser[2].h = 40;
        }

        SDL_RenderCopy(rdr1, txtfg[0], NULL, &FroG01);
        SDL_RenderCopy(rdr1, txtfg[1], NULL, &FroG02);
        SDL_RenderCopy(rdr1, txtfg[2], NULL, &FroG03);

        SDL_SetRenderDrawColor(rdr1, 0, 255, 0, 255);
        SDL_RenderFillRect(rdr1, &rects_of_Laser[0]);
        SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255);
        SDL_RenderFillRect(rdr1, &rects_of_Laser[1]);
        SDL_SetRenderDrawColor(rdr1, 0, 0, 255, 255);
        SDL_RenderFillRect(rdr1, &rects_of_Laser[2]);
        Stop_frOG--;
        return Stop_frOG;
    }
    else
    {
        FroG01.y += V_of_Fg[0];
        FroG02.y += V_of_Fg[1];
        FroG03.y += V_of_Fg[2];
        for (i = 0; i < 3; i++)
        {
            if (*rectsY[i] >= 580)
            {
                *rectsY[i] = 580;
                V_of_Fg[i] = -V_of_Fg[i];
            }
            if (*rectsY[i] <= 250)
            {
                *rectsY[i] = 250;
                V_of_Fg[i] = -V_of_Fg[i];
            }
        }
        if (FroG02.y - FroG01.y <= 60)
        {
            FroG02.y += (60 - FroG02.y + FroG01.y) / 2;
            FroG01.y -= (60 - FroG02.y + FroG01.y) / 2;
            V_of_Fg[0] = -V_of_Fg[0];
            V_of_Fg[1] = -V_of_Fg[1];
        }

        SDL_RenderCopy(rdr1, txtfg[0], NULL, &FroG01);
        SDL_RenderCopy(rdr1, txtfg[1], NULL, &FroG02);
        SDL_RenderCopy(rdr1, txtfg[2], NULL, &FroG03);

        count_of_Frog++;
        return count_of_Frog;
    }
}

int Flies(int atk_Scd, int atk_Dly, int atk_Mod, int atk_Num) // 苍蝇
{
    switch (atk_Mod)
    {
    case 0: // 冲撞
        if (atk_Scd >= 20)
        {
            Fly_Crash(&Fly1.x, &Fly1.y, atk_Scd, 0, atk_Dly);
            Fly_Crash(&Fly2.x, &Fly2.y, atk_Scd, 1, atk_Dly);
            Fly_Crash(&Fly3.x, &Fly3.y, atk_Scd, 2, atk_Dly);
        }
        if (!dAmaGe_F[0])
            SDL_RenderCopy(rdr1, txtfly[0], NULL, &Fly1);
        if (!dAmaGe_F[1])
            SDL_RenderCopy(rdr1, txtfly[1], NULL, &Fly2);
        if (!dAmaGe_F[2])
            SDL_RenderCopy(rdr1, txtfly[2], NULL, &Fly3);
        break;
    case 1: // 转圈
        if (atk_Scd >= 1)
        {
            switch (atk_Num)
            {
            case 0:
                Fly_Circle(&Fly4.x, &Fly4.y, atk_Scd, atk_Dly, atk_Num, 4);
                if (!dAmaGe_F[3])
                    SDL_RenderCopy(rdr1, txtfly[0], NULL, &Fly4);
                if (!dAmaGe_F[4])
                    SDL_RenderCopy(rdr1, txtfly[1], NULL, &Fly5);
                if (!dAmaGe_F[5])
                    SDL_RenderCopy(rdr1, txtfly[2], NULL, &Fly6);
                break;
            case 1:
                Fly_Circle(&Fly5.x, &Fly5.y, atk_Scd, atk_Dly, atk_Num, 5);
                if (!dAmaGe_F[4])
                    SDL_RenderCopy(rdr1, txtfly[1], NULL, &Fly5);
                if (!dAmaGe_F[5])
                    SDL_RenderCopy(rdr1, txtfly[2], NULL, &Fly6);
                break;
            case 2:
                Fly_Circle(&Fly6.x, &Fly6.y, atk_Scd, atk_Dly, atk_Num, 6);
                if (!dAmaGe_F[5])
                    SDL_RenderCopy(rdr1, txtfly[2], NULL, &Fly6);
                break;
            default:
                break;
            }
        }
        break;
    case 2:
        break;
    default:
        break;
    }
    atk_Scd++;
    return atk_Scd;
}

void Fly_Circle(int* F_x, int* F_y, int atk_Scd, int atk_Dly, int atk_Num, int which_FLY) // 苍蝇转圈
{
    int RadIus = atk_Dly + 50;
    int Circle_x[3][9] = { {Player.x - (RadIus / 1.414), Player.x, Player.x + (RadIus / 1.414), Player.x + RadIus, Player.x + (RadIus / 1.414), Player.x, Player.x - (RadIus / 1.414), Player.x - RadIus, Player.x - (RadIus / 1.414)}, {Player.x + (RadIus / 1.414), Player.x + RadIus, Player.x + (RadIus / 1.414), Player.x, Player.x - (RadIus / 1.414), Player.x - RadIus, Player.x - (RadIus / 1.414), Player.x, Player.x + (RadIus / 1.414)}, {Player.x, Player.x + (RadIus / 1.414), Player.x + RadIus, Player.x + (RadIus / 1.414), Player.x, Player.x - (RadIus / 1.414), Player.x - RadIus, Player.x - (RadIus / 1.414), Player.x} };
    int Circle_y[3][9] = { {Player.y - (RadIus / 1.414), Player.y - RadIus, Player.y - (RadIus / 1.414), Player.y, Player.y + (RadIus / 1.414), Player.y + RadIus, Player.y + (RadIus / 1.414), Player.y, Player.y - (RadIus / 1.414)}, {Player.y - (RadIus / 1.414), Player.y, Player.y + (RadIus / 1.414), Player.y + RadIus, Player.y + (RadIus / 1.414), Player.y, Player.y - (RadIus / 1.414), Player.y - RadIus, Player.y - (RadIus / 1.414)}, {Player.y - RadIus, Player.y - (RadIus / 1.414), Player.y, Player.y + (RadIus / 1.414), Player.y + RadIus, Player.y + (RadIus / 1.414), Player.y, Player.y - (RadIus / 1.414), Player.y - RadIus} };
    if (atk_Scd >= 1 && atk_Scd <= 2)
    {
        *F_x = Circle_x[atk_Num][0];
        *F_y = Circle_y[atk_Num][0];
    }
    else if (atk_Scd >= 3 && atk_Scd <= 10)
    {
        *F_x = Circle_x[atk_Num][atk_Scd - 2];
        *F_y = Circle_y[atk_Num][atk_Scd - 2];
    }
    if (atk_Scd == atk_Dly / 2 + 5)
    {
        F_mOve_X[which_FLY] = Player.x - *F_x;
        F_mOve_Y[which_FLY] = Player.y - *F_y;
    }
    if (atk_Scd >= (atk_Dly / 4 + 15) && atk_Scd <= atk_Dly + 8)
    {
        *F_x += F_mOve_X[which_FLY] / (atk_Dly / 6.0);
        *F_y += F_mOve_Y[which_FLY] / (atk_Dly / 6.0);
    }
}

void Fly_Crash(int* F_x, int* F_y, int atk_Scd, int which_FLY, int atk_Dly) // 苍蝇冲撞
{
    if (atk_Scd == atk_Dly)
    {
        F_mOve_X[which_FLY] = Player.x - *F_x;
        F_mOve_Y[which_FLY] = Player.y - *F_y;
    }
    if (atk_Scd >= atk_Dly + 1 && atk_Scd <= atk_Dly + 8)
    {
        *F_x += (F_mOve_X[which_FLY] / (atk_Dly - 8.0) + F_mOve_X[which_FLY] / 50.0 * which_FLY);
        *F_y += (F_mOve_Y[which_FLY] / (atk_Dly - 8.0) + F_mOve_X[which_FLY] / 50.0 * which_FLY);
    }
    if (atk_Scd >= atk_Dly + 9 && atk_Scd <= atk_Dly + 10)
    {
        *F_x += (F_mOve_X[which_FLY] / (atk_Dly - 5.0) + F_mOve_X[which_FLY] / 50.0 * which_FLY);
        *F_y += (F_mOve_Y[which_FLY] / (atk_Dly - 5.0) + F_mOve_X[which_FLY] / 50.0 * which_FLY);
    }
    if (*F_x < 300)
        *F_x = 300;
    if (*F_x > 930)
        *F_x = 930;
    if (*F_y < 250)
        *F_y = 250;
    if (*F_y > 610)
        *F_y = 610;
}

int wall(int ct_fOr_wAll) // 墙壁下落动画
{
    SDL_RenderCopy(rdr1, txtwall, NULL, &wall_L);
    SDL_RenderCopy(rdr1, txtwall, NULL, &wall_R);
    if (ct_fOr_wAll <= 12)
    {
        wall_L.y += 50;
        wall_R.y += 50;
    }
    if (ct_fOr_wAll >= 13 && ct_fOr_wAll <= 16)
    {
        wall_L.y -= 4;
        wall_R.y -= 4;
    }
    if (ct_fOr_wAll >= 17 && ct_fOr_wAll <= 46)
    {
        wall_L.y -= 1;
        wall_R.y -= 1;
    }
    if (ct_fOr_wAll >= 47 && ct_fOr_wAll <= 51)
    {
        wall_L.y += 10;
        wall_R.y += 10;
    }
    ct_fOr_wAll++;
    return ct_fOr_wAll;
}

void TestText(int image_index) // 对话框
{
    SDL_RenderCopy(rdr1, txttt, NULL, &TestTExt);
}

int ColliSion(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) // 碰撞检测
{
    if (x1 < (x2 + w2) && (x1 + w1) > x2 && y1 < (y2 + h2) && (y1 + h1) > y2)
        return 60;
    else
        return 0;
}

void ID_CarD(int Num_of_Stars)
{
    SDL_RenderCopy(rdr1, txtid[Num_of_Stars], NULL, &ID_CaRd);
}

int bOss1_For_sciENtist2()
{
    /*if (SDL_Init(SDL_INIT_EVERYTHING) != 0) // 初始化
    {
        SDL_Log("Init failed: %s", SDL_GetError());
        return -1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return -1;
    }
    win = SDL_CreateWindow("DEMO01", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);  // 创建窗口
    rdr1 = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // 创建渲染器*/

    surf_Dialogue_pic_1[0] = IMG_Load("Files For BOSS1/dialogue pic/Picture flies.png"); // dia pic 1
    txt_Dialogue_pic_1[0] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic_1[0]);
    surf_Dialogue_pic_1[1] = IMG_Load("Files For BOSS1/dialogue pic/Picture operation.png"); // dia pic 2
    txt_Dialogue_pic_1[1] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic_1[1]);
    surf_Dialogue_pic_1[2] = IMG_Load("Files For BOSS1/dialogue pic/Picture healer.png"); // dia pic 3
    txt_Dialogue_pic_1[2] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic_1[2]);
    surf_Dialogue_pic_1[3] = IMG_Load("Files For BOSS1/dialogue pic/Picture star.png"); // dia pic 4
    txt_Dialogue_pic_1[3] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic_1[3]);
    surf_Dialogue_pic_1[4] = IMG_Load("Files For BOSS1/dialogue pic/Picture ID card.png"); // dia pic 5
    txt_Dialogue_pic_1[4] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic_1[4]);
    surf_Dialogue_pic_1[5] = IMG_Load("Files For BOSS1/dialogue pic/Picture frogs.png"); // dia pic 6
    txt_Dialogue_pic_1[5] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic_1[5]);

    surf_hEAlEr[0] = IMG_Load("Files For BOSS1/Healer/Healer 0.png"); // Healer CD 0
    txt_hEAlEr[0] = SDL_CreateTextureFromSurface(rdr1, surf_hEAlEr[0]);
    surf_hEAlEr[1] = IMG_Load("Files For BOSS1/Healer/Healer 1.png"); // Healer CD 1
    txt_hEAlEr[1] = SDL_CreateTextureFromSurface(rdr1, surf_hEAlEr[1]);
    surf_hEAlEr[2] = IMG_Load("Files For BOSS1/Healer/Healer 2.png"); // Healer CD 2
    txt_hEAlEr[2] = SDL_CreateTextureFromSurface(rdr1, surf_hEAlEr[2]);
    surf_hEAlEr[3] = IMG_Load("Files For BOSS1/Healer/Healer 3.png"); // Healer CD 3
    txt_hEAlEr[3] = SDL_CreateTextureFromSurface(rdr1, surf_hEAlEr[3]);

    surffg[0] = IMG_Load("Files For BOSS1/Frog 01.png");
    txtfg[0] = SDL_CreateTextureFromSurface(rdr1, surffg[0]);
    surffg[1] = IMG_Load("Files For BOSS1/Frog 02.png");
    txtfg[1] = SDL_CreateTextureFromSurface(rdr1, surffg[1]);
    surffg[2] = IMG_Load("Files For BOSS1/Frog 03.png");
    txtfg[2] = SDL_CreateTextureFromSurface(rdr1, surffg[2]);
    surffly[0] = IMG_Load("Files For BOSS1/fly01.png");
    txtfly[0] = SDL_CreateTextureFromSurface(rdr1, surffly[0]);
    surffly[1] = IMG_Load("Files For BOSS1/fly02.png");
    txtfly[1] = SDL_CreateTextureFromSurface(rdr1, surffly[1]);
    surffly[2] = IMG_Load("Files For BOSS1/fly03.png");
    txtfly[2] = SDL_CreateTextureFromSurface(rdr1, surffly[2]);
    surfwall = IMG_Load("Files For BOSS1/wall01.png");
    txtwall = SDL_CreateTextureFromSurface(rdr1, surfwall);
    surfpyr[0] = IMG_Load("Files For BOSS1/spr_heart_1.png"); // 设置玩家（受伤）
    txtpyr[0] = SDL_CreateTextureFromSurface(rdr1, surfpyr[0]);
    surfpyr[1] = IMG_Load("Files For BOSS1/spr_heart_0.png"); // 设置玩家
    txtpyr[1] = SDL_CreateTextureFromSurface(rdr1, surfpyr[1]);
    surf_background = IMG_Load("Files For BOSS1/background for BOSS1.png");
    txt_background = SDL_CreateTextureFromSurface(rdr1, surf_background);
    surftt = IMG_Load("Files For BOSS1/test text/test text05.png");
    txttt = SDL_CreateTextureFromSurface(rdr1, surftt);
    Shifter_BackGroundSurface_bOSs1 = IMG_Load("Files For BOSS1/FULL BLACK.png"); // BLACK
    Shifter_BackGroundTexture_bOSs1 = SDL_CreateTextureFromSurface(rdr1, Shifter_BackGroundSurface_bOSs1);
    Game_Over_BackGroundSurface_bOSs1 = IMG_Load("assets/Ingame/GameOver.png"); // GW
    Game_Over_BackGroundTexture_bOSs1 = SDL_CreateTextureFromSurface(rdr1, Game_Over_BackGroundSurface_bOSs1);
    for (i = 0; i < 4; i++)
    {
        SDL_snprintf(file_fOr_bOSs, sizeof(file_fOr_bOSs), "Files For BOSS1/BOSS1 image/BOSS1 %d.png", i + 1);
        surfboss[i] = IMG_Load(file_fOr_bOSs);
        txtboss[i] = SDL_CreateTextureFromSurface(rdr1, surfboss[i]);
    }
    for (i = 0; i < 4; i++)
    {
        SDL_snprintf(IDCardfile, sizeof(IDCardfile), "Files For BOSS1/ID Card/ID Card %02d.png", i);
        surfid[i] = IMG_Load(IDCardfile);
        txtid[i] = SDL_CreateTextureFromSurface(rdr1, surfid[i]);
    }

    SDL_Event event;

    surffloor = IMG_Load("Files For BOSS1/floor.png"); // 地板
    txtfloor = SDL_CreateTextureFromSurface(rdr1, surffloor);
    surfstar = IMG_Load("Files For BOSS1/Stars.png"); // 星星
    txtstar = SDL_CreateTextureFromSurface(rdr1, surfstar);
    surfhp = IMG_Load("Files For BOSS1/HP Bar.png");
    txthp = SDL_CreateTextureFromSurface(rdr1, surfhp);
    Uint64 start_t, end_t;
    int delay;

    BOSS_BGM = Mix_LoadMUS("Files For BOSS1/BOSS01.wav");
    Mix_PlayMusic(BOSS_BGM, -1);

    font_bOSs1 = TTF_OpenFont("assets/Font/Allan-Regular.ttf", 50);

    while (!quit)
    {
        // start to get time
        start_t = SDL_GetTicks64();

        if (!fight)
        {
            moveUp = 0;
            moveDown = 0;
            moveLeft = 0;
            moveRight = 0;
            Player.x = 500;
            Player.y = 275;
        }
        // 处理事件
        while (SDL_PollEvent(&event))
        {
            if (fight == 0)
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x >= 600 && x <= 650 && y >= 300 && y <= 350) // 进入战斗
                        {
                            fight = 1;
                            iS_tHere_froG_OR_NOT = 0;
                            Mix_PlayMusic(BOSS_BGM, -1);
                        }
                    }
                    break;
                default:
                    break;
                }
            }
            if (fight == 1)
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        Pause();
                        break;
                    case SDLK_w:
                        moveUp = 1;
                        break;
                    case SDLK_a:
                        moveLeft = 1;
                        break;
                    case SDLK_s:
                        moveDown = 1;
                        break;
                    case SDLK_d:
                        moveRight = 1;
                        break;
                    case SDLK_SPACE: // 对话进行
                        image_index++;
                        break;
                    case SDLK_e:
                        if (Num_of_Stars == 3 && image_index <= 1)
                        {
                            Num_of_Stars = 0;
                            iS_tHere_froG_OR_NOT = 1;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_w:
                        moveUp = 0;
                        break;
                    case SDLK_a:
                        moveLeft = 0;
                        break;
                    case SDLK_s:
                        moveDown = 0;
                        break;
                    case SDLK_d:
                        moveRight = 0;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
        }

        // 更新游戏状态
        if (moveUp == 1 && Player.y >= 250)
        {
            Player.y -= 5;
            if (Player.y < 250)
                Player.y = 250;
        }
        if (moveDown == 1 && Player.y <= 620)
        {
            Player.y += 5;
            if (Player.y > 620)
                Player.y = 620;
        }
        if (moveLeft == 1 && Player.x >= 300)
        {
            Player.x -= 5;
            if (Player.x < 300)
                Player.x = 300;
        }
        if (moveRight == 1 && Player.x <= 940)
        {
            Player.x += 5;
            if (Player.x > 940)
                Player.x = 940;
        }

        // 渲染
        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
        SDL_RenderClear(rdr1);
        SDL_RenderCopy(rdr1, txt_background, NULL, &fUll_sCrEEn); // 背景
        switch (fight)
        {
        case 0:
            SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255); // 按钮
            SDL_RenderFillRect(rdr1, &Bottum1);
            break;
        case 1:
            if (atk_Num == 0 && atk_Scd == 0 && iS_tHere_froG_OR_NOT == 0) // 每轮攻击开始前重置随机数
            {
                atk_Mod = Random_atk_Mod(atk_Round);
                if (atk_Round >= 2 && Num_of_Stars < 3) // 星星
                    Star_Position = Random_Star_Position(atk_Round);
            }
            SDL_RenderCopy(rdr1, txtfloor, NULL, &Floor); // 还是地板
            ct_fOr_wAll = wall(ct_fOr_wAll);
            if (image_index > 1)
            {
                if (iS_tHere_froG_OR_NOT) // 青蛙
                {
                    if (count_of_Frog % 100 == 0 && count_of_Frog != 0 && Stop_frOG == 0)
                        Stop_frOG = 50;
                    if (Stop_frOG)
                    {
                        Stop_frOG = fROg(count_of_Frog, Stop_frOG);
                        if (!Stop_frOG)
                            count_of_Frog++;
                    }
                    else
                        count_of_Frog = fROg(count_of_Frog, Stop_frOG);
                }
                if (atk_Round >= 2 && Get_Star == 0 && Num_of_Stars < 3 && iS_tHere_froG_OR_NOT == 0)
                {
                    SDL_RenderCopy(rdr1, txtstar, NULL, &Stars[Star_Position]); // 星星
                }
                atk_Scd = Flies(atk_Scd, atk_Dly, atk_Mod, atk_Num);
                if (atk_Scd == atk_Dly + 11) // 1/3轮攻击
                {
                    atk_Scd = 0;
                    atk_Num++;
                }
                if (atk_Num == 3 && atk_Scd == atk_Dly) // 一轮攻击结束
                {
                    if (!iS_tHere_froG_OR_NOT)
                    {
                        image_index = 1;
                        atk_Round++;
                        if (coUNt_oF_hEAl)
                            coUNt_oF_hEAl--;
                    }
                    if (atk_Dly > 20)
                        atk_Dly -= 2;
                    atk_Num = 0;
                    atk_Scd = 0;
                    Get_Star = 0;
                }
                if (iS_tHere_froG_OR_NOT == 1 && ((atk_Mod == 0 && dAmaGe_F[0] && dAmaGe_F[1] && dAmaGe_F[2]) || (atk_Mod == 1 && dAmaGe_F[3] && dAmaGe_F[4] && dAmaGe_F[5])))
                {
                    if (!Delay_Aft_Destroy_F)
                    {
                        Delay_Aft_Destroy_F = 15;
                        Bs_Hp -= 25;
                    }
                    if (Delay_Aft_Destroy_F > 1)
                        Delay_Aft_Destroy_F--;
                    if (Delay_Aft_Destroy_F == 1)
                    {
                        Delay_Aft_Destroy_F = 0;
                        iS_tHere_froG_OR_NOT = 0;
                        image_index = 1;
                        if (atk_Dly > 20)
                            atk_Dly -= 2;
                        atk_Num = 0;
                        atk_Round++;
                        if(coUNt_oF_hEAl)
                            coUNt_oF_hEAl--;
                        atk_Scd = 0;
                        Get_Star = 0;
                        dAmaGe_F[0] = 0;
                        dAmaGe_F[1] = 0;
                        dAmaGe_F[2] = 0;
                        dAmaGe_F[3] = 0;
                        dAmaGe_F[4] = 0;
                        dAmaGe_F[5] = 0;
                        count_of_Frog = 0;
                        Stop_frOG = 0;
                        Num_of_Stars = 0;
                    }
                }
            }
            if (Get_hUrt <= 60 && Get_hUrt > 50 || Get_hUrt <= 40 && Get_hUrt > 30 || Get_hUrt <= 20 && Get_hUrt > 10)
            {
                SDL_RenderCopy(rdr1, txtpyr[0], NULL, &Player);
            }
            else if (Get_hUrt <= 50 && Get_hUrt > 40 || Get_hUrt <= 30 && Get_hUrt > 20 || Get_hUrt <= 10 && Get_hUrt >= 0)
            {
                SDL_RenderCopy(rdr1, txtpyr[1], NULL, &Player);
            }
            if (iS_tHere_froG_OR_NOT == 1 && image_index > 1 && atk_Scd == 0)
            {
                Fly4.x = 365;
                Fly4.y = 50;
                Fly5.x = 615;
                Fly5.y = 50;
                Fly6.x = 915;
                Fly6.y = 50;
            }
            if (image_index <= 1)//between rounds
            {
                if (Py_Hp < 100 && !coUNt_oF_hEAl)
                {
                    coUNt_oF_hEAl = 3;
                    Py_Hp += 10;
                }
                TestText(image_index); // 重置苍蝇
                Fly1.x = 365;
                Fly1.y = 265;
                Fly2.x = 615;
                Fly2.y = 265;
                Fly3.x = 915;
                Fly3.y = 265;
                Fly4.x = 365;
                Fly4.y = 50;
                Fly5.x = 615;
                Fly5.y = 50;
                Fly6.x = 915;
                Fly6.y = 50;
                FroG01.x = 250;
                FroG01.y = 315;
                FroG02.x = 250;
                FroG02.y = 560;
                FroG03.x = 950;
                FroG03.y = 450;
                if (atk_Round == 0 && !bOSs1_iS_dialogue_1)
                {
                    SDL_RenderCopy(rdr1, Shifter_BackGroundTexture_bOSs1, NULL, &fUll_sCrEEn);
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic_1[0], NULL, &rECt_dialogue_pic_1);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs1, dia1_1, Blank_bOSs1, bOSs1_Emma, (char*)"Avatars/Emma.png");
                    present(win, rdr1, font_bOSs1, dia1_2, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia1_3, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia1_4, Blank_bOSs1, bOSs1_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs1, dia1_5, Blank_bOSs1, bOSs1_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs1, dia1_6, Blank_bOSs1, bOSs1_Ellie, (char*)"Avatars/Ellie.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic_1[1], NULL, &rECt_dialogue_pic_1);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs1, dia1_7, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia1_8, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic_1[2], NULL, &rECt_dialogue_pic_1);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs1, dia1_9, Blank_bOSs1, bOSs1_Emma, (char*)"Avatars/Emma.png");
                    present(win, rdr1, font_bOSs1, dia1_10, Blank_bOSs1, bOSs1_Emma, (char*)"Avatars/Emma.png");
                    present(win, rdr1, font_bOSs1, dia1_11, Blank_bOSs1, bOSs1_Prince, (char*)"Avatars/Prince.png");
                    if (presentstate == 0)
                    {
                        Mix_FreeMusic(BOSS_BGM);
                        Mix_CloseAudio();
                        iNIt_bOSs1();
                        cLaEn_All_iN_bOSs1();
                        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                        SDL_RenderClear(rdr1);
                        return 0;
                    }
                    bOSs1_iS_dialogue_1 = 1;
                    moveUp = 0, moveDown = 0, moveLeft = 0, moveRight = 0;
                }
                if (atk_Round == 2 && !bOSs1_iS_dialogue_2)
                {
                    SDL_RenderCopy(rdr1, Shifter_BackGroundTexture_bOSs1, NULL, &fUll_sCrEEn);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs1, dia2_1, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia2_2, Blank_bOSs1, bOSs1_Prince, (char*)"Avatars/Prince.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic_1[3], NULL, &rECt_dialogue_pic_1);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs1, dia2_3, dia2_3_2, bOSs1_Ellie, (char*)"Avatars/Ellie.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic_1[4], NULL, &rECt_dialogue_pic_1);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs1, dia2_4, dia2_4_2, bOSs1_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs1, dia2_5, Blank_bOSs1, bOSs1_Prince, (char*)"Avatars/Prince.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic_1[5], NULL, &rECt_dialogue_pic_1);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs1, dia2_6, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia2_7, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia2_8, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia2_9, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia2_10, Blank_bOSs1, bOSs1_Emma, (char*)"Avatars/Emma.png");
                    present(win, rdr1, font_bOSs1, dia2_11, Blank_bOSs1, bOSs1_Emma, (char*)"Avatars/Emma.png");
                    present(win, rdr1, font_bOSs1, dia2_12, Blank_bOSs1, bOSs1_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs1, dia2_13, Blank_bOSs1, bOSs1_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs1, dia2_14, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia2_15, Blank_bOSs1, bOSs1_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs1, dia2_16, Blank_bOSs1, bOSs1_Wyvern, (char*)"Avatars/Wyvern.png");
                    if (presentstate == 0)
                    {
                        Mix_FreeMusic(BOSS_BGM);
                        Mix_CloseAudio();
                        iNIt_bOSs1();
                        cLaEn_All_iN_bOSs1();
                        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                        SDL_RenderClear(rdr1);
                        return 0;
                    }
                    bOSs1_iS_dialogue_2 = 1;
                    moveUp = 0, moveDown = 0, moveLeft = 0, moveRight = 0;
                }
            }
            if (Get_Star == 0 && atk_Round >= 2 && image_index > 1 && Num_of_Stars < 3 && !iS_tHere_froG_OR_NOT)
                Get_Star = ColliSion(Player.x, Player.y, Player.w, Player.h, Stars[Star_Position].x, Stars[Star_Position].y, Stars[Star_Position].w, Stars[Star_Position].h);
            if (Get_Star == 60)
            {
                Get_Star = 30;
                Num_of_Stars++;
            }
            if (atk_Round >= 2)
                ID_CarD(Num_of_Stars);
            if (iS_tHere_froG_OR_NOT == 1 && Stop_frOG <= 25 && Stop_frOG > 0)
            {
                if (!dAmaGe_F[0] && atk_Mod == 0)
                    dAmaGe_F[0] = ColliSion(Fly1.x, Fly1.y, Fly1.w, Fly1.h, rects_of_Laser[0].x, rects_of_Laser[0].y, rects_of_Laser[0].w, rects_of_Laser[0].h);
                if (!dAmaGe_F[1] && atk_Mod == 0)
                    dAmaGe_F[1] = ColliSion(Fly2.x, Fly2.y, Fly2.w, Fly2.h, rects_of_Laser[1].x, rects_of_Laser[1].y, rects_of_Laser[1].w, rects_of_Laser[1].h);
                if (!dAmaGe_F[2] && atk_Mod == 0)
                    dAmaGe_F[2] = ColliSion(Fly3.x, Fly3.y, Fly3.w, Fly3.h, rects_of_Laser[2].x, rects_of_Laser[2].y, rects_of_Laser[2].w, rects_of_Laser[2].h);
                if (!dAmaGe_F[3] && atk_Mod == 1)
                    dAmaGe_F[3] = ColliSion(Fly4.x, Fly4.y, Fly4.w, Fly4.h, rects_of_Laser[0].x, rects_of_Laser[0].y, rects_of_Laser[0].w, rects_of_Laser[0].h);
                if (!dAmaGe_F[4] && atk_Mod == 1)
                    dAmaGe_F[4] = ColliSion(Fly5.x, Fly5.y, Fly5.w, Fly5.h, rects_of_Laser[1].x, rects_of_Laser[1].y, rects_of_Laser[1].w, rects_of_Laser[1].h);
                if (!dAmaGe_F[5] && atk_Mod == 1)
                    dAmaGe_F[5] = ColliSion(Fly6.x, Fly6.y, Fly6.w, Fly6.h, rects_of_Laser[2].x, rects_of_Laser[2].y, rects_of_Laser[2].w, rects_of_Laser[2].h);
            }
            if (Get_hUrt) // 无敌帧
                Get_hUrt--;
            else
            {
                if (image_index > 1)
                {
                    if (iS_tHere_froG_OR_NOT == 1 && Stop_frOG <= 25 && Stop_frOG > 0)
                    {
                        Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, rects_of_Laser[0].x, rects_of_Laser[0].y, rects_of_Laser[0].w, rects_of_Laser[0].h);
                        if (!Get_hUrt)
                        {
                            Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, rects_of_Laser[1].x, rects_of_Laser[1].y, rects_of_Laser[1].w, rects_of_Laser[1].h);
                            if (!Get_hUrt)
                                Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, rects_of_Laser[2].x, rects_of_Laser[2].y, rects_of_Laser[2].w, rects_of_Laser[2].h);
                        }
                    }
                    if (!iS_tHere_froG_OR_NOT || iS_tHere_froG_OR_NOT == 1 && Get_hUrt == 0)
                    {
                        switch (atk_Mod)
                        {
                        case 0:
                            if (!dAmaGe_F[0])
                                Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, Fly1.x, Fly1.y, Fly1.w, Fly1.h);
                            if (!Get_hUrt)
                            {
                                if (!dAmaGe_F[1])
                                    Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, Fly2.x, Fly2.y, Fly2.w, Fly2.h);
                                if (!Get_hUrt)
                                    if (!dAmaGe_F[2])
                                        Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, Fly3.x, Fly3.y, Fly3.w, Fly3.h);
                            }
                            break;
                        case 1:
                            switch (atk_Num)
                            {
                            case 0:
                                if (!dAmaGe_F[3])
                                    Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, Fly4.x, Fly4.y, Fly4.w, Fly4.h);
                                break;
                            case 1:
                                if (!dAmaGe_F[4])
                                    Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, Fly5.x, Fly5.y, Fly5.w, Fly5.h);
                                break;
                            case 2:
                                if (!dAmaGe_F[5])
                                    Get_hUrt = ColliSion(Player.x, Player.y, Player.w, Player.h, Fly6.x, Fly6.y, Fly6.w, Fly6.h);
                                break;
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
            if (Get_hUrt == 60) // 掉血
            {
                Py_Hp -= 10;
            }
            Health_Bar_Remain.x = 950 - 650 * (Py_Hp / 100.0);
            Health_Bar_Remain.w = 650 * (Py_Hp / 100.0);
            Health_Bar_Loss.w = 650 - 650 * (Py_Hp / 100.0);
            Health_Bar_Remain_BOSS.x = 925 - 600 * (Bs_Hp / 100.0);
            Health_Bar_Remain_BOSS.w = 600 * (Bs_Hp / 100.0);
            Health_Bar_Loss_BOSS.w = 600 - 600 * (Bs_Hp / 100.0);
            SDL_SetRenderDrawColor(rdr1, 0, 0, 255, 255); // 设置BOSS失去血量颜色
            SDL_RenderFillRect(rdr1, &Health_Bar_Loss_BOSS);
            SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255); // 设置BOSS剩余血量颜色
            SDL_RenderFillRect(rdr1, &Health_Bar_Remain_BOSS);
            SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255); // 设置失去血量颜色
            SDL_RenderFillRect(rdr1, &Health_Bar_Loss);
            SDL_SetRenderDrawColor(rdr1, 0, 255, 0, 255); // 设置剩余血量颜色
            SDL_RenderFillRect(rdr1, &Health_Bar_Remain);
            SDL_RenderCopy(rdr1, txthp, NULL, &Health_Bar);
            break;
        default:
            break;
        }
        ct = Boss(ct);

        SDL_RenderCopy(rdr1, txt_hEAlEr[3 - coUNt_oF_hEAl], NULL, &rECt_hEAlEr);

        SDL_RenderPresent(rdr1);

        if (Py_Hp <= 0 || Bs_Hp <= 0)
        {
            if (Py_Hp <= 0)
            {
                Mix_PauseMusic();
                while (!bACk_tO_lASt_sCeNe_bOSs1)
                {
                    if (transparency_Gm_Ov_1 < 223)
                        transparency_Gm_Ov_1++;
                    SDL_SetTextureAlphaMod(Game_Over_BackGroundTexture_bOSs1, transparency_Gm_Ov_1);
                    SDL_RenderCopy(rdr1, Game_Over_BackGroundTexture_bOSs1, NULL, &fUll_sCrEEn);
                    SDL_RenderPresent(rdr1);
                    while (SDL_PollEvent(&event))
                    {
                        if (event.type == SDL_QUIT)
                        {
                            iNIt_bOSs1();
                            cLaEn_All_iN_bOSs1();
                            SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                            SDL_RenderClear(rdr1);
                            return 0;
                        }
                        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
                            bACk_tO_lASt_sCeNe_bOSs1 = 1;
                    }
                }
                iNIt_bOSs1();
                cLaEn_All_iN_bOSs1();
                SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                SDL_RenderClear(rdr1);
                return 3;
            }
            if (Bs_Hp <= 0)
            {
                Mix_FreeMusic(BOSS_BGM);
                Mix_CloseAudio();
                iNIt_bOSs1();
                cLaEn_All_iN_bOSs1();
                SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                SDL_RenderClear(rdr1);
                return 1;
            }
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
    }
    Mix_FreeMusic(BOSS_BGM);
    Mix_CloseAudio();
    iNIt_bOSs1();
    cLaEn_All_iN_bOSs1();
    SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
    SDL_RenderClear(rdr1);
    return 0;
}
