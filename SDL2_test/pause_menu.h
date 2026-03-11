#ifndef _PAUSE_MENU_H_
#define _PAUSE_MENU_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

extern SDL_Window*   Puzzle1_Window;
extern SDL_Renderer* Puzzle1_Renderer;
extern int presentstate;

#define WINDOW_WIDTH  1250
#define WINDOW_HEIGHT 650
#define window   Puzzle1_Window
#define renderer Puzzle1_Renderer

// Pause()  returns: 0 = resume game,  -1 = quit to desktop
int  Pause();
void closeSDL_1();   // kept for enter.h compat (now a no-op)

#endif
