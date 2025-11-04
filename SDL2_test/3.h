#ifndef _3_H_
#define _3_H_
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>


#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 650
extern SDL_Window* Puzzle1_Window;
extern SDL_Renderer* Puzzle1_Renderer;
extern int presentstate;
#define window Puzzle1_Window
#define renderer Puzzle1_Renderer
#define initSDL() initSDL_1()
// 元件类型枚举
typedef enum {
    SWITCH,
    WIRE,
    AND_GATE,
    OR_GATE
} ComponentType;

// 元件结构体
typedef struct {
    int x, y; // 元件位置
    ComponentType type; // 元件类型
    bool state; // 元件状态，关闭为false，打开为true
    SDL_Rect rect; // 元件矩形区域
} Component;

int Puzzle3();
void checkMouseClick(int mouseX, int mouseY);
//int gameLoop();
bool initSDL();
bool loadBackgroundImage();
void renderComponent(Component component);
void renderphoto();
void renderwire();
void iNIt_Puzz3();

#endif
