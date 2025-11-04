/*--------------------------------------BOSS2----------------------------------------------*/
#ifndef __BOSS2_H__
#define __BOSS2_H__
/*
*	Include
*/
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
/*
*	Define
*/
#define W 1250
#define H 650
extern SDL_Window* Puzzle1_Window;
extern SDL_Renderer* Puzzle1_Renderer;
extern int presentstate;
#define win Puzzle1_Window
#define rdr1 Puzzle1_Renderer
/*
*	Funtion
*/
int bOss2_For_dRaGoN(int sTaTe_oF_bOSs);
int bIg_bOMb_iS_cOMiNG(int atk_Scd, int atk_Round);
int On_The_Floor_Or_Not(int Circle_Center_x, int Circle_Center_y);
int bOMbs_Controller(int nUm_oF_bOMbs, int atk_Scd, int atk_Round);
int Boss2(int ct);
void TestText(int image_index);
void cLeAn_All_iN_bOSs2();
int eXtRa_bIg_bOMbS(int atk_Scd, int atk_Round);
void iNIt_bOSs2();
#endif /* __BOSS2_H__ */
