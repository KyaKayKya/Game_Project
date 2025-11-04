/*--------------------------------------RUN GAME----------------------------------------------*/
#ifndef __RUN_GAME__
#define __RUN_GAME__
/*
*	Include
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
/*
*	Define
*/
#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 650
extern SDL_Window* Puzzle1_Window;
extern SDL_Renderer* Puzzle1_Renderer;
extern int presentstate;
#define window Puzzle1_Window
#define renderer Puzzle1_Renderer
/*
*	Funtion
*/
void initialize();
void callback(void* userdata, Uint8* stream, int len);
void init_audio();
void update();
int meet(int bird_x, int pipe_x, int pipe_x2, int top_pipe_height, int bottom_pipe_height, int top_pipe_height2, int bottom_pipe_height2);
void render();
void render2();
void cleanup();
int run_forest_run();
#endif /* __RUN_GAME__ */
