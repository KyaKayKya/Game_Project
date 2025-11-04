#include "test2.h"
#include "BOSS2.h"
#include "SDL2_test.h"

//#include <stdio.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_mixer.h>

//#undef main

#define FR 40 // 帧率Frame Rate
#define FT 1000 / FR

//#define W 1250
//#define H 650

//SDL_Window* win = NULL;
//SDL_Renderer* rdr1 = NULL;
SDL_Surface* sURf_surfboss[108] = { 0 };
SDL_Texture* tXt_txtboss[108] = { 0 };
#define surfboss sURf_surfboss
#define txtboss tXt_txtboss
SDL_Surface* surf_bOSs_gOt_hURt = NULL;
SDL_Texture* txt_bOSs_gOt_hURt = NULL;
SDL_Surface* sURf_urffloor = NULL;
SDL_Texture* tXt_txtfloor = NULL;
#define surffloor sURf_urffloor
#define txtfloor tXt_txtfloor
SDL_Surface* surffloor_F = NULL;
SDL_Texture* txtfloor_F = NULL;
SDL_Surface* surffloor_T = NULL;
SDL_Texture* txtfloor_T = NULL;
SDL_Surface* surffloor_I = NULL;
SDL_Texture* txtfloor_I = NULL;
SDL_Surface* surffloor_S = NULL;
SDL_Texture* txtfloor_S = NULL;
SDL_Surface* surffloor_F_B = NULL;
SDL_Texture* txtfloor_F_B = NULL;
SDL_Surface* surffloor_T_B = NULL;
SDL_Texture* txtfloor_T_B = NULL;
SDL_Surface* surffloor_I_B = NULL;
SDL_Texture* txtfloor_I_B = NULL;
SDL_Surface* surffloor_S_B = NULL;
SDL_Texture* txtfloor_S_B = NULL;
SDL_Surface* surfbomB[16] = { 0 };
SDL_Texture* txtbomB[16] = { 0 };
SDL_Surface* surf_arw_laser[4] = { 0 };
SDL_Texture* txt_arw_laser[4] = { 0 };
SDL_Surface* surf_IDCard[6] = { 0 };
SDL_Texture* txt_IDCard[6] = { 0 };
SDL_Surface* surfpyr = NULL;
SDL_Texture* txtpyr = NULL;
SDL_Surface* surfpyr_hURt = NULL;
SDL_Texture* txtpyr_hURt = NULL;
SDL_Surface* sURf_surftt = NULL;
SDL_Texture* tXt_txttt = NULL;
#define surftt sURf_surftt
#define txttt tXt_txttt
SDL_Surface* sURf_surfhp = NULL;
SDL_Texture* tXt_txthp = NULL;
#define surfhp sURf_surfhp
#define txthp tXt_txthp
SDL_Surface* surfexplOOOsion[3] = { 0 };
SDL_Texture* txtexplOOOsion[3] = { 0 };
SDL_Surface* surfshIEld = NULL;
SDL_Texture* txtshIEld = NULL;
SDL_Surface* surf_bIg_bOMb[6] = { 0 };
SDL_Texture* txt_bIg_bOMb[6] = { 0 };
SDL_Surface* surf_bIg_bOMb_eXpLosIOn[3] = { 0 };
SDL_Texture* txt_bIg_bOMb_eXpLosIOn[3] = { 0 };
SDL_Surface* surf_background[2] = { 0 };
SDL_Texture* txt_background[2] = { 0 };
SDL_Surface* surf_aImInG_cRoSS[2] = { 0 };
SDL_Texture* txt_aImInG_cRoSS[2] = { 0 };
SDL_Surface* surf_hEAlEr_2[4] = { 0 };
SDL_Texture* txt_hEAlEr_2[4] = { 0 };
SDL_Surface* Shifter_BackGroundSurface_bOSs2 = NULL;
SDL_Texture* Shifter_BackGroundTexture_bOSs2 = NULL;
SDL_Surface* surf_Dialogue_pic[6] = {0};
SDL_Texture* txt_Dialogue_pic[6] = {0};
SDL_Surface* Game_Over_BackGroundSurface_bOSs2 = NULL;
SDL_Texture* Game_Over_BackGroundTexture_bOSs2 = NULL;
SDL_Rect eXpLOOOOOOOOOOOsIoN[40] = { 0 };
SDL_Rect rECt_Health_Bar_Remain = { 300, 630, 650, 20 };
#define Health_Bar_Remain rECt_Health_Bar_Remain
SDL_Rect rECt_Health_Bar_Loss = { 300, 630, 0, 20 };
#define Health_Bar_Loss rECt_Health_Bar_Loss
SDL_Rect rECt_Health_Bar = { 300, 630, 650, 20 };
#define Health_Bar rECt_Health_Bar
SDL_Rect aRRoW_laSeR = { 615, 380, 20, 20 };
SDL_Rect bOMbs[40] = { 0 };
SDL_Rect Player2 = { 500, 420, 10, 10 };  // 玩家
SDL_Rect Bottum2 = { 600, 300, 50, 50 }; // 进入战斗
SDL_Rect BoSs2 = { 200, 20, 850, 343 };
SDL_Rect aTTaCk_aReA_oF_eXtRa_bIg_bOMbS[3] = { {200, 380, 283, 250}, {483, 380, 284, 250}, {767, 380, 283, 250} };
SDL_Rect Floor2 = { 200, 380, 850, 250 };
SDL_Rect Floor_Fire = { 350, 430, 100, 100 };
SDL_Rect Floor_Thunder = { 495, 440, 100, 100 };
SDL_Rect Floor_Ice = { 655, 440, 100, 100 };
SDL_Rect Floor_Stone = { 800, 430, 100, 100 };
SDL_Rect ID_CaRd2 = { 100, 110, 80, 80 };
SDL_Rect rECt_hEAlEr2 = { 100, 220, 80, 80 };
SDL_Rect eNErgY_Of_ID_CaRd = { 100, 170, 0, 20 };
SDL_Rect stILL_nOt_eNErgY_Of_ID_CaRd = { 100, 170, 80, 20 };
SDL_Rect stILL_nOt_eNErgY_fOr_Missing_bOMbS = {1140,200,20,400};
SDL_Rect eNErgY_fOr_Missing_bOMbS = { 1140,600,20,0 };
SDL_Rect eNErgY_Of_shEIld[5] = { {100, 170, 16, 20}, {116, 170, 16, 20}, {132, 170, 16, 20}, {148, 170, 16, 20}, {164, 170, 16, 20} };
SDL_Rect LaSer = { 200, 380, 850, 20 };
SDL_Rect TestTExt2 = { 432, 500, 386, 92 };
SDL_Rect sHieLD = { 0 };
SDL_Rect bIg_bOMbS = { 575, -200, 100, 200 };
SDL_Rect rECt_eXtRa_bIg_bOMbS[3] = { {292, -200, 100, 200}, { 575, -200, 100, 200 }, { 858, -200, 100, 200 } };
SDL_Rect fUll_sCrEEn2 = {0, 0, 1250, 650};
SDL_Rect fUll_sCrEEn_fOr_bAcKgRoUNd[4] = { {0, 0, 1250, 650}, {1250, 0, 1250, 650},{0, 0, 1250, 650}, {1250, 0, 1250, 650} };
SDL_Rect rECt_Health_Bar_Remain_BOSS = { 325, 360, 600, 10 };
SDL_Rect rECt_Health_Bar_Loss_BOSS = { 325, 360, 0, 10 };
#define Health_Bar_Remain_BOSS rECt_Health_Bar_Remain_BOSS
#define Health_Bar_Loss_BOSS rECt_Health_Bar_Loss_BOSS
SDL_Rect eNErgY_oF_flOOrS[4][2] = { {{350, 550, 50, 10}, {400, 550, 50, 10}}, {{495, 560, 50, 10}, {545, 560, 50, 10}}, {{655, 560, 50, 10}, {705, 560, 50, 10}}, {{800, 550, 50, 10}, {850, 550, 50, 10}} };
SDL_Rect rECt_dialogue_pic = {289, 40, 672, 350};
Mix_Music* BOSS_BGM2 = NULL;
TTF_Font* font_bOSs2 = NULL;
char file_OF_bombs[50] = { 0 };
char file_OF_laSeR[50] = { 0 };
char file_OF_bOSs[50] = { 0 };
int imAGes_of_bOMbs[40] = { 0 }; // 决定炸弹的贴图
int sHOw_bOMbs_oR_nOt[40] = { 0 };
int diRECtiON_oF_laSeR = 0;
int eXpLOOOOOOOOOOOsIoN_coUNtdOWn[45] = { 0 };
int Get_hUrt_2 = 0;
#define Get_hUrt Get_hUrt_2
int bOSs_gOt_hURt = 0;
int plAYer_oN_whICh_fLOOr = 0;
int eNErgY_oF_ID_cARd = 0;
int shIEld_Or_nOt = 0;
int cOlOr_oF_bIg_bOMb = 0;
int Hp_oF_Bs = 100;
#define Bs_Hp Hp_oF_Bs
int Hp_oF_Py = 100;
#define Py_Hp Hp_oF_Py
int atk_oRdEr_oF_bOMbS[3][16] = { {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, {0, 1, 4, 5, 8, 9, 12, 13, 2, 3, 6, 7, 10, 11, 14, 15}, {4, 5, 6, 1, 0, 3, 2, 7, 8, 9, 11, 13, 12, 14, 15, 10} };
int atk_mOd_oF_bOMbS = 0;
int eNErgY_nEEdEd_fOr_IDCard = 20;
int bOss_sTaTe = 0; // 留作接口，不加设游戏内改变方式
int eNErgY_fOr_flOOrS[4] = { 0 };
int nOt_oN_tHe_flOOr_aT_aLL[4] = { 0 };
int hOw_lONg_boSs_iMaGe = 5;
int x_mOVemENt_oF_bOSs[192] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
int y_mOVemENt_oF_bOSs[240] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
int coUNt_oF_bOSs_mOVemENt = 0;

//int presentstate;

int quit_2 = 0, mOveUp = 0, mOveDown = 0, mOveLeft = 0, mOveRight = 0;
int fight_2 = 1;
int ct_BOSS2 = 1;
#define ct ct_BOSS2
int image_index_2 = 1;
int atk_Scd_2 = 0;
#define atk_Scd atk_Scd_2
int atk_Round_2 = 0;
#define atk_Round atk_Round_2
int GmOr_2 = 0;
int GmWn_2 = 0;
int nUm_oF_bOMbs = 20;
int eNd_oF_AroUNd = 1;
int ID_Card_rEAdY_Or_nOt = 0;
int coUNt_oF_hEAl_2 = 0;
int iS_tHeRe_eXtRa_bOMbS = 0;
int iS_tHeRe_eXtRa_eXtRa_bOMbS = 0;
int atk_Scd_fOr_eXtRa_bOMbS = 0;
int wHerE_ATK = 0;
int eNErgY_oF_Missing_bOMbS = 0;
int bOSs_iS_dRoPPinG_bIg_bOMb = 0;

int bACk_tO_lASt_sCeNe_bOSs2 = 0;
int transparency_Gm_Ov_2 = 0;

int bOSs_iS_dialogue_1_sts1 = 0;//first enter sts1
int bOSs_iS_dialogue_1_sts2 = 0;//first enter sts2
int bOSs_iS_dialogue_2_sts1 = 0;//4th round of sts1
int bOSs_iS_dialogue_2_sts2 = 0;//60% BOSS HP
int bOSs_iS_dialogue_3_sts2 = 0;//20% BOSS HP

char Blank_bOSs2[100] = { 0 };
char bOSs2_Ellie[10] = { "Ellie" };
char bOSs2_DC[10] = { "DC" };
char bOSs2_Prince[10] = { "Prince" };
char bOSs2_Emma[10] = { "Emma" };
char bOSs2_Dragon[10] = { "Dragon" };
char sts1or2_1_1[100] = { "Look! Who\'s here? Dear esteemed guests, welcome to my bomb factory!!!" };
char sts1or2_1_2[100] = { "Well... Maybe Lamy didn\'t fool us..." };
char sts1or2_1_3[100] = { "Wait a moment... Let me take a look at the information that guy left us..." };
char sts1or2_1_4[100] = { "Although we don\'t know the truth, this is the only thing we can rely on at present." };
char sts1or2_1_5[100] = { "I never thought we would use the most basic weapons to fight against a massive robot" };
char sts1or2_1_6[100] = { "that was bombarded wildly!" };
char sts1or2_1_7[100] = { "Ellie, I have sent you the parsed information!" };
char sts1or2_1_8[100] = { "You explain, I\'ll set up the ID card!" };
char sts1or2_1_9[100] = { "Alright! Let me see..." };
char sts1or2_1_10[100] = { "Dragon will release bombs in four colors: red, purple, blue, and yellow." };
char sts1or2_1_11[100] = { "The only way to destroy the bomb is to use the white laser barrier, which is" };
char sts1or2_1_12[100] = { "generated by the ID card in front of the platform!" };
char sts1or2_1_13[100] = { "Bombs will be labeled in four different directions, up, down, left, and right," };
char sts1or2_1_14[100] = { "which are the energy pulse directions required to dismantle the bomb." };
char sts1or2_1_15[100] = { "By ressing ‘UP’, ‘DOWN’, ‘LEFT’, ‘RIGHT’,"};
char sts1or2_1_16[100] = { "you can change the direction of the energy pulse of the laser barrier." };
char sts1or2_1_17[100] = { "When the bomb contacts the laser barrier," };
char sts1or2_1_18[100] = { "pressing the corresponding direction button can use the energy pulse to destroy the bomb!" };
char sts1_1_19[100] = { "The ID card has been successfully activated!" };
char sts1_1_20[100] = { "Now, listen! There are four circular floors on the field," };
char sts1_1_21[100] = { "corresponding to four colors: red, purple, blue, and yellow." };
char sts1_1_22[100] = { "They were originally the switches used by the BOSS to activate the giant bomb release device," };
char sts1_1_23[100] = { "but when I just encountered Lamy, I used the core technology I mastered to rescue Wyvern" };
char sts1_1_23_2[100] = { "to reverse invade and tamper with this system." };
char sts1_1_24[100] = { "Now, observe the color of the bomb and stand on the corresponding floor" };
char sts1_1_24_2[100] = { "to destroy the bomb with the same color as the floor to charge the ID card!" };
char sts1_1_25[100] = { "When the ID card is fully charged, press ‘E’ to activate the energy shield!" };
char sts1_1_26[100] = { "The shield only has 5 energy points, which means it can only withstand 5 attacks for you." };
char sts1_1_27[100] = { "I will keep searching for ways to weaken Dragon's combat effectiveness!" };
char sts1_1_28[100] = { "I will heal you!" };
char sts1_1_29[100] = { "Alright, let me give it a try!" };
char sts1_1_30[100] = { "Stupid! How dare you think you can defeat me!!! Be blown to ashes!" };
char sts2_1_19[100] = { "The ID card has been successfully activated!" };
char sts2_1_20[100] = { "Now, listen! There are four circular floors on the field," };
char sts2_1_21[100] = { "corresponding to four colors: red, purple, blue, and yellow." };
char sts2_1_22[100] = { "They are switches for Dragon to release giant bombs!" };
char sts2_1_23[100] = { "The floor has three energy levels, red, white, and green." };
char sts2_1_24[100] = { "Initially they are all white, as shown below the floors." };
char sts2_1_25[100] = { "Dragon will charge them at the end of each round," };
char sts2_1_25_2[100] = { "don't let all the energy slots on the floor turn red!" };
char sts2_1_26[100] = { "Otherwise, the giant bomb released by Dragon will hit us hard!" };
char sts2_1_27[100] = { "No matter where you stand, as long as you destroy the bomb, you can charge your ID card! " };
char sts2_1_28[100] = { "After charging, the ID card will store energy as one skill point," };
char sts2_1_28_2[100] = { "and the accumulated energy will continue to charge the ID card." };
char sts2_1_29[100] = { "A maximum of 3 skill points can be stored, and the energy obtained after this will overflow!" };
char sts2_1_30[100] = { "When there is a skill point, standing on one of the four floors can press ‘E’" };
char sts2_1_30_2[100] = { "to use the skill to charge the floor." };
char sts2_1_31[100] = { "Unlike Dragon's charging, our charging will increase the level of the floor, up to a green level." };
char sts2_1_32[100] = { "If the energy slots on all four floors turn green, this switch will cause energy overload" };
char sts2_1_32_2[100] = { "and damage the robot controlled by Dragon!" };
char sts2_1_33[100] = { "I will heal you!" };
char sts2_1_34[100] = { "Alright, let me give it a try!" };
char sts2_1_35[100] = { "Stupid! How dare you think you can defeat me!!! Be blown to ashes!" };
char sts1_2_1[100] = { "The appetizer is over, now, try this big one!" };
char sts1_2_2[100] = { "Wait! Isn't it said that the switch for releasing the giant bomb has failed???" };
char sts1_2_3[100] = { "What should we do now?" };
char sts1_2_4[100] = { "Calm down! Those giant bombs look unusual, they come in four colors: red, purple, blue, and yellow!" };
char sts1_2_5[100] = { "Prince, do you still have your shield?" };
char sts1_2_6[100] = { "After resisting the attack of a giant bomb, the energy value of the shield will return to 0," };
char sts1_2_6_2[100] = { "but it can still save your life!" };
char sts1_2_7[100] = { "Also, stand on the floor that is the same color as the bomb!" };
char sts1_2_8[100] = { "If my guess is correct, those giant bombs are not stable." };
char sts1_2_9[100] = { "If you stand on the same colored floor as a giant bomb while holding a shield," };
char sts1_2_9_2[100] = { "the shockwave generated by the shield's collision with the bomb can harm Dragon!" };
char sts2_2_1[100] = { "Ha... It seems that I underestimated you... But it won't be so easy from now on." };
char sts2_2_2[100] = { "Let me see how long you can hold on under the bombardment of giant bombs!!!" };
char sts2_2_3[100] = { "What??? He actually has other means to release the giant bomb? Prince, be careful to avoid!" };
char sts2_2_4[100] = { "I will! Be calm!" };
char sts2_3_1[100] = { "You really angered me... Now, if you don't take my bomb, prepare to taste the giant bomb!!!" };
char sts2_3_2[100] = { "Watch out! Dragon has used a new mechanism that is still in the experimental stage!" };
char sts2_3_3[100] = { "Attention! If his small bomb is not destroyed but passes through the laser barrier," };
char sts2_3_3_2[100] = { "the energy bar on the right will accumulate!" };
char sts2_3_4[100] = { "If the energy bar accumulates full, he will release a giant bomb in the next round!" };
char sts2_3_5[100] = { "I’ll destroy as many bombs as possible!" };

void iNIt_bOSs2()
{
    int i;
    diRECtiON_oF_laSeR = 0;
    Get_hUrt_2 = 0;
    bOSs_gOt_hURt = 0;
    plAYer_oN_whICh_fLOOr = 0;
    eNErgY_oF_ID_cARd = 0;
    shIEld_Or_nOt = 0;
    cOlOr_oF_bIg_bOMb = 0;
    Hp_oF_Bs = 100;
    Hp_oF_Py = 100;
    eNErgY_nEEdEd_fOr_IDCard = 20;
    coUNt_oF_bOSs_mOVemENt = 0;
    quit_2 = 0, mOveUp = 0, mOveDown = 0, mOveLeft = 0, mOveRight = 0;
    fight_2 = 1;
    ct_BOSS2 = 1;
    image_index_2 = 1;
    nUm_oF_bOMbs = 20;
    ID_Card_rEAdY_Or_nOt = 0;
    coUNt_oF_hEAl_2 = 0;
    iS_tHeRe_eXtRa_bOMbS = 0;
    iS_tHeRe_eXtRa_eXtRa_bOMbS = 0;
    atk_Scd_fOr_eXtRa_bOMbS = 0;
    wHerE_ATK = 0;
    eNErgY_oF_Missing_bOMbS = 0;
    bOSs_iS_dRoPPinG_bIg_bOMb = 0;
    bACk_tO_lASt_sCeNe_bOSs2 = 0;
    transparency_Gm_Ov_2 = 0;
    Bs_Hp = 100;
    Py_Hp = 100;
    Mix_PauseMusic();
    Health_Bar_Remain.x = 300;
    Health_Bar_Remain.w = 650;
    Health_Bar_Loss.w = 0;
    Health_Bar_Remain_BOSS.x = 325;
    Health_Bar_Remain_BOSS.w = 600;
    Health_Bar_Loss_BOSS.w = 0;
    image_index_2 = 1;
    atk_Round = 0;
    atk_Scd = 0;
    Get_hUrt = 0;
    bOSs_gOt_hURt = 0;
    shIEld_Or_nOt = 0;
    eNErgY_nEEdEd_fOr_IDCard = 20;
    eNErgY_oF_ID_cARd = 0;
    coUNt_oF_bOSs_mOVemENt = 0;
    for (i = 0; i < 40; i++)
    {
        imAGes_of_bOMbs[i] = 0;
        sHOw_bOMbs_oR_nOt[i] = 0;
    }
    for (i = 0; i < 45; i++)
    {
        eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] = 0 ;
    }
    for (i = 0; i < 4; i++)
    {
        eNErgY_fOr_flOOrS[i] = 0;
        nOt_oN_tHe_flOOr_aT_aLL[i] = 0;
    }
    iS_tHeRe_eXtRa_bOMbS = 0;
    iS_tHeRe_eXtRa_eXtRa_bOMbS = 0;
    bOSs_iS_dialogue_1_sts1 = 0;
    bOSs_iS_dialogue_2_sts1 = 0;
    bOSs_iS_dialogue_1_sts2 = 0;
    bOSs_iS_dialogue_2_sts2 = 0;
    bOSs_iS_dialogue_3_sts2 = 0;
    rECt_eXtRa_bIg_bOMbS[0].y = -200;
    rECt_eXtRa_bIg_bOMbS[1].y = -200;
    rECt_eXtRa_bIg_bOMbS[2].y = -200;
    wHerE_ATK = 0;
    eNErgY_oF_Missing_bOMbS = 0;
}

void cLeAn_All_iN_bOSs2()
{
    int i;
    for (i = 0; i < 6; i++)
    {
        SDL_FreeSurface(surf_Dialogue_pic[i]);
        SDL_DestroyTexture(txt_Dialogue_pic[i]);
    }
    for (i = 0; i < 2; i++)
    {
        SDL_FreeSurface(surf_background[i]);
        SDL_DestroyTexture(txt_background[i]);
    }
    for (i = 0; i < 2; i++)
    {
        SDL_FreeSurface(surf_aImInG_cRoSS[i]);
        SDL_DestroyTexture(txt_aImInG_cRoSS[i]);
    }
    for (i = 0; i < 4; i++)
    {
        SDL_FreeSurface(surf_hEAlEr_2[i]);
        SDL_DestroyTexture(txt_hEAlEr_2[i]);
    }
    for (i = 0; i < 16; i++)
    {
        SDL_FreeSurface(surfbomB[i]);
        SDL_DestroyTexture(txtbomB[i]);
    }
    for (i = 0; i < 4; i++)
    {
        SDL_FreeSurface(surf_arw_laser[i]);
        SDL_DestroyTexture(txt_arw_laser[i]);
    }
    for (i = 0; i < 6; i++)
    {
        SDL_FreeSurface(surf_bIg_bOMb[i]);
        SDL_DestroyTexture(txt_bIg_bOMb[i]);
    }
    for (i = 0; i < 2; i++)
    {
        SDL_FreeSurface(surf_bIg_bOMb_eXpLosIOn[i]);
        SDL_DestroyTexture(txt_bIg_bOMb_eXpLosIOn[i]);
    }
    for (i = 0; i < 6; i++)
    {
        SDL_FreeSurface(surf_IDCard[i]);
        SDL_DestroyTexture(txt_IDCard[i]);
    }
    for (i = 0; i < 3; i++)
    {
        SDL_FreeSurface(surfexplOOOsion[i]);
        SDL_DestroyTexture(txtexplOOOsion[i]);
    }
    for (i = 0; i < 108; i++)
    {
        SDL_FreeSurface(surfboss[i]);
        SDL_DestroyTexture(txtboss[i]);
    }
    SDL_FreeSurface(Shifter_BackGroundSurface_bOSs2);
    SDL_DestroyTexture(Shifter_BackGroundTexture_bOSs2);
    SDL_FreeSurface(surftt);
    SDL_DestroyTexture(txttt);
    SDL_FreeSurface(surfpyr);
    SDL_DestroyTexture(txtpyr);
    SDL_FreeSurface(surfhp);
    SDL_DestroyTexture(txthp);
    SDL_FreeSurface(surfshIEld);
    SDL_DestroyTexture(txtshIEld);
    SDL_FreeSurface(surffloor);
    SDL_DestroyTexture(txtfloor);
    SDL_FreeSurface(surffloor_F);
    SDL_DestroyTexture(txtfloor_F);
    SDL_FreeSurface(surffloor_F_B);
    SDL_DestroyTexture(txtfloor_F_B);
    SDL_FreeSurface(surffloor_I);
    SDL_DestroyTexture(txtfloor_I);
    SDL_FreeSurface(surffloor_I_B);
    SDL_DestroyTexture(txtfloor_I_B);
    SDL_FreeSurface(surffloor_S);
    SDL_DestroyTexture(txtfloor_S);
    SDL_FreeSurface(surffloor_S_B);
    SDL_DestroyTexture(txtfloor_S_B);
    SDL_FreeSurface(surffloor_T);
    SDL_DestroyTexture(txtfloor_T);
    SDL_FreeSurface(surffloor_T_B);
    SDL_DestroyTexture(txtfloor_T_B);
    SDL_FreeSurface(Game_Over_BackGroundSurface_bOSs2);
    SDL_DestroyTexture(Game_Over_BackGroundTexture_bOSs2);
}

int eXtRa_bIg_bOMbS(int atk_Scd_fOr_eXtRa_bOMbS, int atk_Round)
{
    if (atk_Scd_fOr_eXtRa_bOMbS < 60)
    {
        if (atk_Scd_fOr_eXtRa_bOMbS < 60 && atk_Scd_fOr_eXtRa_bOMbS > 50 || atk_Scd_fOr_eXtRa_bOMbS <= 40 && atk_Scd_fOr_eXtRa_bOMbS > 30 || atk_Scd_fOr_eXtRa_bOMbS <= 20 && atk_Scd_fOr_eXtRa_bOMbS > 10)
            SDL_RenderCopy(rdr1, txt_aImInG_cRoSS[0], NULL, &aTTaCk_aReA_oF_eXtRa_bIg_bOMbS[wHerE_ATK]);
        else if (atk_Scd_fOr_eXtRa_bOMbS <= 50 && atk_Scd_fOr_eXtRa_bOMbS > 40 || atk_Scd_fOr_eXtRa_bOMbS <= 30 && atk_Scd_fOr_eXtRa_bOMbS > 20 || atk_Scd_fOr_eXtRa_bOMbS <= 10 && atk_Scd_fOr_eXtRa_bOMbS >= 0)
            SDL_RenderCopy(rdr1, txt_aImInG_cRoSS[1], NULL, &aTTaCk_aReA_oF_eXtRa_bIg_bOMbS[wHerE_ATK]);
    }
    else if (atk_Scd_fOr_eXtRa_bOMbS <= 115)
    {
        rECt_eXtRa_bIg_bOMbS[wHerE_ATK].y += 9;
        SDL_RenderCopy(rdr1, txt_bIg_bOMb[5], NULL, &rECt_eXtRa_bIg_bOMbS[wHerE_ATK]);
    }
    else if (atk_Scd_fOr_eXtRa_bOMbS > 115 && atk_Scd_fOr_eXtRa_bOMbS < 125)
    {
        SDL_RenderCopy(rdr1, txt_bIg_bOMb_eXpLosIOn[2], NULL, &aTTaCk_aReA_oF_eXtRa_bIg_bOMbS[wHerE_ATK]);
    }
    if (atk_Scd_fOr_eXtRa_bOMbS == 116)
    {
        rECt_eXtRa_bIg_bOMbS[wHerE_ATK].y = -200;
        if (Player2.x < (aTTaCk_aReA_oF_eXtRa_bIg_bOMbS[wHerE_ATK].x + aTTaCk_aReA_oF_eXtRa_bIg_bOMbS[wHerE_ATK].w) && (Player2.x + Player2.w) > aTTaCk_aReA_oF_eXtRa_bIg_bOMbS[wHerE_ATK].x)
        {
            if (!Get_hUrt)
            {
                Py_Hp -= 20;
                Get_hUrt = 60;
            }
        }
    }
    if (atk_Scd_fOr_eXtRa_bOMbS == 124)
    { 
        atk_Scd_fOr_eXtRa_bOMbS = 0;
        if (wHerE_ATK < 2)
            wHerE_ATK++;
        else wHerE_ATK = 0;
    }
    else
        atk_Scd_fOr_eXtRa_bOMbS++;
    return atk_Scd_fOr_eXtRa_bOMbS;
}

int bIg_bOMb_iS_cOMiNG(int atk_Scd, int atk_Round)
{
    int i;
    if (atk_Scd == 0)
        cOlOr_oF_bIg_bOMb = ((Player2.x + Player2.y) * atk_Round) % 4;
    if (atk_Scd < 65)
    {
        bIg_bOMbS.y += 10;
        SDL_RenderCopy(rdr1, txt_bIg_bOMb[cOlOr_oF_bIg_bOMb], NULL, &bIg_bOMbS);
    }
    else if (atk_Scd >= 65 && atk_Scd < 70)
        SDL_RenderCopy(rdr1, txt_bIg_bOMb[4], NULL, &bIg_bOMbS); // pre-explosion
    if (atk_Scd >= 70 && atk_Scd < 80)
        SDL_RenderCopy(rdr1, txt_bIg_bOMb_eXpLosIOn[0], NULL, &fUll_sCrEEn2);
    else if (atk_Scd >= 80 && atk_Scd < 90)
        SDL_RenderCopy(rdr1, txt_bIg_bOMb_eXpLosIOn[1], NULL, &fUll_sCrEEn2);
    if (atk_Scd == 70)
    {
        if (shIEld_Or_nOt)
        {
            if (plAYer_oN_whICh_fLOOr == cOlOr_oF_bIg_bOMb + 1)
            {
                Bs_Hp -= 20;
                bOSs_gOt_hURt = 60;
            }
        }
        else
        {
            Py_Hp -= 20;
            Get_hUrt = 60;
            if(eNErgY_fOr_flOOrS[0] == -2 && eNErgY_fOr_flOOrS[1] == -2 && eNErgY_fOr_flOOrS[2] == -2 && eNErgY_fOr_flOOrS[3] == -2)
            {
                for (i = 0; i < 4; i++)
                {
                    eNErgY_fOr_flOOrS[i] = 0;
                }
            }
        }
    }
    atk_Scd++;
    return atk_Scd;
}

int On_The_Floor_Or_Not(int Circle_Center_x, int Circle_Center_y)
{
    if ((Player2.x + 5 - Circle_Center_x) * (Player2.x + 5 - Circle_Center_x) + (Player2.y + 5 - Circle_Center_y) * (Player2.y + 5 - Circle_Center_y) <= 3025)
        return 1;
    else
        return 0;
}

int bOMbs_Controller(int nUm_oF_bOMbs, int atk_Scd, int atk_Round)
{
    int i;
    int x_PosiTion[20] = { 235, 275, 315, 355, 395, 435, 475, 515, 555, 595, 635, 675, 715, 755, 795, 835, 875, 915, 955, 995 };
    if (!atk_Scd)
    {
        if (bOss_sTaTe)
            atk_mOd_oF_bOMbS = atk_Round % 3;
        else
            atk_mOd_oF_bOMbS = ((Player2.x + Player2.y) * atk_Round) % 4;
    }
    if (atk_mOd_oF_bOMbS == 3)
        atk_mOd_oF_bOMbS = 2;
    for (i = 0; i < nUm_oF_bOMbs; i++)
    {
        bOMbs[i].h = 20;
        bOMbs[i].w = 20;
        if (!atk_Scd)
        {
            bOMbs[i].y = 130 - (i * 40);
            imAGes_of_bOMbs[i] = atk_oRdEr_oF_bOMbS[atk_mOd_oF_bOMbS][i % 16];
        }
        else if (bOMbs[i].y <= Player2.y && !(sHOw_bOMbs_oR_nOt[i]) && bOMbs[i].y <= 580 && !eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i])
            bOMbs[i].y += 3; // 下落
        else if (!eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] && !(sHOw_bOMbs_oR_nOt[i]))
        {
            eXpLOOOOOOOOOOOsIoN[i].w = 100;
            eXpLOOOOOOOOOOOsIoN[i].h = 100;
            eXpLOOOOOOOOOOOsIoN[i].x = bOMbs[i].x - 40;
            eXpLOOOOOOOOOOOsIoN[i].y = bOMbs[i].y - 40;
            eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] = 70;
        }
        if (eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i])
        {
            if (eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] <= 70 && eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] > 60 || eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] <= 50 && eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] > 40 || eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] <= 30 && eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] > 20)
                SDL_RenderCopy(rdr1, txtexplOOOsion[0], NULL, &eXpLOOOOOOOOOOOsIoN[i]);
            else if (eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] <= 60 && eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] > 50 || eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] <= 40 && eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] > 30 || eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] <= 20 && eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] > 10)
                SDL_RenderCopy(rdr1, txtexplOOOsion[1], NULL, &eXpLOOOOOOOOOOOsIoN[i]);
            else if (eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] <= 10 && eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] > 0)
            {
                if (On_The_Floor_Or_Not(bOMbs[i].x + 10, bOMbs[i].y + 10) && !Get_hUrt)
                {
                    if (shIEld_Or_nOt == 1)
                        Get_hUrt = 61;
                    else
                        Get_hUrt = 60;
                    if (shIEld_Or_nOt)
                        shIEld_Or_nOt--;
                }
                SDL_RenderCopy(rdr1, txtexplOOOsion[2], NULL, &eXpLOOOOOOOOOOOsIoN[i]);
            }
            eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i]--;
            if (eXpLOOOOOOOOOOOsIoN_coUNtdOWn[i] == 0)
                sHOw_bOMbs_oR_nOt[i] = 1;
        }
        if (atk_oRdEr_oF_bOMbS[atk_mOd_oF_bOMbS][i % 16] % 4 == diRECtiON_oF_laSeR - 1)
            if (bOMbs[i].y < 400 && bOMbs[i].y + 20 > 380)
            {
                if (imAGes_of_bOMbs[i] >= (plAYer_oN_whICh_fLOOr - 1) * 4 && imAGes_of_bOMbs[i] < (plAYer_oN_whICh_fLOOr) * 4 && !(sHOw_bOMbs_oR_nOt[i]) && !(shIEld_Or_nOt) && !bOss_sTaTe)
                    eNErgY_oF_ID_cARd++; // 对应颜色加能量（状态1）
                if (bOss_sTaTe && !(sHOw_bOMbs_oR_nOt[i]) && eNErgY_oF_ID_cARd < 36)
                    eNErgY_oF_ID_cARd++;
                sHOw_bOMbs_oR_nOt[i] = 1;
            }
        if (i < 20)
            bOMbs[i].x = x_PosiTion[i % 20];
        else
            bOMbs[i].x = x_PosiTion[19 - (i % 20)];
        if (!(sHOw_bOMbs_oR_nOt[i]))
            SDL_RenderCopy(rdr1, txtbomB[imAGes_of_bOMbs[i]], NULL, &bOMbs[i]);
        if (bOMbs[i].y == 401 && !sHOw_bOMbs_oR_nOt[i] && iS_tHeRe_eXtRa_eXtRa_bOMbS && eNErgY_oF_Missing_bOMbS < 20)
            eNErgY_oF_Missing_bOMbS++;
    }
    atk_Scd++;
    return atk_Scd;
}

int Boss2(int ct) // Boss图像
{
    if (ct == 109)
        ct = 1;
    if (coUNt_oF_bOSs_mOVemENt == 959)
        coUNt_oF_bOSs_mOVemENt = 0;
    else coUNt_oF_bOSs_mOVemENt++;
    BoSs2.x += x_mOVemENt_oF_bOSs[coUNt_oF_bOSs_mOVemENt % 192];
    BoSs2.y += y_mOVemENt_oF_bOSs[coUNt_oF_bOSs_mOVemENt % 240];
    SDL_RenderCopy(rdr1, txtboss[ct - 1], NULL, &BoSs2);
    if (hOw_lONg_boSs_iMaGe)
    {
        hOw_lONg_boSs_iMaGe--;
        return ct;
    }
    else
    {
        ct++;
        hOw_lONg_boSs_iMaGe = 5;
        return ct;
    }
}

void TestText_2(int image_index) // 对话框
{
    SDL_RenderCopy(rdr1, txttt, NULL, &TestTExt2);
}

int bOss2_For_dRaGoN(int sTaTe_oF_bOSs)
{
    int i;
    bOss_sTaTe = sTaTe_oF_bOSs;
    //bOss_sTaTe = 0; //used for debug
    //if (SDL_Init(SDL_INIT_EVERYTHING) != 0) // 初始化
    //{
    //    SDL_Log("Init failed: %s", SDL_GetError());
    //    return -1;
    //}
    //if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    //{
    //    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    //    return -1;
    //}
    //win = SDL_CreateWindow("DEMO02", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, 0); // 创建窗口
    //rdr1 = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);  // 创建渲染器

    surf_Dialogue_pic[0] = IMG_Load("Files For BOSS2/dialogue pic/Picture bombs.png"); // dia pic 1
    txt_Dialogue_pic[0] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic[0]);
    surf_Dialogue_pic[1] = IMG_Load("Files For BOSS2/dialogue pic/Picture floors.png"); // dia pic 2
    txt_Dialogue_pic[1] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic[1]);
    surf_Dialogue_pic[2] = IMG_Load("Files For BOSS2/dialogue pic/Picture floors 2.png"); // dia pic 3
    txt_Dialogue_pic[2] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic[2]);
    surf_Dialogue_pic[3] = IMG_Load("Files For BOSS2/dialogue pic/Picture extra bombs.png"); // dia pic 4
    txt_Dialogue_pic[3] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic[3]);
    surf_Dialogue_pic[4] = IMG_Load("Files For BOSS2/dialogue pic/Picture big bombs.png"); // dia pic 5
    txt_Dialogue_pic[4] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic[4]);
    surf_Dialogue_pic[5] = IMG_Load("Files For BOSS2/dialogue pic/Picture extra extra bombs.png"); // dia pic 6
    txt_Dialogue_pic[5] = SDL_CreateTextureFromSurface(rdr1, surf_Dialogue_pic[5]);
    surf_IDCard[0] = IMG_Load("Files For BOSS2/ID Card For BOSS2/ID Card For BOSS2 0.png"); // IDCARD1
    txt_IDCard[0] = SDL_CreateTextureFromSurface(rdr1, surf_IDCard[0]);
    surf_IDCard[1] = IMG_Load("Files For BOSS2/ID Card For BOSS2/ID Card For BOSS2 1.png"); // IDCARD2
    txt_IDCard[1] = SDL_CreateTextureFromSurface(rdr1, surf_IDCard[1]);
    surf_IDCard[2] = IMG_Load("Files For BOSS2/ID Card For BOSS2/ID Card For BOSS2 2.png"); // IDCARD for sts2 1
    txt_IDCard[2] = SDL_CreateTextureFromSurface(rdr1, surf_IDCard[2]);
    surf_IDCard[3] = IMG_Load("Files For BOSS2/ID Card For BOSS2/ID Card For BOSS2 3.png"); // IDCARD for sts2 2
    txt_IDCard[3] = SDL_CreateTextureFromSurface(rdr1, surf_IDCard[3]);
    surf_IDCard[4] = IMG_Load("Files For BOSS2/ID Card For BOSS2/ID Card For BOSS2 4.png"); // IDCARD for sts2 3
    txt_IDCard[4] = SDL_CreateTextureFromSurface(rdr1, surf_IDCard[4]);
    surf_IDCard[5] = IMG_Load("Files For BOSS2/ID Card For BOSS2/ID Card For BOSS2 5.png"); // IDCARD for sts2 4
    txt_IDCard[5] = SDL_CreateTextureFromSurface(rdr1, surf_IDCard[5]);
    surf_hEAlEr_2[0] = IMG_Load("Files For BOSS2/Healer/Healer 0.png"); // Healer CD 0
    txt_hEAlEr_2[0] = SDL_CreateTextureFromSurface(rdr1, surf_hEAlEr_2[0]);
    surf_hEAlEr_2[1] = IMG_Load("Files For BOSS2/Healer/Healer 1.png"); // Healer CD 1
    txt_hEAlEr_2[1] = SDL_CreateTextureFromSurface(rdr1, surf_hEAlEr_2[1]);
    surf_hEAlEr_2[2] = IMG_Load("Files For BOSS2/Healer/Healer 2.png"); // Healer CD 2
    txt_hEAlEr_2[2] = SDL_CreateTextureFromSurface(rdr1, surf_hEAlEr_2[2]);
    surf_hEAlEr_2[3] = IMG_Load("Files For BOSS2/Healer/Healer 3.png"); // Healer CD 3
    txt_hEAlEr_2[3] = SDL_CreateTextureFromSurface(rdr1, surf_hEAlEr_2[3]);
    surfexplOOOsion[0] = IMG_Load("Files For BOSS2/explosion01.png"); // 爆炸延时
    txtexplOOOsion[0] = SDL_CreateTextureFromSurface(rdr1, surfexplOOOsion[0]);
    surfexplOOOsion[1] = IMG_Load("Files For BOSS2/explosion02.png"); // 爆炸延时
    txtexplOOOsion[1] = SDL_CreateTextureFromSurface(rdr1, surfexplOOOsion[1]);
    surfexplOOOsion[2] = IMG_Load("Files For BOSS2/explosion03.png"); // 爆炸延时
    txtexplOOOsion[2] = SDL_CreateTextureFromSurface(rdr1, surfexplOOOsion[2]);
    surf_bIg_bOMb[0] = IMG_Load("Files For BOSS2/BIG BOMBS/BIG BOMB 1.png"); // BIG BOMB 1
    txt_bIg_bOMb[0] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb[0]);
    surf_bIg_bOMb[1] = IMG_Load("Files For BOSS2/BIG BOMBS/BIG BOMB 2.png"); // BIG BOMB 2
    txt_bIg_bOMb[1] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb[1]);
    surf_bIg_bOMb[2] = IMG_Load("Files For BOSS2/BIG BOMBS/BIG BOMB 3.png"); // BIG BOMB 3
    txt_bIg_bOMb[2] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb[2]);
    surf_bIg_bOMb[3] = IMG_Load("Files For BOSS2/BIG BOMBS/BIG BOMB 4.png"); // BIG BOMB 4
    txt_bIg_bOMb[3] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb[3]);
    surf_bIg_bOMb[4] = IMG_Load("Files For BOSS2/BIG BOMBS/BIG BOMB 5.png"); // BIG BOMB 5
    txt_bIg_bOMb[4] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb[4]);
    surf_bIg_bOMb[5] = IMG_Load("Files For BOSS2/BIG BOMBS/BIG BOMB 6.png"); // BIG BOMB 6
    txt_bIg_bOMb[5] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb[5]);
    surf_bIg_bOMb_eXpLosIOn[0] = IMG_Load("Files For BOSS2/BIG BOMBS/BIGBOMBEXPLOSION1.png"); // BIG BOMB EXP 1
    txt_bIg_bOMb_eXpLosIOn[0] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb_eXpLosIOn[0]);
    surf_bIg_bOMb_eXpLosIOn[1] = IMG_Load("Files For BOSS2/BIG BOMBS/BIGBOMBEXPLOSION2.png"); // BIG BOMB EXP 2
    txt_bIg_bOMb_eXpLosIOn[1] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb_eXpLosIOn[1]);
    surf_bIg_bOMb_eXpLosIOn[2] = IMG_Load("Files For BOSS2/BIG BOMBS/EXTRABIGBOMBEXPLOSION.png"); // EXTRA BIG BOMB EXP
    txt_bIg_bOMb_eXpLosIOn[2] = SDL_CreateTextureFromSurface(rdr1, surf_bIg_bOMb_eXpLosIOn[2]);
    surf_background[0] = IMG_Load("Files For BOSS2/background for BOSS2 above.png"); // 背景
    txt_background[0] = SDL_CreateTextureFromSurface(rdr1, surf_background[0]);
    surf_background[1] = IMG_Load("Files For BOSS2/background for BOSS2 below.png"); // 背景
    txt_background[1] = SDL_CreateTextureFromSurface(rdr1, surf_background[1]);
    surf_aImInG_cRoSS[0] = IMG_Load("Files For BOSS2/Aiming cross/Aiming cross 1.png"); // Aiming Cross
    txt_aImInG_cRoSS[0] = SDL_CreateTextureFromSurface(rdr1, surf_aImInG_cRoSS[0]);
    surf_aImInG_cRoSS[1] = IMG_Load("Files For BOSS2/Aiming cross/Aiming cross 2.png"); // Aiming Cross
    txt_aImInG_cRoSS[1] = SDL_CreateTextureFromSurface(rdr1, surf_aImInG_cRoSS[1]);
    Shifter_BackGroundSurface_bOSs2 = IMG_Load("Files For BOSS2/FULL BLACK.png"); // BLACK
    Shifter_BackGroundTexture_bOSs2 = SDL_CreateTextureFromSurface(rdr1, Shifter_BackGroundSurface_bOSs2);
    surfhp = IMG_Load("Files For BOSS2/HP Bar.png"); // 血条
    txthp = SDL_CreateTextureFromSurface(rdr1, surfhp);
    surffloor = IMG_Load("Files For BOSS2/floor.png"); // 地板
    txtfloor = SDL_CreateTextureFromSurface(rdr1, surffloor);
    surffloor_F = IMG_Load("Files For BOSS2/Floor Fire.png"); // 火地板
    txtfloor_F = SDL_CreateTextureFromSurface(rdr1, surffloor_F);
    surffloor_T = IMG_Load("Files For BOSS2/Floor Thunder.png"); // 雷地板
    txtfloor_T = SDL_CreateTextureFromSurface(rdr1, surffloor_T);
    surffloor_I = IMG_Load("Files For BOSS2/Floor Ice.png"); // 冰地板
    txtfloor_I = SDL_CreateTextureFromSurface(rdr1, surffloor_I);
    surffloor_S = IMG_Load("Files For BOSS2/Floor Stone.png"); // 岩地板
    txtfloor_S = SDL_CreateTextureFromSurface(rdr1, surffloor_S);
    surffloor_F_B = IMG_Load("Files For BOSS2/Floor Fire Bright.png"); // 火亮地板
    txtfloor_F_B = SDL_CreateTextureFromSurface(rdr1, surffloor_F_B);
    surffloor_T_B = IMG_Load("Files For BOSS2/Floor Thunder Bright.png"); // 雷亮地板
    txtfloor_T_B = SDL_CreateTextureFromSurface(rdr1, surffloor_T_B);
    surffloor_I_B = IMG_Load("Files For BOSS2/Floor Ice Bright.png"); // 冰亮地板
    txtfloor_I_B = SDL_CreateTextureFromSurface(rdr1, surffloor_I_B);
    surffloor_S_B = IMG_Load("Files For BOSS2/Floor Stone Bright.png"); // 岩亮地板
    txtfloor_S_B = SDL_CreateTextureFromSurface(rdr1, surffloor_S_B);
    surfpyr_hURt = IMG_Load("Files For BOSS2/spr_heart_1.png"); // 设置玩家（受伤）
    txtpyr_hURt = SDL_CreateTextureFromSurface(rdr1, surfpyr_hURt);
    surfpyr = IMG_Load("Files For BOSS2/spr_heart_0.png"); // 设置玩家
    txtpyr = SDL_CreateTextureFromSurface(rdr1, surfpyr);
    surfshIEld = IMG_Load("Files For BOSS2/shield.png"); // 设置护盾
    txtshIEld = SDL_CreateTextureFromSurface(rdr1, surfshIEld);
    surf_bOSs_gOt_hURt = IMG_Load("Files For BOSS2/BOSS2 image/BOSS2 GOT HURT.png"); // BOSS受伤特效
    txt_bOSs_gOt_hURt = SDL_CreateTextureFromSurface(rdr1, surf_bOSs_gOt_hURt);
    Game_Over_BackGroundSurface_bOSs2 = IMG_Load("assets/Ingame/GameOver.png"); // GW
    Game_Over_BackGroundTexture_bOSs2 = SDL_CreateTextureFromSurface(rdr1, Game_Over_BackGroundSurface_bOSs2);
    for (i = 0; i < 108; i++) // 加载BOSS
    {
        SDL_snprintf(file_OF_bOSs, sizeof(file_OF_bOSs), "Files For BOSS2/BOSS2 image/BOSS2 %d.png", (i + 1));
        surfboss[i] = IMG_Load(file_OF_bOSs);
        txtboss[i] = SDL_CreateTextureFromSurface(rdr1, surfboss[i]);
    }
    for (i = 0; i < 16; i++) // 加载炸弹
    {
        SDL_snprintf(file_OF_bombs, sizeof(file_OF_bombs), "Files For BOSS2/Arrows/aRRow_%d.png", (i + 1));
        surfbomB[i] = IMG_Load(file_OF_bombs);
        txtbomB[i] = SDL_CreateTextureFromSurface(rdr1, surfbomB[i]);
    }
    for (i = 0; i < 4; i++)
    {
        SDL_snprintf(file_OF_laSeR, sizeof(file_OF_laSeR), "Files For BOSS2/Arrows/laSeR_aRRow_%d.png", (i + 1));
        surf_arw_laser[i] = IMG_Load(file_OF_laSeR);
        txt_arw_laser[i] = SDL_CreateTextureFromSurface(rdr1, surf_arw_laser[i]);
    }
    for (i = 0; i < 5; i++)
    {
        surftt = IMG_Load("Files For BOSS2/test text/test text05.png");
        txttt = SDL_CreateTextureFromSurface(rdr1, surftt);
        SDL_RenderCopy(rdr1, txttt, NULL, &TestTExt2);
    }

    SDL_Event event;

    BOSS_BGM2 = Mix_LoadMUS("Files For BOSS2/BOSS02.wav");
    Mix_PlayMusic(BOSS_BGM2, -1);

    font_bOSs2 = TTF_OpenFont("assets/Font/Allan-Regular.ttf", 50);

    while (!quit_2)
    {
        Uint64 start_t = 0, end_t = 0;
        int delay;
        if (!fight_2)
        {
            mOveUp = 0;
            mOveDown = 0;
            mOveLeft = 0;
            mOveRight = 0;
            Player2.x = 500;
            Player2.y = 420;
        }
        // 处理事件
        while (SDL_PollEvent(&event))
        {
            if (fight_2 == 0)
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    quit_2 = 1;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x >= 600 && x <= 650 && y >= 300 && y <= 350) // 进入战斗
                        {
                            fight_2 = 1;
                            GmOr_2 = 0;
                            GmWn_2= 0;
                            Mix_PlayMusic(BOSS_BGM2, -1);
                        }
                    }
                    break;
                default:
                    break;
                }
            }
            if (fight_2 == 1)
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    quit_2 = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        Pause();
                        break;
                    case SDLK_w:
                        mOveUp = 1;
                        break;
                    case SDLK_a:
                        mOveLeft = 1;
                        break;
                    case SDLK_s:
                        mOveDown = 1;
                        break;
                    case SDLK_d:
                        mOveRight = 1;
                        break;
                    case SDLK_SPACE: // 对话进行
                        image_index_2++;
                        break;
                    case SDLK_e:
                        if (ID_Card_rEAdY_Or_nOt && !bOss_sTaTe)
                        {
                            shIEld_Or_nOt = 5;
                            ID_Card_rEAdY_Or_nOt = 0;
                            eNErgY_oF_ID_cARd = 0;
                            eNErgY_Of_ID_CaRd.w = 0;
                            stILL_nOt_eNErgY_Of_ID_CaRd.x = 100;
                            stILL_nOt_eNErgY_Of_ID_CaRd.w = 80;
                        }
                        else if (bOss_sTaTe)
                        {
                            if (!(nOt_oN_tHe_flOOr_aT_aLL[0] * nOt_oN_tHe_flOOr_aT_aLL[1] * nOt_oN_tHe_flOOr_aT_aLL[2] * nOt_oN_tHe_flOOr_aT_aLL[3]) && eNErgY_oF_ID_cARd >= 12 && eNErgY_fOr_flOOrS[plAYer_oN_whICh_fLOOr - 1] < 2)
                            {
                                if (eNErgY_oF_ID_cARd >= 12 && eNErgY_oF_ID_cARd < 36)
                                    eNErgY_oF_ID_cARd -= 12;
                                if (eNErgY_oF_ID_cARd >= 36)
                                    eNErgY_oF_ID_cARd = 24;
                                eNErgY_fOr_flOOrS[plAYer_oN_whICh_fLOOr - 1] += 2;
                            }
                        }
                        break;
                    case SDLK_UP:
                        if (image_index_2 > 1 && !(diRECtiON_oF_laSeR))
                            diRECtiON_oF_laSeR = 1;
                        break;
                    case SDLK_DOWN:
                        if (image_index_2 > 1 && !(diRECtiON_oF_laSeR))
                            diRECtiON_oF_laSeR = 2;
                        break;
                    case SDLK_LEFT:
                        if (image_index_2 > 1 && !(diRECtiON_oF_laSeR))
                            diRECtiON_oF_laSeR = 3;
                        break;
                    case SDLK_RIGHT:
                        if (image_index_2 > 1 && !(diRECtiON_oF_laSeR))
                            diRECtiON_oF_laSeR = 4;
                        break;
                    default:
                        break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_w:
                        mOveUp = 0;
                        break;
                    case SDLK_a:
                        mOveLeft = 0;
                        break;
                    case SDLK_s:
                        mOveDown = 0;
                        break;
                    case SDLK_d:
                        mOveRight = 0;
                        break;
                    case SDLK_UP:
                        if (image_index_2 > 1)
                            diRECtiON_oF_laSeR = 0;
                        break;
                    case SDLK_DOWN:
                        if (image_index_2 > 1)
                            diRECtiON_oF_laSeR = 0;
                        break;
                    case SDLK_LEFT:
                        if (image_index_2 > 1)
                            diRECtiON_oF_laSeR = 0;
                        break;
                    case SDLK_RIGHT:
                        if (image_index_2 > 1)
                            diRECtiON_oF_laSeR = 0;
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
        if (mOveUp == 1 && Player2.y >= 400)
        {
            Player2.y -= 5;
            if (Player2.y < 400)
                Player2.y = 400;
        }
        if (mOveDown == 1 && Player2.y <= 620)
        {
            Player2.y += 5;
            if (Player2.y > 620)
                Player2.y = 620;
        }
        if (mOveLeft == 1 && Player2.x >= 200)
        {
            Player2.x -= 5;
            if (Player2.x < 200)
                Player2.x = 200;
        }
        if (mOveRight == 1 && Player2.x <= 1040)
        {
            Player2.x += 5;
            if (Player2.x > 1040)
                Player2.x = 1040;
        }
        fUll_sCrEEn_fOr_bAcKgRoUNd[0].x -= 1;
        fUll_sCrEEn_fOr_bAcKgRoUNd[1].x -= 1;
        fUll_sCrEEn_fOr_bAcKgRoUNd[2].x -= 2;
        fUll_sCrEEn_fOr_bAcKgRoUNd[3].x -= 2;
        for (i = 0; i < 4; i++)
        {
            if (fUll_sCrEEn_fOr_bAcKgRoUNd[i].x <= -1250)
                fUll_sCrEEn_fOr_bAcKgRoUNd[i].x = 1250;
        }
        // 渲染
        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
        SDL_RenderClear(rdr1);
        SDL_RenderCopy(rdr1, txt_background[0], NULL, &fUll_sCrEEn_fOr_bAcKgRoUNd[0]); // 背景
        SDL_RenderCopy(rdr1, txt_background[0], NULL, &fUll_sCrEEn_fOr_bAcKgRoUNd[1]); // 背景
        SDL_RenderCopy(rdr1, txt_background[1], NULL, &fUll_sCrEEn_fOr_bAcKgRoUNd[2]); // 背景
        SDL_RenderCopy(rdr1, txt_background[1], NULL, &fUll_sCrEEn_fOr_bAcKgRoUNd[3]); // 背景
        ct = Boss2(ct);
        switch (fight_2)
        {
        case 0:
            SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255); // 按钮
            SDL_RenderFillRect(rdr1, &Bottum2);
            break;
        case 1:
            SDL_RenderCopy(rdr1, txtfloor, NULL, &Floor2); // 还是地板
            if (On_The_Floor_Or_Not(400, 480))
            {
                SDL_RenderCopy(rdr1, txtfloor_F_B, NULL, &Floor_Fire);
                plAYer_oN_whICh_fLOOr = 1;
                nOt_oN_tHe_flOOr_aT_aLL[0] = 0;
            }
            else
            {
                SDL_RenderCopy(rdr1, txtfloor_F, NULL, &Floor_Fire);
                nOt_oN_tHe_flOOr_aT_aLL[0] = 1;
            }
            if (On_The_Floor_Or_Not(545, 490))
            {
                SDL_RenderCopy(rdr1, txtfloor_T_B, NULL, &Floor_Thunder);
                plAYer_oN_whICh_fLOOr = 2;
                nOt_oN_tHe_flOOr_aT_aLL[1] = 0;
            }
            else
            {
                SDL_RenderCopy(rdr1, txtfloor_T, NULL, &Floor_Thunder);
                nOt_oN_tHe_flOOr_aT_aLL[1] = 1;
            }
            if (On_The_Floor_Or_Not(705, 490))
            {
                SDL_RenderCopy(rdr1, txtfloor_I_B, NULL, &Floor_Ice);
                plAYer_oN_whICh_fLOOr = 3;
                nOt_oN_tHe_flOOr_aT_aLL[2] = 0;
            }
            else
            {
                SDL_RenderCopy(rdr1, txtfloor_I, NULL, &Floor_Ice);
                nOt_oN_tHe_flOOr_aT_aLL[2] = 1;
            }
            if (On_The_Floor_Or_Not(850, 480))
            {
                SDL_RenderCopy(rdr1, txtfloor_S_B, NULL, &Floor_Stone);
                plAYer_oN_whICh_fLOOr = 4;
                nOt_oN_tHe_flOOr_aT_aLL[3] = 0;
            }
            else
            {
                SDL_RenderCopy(rdr1, txtfloor_S, NULL, &Floor_Stone);
                nOt_oN_tHe_flOOr_aT_aLL[3] = 1;
            }
            if (Get_hUrt <= 60 && Get_hUrt > 50 || Get_hUrt <= 40 && Get_hUrt > 30 || Get_hUrt <= 20 && Get_hUrt > 10)
                SDL_RenderCopy(rdr1, txtpyr_hURt, NULL, &Player2);
            else if (Get_hUrt <= 50 && Get_hUrt > 40 || Get_hUrt <= 30 && Get_hUrt > 20 || Get_hUrt <= 10 && Get_hUrt >= 0)
                SDL_RenderCopy(rdr1, txtpyr, NULL, &Player2);
            if (shIEld_Or_nOt && !bOss_sTaTe)
            {
                sHieLD.x = Player2.x - 20;
                sHieLD.y = Player2.y - 20;
                sHieLD.w = 50;
                sHieLD.h = 50;
                SDL_RenderCopy(rdr1, txtshIEld, NULL, &sHieLD);
            }

            if (bOss_sTaTe)
            {
                for (i = 0; i < 4; i++) // 给地板下面的能量条涂色
                {
                    switch (eNErgY_fOr_flOOrS[i])
                    {
                    case 2:
                        SDL_SetRenderDrawColor(rdr1, 0, 255, 0, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][0]);
                        SDL_SetRenderDrawColor(rdr1, 0, 255, 0, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][1]);
                        break;
                    case 1:
                        SDL_SetRenderDrawColor(rdr1, 0, 255, 0, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][0]);
                        SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][1]);
                        break;
                    case 0:
                        SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][0]);
                        SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][1]);
                        break;
                    case -1:
                        SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][0]);
                        SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][1]);
                        break;
                    case -2:
                        SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][0]);
                        SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255);
                        SDL_RenderFillRect(rdr1, &eNErgY_oF_flOOrS[i][1]);
                        break;
                    default:
                        break;
                    }
                }
            }
            SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255); // 激光
            SDL_RenderFillRect(rdr1, &LaSer);
            if (image_index_2 > 1)
            {
                if (!bOss_sTaTe) // BOSS为第一状态
                {
                    if (atk_Round % 4 == 3)
                    {
                        atk_Scd = bIg_bOMb_iS_cOMiNG(atk_Scd, atk_Round);
                        if (atk_Scd == 90)
                        {
                            shIEld_Or_nOt = 0;
                            atk_Scd = 0;
                            image_index_2 = 1;
                            diRECtiON_oF_laSeR = 0;
                            atk_Round++;
                            if (coUNt_oF_hEAl_2)
                                coUNt_oF_hEAl_2--;
                            bIg_bOMbS.y = -200;
                        }
                    }
                    else
                    {
                        SDL_RenderCopy(rdr1, txt_arw_laser[diRECtiON_oF_laSeR - 1], NULL, &aRRoW_laSeR);
                        atk_Scd = bOMbs_Controller(nUm_oF_bOMbs, atk_Scd, atk_Round);
                        for (i = 0; i < nUm_oF_bOMbs; i++)
                            if (sHOw_bOMbs_oR_nOt[i] == 0)
                                eNd_oF_AroUNd = 0;
                        if (eNd_oF_AroUNd)
                        {
                            for (i = 0; i < nUm_oF_bOMbs; i++)
                            {
                                sHOw_bOMbs_oR_nOt[i] = 0;
                            }
                            if (nUm_oF_bOMbs < 40)
                                nUm_oF_bOMbs += 4;
                            atk_Scd = 0;
                            image_index_2 = 1;
                            diRECtiON_oF_laSeR = 0;
                            atk_Round++;
                            if (coUNt_oF_hEAl_2)
                                coUNt_oF_hEAl_2--;
                        }
                        eNd_oF_AroUNd = 1;
                    }
                }
                else // BOSS为第二状态
                {
                    if (!atk_Scd && ((eNErgY_fOr_flOOrS[0] == -2 && eNErgY_fOr_flOOrS[1] == -2 && eNErgY_fOr_flOOrS[2] == -2 && eNErgY_fOr_flOOrS[3] == -2) || eNErgY_oF_Missing_bOMbS == 20))
                    {
                        bOSs_iS_dRoPPinG_bIg_bOMb = 1;
                    }
                    if(bOSs_iS_dRoPPinG_bIg_bOMb)
                    {
                        atk_Scd = bIg_bOMb_iS_cOMiNG(atk_Scd, atk_Round);
                        if (atk_Scd == 90)
                        {
                            shIEld_Or_nOt = 0;
                            atk_Scd = 0;
                            image_index_2 = 1;
                            diRECtiON_oF_laSeR = 0;
                            atk_Round++;
                            atk_Scd_fOr_eXtRa_bOMbS = 0;
                            if (Bs_Hp <= 60)
                                iS_tHeRe_eXtRa_bOMbS = 1;
                            if (Bs_Hp <= 20)
                                iS_tHeRe_eXtRa_eXtRa_bOMbS = 1;
                            if (coUNt_oF_hEAl_2)
                                coUNt_oF_hEAl_2--;
                            bIg_bOMbS.y = -200;
                            eNErgY_oF_Missing_bOMbS = 0;
                            bOSs_iS_dRoPPinG_bIg_bOMb = 0;
                        }
                    }
                    else
                    {
                        SDL_RenderCopy(rdr1, txt_arw_laser[diRECtiON_oF_laSeR - 1], NULL, &aRRoW_laSeR);
                        if (iS_tHeRe_eXtRa_bOMbS)
                            atk_Scd_fOr_eXtRa_bOMbS = eXtRa_bIg_bOMbS(atk_Scd_fOr_eXtRa_bOMbS, atk_Round);
                        atk_Scd = bOMbs_Controller(nUm_oF_bOMbs, atk_Scd, atk_Round);
                        for (i = 0; i < nUm_oF_bOMbs; i++)
                            if (sHOw_bOMbs_oR_nOt[i] == 0)
                                eNd_oF_AroUNd = 0;
                        if (eNd_oF_AroUNd)
                        {
                            for (i = 0; i < nUm_oF_bOMbs; i++)
                            {
                                sHOw_bOMbs_oR_nOt[i] = 0;
                            }
                            if (nUm_oF_bOMbs < 40)
                                nUm_oF_bOMbs += 4;
                            atk_Scd = 0;
                            image_index_2 = 1;
                            diRECtiON_oF_laSeR = 0;
                            atk_Round++;
                            atk_Scd_fOr_eXtRa_bOMbS = 0;
                            if (Bs_Hp <= 60)
                                iS_tHeRe_eXtRa_bOMbS = 1;
                            if (Bs_Hp <= 20)
                                iS_tHeRe_eXtRa_eXtRa_bOMbS = 1;
                            rECt_eXtRa_bIg_bOMbS[0].y = -200;
                            rECt_eXtRa_bIg_bOMbS[1].y = -200;
                            rECt_eXtRa_bIg_bOMbS[2].y = -200;
                            if (coUNt_oF_hEAl_2)
                                coUNt_oF_hEAl_2--;
                            for (i = 0; i < 4; i++)
                            {
                                if (eNErgY_fOr_flOOrS[i] > -2)
                                {
                                    eNErgY_fOr_flOOrS[i] -= 2;
                                    i = 4;
                                }
                            }
                        }
                        eNd_oF_AroUNd = 1;
                    }
                    if (eNErgY_fOr_flOOrS[0] == 2 && eNErgY_fOr_flOOrS[1] == 2 && eNErgY_fOr_flOOrS[2] == 2 && eNErgY_fOr_flOOrS[3] == 2)
                    {
                        Bs_Hp -= 20;
                        bOSs_gOt_hURt = 60;
                        for (i = 0; i < 4; i++)
                        {
                            eNErgY_fOr_flOOrS[i] = 0;
                        }
                    }
                }
            }
            else
            {
                TestText_2(image_index_2);
                if (Py_Hp < 100 && !coUNt_oF_hEAl_2)
                {
                    coUNt_oF_hEAl_2 = 3;
                    Py_Hp += 10;
                }
                if (!bOss_sTaTe && atk_Round_2 == 0 && !bOSs_iS_dialogue_1_sts1)
                {
                    SDL_RenderCopy(rdr1, Shifter_BackGroundTexture_bOSs2, NULL, &fUll_sCrEEn2);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts1or2_1_1, Blank_bOSs2, bOSs2_Dragon, (char*)"Avatars/Dragon.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_2, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_3, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_4, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_5, sts1or2_1_6, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_7, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_8, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_9, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic[0], NULL, &rECt_dialogue_pic);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts1or2_1_10, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_11, sts1or2_1_12, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_13, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_14, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_15, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_16, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_17, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_18, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic[0], NULL, &rECt_dialogue_pic);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts1_1_19, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_20, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_21, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_22, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_23, sts1_1_23_2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_24, sts1_1_24_2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_25, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_26, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_27, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_1_28, Blank_bOSs2, bOSs2_Emma, (char*)"Avatars/Emma.png");
                    present(win, rdr1, font_bOSs2, sts1_1_29, Blank_bOSs2, bOSs2_Prince, (char*)"Avatars/Prince.png");
                    present(win, rdr1, font_bOSs2, sts1_1_30, Blank_bOSs2, bOSs2_Dragon, (char*)"Avatars/Dragon.png");
                    if (presentstate == 0)
                    {
                        Mix_FreeMusic(BOSS_BGM2);
                        Mix_CloseAudio();
                        iNIt_bOSs2();
                        cLeAn_All_iN_bOSs2();
                        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                        SDL_RenderClear(rdr1);
                        return 0;
                    }
                    bOSs_iS_dialogue_1_sts1 = 1;
                    mOveUp = 0, mOveDown = 0, mOveLeft = 0, mOveRight = 0;
                }
                if (bOss_sTaTe && atk_Round_2 == 0 && !bOSs_iS_dialogue_1_sts2)
                {
                    SDL_RenderCopy(rdr1, Shifter_BackGroundTexture_bOSs2, NULL, &fUll_sCrEEn2);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts1or2_1_1, Blank_bOSs2, bOSs2_Dragon, (char*)"Avatars/Dragon.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_2, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_3, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_4, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_5, sts1or2_1_6, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_7, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_8, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_9, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic[0], NULL, &rECt_dialogue_pic);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts1or2_1_10, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_11, sts1or2_1_12, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_13, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_14, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_15, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_16, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_17, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1or2_1_18, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic[2], NULL, &rECt_dialogue_pic);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts2_1_19, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_20, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_21, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_22, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_23, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_24, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_25, sts2_1_25_2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_26, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_27, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_28, sts2_1_28_2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_29, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_1_30, sts2_1_30_2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts2_1_31, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts2_1_32, sts2_1_32_2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts2_1_33, Blank_bOSs2, bOSs2_Emma, (char*)"Avatars/Emma.png");
                    present(win, rdr1, font_bOSs2, sts2_1_34, Blank_bOSs2, bOSs2_Prince, (char*)"Avatars/Prince.png");
                    present(win, rdr1, font_bOSs2, sts2_1_35, Blank_bOSs2, bOSs2_Dragon, (char*)"Avatars/Dragon.png");
                    if (presentstate == 0)
                    {
                        Mix_FreeMusic(BOSS_BGM2);
                        Mix_CloseAudio();
                        iNIt_bOSs2();
                        cLeAn_All_iN_bOSs2();
                        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                        SDL_RenderClear(rdr1);
                        return 0;
                    }
                    bOSs_iS_dialogue_1_sts2 = 1;
                    mOveUp = 0, mOveDown = 0, mOveLeft = 0, mOveRight = 0;
                }
                if (!bOss_sTaTe && atk_Round_2 == 3 && !bOSs_iS_dialogue_2_sts1)
                {
                    SDL_RenderCopy(rdr1, Shifter_BackGroundTexture_bOSs2, NULL, &fUll_sCrEEn2);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts1_2_1, Blank_bOSs2, bOSs2_Dragon, (char*)"Avatars/Dragon.png");
                    present(win, rdr1, font_bOSs2, sts1_2_2, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1_2_3, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts1_2_4, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_2_5, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_2_6, sts1_2_6_2, bOSs2_DC, (char*)"Avatars/DC.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic[4], NULL, &rECt_dialogue_pic);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts1_2_7, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_2_8, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts1_2_9, sts1_2_9_2, bOSs2_DC, (char*)"Avatars/DC.png");
                    if (presentstate == 0)
                    {
                        Mix_FreeMusic(BOSS_BGM2);
                        Mix_CloseAudio();
                        iNIt_bOSs2();
                        cLeAn_All_iN_bOSs2();
                        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                        SDL_RenderClear(rdr1);
                        return 0;
                    }
                    bOSs_iS_dialogue_2_sts1 = 1;
                    mOveUp = 0, mOveDown = 0, mOveLeft = 0, mOveRight = 0;
                }
                if (bOss_sTaTe && iS_tHeRe_eXtRa_bOMbS && !bOSs_iS_dialogue_2_sts2)
                {
                    SDL_RenderCopy(rdr1, Shifter_BackGroundTexture_bOSs2, NULL, &fUll_sCrEEn2);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts2_2_1, Blank_bOSs2, bOSs2_Dragon, (char*)"Avatars/Dragon.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic[3], NULL, &rECt_dialogue_pic);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts2_2_2, Blank_bOSs2, bOSs2_Dragon, (char*)"Avatars/Dragon.png");
                    present(win, rdr1, font_bOSs2, sts2_2_3, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts2_2_4, Blank_bOSs2, bOSs2_Prince, (char*)"Avatars/Prince.png");
                    if (presentstate == 0)
                    {
                        Mix_FreeMusic(BOSS_BGM2);
                        Mix_CloseAudio();
                        iNIt_bOSs2();
                        cLeAn_All_iN_bOSs2();
                        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                        SDL_RenderClear(rdr1);
                        return 0;
                    }
                    bOSs_iS_dialogue_2_sts2 = 1;
                    mOveUp = 0, mOveDown = 0, mOveLeft = 0, mOveRight = 0;
                }
                if (bOss_sTaTe && iS_tHeRe_eXtRa_eXtRa_bOMbS && !bOSs_iS_dialogue_3_sts2)
                {
                    SDL_RenderCopy(rdr1, Shifter_BackGroundTexture_bOSs2, NULL, &fUll_sCrEEn2);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts2_3_1, Blank_bOSs2, bOSs2_Dragon, (char*)"Avatars/Dragon.png");
                    SDL_RenderCopy(rdr1, txt_Dialogue_pic[5], NULL, &rECt_dialogue_pic);
                    SDL_RenderPresent(rdr1);
                    present(win, rdr1, font_bOSs2, sts2_3_2, Blank_bOSs2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_3_3, sts2_3_3_2, bOSs2_DC, (char*)"Avatars/DC.png");
                    present(win, rdr1, font_bOSs2, sts2_3_4, Blank_bOSs2, bOSs2_Ellie, (char*)"Avatars/Ellie.png");
                    present(win, rdr1, font_bOSs2, sts2_3_5, Blank_bOSs2, bOSs2_Prince, (char*)"Avatars/Prince.png");
                    if (presentstate == 0)
                    {
                        Mix_FreeMusic(BOSS_BGM2);
                        Mix_CloseAudio();
                        iNIt_bOSs2();
                        cLeAn_All_iN_bOSs2();
                        SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                        SDL_RenderClear(rdr1);
                        return 0;
                    }
                    bOSs_iS_dialogue_3_sts2 = 1;
                    mOveUp = 0, mOveDown = 0, mOveLeft = 0, mOveRight = 0;
                }
            }
            if (bOSs_gOt_hURt)
            {
                if (bOSs_gOt_hURt <= 60 && bOSs_gOt_hURt > 50 || bOSs_gOt_hURt <= 40 && bOSs_gOt_hURt > 30 || bOSs_gOt_hURt <= 20 && bOSs_gOt_hURt > 10)
                    SDL_RenderCopy(rdr1, txt_bOSs_gOt_hURt, NULL, &BoSs2);
                bOSs_gOt_hURt--;
            }

            SDL_RenderCopy(rdr1, txt_hEAlEr_2[3 - coUNt_oF_hEAl_2], NULL, &rECt_hEAlEr2);// healer CD

            if (bOss_sTaTe && iS_tHeRe_eXtRa_eXtRa_bOMbS)
            {
                stILL_nOt_eNErgY_fOr_Missing_bOMbS.h = 400 - 400 * (eNErgY_oF_Missing_bOMbS / 20.0);
                eNErgY_fOr_Missing_bOMbS.y = 600 - 400 * (eNErgY_oF_Missing_bOMbS / 20.0);
                eNErgY_fOr_Missing_bOMbS.h = 400 * (eNErgY_oF_Missing_bOMbS / 20.0);
                SDL_SetRenderDrawColor(rdr1, 255, 0, 0, 255); // 积攒能量条
                SDL_RenderFillRect(rdr1, &eNErgY_fOr_Missing_bOMbS);
                SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255); // 空能量条
                SDL_RenderFillRect(rdr1, &stILL_nOt_eNErgY_fOr_Missing_bOMbS);
            }

            if (!bOss_sTaTe) // BOSS为第一状态
            {
                if (eNErgY_nEEdEd_fOr_IDCard < 32)
                    eNErgY_nEEdEd_fOr_IDCard = 20 + atk_Round / 4 * 4;
                if (eNErgY_oF_ID_cARd >= eNErgY_nEEdEd_fOr_IDCard)
                {
                    ID_Card_rEAdY_Or_nOt = 1;
                    eNErgY_Of_ID_CaRd.w = 80;
                    SDL_SetRenderDrawColor(rdr1, 255, 255, 0, 255); // IDCard FULL ENERGY
                    SDL_RenderFillRect(rdr1, &eNErgY_Of_ID_CaRd);
                }
                else
                {
                    ID_Card_rEAdY_Or_nOt = 0;
                    if (shIEld_Or_nOt)
                    {
                        for (i = 0; i < shIEld_Or_nOt; i++)
                        {
                            SDL_SetRenderDrawColor(rdr1, 255, 223 - i * 16, 0, 255);
                            SDL_RenderFillRect(rdr1, &eNErgY_Of_shEIld[i]);
                        }
                        for (i = shIEld_Or_nOt; i < 5; i++)
                        {
                            SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255);
                            SDL_RenderFillRect(rdr1, &eNErgY_Of_shEIld[i]);
                        }
                    }
                    else
                    {
                        eNErgY_Of_ID_CaRd.w = eNErgY_oF_ID_cARd * (80.0 / eNErgY_nEEdEd_fOr_IDCard);
                        stILL_nOt_eNErgY_Of_ID_CaRd.x = 100 + eNErgY_oF_ID_cARd * (80.0 / eNErgY_nEEdEd_fOr_IDCard);
                        stILL_nOt_eNErgY_Of_ID_CaRd.w = 80 - eNErgY_oF_ID_cARd * (80.0 / eNErgY_nEEdEd_fOr_IDCard);
                        SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255); // IDCard NOT FULL ENERGY
                        SDL_RenderFillRect(rdr1, &stILL_nOt_eNErgY_Of_ID_CaRd);
                        SDL_SetRenderDrawColor(rdr1, 255, 255, 0, 255); // IDCard FULL ENERGY
                        SDL_RenderFillRect(rdr1, &eNErgY_Of_ID_CaRd);
                    }
                }
                SDL_RenderCopy(rdr1, txt_IDCard[ID_Card_rEAdY_Or_nOt], NULL, &ID_CaRd2);
            }
            else
            {
                if (eNErgY_oF_ID_cARd == 0 || eNErgY_oF_ID_cARd == 12 || eNErgY_oF_ID_cARd == 24 || eNErgY_oF_ID_cARd == 36)
                {
                    stILL_nOt_eNErgY_Of_ID_CaRd.w = 80;
                    stILL_nOt_eNErgY_Of_ID_CaRd.x = 100;
                    eNErgY_Of_ID_CaRd.w = 0;
                }
                if (eNErgY_oF_ID_cARd >= 36)
                {
                    eNErgY_Of_ID_CaRd.w = 80;
                    SDL_SetRenderDrawColor(rdr1, 255, 159, 0, 255); // IDCard FULL ENERGY
                    SDL_RenderFillRect(rdr1, &eNErgY_Of_ID_CaRd);
                    SDL_RenderCopy(rdr1, txt_IDCard[5], NULL, &ID_CaRd2);
                }
                if (eNErgY_oF_ID_cARd >= 24 && eNErgY_oF_ID_cARd < 36)
                {
                    eNErgY_Of_ID_CaRd.w = (eNErgY_oF_ID_cARd - 24) * (80.0 / 12);
                    stILL_nOt_eNErgY_Of_ID_CaRd.x = 100 + (eNErgY_oF_ID_cARd - 24) * (80.0 / 12);
                    stILL_nOt_eNErgY_Of_ID_CaRd.w = 80 - (eNErgY_oF_ID_cARd - 24) * (80.0 / 12);
                    SDL_SetRenderDrawColor(rdr1, 255, 191, 0, 255); // IDCard NOT FULL ENERGY
                    SDL_RenderFillRect(rdr1, &stILL_nOt_eNErgY_Of_ID_CaRd);
                    SDL_SetRenderDrawColor(rdr1, 255, 159, 0, 255); // IDCard FULL ENERGY
                    SDL_RenderFillRect(rdr1, &eNErgY_Of_ID_CaRd);
                    SDL_RenderCopy(rdr1, txt_IDCard[4], NULL, &ID_CaRd2);
                }
                if (eNErgY_oF_ID_cARd >= 12 && eNErgY_oF_ID_cARd < 24)
                {
                    eNErgY_Of_ID_CaRd.w = (eNErgY_oF_ID_cARd - 12) * (80.0 / 12);
                    stILL_nOt_eNErgY_Of_ID_CaRd.x = 100 + (eNErgY_oF_ID_cARd - 12) * (80.0 / 12);
                    stILL_nOt_eNErgY_Of_ID_CaRd.w = 80 - (eNErgY_oF_ID_cARd - 12) * (80.0 / 12);
                    SDL_SetRenderDrawColor(rdr1, 255, 223, 0, 255); // IDCard NOT FULL ENERGY
                    SDL_RenderFillRect(rdr1, &stILL_nOt_eNErgY_Of_ID_CaRd);
                    SDL_SetRenderDrawColor(rdr1, 255, 191, 0, 255); // IDCard FULL ENERGY
                    SDL_RenderFillRect(rdr1, &eNErgY_Of_ID_CaRd);
                    SDL_RenderCopy(rdr1, txt_IDCard[3], NULL, &ID_CaRd2);
                }
                if (eNErgY_oF_ID_cARd >= 0 && eNErgY_oF_ID_cARd < 12)
                {
                    eNErgY_Of_ID_CaRd.w = eNErgY_oF_ID_cARd * (80.0 / 12);
                    stILL_nOt_eNErgY_Of_ID_CaRd.x = 100 + eNErgY_oF_ID_cARd * (80.0 / 12);
                    stILL_nOt_eNErgY_Of_ID_CaRd.w = 80 - eNErgY_oF_ID_cARd * (80.0 / 12);
                    SDL_SetRenderDrawColor(rdr1, 255, 255, 255, 255); // IDCard NOT FULL ENERGY
                    SDL_RenderFillRect(rdr1, &stILL_nOt_eNErgY_Of_ID_CaRd);
                    SDL_SetRenderDrawColor(rdr1, 255, 223, 0, 255); // IDCard FULL ENERGY
                    SDL_RenderFillRect(rdr1, &eNErgY_Of_ID_CaRd);
                    SDL_RenderCopy(rdr1, txt_IDCard[2], NULL, &ID_CaRd2);
                }
            }

            if (Get_hUrt == 60 && !(shIEld_Or_nOt)) // 掉血
            {
                Py_Hp -= 10;
            }
            if (Get_hUrt)
            {
                if (Get_hUrt == 61) // 防止1点盾掉了直接掉血
                    Get_hUrt -= 2;
                else
                    Get_hUrt--;
            }

            Health_Bar_Remain.x = 1050 - 850 * (Py_Hp / 100.0);
            Health_Bar_Remain.w = 850 * (Py_Hp / 100.0);
            Health_Bar_Loss.w = 850 - 850 * (Py_Hp / 100.0);
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
        }

        SDL_RenderPresent(rdr1);

        if (Py_Hp <= 0 || Bs_Hp <= 0)
        {
            if (Py_Hp <= 0)
            {
                Mix_PauseMusic();
                while (!bACk_tO_lASt_sCeNe_bOSs2)
                {
                    if (transparency_Gm_Ov_2 < 223)
                        transparency_Gm_Ov_2++;
                    SDL_SetTextureAlphaMod(Game_Over_BackGroundTexture_bOSs2, transparency_Gm_Ov_2);
                    SDL_RenderCopy(rdr1, Game_Over_BackGroundTexture_bOSs2, NULL, &fUll_sCrEEn2);
                    SDL_RenderPresent(rdr1);
                    while (SDL_PollEvent(&event))
                    {
                        if (event.type == SDL_QUIT)
                        {
                            iNIt_bOSs2();
                            cLeAn_All_iN_bOSs2();
                            SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                            SDL_RenderClear(rdr1);
                            return 0;
                        }
                        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
                            bACk_tO_lASt_sCeNe_bOSs2 = 1;
                    }
                }
                iNIt_bOSs2();
                cLeAn_All_iN_bOSs2();
                SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
                SDL_RenderClear(rdr1);
                return 3;
            }
            if (Bs_Hp <= 0)
            {
                Mix_FreeMusic(BOSS_BGM2);
                Mix_CloseAudio();
                iNIt_bOSs2();
                cLeAn_All_iN_bOSs2();
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

        //SDL_Delay(16);
    }
    Mix_FreeMusic(BOSS_BGM2);
    Mix_CloseAudio();
    iNIt_bOSs2();
    cLeAn_All_iN_bOSs2();
    SDL_SetRenderDrawColor(rdr1, 0, 0, 0, 255); // 设置背景色
    SDL_RenderClear(rdr1);
    return 0;
}