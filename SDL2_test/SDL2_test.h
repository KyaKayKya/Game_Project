#ifndef __SDL2_TEST_H__
#define __SDL2_TEST_H__
/*
*	Define 
*/
#define SDL_MAIN_HANDLED  // give back my main！
#define FR 40  // Frame Rate
#define FT 1000 / FR
#define MT 300  // One Motion Time(ms)

#define W 1250
#define H 650

const int Bullet_Speed = 5;  /*
This cannot be changed anymore! 
The accuracy of targeted strikes is relatively high, while the slow and sluggish ones are fewer.
*/
#define Bullet_Normal_Speed 5
#define Bullet_Max_Speed 10
#define Plane_Speed 5
#define No_Hit_Time 500
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
#include <stdbool.h>
/*
*	Structure
*/
typedef struct Player {
	int x;  // center point
	int y;
	int v_x;
	int v_y;
	int w;
	int h;
	int r;  // radius of circular collision box
}Player;

typedef struct Object {
	int x;  // top-left coordinates
	int y;
	int w;
	int h;
	int l_u[2];  // top-left coordinates
	int r_u[2];  // top-right coordinates.
	int l_d[2];  // bottom-left coordinates
	int r_d[2];  // bottom-right coordinates.
}Object;  // rectangle collision box structure

typedef struct Circle {
	int x;  // center coordinates
	int y;
	int r;
	int v_x;
	int v_y;
	bool is_exist = false;
}Circle;  // circle collision box structure

typedef struct Keycontrol {
	int w;
	int a;
	int s;
	int d;
	int E;
	char l_cmd;
}Keycontrol;  // Store the key command

typedef struct Puzzle1 {
	int register_row = 0;
	int register_column = 0;
	int player_row = 0;
	int player_column = 0;
	int puzzle_1_w = (1133 - 42) / 29 + (1133 - 42) * 1.5 / (29 * 22);
	int puzzle_1_h = (604 - 96) / 12 + (604 - 96) * 1.3 / (12 * 12);
	int round = 0;  // 0 represent player's turn 1 represent dragon's turn
	int is_controlled = 0;  // 1 represent has been (dragon）controlled  0 represent has not been (dragon）controlled
	int result = 10; // 1 represents dragon win，0 repreents player win
	int last_result = 0;  // 0 win 1 lose
	int is_dialogue = 0;  // 是否对话过
}Puzzle1;

extern int presentstate;

/*
*	Funtion
*/
int cHooSe_oF_bOSs1();
void INIT();
void LOAD();
void PrintPlayer();  // print player's animation
void QUIT();
void Center_Text(int x, int y, int w, int h, const char* text);  // put the text in the center of a rect
void Key_detect();
void Player_move(int start, int end);
void Map_0();
void Map_1(int start, int end);
void Map_2(int start, int end);
void Map_3(int start, int end);
void Map_4(int start, int end);
void Map_5(int start, int end);
void Map_6(int start, int end);
void Map_7(int start, int end);
void Map_8();
void Map_21();
void Map_22();
void Map_24();
void Puzzle_1();
void Bullet_INIT();  // init all bullet
void Are_You_Tough_Man();  // Plane_fight(endure for 30 seconds if you are a man)
void Bullet_Print();  // render bullet
void Map_Shift(int map_num, int x, int y);  // shifting map with a gradually disappear effect
void Puzzle_1_Init();  // init puzzle 1
int Is_SameQuadrant(Object object, int x, int y);  // detect if the rect are in the same quadrant(x,y is the center point's position)
int Is_collide(Object object, int player_w, int player_h, int x, int y, int r);  // detect if they(rect and circle) are collided(x,y)
int Is_collide_Rect(Object object, int x, int y, int w, int h);  // detect if they(rect and rect) are collided
int Collision_Detect(int x, int y, int r, int start, int end);  // detect all object from start to end(including start&end)
void Object_INIT();  // init all object
void Object_Update();  // update all object
void Object_INIT_Point(int i);  // init all objects' points
void Plane_Object_Update();  // update the collision box of plane
int present(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, char* a, char* b, char* name, char* picture);
//int textFadeInOut(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color textColor);
int Find_Max(int a, int b);  // find absolute maximum number from two int
void save();

#endif /* __SDL2_TEST_H__ */
