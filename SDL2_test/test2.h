#ifndef _TEST2_H_
#define _TEST2_H_

#include <SDL2/SDL.h>  
#include <SDL2/SDL_image.h>  
#include <stdio.h>  
#include <stdbool.h>  
 
extern SDL_Window* Puzzle1_Window;
extern SDL_Renderer* Puzzle1_Renderer;
extern int presentstate;
#define FRAME_RATE 60  
#define IMAGE_COUNT 150  // ºŸ…Ë”–10’≈Õº∆¨  
#define WINDOW_WIDTH 1250  
#define WINDOW_HEIGHT 650  
#define window Puzzle1_Window
#define renderer Puzzle1_Renderer
#define closeSDL() closeSDL_1()

bool initSDL();
int Pause();
void closeSDL_1();
bool loadImages();
int show_instruction(SDL_Renderer* renderer, char* next, char* before, char* yes);

#endif
