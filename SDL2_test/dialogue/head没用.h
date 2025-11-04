#ifndef GLOBALS_H
#define GLOBALS_H


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <string.h>


Uint8 *audio_buf;
Uint32 audio_len;
Uint32 audio_pos;
SDL_AudioDeviceID device_id;//以上四个音量所需

SDL_Rect dialogue;//对话框的位置
bool show_dialog;

int dialoguetime;//记录到第几行
char a[100];
    //一行50
char b[100];
char c[100];//一行50,直接在这改三句话，如果不足三行直接输入空格

#endif