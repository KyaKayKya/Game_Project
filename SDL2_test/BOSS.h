/*--------------------------------------BOSS----------------------------------------------*/
#ifndef __BOSS_H__
#define __BOSS_H__
/*
*	Include
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

int Boss(int ct);
int Random_atk_Mod(int atk_Round);
int Random_Star_Position(int atk_Round);
int fROg(int count_of_Frog, int Stop_frOG);
int Flies(int atk_Scd, int atk_Dly, int atk_Mod, int atk_Num);
void Fly_Circle(int* F_x, int* F_y, int atk_Scd, int atk_Dly, int atk_Num, int which_FLY);
void Fly_Crash(int* F_x, int* F_y, int atk_Scd, int which_FLY, int atk_Dly);
int wall(int i);
void TestText(int image_index);
int ColliSion(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
void ID_CarD(int Num_of_Stars);
int bOss1_For_sciENtist2();
void cLaEn_All_iN_bOSs1();
void iNIt_bOSs1();

#endif /* __BOSS_H__ */
