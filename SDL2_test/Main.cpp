#define _CRT_SECURE_NO_WARNINGS

#include "SDL2_test.h"
#include "BOSS.h"
#include "Run Game.h"
#include "BOSS2.h"
#include "enter.h"
#include "test2.h"
#include "3.h"
/*
*
*	Global Variable
*
*/
int is_disk3 = 1;
int is_disk4 = 1;
int is_disk6 = 1;
// disk 
SDL_Surface* disk_BackGroundSurface = NULL;  // 图形
SDL_Texture* disk_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect disk_BackGroundRect[3];
// choice
SDL_Surface* choice_BackGroundSurface = NULL;  // 图形
SDL_Texture* choice_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect choice_BackGroundRect;
// map 0
SDL_Window* Puzzle1_Window = NULL;  // 窗口
SDL_Renderer* Puzzle1_Renderer = NULL;  // 画笔
SDL_Surface* Puzzle1_BackGroundSurface = NULL;  // 图形
SDL_Texture* Puzzle1_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Puzzle1_BackGroundRect;
// map 1
SDL_Surface* Map1_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map1_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map1_BackGroundRect;
// map 2
SDL_Surface* Map2_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map2_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map2_BackGroundRect;
// map 3
SDL_Surface* Map3_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map3_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map3_BackGroundRect;
// map 4
SDL_Surface* Map4_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map4_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map4_BackGroundRect;
// map 5
SDL_Surface* Map5_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map5_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map5_BackGroundRect;
// map 5_2
SDL_Surface* Map5_2_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map5_2_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map5_2_BackGroundRect;
// map 6
SDL_Surface* Map6_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map6_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map6_BackGroundRect;
// map 7
SDL_Surface* Map7_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map7_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map7_BackGroundRect;
// map 8
SDL_Surface* Map8_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map8_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map8_BackGroundRect;
// map 20
SDL_Surface* Map20_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map20_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map20_BackGroundRect;
// map 21
SDL_Surface* Map21_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map21_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map21_BackGroundRect;
// map 22
SDL_Surface* Map22_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map22_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map22_BackGroundRect;
// map 23
SDL_Surface* Map23_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map23_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map23_BackGroundRect;
// map 24
SDL_Surface* Map24_BackGroundSurface = NULL;  // 图形
SDL_Texture* Map24_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Map24_BackGroundRect;
// Puzzle 1
SDL_Surface* Puzzle_1_BackGroundSurface = NULL;  // 图形
SDL_Texture* Puzzle_1_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Puzzle_1_BackGroundRect;
// Heart
SDL_Surface* Heart_BackGroundSurface = NULL;  // 图形
SDL_Texture* Heart_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Heart_BackGroundRect;
// Dragon_Heart
SDL_Surface* Dragon_Heart_BackGroundSurface = NULL;  // 图形
SDL_Texture* Dragon_Heart_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
// map shifter
SDL_Surface* Shifter_BackGroundSurface = NULL;  // 图形
SDL_Texture* Shifter_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Shifter_BackGroundRect;
// Plane fight
SDL_Surface* Plane_fight_BackGroundSurface = NULL;  // 图形
SDL_Texture* Plane_fight_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Plane_fight_BackGroundRect;
SDL_Rect Plane_fight_BackGroundRect_B[2];  // Blue sky
// Plane
SDL_Surface* Plane_BackGroundSurface = NULL;  // 图形
SDL_Texture* Plane_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Plane_BackGroundRect;
// Bullet
const int Bullet_num = 60;
SDL_Surface* Bullet_BackGroundSurface = NULL;  // 图形
SDL_Texture* Bullet_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Bullet_BackGroundRect[Bullet_num];
// GameOver
SDL_Surface* GameOver_BackGroundSurface = NULL;  // 图形
SDL_Texture* GameOver_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect GameOver_BackGroundRect;
// left、right
SDL_Surface* Player0_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player0_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Player0_BackGroundRect;
SDL_Surface* Player1_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player1_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Surface* Player12_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player12_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
// up
SDL_Surface* Player2_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player2_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Surface* Player3_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player3_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Surface* Player4_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player4_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Surface* Player5_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player5_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
// down
SDL_Surface* Player6_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player6_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Surface* Player7_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player7_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Surface* Player8_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player8_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Surface* Player9_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player9_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
TTF_Font* Date_Font = NULL;
Mix_Chunk* SoundEffect;
Mix_Chunk* Error_SoundEffect;
Mix_Music* SoundBackGround;
Mix_Music* Puzzle_1_bgm;
Mix_Music* Puzzle_2_bgm;
Mix_Music* Before_boss2_bgm;
SDL_Color FontColor = { 255, 255, 255, 255 };  // RGBA
Keycontrol key_cmd;  // 键盘控制结构体
Player player; // 玩家结构体
Puzzle1 puzzle1;  // 谜题结构体
Object object[100];  // 地图中碰撞箱结构体
Circle Bullet[Bullet_num];  // 弹幕结构体
SDL_Rect mAIn_fUll_sCrEEn = { 0, 0, 1250, 650 };
SDL_Rect rECt_dialogue_pic_mAIn = { 289, 40, 672, 350 };
int lose_count = 0;  // 真男人失败次数 大于5次难度减半
int is_quit = 0;  // 标志是否QUIT过
int map = 0;  // 0代表地图0；1代表Map1；2代表puzzle1；3代表真男人; 5 代表boss1; 12代表Map2;13代表Map3;14代表Map4;15代表Map5;16代表Map6;17代表Map7;
int map_num = 3;  // 代表要换的地图(初始化的值为直接跳到的地图编号)
int F_counter = 0;  // 帧计数器
int is_change = 0;  // 1代表要换地图了
int alpha = 0;  // 透明度
int map_ID_opeNDoor = 0;
int calendar[12][31] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };  // 表示日期是否存在 1 存在 0 不存在
Uint64 last_cmd = 0, now_cmd = 0;  // Puzzle1 两命令间隔限制

int boss1_result = 2;  // result of boss1 0 quit 1 win 2 nothing 3 lose
int boss2_result = 2;  // result of boss2 0 quit 1 win 2 nothing 3 lose
int parkour_result = 2;  // result of parkour -1 lose 0 quit 1 win 2 nothing
bool kill_Scientist = 0;  // 1 die(kill) 0 live(save)
bool is_ID = 0;  // 0 no ID  1 has ID
int disk_num = 0;  // num of disk
int puzzle2_is_auto = 0;  // whether if auto is played 0 no 1 yes

int presentstate = 1;

int hit_count = 0;  // 记录被击中数
int Bullet_Generate_Ratio = 6;  // 生成bullet参数
Uint64 last_hit = 0;  // 两次碰撞间隔
Uint64 Start_Plane_time = 0;  // 开始游玩的时候

Uint64 Last_E_time = 0;

int is_time_machine_dialogue = 0;  // is introduce time machin

int map5_is_dialogue = 0;

int enter_is_dialogue = 0;

int tough_enough_dialogue = 0;

int rOCk_hOLe_dialogue = 0;

int dialogue_beFOre_Puzz3 = 0;

int dialogue_aFTEr_pLAne = 0;

int dialogue_Lamy = 0;

int plane_start = 0;

int dialogue_Emma = 0;

int dialogue_Wyvern = 0;

SDL_Surface* surf_Pic_fOr_diAlOGue[12] = { 0 };
SDL_Texture* txt_Pic_fOr_diAlOGue[12] = { 0 };

/*
Dialogue
*/
/*
	time machin instruction:
	- 【Warning!】Follows are VERY important, there were a lot of workers lost in time because they SKIP ME!
	  【Warning!】Do NOT skip me unless you know how to control the time machine.
	   Time machine can't 'jump' from 1.1 to 12.31 directly, there's three limitations.

	- 1.Within the same turn of control, the time machine can only travel to the future and cannot go back to the past.
	1.10->1.19 Yes  1.10->1.1 No
	- 2.The time machine can only travel within the same month (e.g., from January 1st to January 20th)
	or between different months but the same day (e.g., from February 24th to May 24th).
	- 3.You can't travel to today (10.10->10.10)
	- 【WASD】to choose the date
	- 【Enter】to travel to the date you choose
	- In sum,  in a "calendar", time machine can only travel horizontally or vertically in one turn.

	Encounter with time phantom:

	- Why... I can't control my body!
	- 【Warning!】 【Warning!】 You encounter an evil time phantom!
	- The time phantom manages to possess your body
	- The time phantom succeed...temporarily
	- You and time phantom will take turns controlling your body,
	- Your goal is to arrive December 31st when your body is under your control.
	- Otherwise, your body will be forever controlled by the time phantom.

	Hint:

	- In each month, the day that is equal to the month's number plus 19 is called a "magic date."
	- Brave Prince, please ensure that every time you control the time machine
	- You aim for the "magic date" as your destination.
	- Wishing you a smooth journey.

	*/
// title
int title_num = 6;
int title_period = 30000;
int title_FN = (title_period / 1000)*40;
int title_f_counter = 0;
char T0[100] = { "Illuminati: The end of the world" };
char T1[100] = { "Illuminati: Small Blocks, Not for Children Under the Age of 5" };
char T2[100] = { "Illuminati: Can You Resist for 20 Seconds ?" };
char T3[100] = { "Illuminati: Press alt+f4" };
char T4[100] = { "Illuminati: Illuminati: Illuminati:" };
char T5[100] = { "Illuminati: Do You Really Find That Title Will Change?" };

// basic instruction
char Blank[100] = { 0 };
char Name[8][10] = { "Ellie", "Prince", "Emma", "DC", "Wyvern", "Lamy", "Dragon", "???"};
char nAMe_Ellie[10] = { "Ellie" };
char nAMe_Prince[10] = { "Prince" };
char nAMe_DC[10] = { "DC" };
char nAMe_Dragon[10] = { "Dragon" };
char nAMe_Emma[10] = { "Emma" };
char nAMe_Wyvern[10] = { "Wyvern" };
char nAMe_Lamy[10] = { "Lamy" };
char nAMe_who[10] = { "???" };

char Puzz1_1[100] = { "Prince, there\'s a very chaotic time and turbulence ahead!" };
char Puzz1_2[100] = { "Hold on tight and we\'ll go through it to go back to the pass." };
char Puzz1_3[100] = { "It\'s very dangerous, so I\'ll give you some instruction first." };
char Puzz1_4[100] = { "You have to know that time machine can't 'jump' from January 1st to December 31th directly." };
char Puzz1_5[100] = { "There are three limitations, please remember them and use the time machine properly." };
char Puzz1_6[200] = { "1. Within the same turn of control, the time machine can only travel to the future." };
char Puzz1_7[100] = { "For example, you can 1.10->1.19. But can't 1.10->1.1" };
char Puzz1_8[100] = { "2. The time machine can only travel within the same month (from January 1st to January 20th)" };
char Puzz1_9[100] = { "or between different months but the same day(from February 24th to May 24th)." };
char Puzz1_10[100] = { "3. You are not supposed to travel to today (10.10->10.10)" };
char Puzz1_11[100] = { "Long press\"WASD\"to choose the date. Again, Please long Pressing." };
char Puzz1_12[100] = { "\"Enter\"to travel to the date you choose" };
char Puzz1_13[100] = { "In sum,in a \"calendar\", time machine can only travel horizontally or vertically in one turn." };
char Puzz1_14[100] = { "Well, now you can press \"Enter\" to start your time travel.Good luck!" };
// encounter phantom
char Puzz1_15[100] = { "Why... I can\'t control my body!" };
char Puzz1_16[100] = { "I am turning ... purple!" };
char Puzz1_17[100] = { "Oh,God! You encounter an evil time phantom!" };
char Puzz1_18[100] = { "The time phantom manages to possess your body" };
char Puzz1_19[100] = { "The time phantom succeed...temporarily" };
char Puzz1_20[100] = { "Your goal is to arrive December 31st when your body is under your control." };
char Puzz1_21[100] = { "Otherwise...your body will be forever controlled by the time phantom." };
// hint
char Puzz1_22[100] = { "Don\'t worry. We can try again." };
char Puzz1_23[100] = { "I\'ve just done an analysis. Let me give you a hint." };
char Puzz1_24[100] = { "In each month, the day that is equal to the month's number plus 19 is called a \"magic date.\"" };
char Puzz1_25[100] = { "Brave Prince, please ensure that every time you control the time machine" };
char Puzz1_26[100] = { "You aim for the \"magic date\" as your destination." };
char Puzz1_27[100] = { "Wishing you a success." };

//char P28[100] = { "Brilliant！You defeat the time phantom!" };
//
//char P29[100] = { "This is a test text!" };
char P30[100];
//char P31[100] = { "You need ID card to enter this gate. Find 3 disks in this map to gain ID card." };
//
//char P32[100] = { "Let me see, three hard drives? Wait for me, I\'ll analyze the content inside." };
//char P33[100] = { "Here it is. A coordinate and a string of passwords." };
//char P34[100] = { "This coordinate... I remember it was a door that had never been opened before." };
//char P35[100] = { "Since you are so idle, how about going and see ?" };
//char P36[100] = { "Why don\'t you come with us? " };
//char P37[100] = { "It's not far. Not getting up and walking again is not good for your waist." };
//char P38[100] = { "(Sigh) Alright, alright. Guide me then." };

char etr_1[100] = { "Uh... Where am I? I remember..." };
char etr_2[100] = { "Hey Prince! You finally wake up! Do you still remember me?" };
char etr_3[100] = { "Oh, yeah, of course. You are an honest scientist. Thank you very much for your previous help..." };
char etr_4[100] = { "But where are we now?" };
char etr_5[100] = { "Remember? Dragon, the leader of Illuminati, used a big bomb to spread virus and" };
char etr_5_2[100] = { "destroyed our world." };
char etr_6[100] = { "Oh, I remember! Thanks to your help, we were able to use the laboratory facilities" };
char etr_6_2[100] = { "to save our lives." };
char etr_7[100] = { "Yeah. But the world had been destroyed. After that, we found a time machine." };
char etr_8[100] = { "Based on my analysis, it is possible to go back to the past and save the world" };
char etr_8_2[100] = { "through this time machine." };
char etr_9[100] = { "So we\'ve already jump in the time machine? We are in the chaos of time and space?" };
char etr_10[100] = { "Yes. And we\'ll go back to the past later." };
char etr_11[100] = { "Remember, no matter what difficulties you encounter, please move forward bravely." };
char etr_12[100] = { "We will definitely be able to stop Dragon\'s plan." };

char aft_bOSs1_1[100] = { "Alright... I\'ve got nothing to lose now." };
char aft_bOSs1_2[100] = { "As long as I\'m still controlled by Dragon, I cannot be enemies with him." };
char aft_bOSs1_3[100] = { "You are strong enough to stop Dragon. Now, please give me a relief." };
char aft_bOSs1_c1_1[100] = { "Alright... rest in peace now." };
char aft_bOSs1_c2_1[100] = { "(Take a look at DC)" };
char aft_bOSs1_c2_2[100] = { "(Sigh) I know what you mean. I\'ll try." };
char aft_bOSs1_c2_3[100] = { "Wait... That is one of Dragon's core technologies. You want to crack it?" };
char aft_bOSs1_c2_4[100] = { "Maybe it's not as difficult as you think..." };
char aft_bOSs1_c2_5[100] = { "..." };
char aft_bOSs1_c2_6[100] = { "Here it is. Wyven, you are free now." };
char aft_bOSs1_c2_7[100] = { "How can you... (Sign) Anyway, I really appreciate it." };
char aft_bOSs1_c2_8[100] = { "Now you have shown me a life-saving kindness." };
char aft_bOSs1_c2_9[100] = { "With my current physical condition, I can’t go with you." };
char aft_bOSs1_c2_10[100] = { "But after saving the world, if there is any need in the laboratory, I will do my best to help." };
char aft_bOSs1_c2_11[100] = { "I will perform basic wound treatment for you. Please do not move around." };
char aft_bOSs1_c2_12[100] = { "Thanks. DC is a genius. He always manage to do things that ordinary people dare not think of..." };
char aft_bOSs1_c2_13[100] = { "By the way, I have roughly understood Dragon's core technology. Hope this can be helpful" };
char aft_bOSs1_c2_13_2[100] = { "in the future." };
char aft_bOSs1_c2_14[100] = { "That helps a lot. Alright, we need to move ahead. Otherwise, Dragon may slip away." };

char apROn_1[100] = { "Hurry up! Dragon is about to run away!" };
char apROn_2[100] = { "Damn man! Dragon has set off and we have lost the best time to catch him." };
char apROn_3[100] = { "Don\'t give up! Look,there is an aircraft lying there waiting for us!" };
char apROn_4[100] = { "We can still catch up with Dragon." };
char apROn_5[100] = { "Yes, it is not a time to give up! Let\'s get on and try our best to save the world!" };

char tOUgh_1[100] = { "Oh no! It seems that Dragon is already prepared, we have been ambushed!" };
char tOUgh_2[100] = { "We are trapped in a firepower blockade!" };
char tOUgh_3[100] = { "These bullets appear to have different flight speeds and modes! Be careful to avoid!" };
char tOUgh_4[100] = { "Don't worry, we can break through the blockade in about 20 seconds at our speed!" };
char tOUgh_5[100] = { "All we need to do now is to dodge with all our might and not be hit!" };
char tOUgh_6[100] = { "Hold on! The violent shaking of the plane can make people feel uncomfortable," };
char tOUgh_6_2[100] = { "so be mentally prepared!" };

char rOCk_hOLe_D_1[100] = { "Uh... It hurts enough... How could there be such a big hole at the end of the trap... Where are we?" };
char rOCk_hOLe_D_2[100] = { "Let me take a look... A cave? There seems to be only one road here." };
char rOCk_hOLe_D_3[100] = { "Let\'s go in and see what is in it." };
char rOCk_hOLe_D_4[100] = { "But... This may be another trap set by Lamy..." };
char rOCk_hOLe_D_5[100] = { "I understand your concerns, Emma." };
char rOCk_hOLe_D_6[100] = { "But it seems that if we want to go out and find Dragon, there is only one way to go." };
char rOCk_hOLe_D_7[100] = { "No one will pass by here, if we don\'t move forward, we will be stuck here forever." };
char rOCk_hOLe_D_7_2[100] = { "That\'s what Dragon wishes." };
char rOCk_hOLe_D_8[100] = { "We must stop Dragon. Let\'s go ahead." };

char bef_Puzz3_1[100] = { "No... No!... Noooooo!!!!!!" };
char bef_Puzz3_2[100] = { "We finally make it!" };
char bef_Puzz3_3[100] = { "Don\'t be too happy too early! Hurry up! Let\'s go dismantle the bio bomb!" };
char bef_Puzz3_4[100] = { "Here is the bomb!" };
char bef_Puzz3_5[100] = { "Look! The yellow one is the OR door, the red one is the switch, the green one is the wire," };
char bef_Puzz3_5_2[100] = { "and the blue one is the AND door!" };
char bef_Puzz3_6[100] = { "It seems that the switch can be opened infinitely, and the current passing through the switch" };
char bef_Puzz3_6_2[100] = { "can be turned on." };
char bef_Puzz3_7[100] = { "Electric wires can pass through current, you can click to cut them." };
char bef_Puzz3_8[100] = { "After cutting, they cannot be connected again!" };
char bef_Puzz3_9[100] = { "The OR gate has two inputs and one output, and can only output current" };
char bef_Puzz3_9_2[100] = { "if there is only one input." };
char bef_Puzz3_10[100] = { "The AND gate outputs two outputs and one input, and can only output current" };
char bef_Puzz3_10_2[100] = { "if both have outputs." };
char bef_Puzz3_11[100] = { "Our goal is to make all three green lights in the middle light up!" };
char bef_Puzz3_12[100] = { "The bottom red light cannot light up during the process! Otherwise, the bomb will explode!" };
char bef_Puzz3_13[100] = { "Got it! I\'ll try my best." };


char bef_rUn_1[100] = { "Oh no this is truly a disaster road!" };
char bef_rUn_2[100] = { "Watch out! There is a laser coming from ahead, quickly dodge, otherwise we will be buried here!" };
char bef_rUn_3[100] = { "Oh my god! Maybe this is just a trap set by Lamy!" };
char bef_rUn_4[100] = { "But we have no way to be back. Let\'s try our best to make it!" };

char aft_plane_1[100] = { "(The aircraft run out of fuel. They are forced to land in the forest.)" };
char aft_plane_2[100] = { "Thank goodness, we survived!" };
char aft_plane_3[100] = { "Now we have entered the forest where the dragon is hiding. Be careful!" };
char aft_plane_4[100] = { "There is a secret base along the direction of Dragon\'s escape, let\'s hurry up!" };
char aft_plane_5[100] = { "There is a Guard standing by the gate. Everyone, please be prepared for the battle." };
char aft_plane_6[100] = { "Do not go ahead anymore." };
char aft_plane_7[100] = { "Don\'t stop us. Otherwise, we will have to use force to enter." };
char aft_plane_8[100] = { "You don\'t have to hold such great hostility." };
char aft_plane_9[100] = { "My name is Lamy. Meeting me here means that you find the clue I gave you." };
char aft_plane_10[100] = { "Clue? You mean you left hard drives and the ID card? How can you prove it?" };
char aft_plane_11[100] = { "Give me those three hard drives. They are now useless in your hands, right?" };
char aft_plane_12[100] = { "... Alright." };
char aft_plane_13[100] = { "(Lamy decrypts them through special means and obtained another piece of information.)" };
char aft_plane_14[100] = { "Here, it\'s information about Dragon." };
char aft_plane_15[100] = { "Let me check it." };
char aft_plane_16[100] = { "... The information had a certain level of credibility. Maybe we could believe her temporarily." };
char aft_plane_17[100] = { "But why you choose to help us?" };
char aft_plane_18[100] = { "(Laugh slightly) I just don\'t want the world be destroyed. That\'s not fun at all." };
char aft_plane_19[100] = { "Also, I need to warn you that even if I give you a few pieces of information about the dragon," };
char aft_plane_19_2[100] = { "it will still be difficult for you to defeat it." };
char aft_plane_20[100] = { "How far can you reach depends on you." };
char aft_plane_21[100] = { "I will remember it in my heart. So, can you let us in now?" };
char aft_plane_22[100] = { "No." };
char aft_plane_23[100] = { "...?" };
char aft_plane_24[100] = { "I mean, this is the wrong way. Dragon is not here." };
char aft_plane_25[100] = { "Look, there\'s another hidden path. You know what to do." };
char aft_plane_26[100] = { "Alright, we\'ll trust you this time. Let\'s stop Dragon!" };
char aft_plane_27[100] = { "Oh!" };
char aft_plane_28[100] = { "Ohhhh!" };
char aft_plane_29[100] = { "Ohhhhhhhhhhhh!" };

char aft_Puzz1_1[100] = { "Brilliant! You defeat the time phantom!" };
char aft_Puzz1_2[100] = { "Oh... Who are you? Is it because my eyes are blurred..." };
char aft_Puzz1_3[100] = { "You seem to have appeared in front of me out of thin air..." };
char aft_Puzz1_4[100] = { "Uh... Hello, I\'m Ellie, and the person next to me is Prince." };
char aft_Puzz1_5[100] = { "We... We have something to do with Mr. Dragon. Do you know where he is?" };
char aft_Puzz1_6[100] = { "Dragon? I don\'t know... But recently there have been rumors that he is doing some shady things..." };
char aft_Puzz1_7[100] = { "If you have something to do with him, could you please provide specific information?" };
char aft_Puzz1_8[100] = { "Uh... We..." };
char aft_Puzz1_9[100] = { "We just..." };
char aft_Puzz1_10[100] = { "We want to discuss some business issues with him." };
char aft_Puzz1_11[100] = { "We represent the Ministry of Science and Technology to notify him to accept recognition" };
char aft_Puzz1_11_2[100] = { "from his superiors." };
char aft_Puzz1_12[100] = { "..." };
char aft_Puzz1_13[100] = { "..." };
char aft_Puzz1_14[100] = { "..." };
char aft_Puzz1_15[100] = { "Uh... No one should come to help me in the short term..." };
char aft_Puzz1_16[100] = { "But I still need to take you to the laboratory supervisor..." };
char aft_Puzz1_17[100] = { "Wait, did you just say that no one will come soon?" };
char aft_Puzz1_18[100] = { "Yeah. And, unfortunately, the camera here just broke down a few days ago." };
char aft_Puzz1_19[100] = { "Even so, I will still subdue you two suspicious individuals." };
char aft_Puzz1_20[100] = { "Wait!!! I\'ll explain to you." };
char aft_Puzz1_21[100] = { "Prince and I come from the future." };
char aft_Puzz1_22[100] = { "Just now you mentioned that Dragon seems to be doing something unspeakable." };
char aft_Puzz1_23[100] = { "In the future, he will use a biochemical bomb to destroy the world." };
char aft_Puzz1_24[100] = { "We are survivors of the destruction of the world, who accidentally discovered the time machine" };
char aft_Puzz1_24_2[100] = { "and used it to go back in time to stop Dragon." };
char aft_Puzz1_25[100] = { "Uh...? But.. How can you prove it..." };
char aft_Puzz1_26[100] = { "We just appeared in front of you out of thin air." };
char aft_Puzz1_27[100] = { "If this is not enough evidence, please take a look at this." };
char aft_Puzz1_28[100] = { "This photo passed through the time machine with us, so now it looks unstable." };
char aft_Puzz1_29[100] = { "With just a slight shake, you can see the content of the photo transforming from a dilapidated city" };
char aft_Puzz1_29_2[100] = { "to a bustling intersection." };
char aft_Puzz1_30[100] = { "..." };
char aft_Puzz1_31[100] = { "Even if you don\'t believe this, please believe that we are not suspicious individuals." };
char aft_Puzz1_32[100] = { "... Alright... That proof is enough. I believe your words now." };
char aft_Puzz1_33[100] = { "Then how is your plan to stop Dragon?" };
char aft_Puzz1_34[100] = { "Well... We\'re still trying to find Dragon first." };
char aft_Puzz1_35[100] = { "Then let me join you. I want to contribute to saving the world." };
char aft_Puzz1_36[100] = { "I\'m Emma, a nurse in the laboratory." };
char aft_Puzz1_37[100] = { "I have contact with most of the staff and can help you find Dragon." };
char aft_Puzz1_38[100] = { "If you are injured, I can also treat you." };
char aft_Puzz1_39[100] = { "That helps a lot." };
char aft_Puzz1_40[100] = { "I know a person who may know something about Dragon, or at least unusual mechanisms" };
char aft_Puzz1_40_2[100] = { "in the laboratory." };
char aft_Puzz1_41[100] = { "Dragon must hide in somewhere. Let\'s go, this way." };

char first_DC_1[100] = { "Hey DC, how is it going?" };
char first_DC_2[100] = { "Not bad... You looks a bit anxious. What happened?" };
char first_DC_3[100] = { "Well... Nothing." };
char first_DC_4[100] = { "Not to mention this, has there been anything in the laboratory that caught your attention" };
char first_DC_4_2[100] = { "recently?" };
char first_DC_5[100] = { "You always like to discover these details, but always have no time to personally" };
char first_DC_5_2[100] = { "explore their origins." };
char first_DC_6[100] = { "Don\'t make fun of me... But there is indeed something that caught my attention." };
char first_DC_7[100] = { "Here, a decoder. There are three coordinates recorded here." };
char first_DC_8[100] = { "If you\'re free, go and see what they all have. I need to continue writing my paper..." };
char first_DC_9[100] = { "Thanks! Hope you have a pleasant time with your deadline." };
char first_DC_10[100] = { "We\'ll contact you if we\'ve found anything about it." };

char gEt_3_dicks_1[100] = { "Hey DC, look what we\'ve found." };
char gEt_3_dicks_2[100] = { "There\'s enough free time for you... Let me see, three hard drives?" };
char gEt_3_dicks_3[100] = { "Wait for me, I'll analyze the content inside." };
char gEt_3_dicks_4[100] = { "Here it is. A coordinate and a string of passwords." };
char gEt_3_dicks_5[100] = { "This coordinate... I remember it was a door that had never been opened before." };
char gEt_3_dicks_6[100] = { "Since you are so idle, how about going and see?" };
char gEt_3_dicks_7[100] = { "Why do\'t you come with us? It\'s not far." };
char gEt_3_dicks_8[100] = { "Not getting up and walking again is not good for your waist." };
char gEt_3_dicks_9[100] = { "(Sigh) Alright, alright. Guide me then." };

char oPEn_ID_dOOr_1[100] = { "What is this... An ID card? It seems to be something related to Mr. Dragon. Why is it here?" };
char oPEn_ID_dOOr_2[100] = { "Dragon..." };
char oPEn_ID_dOOr_3[100] = { "Nobody would come to here, right?" };
char oPEn_ID_dOOr_4[100] = { "...? What do you mean?" };
char oPEn_ID_dOOr_5[100] = { "Alright... Let me tell you some truth, DC." };
char oPEn_ID_dOOr_6[100] = { "(Ellie informs DC of the fact that she and Prince come from the future. Also, she mentions" };
char oPEn_ID_dOOr_6_2[100] = { "Dragon's evil plan.)" };
char oPEn_ID_dOOr_7[100] = { "... This is truly an astonishing fact... I believe you, Ellie. I trust your character." };
char oPEn_ID_dOOr_8[100] = { "Thanks." };
char oPEn_ID_dOOr_9[100] = { "Then let me see what the ID card contains..." };
char oPEn_ID_dOOr_10[100] = { "Another coordinate pointing towards the depth of this channel." };
char oPEn_ID_dOOr_11[100] = { "Do you want to take a look? I will go with you now." };
char oPEn_ID_dOOr_12[100] = { "If the world is really going to be destroyed, I don't want to be with mountains of papers" };
char oPEn_ID_dOOr_12_2[100] = { "before the moment I die." };
char oPEn_ID_dOOr_13[100] = { "Thank you very much for your help, DC." };
char oPEn_ID_dOOr_14[100] = { "Let's move forward and see what's hidden in front of the passage." };
char oPEn_ID_dOOr_15[100] = { "We must find Dragon's hiding place." };

char bef_bOSs1_1[100] = { "Don\'t go any further... I have to stop you here." };
char bef_bOSs1_2[100] = { "Wyvern... I know him." };
char bef_bOSs1_3[100] = { "He has suffered fatal injuries and undergone mechanical organ modifications." };
char bef_bOSs1_4[100] = { "He is a talented scientist, but... Why does he become enemy with us?" };
char bef_bOSs1_5[100] = { "He is a principled person, he shouldn\'t agree with Dragon's plan..." };
char bef_bOSs1_6[100] = { "I have heard that... Dragon controls the mechanical organs inside his body." };
char bef_bOSs1_7[100] = { "So, he must have been forced to be our enemy, am I right, Wyvern?" };
char bef_bOSs1_8[100] = { "...(Sigh) That\'s true, but I don\'t want to be seen as innocent..." };
char bef_bOSs1_9[100] = { "Even if forced by Dragon, the crimes I have committed are still real." };
char bef_bOSs1_10[100] = { "Here, you kill me and release me; Alternatively, I will kill you, and let my sinful life" };
char bef_bOSs1_10_2[100] = { "be shattered under Dragon\'s bomb." };
char bef_bOSs1_11[100] = { "Since that's the case... We will provide you with liberation." };

char ending_1[100] = { "Sunrise and sunset, people live an ordinary life, but they don't know that someone has just lifted" };
char ending_1_2[100] = { "a crisis that concerns the world." };
char ending_2[100] = { "You came from the masses and eventually returned to them in obscurity." };
char ending_3[100] = { "This is a difficult journey, but thank you for being able to sustain the lives of the people." };
char ending_4[100] = { "Thank you for playing." };

/*
SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
SDL_RenderPresent(Puzzle1_Renderer);

present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Blank, P28, Blank, (char*)"man.png");
*/

bool running = true;
int main(int argc, char* argv[])
{

	// 帧率控制
	Uint64 start_t, end_t;
	int delay;

	// main event
	SDL_Event MainEvent;

	// init SDL
	INIT();

	// init player
	player.v_x = 7;
	player.v_y = 7;
	player.w = 17 * 2.5;
	player.h = 29 * 2.5;
	player.x = W / 2;
	player.y = H - player.h;
	player.r = player.w / 2;

	// init puzzle1
	puzzle1.player_column = 0;
	puzzle1.player_row = 0;
	puzzle1.register_column = 0;
	puzzle1.register_row = 0;

	// create window
	Puzzle1_Window = SDL_CreateWindow((const char *)T0, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
	Puzzle1_Renderer = SDL_CreateRenderer(Puzzle1_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// open audio
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 3, 4096) == -1)
		printf("Failed to Open Audio!\n");

	// load everything
	LOAD();

	// Init object
	Object_INIT();

	// 入场
	/*textFadeInOut(Puzzle1_Window, Puzzle1_Renderer, Date_Font, "Click to start", FontColor);*/
	int load_result = Load_IN();
	if (load_result == -1)
	{
		QUIT();
		return -1;
	}
	else if (load_result == 1)
	{
		QUIT();
		return 0;
	}
	else
	{
		player.x = gameData.playerplacex;
		player.y = gameData.playerplacey;
		map_num = gameData.map;
		kill_Scientist = gameData.s2;
		is_ID = gameData.ID;
		disk_num = gameData.disk;
		boss1_result = gameData.boss1_result;
		boss2_result = gameData.boss2_result;
		is_time_machine_dialogue = gameData.is_time_machine_dialogue;
		parkour_result = gameData.parkour_result;
		lose_count = gameData.lose_count;
	}
	if (player.x==0 && player.y==0 || boss1_result == 0 || boss2_result == 0)
	{
		if(map == 0)
		{
			player.x = W / 2;
			player.y = H - player.h;
		}
		boss1_result = 2;
		boss2_result = 2;
		parkour_result = 2;
	}
	if (is_ID == 1)
	{
		is_disk3 = 0;
		is_disk4 = 0;
		is_disk6 = 0;
	}
	//map_num = 24;  // only use to debug

	// init volume
	Mix_HaltMusic();
	Mix_Volume(-1, 0);
	int sound_channel_1 = Mix_PlayChannel(-1, SoundEffect, 0);  // 播放音效
	Mix_Volume(sound_channel_1, 32);
	Mix_VolumeMusic(64);  // 0~128

	// play Music
	Mix_PlayMusic(SoundBackGround, -1);  // 播放音乐


	while (map != map_num)
	{
		if (map_num == 1)
		{
			Map_Shift(1, 376, 305);
		}
		else if(map_num != 0)
		{
			Map_Shift(map_num, player.x, player.y);  // 方便调试
		}
		else if (map_num == 0)
		{
			Map_Shift(map_num, W/2, H - player.h);
		}
		//Map_Shift(map_num, player.x, player.y);  // 方便调试
		// represent
		SDL_RenderPresent(Puzzle1_Renderer);
	}


	surf_Pic_fOr_diAlOGue[0] = IMG_Load("assets/Ingame/broken city.png");
	txt_Pic_fOr_diAlOGue[0] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[0]);
	surf_Pic_fOr_diAlOGue[1] = IMG_Load("assets/Ingame/time machine.png");
	txt_Pic_fOr_diAlOGue[1] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[1]);
	surf_Pic_fOr_diAlOGue[2] = IMG_Load("assets/Ingame/plane for dialogue.png");
	txt_Pic_fOr_diAlOGue[2] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[2]);
	surf_Pic_fOr_diAlOGue[3] = IMG_Load("assets/Ingame/bomb chamber.png");
	txt_Pic_fOr_diAlOGue[3] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[3]);
	surf_Pic_fOr_diAlOGue[4] = IMG_Load("assets/Ingame/puzzle3 1.png");
	txt_Pic_fOr_diAlOGue[4] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[4]);
	surf_Pic_fOr_diAlOGue[5] = IMG_Load("assets/Ingame/puzzle3 2.png");
	txt_Pic_fOr_diAlOGue[5] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[5]);
	surf_Pic_fOr_diAlOGue[6] = IMG_Load("assets/Ingame/puzzle3 3.png");
	txt_Pic_fOr_diAlOGue[6] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[6]);
	surf_Pic_fOr_diAlOGue[7] = IMG_Load("assets/Ingame/puzzle3 4.png");
	txt_Pic_fOr_diAlOGue[7] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[7]);
	surf_Pic_fOr_diAlOGue[8] = IMG_Load("assets/Ingame/puzzle3 5.png");
	txt_Pic_fOr_diAlOGue[8] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[8]);
	surf_Pic_fOr_diAlOGue[9] = IMG_Load("assets/Ingame/puzzle3 6.png");
	txt_Pic_fOr_diAlOGue[9] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[9]);
	surf_Pic_fOr_diAlOGue[10] = IMG_Load("assets/Ingame/ID Card.png");
	txt_Pic_fOr_diAlOGue[10] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[10]);
	surf_Pic_fOr_diAlOGue[11] = IMG_Load("assets/Ingame/city life.png");
	txt_Pic_fOr_diAlOGue[11] = SDL_CreateTextureFromSurface(Puzzle1_Renderer, surf_Pic_fOr_diAlOGue[11]);

	while (running)
	{
		// start to get time
		start_t = SDL_GetTicks64();

		// switch title
		title_f_counter++;
		if (title_f_counter == title_FN)
		{
			title_f_counter = 0;
			switch (int(rand() % title_num))
			{
				case 0:
					SDL_SetWindowTitle(Puzzle1_Window, (const char*)T0);
					break;
				case 1:
					SDL_SetWindowTitle(Puzzle1_Window, (const char*)T1);
					break;
				case 2:
					SDL_SetWindowTitle(Puzzle1_Window, (const char*)T2);
					break;
				case 3:
					SDL_SetWindowTitle(Puzzle1_Window, (const char*)T3);
					break;
				case 4:
					SDL_SetWindowTitle(Puzzle1_Window, (const char*)T4);
					break;
				case 5:
					SDL_SetWindowTitle(Puzzle1_Window, (const char*)T5);
					break;
				default:
					break;
			}
		}

		// clear
		SDL_RenderClear(Puzzle1_Renderer);
		while (SDL_PollEvent(&MainEvent))
		{
			int pause_reault = 0;
			switch (MainEvent.type)
			{
			case SDL_QUIT:
				/*present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, a, c, c, (char*)"man.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, c, b, c, (char*)"man.png");*/
				QUIT();
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (MainEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					pause_reault = Pause();
					if (pause_reault == -1)
					{
						QUIT();
						running = false;
					}
					break;
				default:
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				// functions here
				if (map == 12)
				{
					printf("Button down at (% d, % d) in map 12\n", MainEvent.button.x - Map2_BackGroundRect.x, MainEvent.button.y - Map2_BackGroundRect.y);
				}
				else
				{
					printf("Button down at (% d, % d)\n", MainEvent.button.x, MainEvent.button.y);
				}
				break;

			case SDL_MOUSEBUTTONUP:
				if (map == 12)
				{
					printf("Player at (% d, % d)\n", player.x - player.w / 2 - Map2_BackGroundRect.x, player.y - player.h / 2 - Map2_BackGroundRect.y);
				}
				break;
			default:
				break;
			}
		}
		if (is_quit == 0)
		{
			if (map == 0)
			{

				if (!enter_is_dialogue)
				{
					SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
					SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
					SDL_RenderPresent(Puzzle1_Renderer);

					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_1, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_2, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_3, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_4, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
					
					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[0], NULL, &mAIn_fUll_sCrEEn);
					SDL_RenderPresent(Puzzle1_Renderer);

					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_5, etr_5_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_6, etr_6_2, nAMe_Prince, (char*)"Avatars/Prince.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_7, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					
					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[1], NULL, &rECt_dialogue_pic_mAIn);
					SDL_RenderPresent(Puzzle1_Renderer);

					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_8, etr_8_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_9, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_10, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_11, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, etr_12, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					if (presentstate == 0)
					{
						running = false;
						QUIT();
					}
					enter_is_dialogue = 1;//story background
				}

				Key_detect();

				Map_0();
				/*Center_Text(0, 0, W, H / 6, "Hallway");*/
				if (is_change == 1)
				{
					// 换地图
					map_num = 2;
					Map_Shift(map_num, W / 2 + Map1_BackGroundSurface->w * 3 / 2 - player.w / 2, player.y);
				}
				if (puzzle1.last_result == 1)
				{
					SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
					SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
					SDL_RenderPresent(Puzzle1_Renderer);

					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_22, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_23, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_24, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_25, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_26, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_27, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					if (presentstate == 0)
					{
						running = false;
						QUIT();
					}
					puzzle1.last_result = 0;//hint of puzzle 1
				}
			}
			else if (map == 1)
			{
				Key_detect();

				Map_1(19, 19);
				if (is_change == 1)
				{
					// 换地图
					map_num = 12;
					Map_Shift(map_num, Map2_BackGroundRect.x + 16 + player.w / 2, Map2_BackGroundRect.y + 755 + player.h / 2);
				}
			}
			else if (map == 2)
			{
				const Uint8* keystates = SDL_GetKeyboardState(NULL);

				if (keystates[SDL_SCANCODE_A] == 1 && key_cmd.a == 0)
				{
					key_cmd.a = 1;
					/*printf("A: %d\n", start_t);  // 事实证明，keystates方法一次可以检测所有按键的状态*/
				}
				else if (keystates[SDL_SCANCODE_A] == 0 && key_cmd.a > 0)
				{
					key_cmd.a -= 1;
				}
				if (keystates[SDL_SCANCODE_W] == 1 && key_cmd.w == 0)
				{
					key_cmd.w = 1;
				}
				else if (keystates[SDL_SCANCODE_W] == 0 && key_cmd.w > 0)
				{
					key_cmd.w -= 1;
				}
				if (keystates[SDL_SCANCODE_D] && key_cmd.d == 0)
				{
					key_cmd.d = 1;
				}
				else if (keystates[SDL_SCANCODE_D] == 0 && key_cmd.d > 0)
				{
					key_cmd.d -= 1;
				}
				if (keystates[SDL_SCANCODE_S] && key_cmd.s == 0)
				{
					key_cmd.s = 1;
				}
				else if (keystates[SDL_SCANCODE_S] == 0 && key_cmd.s > 0)
				{
					key_cmd.s -= 1;
				}
				if (keystates[SDL_SCANCODE_RETURN] == 1)
				{
					key_cmd.E = 1;
				}
				else if (keystates[SDL_SCANCODE_RETURN] == 0)
				{
					key_cmd.E = 0;
				}
				if (puzzle1.result == 10)
				{
					Puzzle_1();
				}

				// 输出日期
				char date[60];
				const char* Month[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

				sprintf_s(date, "%s %d -> %s %d", Month[puzzle1.register_row], puzzle1.register_column + 1, Month[puzzle1.player_row], puzzle1.player_column + 1);

				Center_Text(0, 0, W, H / 6 - 20, date);

				// 判断结果
				if (puzzle1.result == 1)
				{
					// dragon win
					puzzle1.last_result = 1;
					Map_Shift(0, W / 2, H / 2 + player.h * 2);
				}
				else if (puzzle1.result == 0)
				{
					// play Music
					Mix_HaltMusic();
					// player win
					puzzle1.last_result = 0;
					Map_Shift(1, 376, 305);
					/*goto log_in;*/
				}
			}
			else if (map == 3)
			{
				if (plane_start == 0)
				{
					plane_start = 1;
					Start_Plane_time = SDL_GetTicks64();
				}
				Key_detect();

				Are_You_Tough_Man();

				if (SDL_GetTicks64() - Start_Plane_time < 5000)
				{
					Bullet_Generate_Ratio = 40;
				}
				else if (SDL_GetTicks64() - Start_Plane_time > 5000 && SDL_GetTicks64() - Start_Plane_time < 8000)
				{
					Bullet_Generate_Ratio = 35;
				}
				else if (SDL_GetTicks64() - Start_Plane_time > 8000 && SDL_GetTicks64() - Start_Plane_time < 10000)
				{
					Bullet_Generate_Ratio = 30;
				}
				else if (SDL_GetTicks64() - Start_Plane_time > 10000 && lose_count < 5)
				{
					Bullet_Generate_Ratio = 6;
				}

				if (tough_enough_dialogue)
					// 输出秒数
					/*char hit_num[60];*/
				{
					int Time = 20000;  // 定时器倒计时(ms)
					char time[60];
					int msecond = SDL_GetTicks64() - Start_Plane_time;
					int second = (Time - msecond) / 1000;
					msecond = (Time - msecond) % 1000;
					sprintf_s(time, "%d.%ds", second, msecond);
					FontColor = { 0, 0, 0, 255 };
					Center_Text(0, 0, W, H / 3, time);
					FontColor = { 255, 255, 255, 255 };
				
					if (hit_count >= 1)
					{
						lose_count++;
						while (map != 20)
						{
							map_num = 20;
							SDL_RenderPresent(Puzzle1_Renderer);
							SDL_Delay(FT);
							Map_Shift(map_num, 600 + player.w / 2, 600 - player.h / 2);
							plane_start = 0;
						}
					}
					else if (second <= 0)
					{
						while (map != 21)
						{
							map_num = 21;
							SDL_RenderPresent(Puzzle1_Renderer);
							SDL_Delay(FT);
							Map_Shift(map_num, player.w / 2, 600 - player.h / 2);
							plane_start = 0;
						}
					}
				}
			}
			else if (map == 5)
			{
				Mix_HaltMusic();
				if (boss1_result == 2)
				{
					boss1_result = bOss1_For_sciENtist2();
				}
				else if (boss1_result == 0)
				{
					QUIT();
					running = 0;  // quit
				}
				else if (boss1_result == 1)
				{
					Map_Shift(18, W/2 - player.w, 405);  // win
				}
				else if (boss1_result == 3)
				{
					map_num = 18;
					Map_Shift(map_num, 33, 405);  // lose
				}
			}
			else if (map == 12)
			{
				Key_detect();

				Map_2(8,17);
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 13)
					{
						Map_Shift(map_num, 84,285);
					}
					else if (map_num == 15)
					{
						Map_Shift(map_num, 200, 282);
					}
					else if (map_num == 1)
					{
						Map_Shift(map_num, 925, 303);
					}
				}
			}
			else if (map == 13)
			{
				Key_detect();

				Map_3(33, 38);
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 141)
					{
						Map_Shift(14, 723, 491);
					}
					else if (map_num == 142)
					{
						Map_Shift(14, 134, 487);
					}
					else if (map_num == 12)
					{
						Map_Shift(map_num, 818, 450);
						Map2_BackGroundRect.x = W / 2 - Map2_BackGroundRect.w / 2;
						Map2_BackGroundRect.y = -H;
					}
				}
			}
			else if (map == 14)
			{
				Key_detect();

				Map_4(29, 32);
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 15)
					{
						Map_Shift(map_num, 616, 471);
					}
					else if (map_num == 16)
					{
						Map_Shift(map_num, 619, 601);
					}
					else if (map_num == 131)
					{
						Map_Shift(13, 1076, 110);
					}
					else if (map_num == 132)
					{
						Map_Shift(13, 484, 118);
					}
				}
			}
			else if (map == 15)
			{
				Key_detect();

				Map_5(18,22);
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 16)
					{
						Map_Shift(map_num, 505, 457);
					}
					else if (map_num == 12)
					{
						Map_Shift(map_num, 818, 336);
						Map2_BackGroundRect.x = W / 2 - Map2_BackGroundRect.w / 2;
						Map2_BackGroundRect.y = 289 - 443;
					}
					else if (map_num == 14)
					{
						Map_Shift(map_num, 141, 158);
					}
					else if (map_num == 17)
					{
						Map_Shift(map_num, 141, 500);
					}
				}
			}
			else if (map == 16)
			{
				Key_detect();

				Map_6(23, 28);
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 14)
					{
						Map_Shift(map_num, 727, 151);
					}
					else if (map_num == 15)
					{
						Map_Shift(map_num, 1030, 274);
					}
				}
			}
			else if (map == 17)
			{
				Key_detect();

				Map_7(39, 40);
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 18)
					{
						Map_Shift(map_num, 33, 405);
					}
					else if (map_num == 15)
					{
						Map_Shift(map_num, 611, 163);
					}
				}
			}
			else if (map == 18)
			{
				Key_detect();

				Map_8();
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 17)
					{
						Map_Shift(map_num, 1148, 313);
					}
					else if (map_num == 5 && (boss1_result == 2 || boss1_result == 3))
					{
						Map_Shift(map_num, 1030, 274);
					}
					else if ((map_num == 5 || map_num == 20) && boss1_result == 1)
					{
						map_num = 20;
						Map_Shift(map_num, 600 + player.w / 2, 600 - player.h / 2);
					}
				}
			}
			//else if (map == 19)
			//{
			//	// game over scene
			//	Key_detect();

			//	/*Game_over();*/
			//	if (is_change == 1)
			//	{
			//		// 换地图
			//		if (boss1_result == 3)
			//		{
			//			map_num = 18;
			//			Map_Shift(map_num, W / 2 - player.w, 405);
			//		}
			//		else if (boss2_result == 3)
			//		{
			//			map_num = 24;
			//			Map_Shift(map_num, W / 2, H - player.h);
			//		}
			//	}
			//}
			else if (map == 20)
			{
				// 第二幕 第0张图（飞机大战前剧情 apron）
				SDL_RenderCopy(Puzzle1_Renderer, Map20_BackGroundTexture, NULL, &Map20_BackGroundRect);
				if (lose_count == 0 || puzzle2_is_auto == 0)
				{
					puzzle2_is_auto = 1;
					Mix_HaltMusic();
					Mix_PlayMusic(Puzzle_2_bgm, -1);  // 播放音乐
				}
				/*
				这里加剧情
				*/
				if (map_num == 20)
				{
					SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
					SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
					SDL_RenderPresent(Puzzle1_Renderer);
					if (lose_count > 1)
					{
						sprintf(P30, "You have tried %d times...But I trust you can do it!", lose_count);
					}
					else if(lose_count == 1)
					{
						sprintf(P30, "Don't worry you can do it!", lose_count);
					}
					else if (lose_count == 0)
					{
						SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
						SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
						SDL_RenderPresent(Puzzle1_Renderer);

						present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, apROn_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
						present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, apROn_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
						
						SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[2], NULL, &rECt_dialogue_pic_mAIn);
						SDL_RenderPresent(Puzzle1_Renderer);
						present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, apROn_3, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
						present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, apROn_4, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
						present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, apROn_5, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
						if (presentstate == 0)
						{
							running = false;
							QUIT();
						}
					}
					if (lose_count)
					{
						present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, P30, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
						if (presentstate == 0)
						{
							running = false;
							QUIT();
						}
						Start_Plane_time = SDL_GetTicks64();
					}
					map_num = 3;
				}
				
				Map_Shift(map_num, 1030, 274);
			}
			else if (map == 21)
			{
				// 第二幕 第1张图（飞机大战后森林）
				Key_detect();

				Map_21();
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 22)
					{
						Map_Shift(map_num, player.w, H - player.h);
					}
				}
			}
			else if (map == 22)
			{
				// 第二幕 第2张图（跑酷前森林）
				Key_detect();

				Map_22();
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 23 && parkour_result == 2)
					{
						Map_Shift(map_num, player.w, H - player.h);
					}
					else if (map_num == 23 && parkour_result == -1)
					{
						Map_Shift(map_num, player.w, H - player.h);
					}
				}
			}
			else if (map == 23)
			{
				// 第二幕 跑酷
				if (parkour_result == 2)  // nothing
				{
					parkour_result = run_forest_run();
				}
				else if (parkour_result == 0)  // quit
				{
					QUIT();
					running = 0;
				}
				else if (parkour_result == 1)  // win
				{
					map_num = 24;
					Map_Shift(map_num, W / 2, H - player.h);
				}
				else if (parkour_result == -1)  // lose
				{
					map_num = 22;
					Map_Shift(map_num, W - player.w, H - player.h);
				}
			}
			else if (map == 24)
			{
				// rock hole
				Key_detect();

				Map_24();
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 25)
					{
						Map_Shift(map_num, player.w, H - player.h);
					}
				}
			}
			else if (map == 25)
			{
				Mix_HaltMusic();
				if (boss2_result == 2)
				{
					boss2_result = bOss2_For_dRaGoN(kill_Scientist);
				}
				else if (boss2_result == 0)
				{
					QUIT();
					running = 0;  // quit
				}
				else if (boss2_result == 1)
				{
					Map_Shift(26, W / 2 - player.w, 405);  // win
				}
				else if (boss2_result == 3)
				{
					map_num = 24;
					Map_Shift(map_num, W / 2, H - player.h);
				}
			}
			else if (map == 26)
			{
				if(!dialogue_beFOre_Puzz3)
				{
					SDL_RenderPresent(Puzzle1_Renderer);

					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_1, Blank, nAMe_Dragon, (char*)"Avatars/Dragon.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_2, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_3, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");

					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[3], NULL, &mAIn_fUll_sCrEEn);
					SDL_RenderPresent(Puzzle1_Renderer);

					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_4, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");

					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[4], NULL, &rECt_dialogue_pic_mAIn);
					SDL_RenderPresent(Puzzle1_Renderer);
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_5, bef_Puzz3_5_2, nAMe_DC, (char*)"Avatars/DC.png");
					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[5], NULL, &rECt_dialogue_pic_mAIn);
					SDL_RenderPresent(Puzzle1_Renderer);
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_6, bef_Puzz3_6_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[6], NULL, &rECt_dialogue_pic_mAIn);
					SDL_RenderPresent(Puzzle1_Renderer);
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_7, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_8, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[7], NULL, &rECt_dialogue_pic_mAIn);
					SDL_RenderPresent(Puzzle1_Renderer);
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_9, bef_Puzz3_9_2, nAMe_DC, (char*)"Avatars/DC.png");
					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[8], NULL, &rECt_dialogue_pic_mAIn);
					SDL_RenderPresent(Puzzle1_Renderer);
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_10, bef_Puzz3_10_2, nAMe_DC, (char*)"Avatars/DC.png");
					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[9], NULL, &rECt_dialogue_pic_mAIn);
					SDL_RenderPresent(Puzzle1_Renderer);
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_11, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_12, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_Puzz3_13, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
					if (presentstate == 0)
					{
						running = false;
						QUIT();
					}
					dialogue_beFOre_Puzz3 = 1;
				}
				Mix_HaltMusic();
				int result = Puzzle3();
				if ( result == 3)
				{
					dialogue_beFOre_Puzz3 = 0;
					map == 26;
					
				}
				else if (result == 1)
				{
					printf("You win!");
					SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[11], NULL, &mAIn_fUll_sCrEEn);
					SDL_RenderPresent(Puzzle1_Renderer);

					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, ending_1, ending_1_2, Blank, (char*)"Avatars/Aside.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, ending_2, Blank, Blank, (char*)"Avatars/Aside.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, ending_3, Blank, Blank, (char*)"Avatars/Aside.png");
					present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, ending_4, Blank, Blank, (char*)"Avatars/Aside.png");
					if (presentstate == 0)
					{
						running = false;
						QUIT();
					}
					QUIT();
				}
				else if (result == 0)
				{
					QUIT();
					running = 0;  // quit
				}
			}
			// represent
			SDL_RenderPresent(Puzzle1_Renderer);

			end_t = SDL_GetTicks64();
			delay = FT - (end_t - start_t);
			if (delay > 0 && map != 2)  // Puzzle1不需要控制帧率
			{
				SDL_Delay(delay);
			}
			else
			{
				SDL_Delay(10);
			}
		}
	}

	if (is_quit == 0)
	{
		QUIT();
	}
	
	return 0;
}
int cHooSe_oF_bOSs1()
{
	SDL_Event event1;
	int chOIce = 2;
	while (chOIce == 2)
	{
		while (SDL_PollEvent(&event1))
		{
			switch (event1.type)
			{
			case SDL_QUIT:
				QUIT();
				running = 0;
				break;
			case SDL_KEYDOWN:
				switch (event1.key.keysym.sym)
				{
				case SDLK_y:
					chOIce = 1;
					return chOIce;
					break;
				case SDLK_n:
					chOIce = 0;
					return chOIce;
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
	}
}
void INIT()
{
	// initialize and quit
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
	//Mix_Volume(-1, MIX_MAX_VOLUME);
	TTF_Init();
}
void LOAD()
{
	// choice
	choice_BackGroundSurface = IMG_Load("assets/Ingame/choice.png");
	choice_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, choice_BackGroundSurface);  // 转换为纹理
	choice_BackGroundRect.x = 0;  // choice
	choice_BackGroundRect.y = 0;
	choice_BackGroundRect.w = W;
	choice_BackGroundRect.h = H;
	// disk
	disk_BackGroundSurface = IMG_Load("assets/Ingame/disk.png");
	disk_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, disk_BackGroundSurface);  // 转换为纹理
	disk_BackGroundRect[0].x = 460;  // disk3
	disk_BackGroundRect[0].y = 415;
	disk_BackGroundRect[0].w = 35;
	disk_BackGroundRect[0].h = 35;
	disk_BackGroundRect[1].x = 1119;  // disk4
	disk_BackGroundRect[1].y = 297;
	disk_BackGroundRect[1].w = 35;
	disk_BackGroundRect[1].h = 35;
	disk_BackGroundRect[2].x = 596;  // disk6
	disk_BackGroundRect[2].y = 128;
	disk_BackGroundRect[2].w = 35;
	disk_BackGroundRect[2].h = 35;
	// Map0
	Puzzle1_BackGroundSurface = IMG_Load("assets/Ingame/teleport.png");
	Puzzle1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Puzzle1_BackGroundSurface);  // 转换为纹理
	Puzzle1_BackGroundRect.x = W/2-Puzzle1_BackGroundSurface->w/2;  // 居中
	Puzzle1_BackGroundRect.y = -H;
	Puzzle1_BackGroundRect.w = Puzzle1_BackGroundSurface->w;
	Puzzle1_BackGroundRect.h = H*2;
	// Map1
	Map1_BackGroundSurface = IMG_Load("assets/Ingame/map_1.png");
	Map1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map1_BackGroundSurface);  // 转换为纹理
	Map1_BackGroundRect.x = W/2 - 320;  // 侧边居中
	Map1_BackGroundRect.y = H / 2 - 200;
	Map1_BackGroundRect.w = 640;
	Map1_BackGroundRect.h = 400;
	// Map2
	Map2_BackGroundSurface = IMG_Load("assets/Ingame/map_2.png");
	Map2_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map2_BackGroundSurface);  // 转换为纹理
	Map2_BackGroundRect.w = 450;
	Map2_BackGroundRect.h = H * 2;
	Map2_BackGroundRect.x = W / 2 - Map2_BackGroundRect.w / 2;  // 居中
	Map2_BackGroundRect.y = -H + 220;
	// Map3
	Map3_BackGroundSurface = IMG_Load("assets/Ingame/map_3.png");
	Map3_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map3_BackGroundSurface);  // 转换为纹理
	Map3_BackGroundRect.w = Map3_BackGroundSurface->w * 3;
	Map3_BackGroundRect.h = Map3_BackGroundSurface->h * 3;
	Map3_BackGroundRect.x = W / 2 - Map3_BackGroundRect.w/2;  // 居中
	Map3_BackGroundRect.y = H / 2 - Map3_BackGroundRect.h/2;
	// Map4
	Map4_BackGroundSurface = IMG_Load("assets/Ingame/map_4.png");
	Map4_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map4_BackGroundSurface);  // 转换为纹理
	Map4_BackGroundRect.w = Map4_BackGroundSurface->w*3;
	Map4_BackGroundRect.h = Map4_BackGroundSurface->h*3;
	Map4_BackGroundRect.x = W/2 - Map4_BackGroundRect.w/2;  // 居中
	Map4_BackGroundRect.y = H/2 - Map4_BackGroundRect.h/2;
	// Map5
	Map5_BackGroundSurface = IMG_Load("assets/Ingame/map_5.png");
	Map5_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map5_BackGroundSurface);  // 转换为纹理
	Map5_BackGroundRect.x = W / 2 - 440;  // 居中
	Map5_BackGroundRect.y = H / 2 - 359;
	Map5_BackGroundRect.w = 880;
	Map5_BackGroundRect.h = 559;
	// Map5_2
	Map5_2_BackGroundSurface = IMG_Load("assets/Ingame/map_5_2.png");
	Map5_2_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map5_2_BackGroundSurface);  // 转换为纹理
	Map5_2_BackGroundRect.x = W / 2 - 440;  // 居中
	Map5_2_BackGroundRect.y = H / 2 - 359;
	Map5_2_BackGroundRect.w = 880;
	Map5_2_BackGroundRect.h = 559;
	// Map6
	Map6_BackGroundSurface = IMG_Load("assets/Ingame/map_6.png");
	Map6_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map6_BackGroundSurface);  // 转换为纹理
	Map6_BackGroundRect.w = 300;
	Map6_BackGroundRect.h = H;
	Map6_BackGroundRect.x = W/2 - Map6_BackGroundRect.w/2;  // 居中
	Map6_BackGroundRect.y = 0;
	// Map7
	Map7_BackGroundSurface = IMG_Load("assets/Ingame/map_7.png");
	Map7_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map7_BackGroundSurface);  // 转换为纹理
	Map7_BackGroundRect.w = Map4_BackGroundSurface->w * 3;
	Map7_BackGroundRect.h = Map4_BackGroundSurface->h * 3;
	Map7_BackGroundRect.x = W / 2 - Map7_BackGroundRect.w / 2;  // 居中
	Map7_BackGroundRect.y = H / 2 - Map7_BackGroundRect.h / 2;
	// Map8
	Map8_BackGroundSurface = IMG_Load("assets/Ingame/map_8.png");
	Map8_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map8_BackGroundSurface);  // 转换为纹理
	Map8_BackGroundRect.w = Map8_BackGroundSurface->w / 2;
	Map8_BackGroundRect.h = Map8_BackGroundSurface->h / 2;
	Map8_BackGroundRect.x = 0;  // 居中
	Map8_BackGroundRect.y = H / 2 - Map8_BackGroundRect.h / 2;
	// Map20
	Map20_BackGroundSurface = IMG_Load("assets/Ingame/Airport.png");
	Map20_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map20_BackGroundSurface);  // 转换为纹理
	Map20_BackGroundRect.w = W;
	Map20_BackGroundRect.h = H;
	Map20_BackGroundRect.x = 0;  // 左上
	Map20_BackGroundRect.y = 0;
	// Map21
	Map21_BackGroundSurface = IMG_Load("assets/Ingame/Forest1.jpg");
	Map21_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map21_BackGroundSurface);  // 转换为纹理
	Map21_BackGroundRect.w = Map21_BackGroundSurface->w;
	Map21_BackGroundRect.h = Map21_BackGroundSurface->h;
	Map21_BackGroundRect.x = W/2 - Map21_BackGroundRect.w/2;  // 居中
	Map21_BackGroundRect.y = H/2 - Map21_BackGroundRect.h/2;
	// Map22
	Map22_BackGroundSurface = IMG_Load("assets/Ingame/Forest2.png");
	Map22_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map22_BackGroundSurface);  // 转换为纹理
	Map22_BackGroundRect.w = Map22_BackGroundSurface->w;
	Map22_BackGroundRect.h = Map21_BackGroundSurface->h;
	Map22_BackGroundRect.x = W / 2 - Map22_BackGroundRect.w / 2;  // 居中
	Map22_BackGroundRect.y = H / 2 - Map22_BackGroundRect.h / 2;
	// Map23
	Map23_BackGroundSurface = IMG_Load("assets/Ingame/map_8.png");
	Map23_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map23_BackGroundSurface);  // 转换为纹理
	Map23_BackGroundRect.w = 0;
	Map23_BackGroundRect.h = 0;
	Map23_BackGroundRect.x = 0;  // 居中
	Map23_BackGroundRect.y = 0;
	// Map24
	Map24_BackGroundSurface = IMG_Load("assets/Ingame/rock_hole.png");
	Map24_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map24_BackGroundSurface);  // 转换为纹理
	Map24_BackGroundRect.w = Map24_BackGroundSurface->w;
	Map24_BackGroundRect.h = Map24_BackGroundSurface->h;
	Map24_BackGroundRect.x = W / 2 - Map24_BackGroundRect.w / 2;  // 居中
	Map24_BackGroundRect.y = H / 2 - Map24_BackGroundRect.h / 2;
	// Puzzle1
	Puzzle_1_BackGroundSurface = IMG_Load("assets/Ingame/Puzzle_1_0.png");
	Puzzle_1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Puzzle_1_BackGroundSurface);  // 转换为纹理
	Puzzle_1_BackGroundRect.x = 0;  // 居中
	Puzzle_1_BackGroundRect.y = 0;
	Puzzle_1_BackGroundRect.w = W;
	Puzzle_1_BackGroundRect.h = H;
	// Heart
	Heart_BackGroundSurface = IMG_Load("assets/character/heart.png");
	Heart_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Heart_BackGroundSurface);  // 转换为纹理
	Heart_BackGroundRect.x = 42;  // Jan 1st
	Heart_BackGroundRect.y = 96 + puzzle1.puzzle_1_h / 2 - puzzle1.puzzle_1_w / 2;
	Heart_BackGroundRect.w = puzzle1.puzzle_1_w;
	Heart_BackGroundRect.h = puzzle1.puzzle_1_w;
	// Dragon_Heart
	Dragon_Heart_BackGroundSurface = IMG_Load("assets/character/dragon_heart.png");
	Dragon_Heart_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Dragon_Heart_BackGroundSurface);  // 转换为纹理
	// Shifter
	Shifter_BackGroundSurface = IMG_Load("assets/Ingame/background1_0.png");
	Shifter_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Shifter_BackGroundSurface);  // 转换为纹理
	Shifter_BackGroundRect.x = 0;
	Shifter_BackGroundRect.y = 0;
	Shifter_BackGroundRect.w = W;
	Shifter_BackGroundRect.h = H;
	// Game over
	GameOver_BackGroundSurface = IMG_Load("assets/Ingame/GameOver.png");
	GameOver_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, GameOver_BackGroundSurface);  // 转换为纹理
	GameOver_BackGroundRect.x = 0;
	GameOver_BackGroundRect.y = 0;
	GameOver_BackGroundRect.w = W;
	GameOver_BackGroundRect.h = H;
	// 左右
	Player0_BackGroundSurface = IMG_Load("assets/character/spr_maincharal_0.png");
	Player0_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player0_BackGroundSurface);  // 转换为纹理
	Player0_BackGroundRect.x = player.x - player.w / 2;
	Player0_BackGroundRect.y = player.y - player.h / 2;
	Player0_BackGroundRect.w = player.w;
	Player0_BackGroundRect.h = player.h;
	Player1_BackGroundSurface = IMG_Load("assets/character/spr_maincharal_1.png");
	Player1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player1_BackGroundSurface);  // 转换为纹理
	Player12_BackGroundSurface = IMG_Load("assets/character/spr_maincharal_2.png");
	Player12_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player12_BackGroundSurface);
	// 上行
	Player2_BackGroundSurface = IMG_Load("assets/character/spr_maincharau_0.png");
	Player2_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player2_BackGroundSurface);  // 转换为纹理
	Player3_BackGroundSurface = IMG_Load("assets/character/spr_maincharau_1.png");
	Player3_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player3_BackGroundSurface);  // 转换为纹理
	Player4_BackGroundSurface = IMG_Load("assets/character/spr_maincharau_2.png");
	Player4_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player4_BackGroundSurface);  // 转换为纹理
	Player5_BackGroundSurface = IMG_Load("assets/character/spr_maincharau_3.png");
	Player5_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player5_BackGroundSurface);  // 转换为纹理
	// 下行
	Player6_BackGroundSurface = IMG_Load("assets/character/spr_maincharad_water_0.png");
	Player6_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player6_BackGroundSurface);  // 转换为纹理
	Player7_BackGroundSurface = IMG_Load("assets/character/spr_maincharad_water_1.png");
	Player7_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player7_BackGroundSurface);  // 转换为纹理
	Player8_BackGroundSurface = IMG_Load("assets/character/spr_maincharad_water_2.png");
	Player8_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player8_BackGroundSurface);  // 转换为纹理
	Player9_BackGroundSurface = IMG_Load("assets/character/spr_maincharad_water_3.png");
	Player9_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player9_BackGroundSurface);  // 转换为纹理
	// Plane
	Plane_BackGroundSurface = IMG_Load("assets/character/plane.png");
	Plane_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Plane_BackGroundSurface);  // 转换为纹理
	Plane_BackGroundRect.w = Plane_BackGroundSurface->w / 1.5;
	Plane_BackGroundRect.h = Plane_BackGroundSurface->h / 1.5;
	Plane_BackGroundRect.x = W / 2 - Plane_BackGroundRect.w / 2;
	Plane_BackGroundRect.y = H / 2 - Plane_BackGroundRect.h / 2;
	// Plane fight
	Plane_fight_BackGroundSurface = IMG_Load("assets/Ingame/PlaneBattle.png");
	Plane_fight_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Plane_fight_BackGroundSurface);  // 转换为纹理
	Plane_fight_BackGroundRect_B[0].w = W;
	Plane_fight_BackGroundRect_B[0].h = Plane_fight_BackGroundSurface->h * W / Plane_fight_BackGroundSurface->w;  // 等比例放缩
	Plane_fight_BackGroundRect_B[0].x = 0;
	Plane_fight_BackGroundRect_B[0].y = 0;
	Plane_fight_BackGroundRect_B[1].w = W;
	Plane_fight_BackGroundRect_B[1].h = Plane_fight_BackGroundSurface->h * W / Plane_fight_BackGroundSurface->w;  // 等比例放缩
	Plane_fight_BackGroundRect_B[1].x = 0;
	Plane_fight_BackGroundRect_B[1].y = -Plane_fight_BackGroundRect_B[1].h;

	// Plane_BG_IMG( no use, only to fit the old code)
	Plane_fight_BackGroundRect.x = 0;
	Plane_fight_BackGroundRect.y = 0;
	Plane_fight_BackGroundRect.w = W;
	Plane_fight_BackGroundRect.h = H;

	// Bullet
	Bullet_BackGroundSurface = IMG_Load("assets/Ingame/bullet.png");
	Bullet_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Bullet_BackGroundSurface);  // 转换为纹理
	for (int i = 0; i < Bullet_num; i++)
	{
		Bullet_BackGroundRect[i].w = Plane_BackGroundSurface->h / 6;
		Bullet_BackGroundRect[i].h = Plane_BackGroundSurface->h / 6;  // the size of bullet is one six of the plane's Surface height
		Bullet[i].r = Bullet_BackGroundRect[i].w / 2;
	}


	Date_Font = TTF_OpenFont("assets/Font/Allan-Regular.ttf", 50);

	SoundEffect = Mix_LoadWAV("assets/Audio/teleport.mp3");
	Error_SoundEffect = Mix_LoadWAV("assets/Audio/error.mp3");
	SoundBackGround = Mix_LoadMUS("assets/Audio/bar.mp3");
	Puzzle_1_bgm = Mix_LoadMUS("assets/Audio/puzzle1.mp3");
	Puzzle_2_bgm = Mix_LoadMUS("assets/Audio/Plane.mp3");
	Before_boss2_bgm = Mix_LoadMUS("assets/Audio/beforBOSS2.mp3");
}
void PrintPlayer()
{
	int F_N = MT; // Compute how many frames for one motion of the player
	int F_T = FT;
	F_N = F_N / F_T;
	F_counter++;

	Player0_BackGroundRect = { player.x - player.w / 2, player.y - player.h / 2, player.w, player.h };

	// 渲染玩家碰撞箱（用于调试）
	/*SDL_RenderDrawRect(Puzzle1_Renderer, &Player0_BackGroundRect);*/

	if (key_cmd.d == 1 && key_cmd.a == 0)
	{
		key_cmd.l_cmd = char("d");
		if (F_counter >= 0 && F_counter < F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (F_counter >= F_N && F_counter < 2 * F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player1_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (F_counter >= 2 * F_N && F_counter < 3 * F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (F_counter >= 3 * F_N && F_counter < 4 * F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player12_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (F_counter >= 4 * F_N)
		{
			F_counter = 0;
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
	}
	else if (key_cmd.d == 0 && key_cmd.a == 1)
	{
		key_cmd.l_cmd = char("a");
		if (F_counter >= 0 && F_counter < F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
		}
		else if (F_counter >= F_N && F_counter < 2 * F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player1_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
		}
		else if (F_counter >= 2 * F_N && F_counter < 3 * F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
		}
		else if (F_counter >= 3 * F_N && F_counter < 4 * F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player12_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
		}
		else if (F_counter >= 4 * F_N)
		{
			F_counter = 0;
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
		}
	}
	else if ((key_cmd.d == 0 && key_cmd.a == 0) || (key_cmd.d == 1 && key_cmd.a == 1))
	{
		if (key_cmd.w == 1 && key_cmd.s == 0)
		{
			key_cmd.l_cmd = char("w");
			if (F_counter >= 0 && F_counter < F_N)
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player2_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else if (F_counter >= F_N && F_counter < 2 * F_N)
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player3_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else if (F_counter >= 2 * F_N && F_counter < 3 * F_N)
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player4_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else if (F_counter >= 3 * F_N && F_counter < 4 * F_N)
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player5_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else
			{
				F_counter = 0;
				SDL_RenderCopyEx(Puzzle1_Renderer, Player2_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
		}
		else if (key_cmd.w == 0 && key_cmd.s == 1)
		{
			key_cmd.l_cmd = char("s");
			if (F_counter >= 0 && F_counter < F_N)
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player6_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else if (F_counter >= F_N && F_counter < 2 * F_N)
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player7_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else if (F_counter >= 2 * F_N && F_counter < 3 * F_N)
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player8_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else if (F_counter >= 3 * F_N && F_counter < 4 * F_N)
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player9_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else
			{
				F_counter = 0;
				SDL_RenderCopyEx(Puzzle1_Renderer, Player6_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
		}
		else if (key_cmd.a == 0 && key_cmd.d == 0 && key_cmd.s == 0 && key_cmd.w == 0)
		{
			if (key_cmd.l_cmd == char("d"))
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
			}
			else if (key_cmd.l_cmd == char("a"))
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else if (key_cmd.l_cmd == char("w"))
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player2_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else if (key_cmd.l_cmd == char("s"))
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player6_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
			}
			else
			{
				SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
			}
		}
		else
		{
			// 防止其它奇奇怪怪操作（如只同时按A,D或W,S键）时人物消失
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
	}
	else
	{
		// 防止其它奇奇怪怪操作（如同时按A,D键）时人物消失
		SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
	}
}
void Player_move(int start, int end)
{
	/*

	*/
	int x_register = player.x;
	int y_register = player.y;

	// 处理移动
	if (key_cmd.w == 1)
	{
		y_register -= player.v_y;
		if (start != 0 || end != 0)
		{
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)  // collision detect
		{
			player.y -= player.v_y;
		}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.s == 1)
	{
		y_register += player.v_y;
		if (start != 0 || end != 0)
		{
			if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)  // collision detect
			{
				player.y += player.v_y;
			}
		}
		x_register = player.x;
		y_register = player.y;
	}
	if (key_cmd.a == 1)
	{
		x_register -= player.v_x;
		if (start != 0 || end != 0)
		{
			if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)  // collision detect
			{
				player.x -= player.v_x;
			}
		}
		x_register = player.x;
		y_register = player.y;
	}
	if (key_cmd.d == 1)
	{
		x_register += player.v_x;
		if (start != 0 || end != 0)
		{
			if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)  // collision detect
			{
				player.x += player.v_x;
			}
		}
		x_register = player.x;
		y_register = player.y;
	}
}
void Map_0()
{
	int x_register = player.x;
	int y_register = player.y;

	// 处理地图移动
	if (key_cmd.w == 1 && player.y >= H / 2 && Puzzle1_BackGroundRect.y + player.v_y <= 0)
	{
		// 此时地图不到头，人在下半屏
		y_register -= player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 6) == 0)  // collision detect
		{
			player.y -= player.v_y;
			if (player.y <= H / 2)
			{
				int i = H / 2 - player.y;
				player.y = H / 2;
				Puzzle1_BackGroundRect.y += i;
			}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	else if (key_cmd.w == 1 && player.y <= H / 2 && Puzzle1_BackGroundRect.y + player.v_y > 0)
	{
		// 此时地图(快)到头，人在上半屏
		y_register -= player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 6) == 0)  // collision detect
		{
			Puzzle1_BackGroundRect.y = 0;
			if (player.y - player.v_y > player.h / 2)
			{
				player.y -= player.v_y;
			}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.s == 1 && player.y <= H / 2 && Puzzle1_BackGroundRect.y - player.v_y >= -H)
	{
		// 此时地图不到头，人在上半屏
		y_register += player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 6) == 0)
		{
			player.y += player.v_y;
			if (player.y > H / 2)
			{
				int i = player.y - H / 2;
				player.y = H / 2;
				Puzzle1_BackGroundRect.y -= i;
			}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	else if (key_cmd.s == 1 && player.y >= H / 2 && Puzzle1_BackGroundRect.y - player.v_y <= -H)
	{
		// 此时地图（快）到头，人在下半屏
		y_register += player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 6) == 0)
		{
			Puzzle1_BackGroundRect.y = -H;
			if (player.y + player.v_y <= H - player.h / 2)
			{
				player.y += player.v_y;
			}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.a == 1)
	{
		// 此时地图不到头，人在右半屏
		x_register -= player.v_x;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 6) == 0)  // collision detect
		{
			player.x -= player.v_x;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.d == 1)
	{
		// 此时地图不到头，人在左半屏
		x_register += player.v_x;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 6) == 0)  // collision detect
		{
			player.x += player.v_x;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	//if (key_cmd.a == 1 && Puzzle1_BackGroundRect.x + player.v_x < W / 2 && player.x >= W / 2)
	//{
	//	// 此时地图不到头，人在右半屏
	//	x_register -= player.v_x;
	//	if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 1) == 0)  // collision detect
	//	{
	//		player.x -= player.v_x;
	//		if (player.x <= W / 2)
	//		{
	//			int i = W / 2 - player.x;
	//			player.x = W / 2;
	//			Puzzle1_BackGroundRect.x += i;
	//		}
	//	}
	//	x_register = player.x;
	//	y_register = player.y;  // 防止影响后续判断
	//}
	//else if (key_cmd.a == 1 && Puzzle1_BackGroundRect.x + player.v_x >= W/2)
	//{
	//	// 此时地图(快)到头了，人在左半屏
	//	x_register -= player.v_x;
	//	if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 1) == 0)  // collision detect
	//	{
	//		player.x -= player.v_x;
	//		Puzzle1_BackGroundRect.x = W / 2;
	//		if (player.x < Puzzle1_BackGroundRect.x + player.w / 2)
	//		{
	//			player.x = Puzzle1_BackGroundRect.x + player.w / 2;
	//		}
	//	}
	//	x_register = player.x;
	//	y_register = player.y;  // 防止影响后续判断
	//}
	//if (key_cmd.d == 1 && Puzzle1_BackGroundRect.x - player.v_x > W/2-Puzzle1_BackGroundSurface->w && player.x <= W / 2)
	//{
	//	// 此时地图不到头，人在左半屏
	//	x_register += player.v_x;
	//	if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 1) == 0)  // collision detect
	//	{
	//		player.x += player.v_x;
	//		if (player.x >= W / 2)
	//		{
	//			int i = player.x - W / 2;
	//			player.x = W / 2;
	//			Puzzle1_BackGroundRect.x -= i;
	//		}
	//		/*if (player.x <= player.w && key_cmd.E == 1)
	//		{
	//			is_change = 1;
	//		}*/
	//	}
	//	x_register = player.x;
	//	y_register = player.y;  // 防止影响后续判断
	//}
	//else if (key_cmd.d == 1 && Puzzle1_BackGroundRect.x - player.v_x <= W/2 - Puzzle1_BackGroundSurface->w)
	//{
	//	// 此时地图(快)到头了，人在右半屏
	//	x_register += player.v_x;
	//	if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 1) == 0)  // collision detect
	//	{
	//		player.x += player.v_x;
	//		/*if (player.x <= player.w && key_cmd.E == 1)
	//		{
	//			is_change = 1;
	//		}*/
	//	}
	//	x_register = player.x;
	//	y_register = player.y;  // 防止影响后续判断
	//}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Puzzle1_BackGroundTexture, NULL, &Puzzle1_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();
	if (player.y <= player.h && is_time_machine_dialogue == 0)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_2, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_3, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_4, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_5, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_6, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_7, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_8, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_9, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_10, Blank,nAMe_Ellie,  (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_11, Blank,nAMe_Ellie,  (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_12, Blank,nAMe_Ellie,  (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_13, Blank,nAMe_Ellie,  (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_14, Blank,nAMe_Ellie,  (char*)"Avatars/Ellie.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		is_time_machine_dialogue = 1;
	}
	else if (player.y <= player.h && key_cmd.E == 1)
	{
		is_change = 1;
	}
}
void Map_1(int start, int end)
{
	Player_move(start, end);
	if (key_cmd.E == 1)
	{
		if (player.x >= 930 - player.w * 2)
		{
			is_change = 1;
			map_num = 12;
		}
		//else if (player.x >= 374 && player.x <= 790 && player.y >= 118 && player.y <= 332)
		//{
		//	is_change = 1;
		//	map_num = 2;
		//}
		//else if (player.x >= 147 && player.x <= 220 && player.y >= 363 - player.h / 2 && player.y <= 523 - player.h / 2)
		//{
		//	is_change = 1;
		//	map_num = 5;
		//}
		//else if (player.x >= 556 + player.w / 2 && player.x <= 648 + player.w / 2 && player.y >= 516 - player.h / 2)
		//{
		//	is_change = 1;
		//	map_num = 3;
		//}
	}

	// 限制移动
	if (player.y >= 315)
	{
		player.y = 315;
	}
	if (player.y <= 260)
	{
		player.y = 260;
	}
	if (player.x >= 930)
	{
		player.x = 930;
	}
	if (player.x <= 345)
	{
		player.x = 345;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map1_BackGroundTexture, NULL, &Map1_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();

	if (!dialogue_Emma)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_2, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_3, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_4, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_5, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_6, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_7, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_8, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_9, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_10, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_11, aft_Puzz1_11_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_12, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_13, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_14, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_15, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_16, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_17, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_18, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_19, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_20, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_21, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_22, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_23, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_24, aft_Puzz1_24_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_25, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_26, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_27, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");

		SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[0], NULL, &rECt_dialogue_pic_mAIn);
		SDL_RenderPresent(Puzzle1_Renderer);

		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_28, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_29, aft_Puzz1_29_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_30, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_31, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_32, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_33, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_34, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_35, Blank, nAMe_who, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_36, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_37, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_38, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_39, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_40, aft_Puzz1_40_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_Puzz1_41, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		dialogue_Emma = 1;
	}

}
void Map_2(int start, int end)
{
	int x_register = player.x;
	int y_register = player.y;

	// 处理地图移动
	if (player.y < H / 2 && Map2_BackGroundRect.y + player.v_y <= 0)
	{
		// 此时地图显示出现错误
		int i = H / 2 - player.y;
		player.y = H / 2;
		Map2_BackGroundRect.y + i;
	}
	if (player.y > H / 2 && Map2_BackGroundRect.y - player.v_y >= -H)
	{
		// 此时地图显示出现错误
		int i = player.y - H / 2;
		player.y = H / 2;
		Map2_BackGroundRect.y - i;
	}
	if (key_cmd.w == 1 && player.y >= H / 2 && Map2_BackGroundRect.y + player.v_y <= 0)
	{
		// 此时地图不到头，人在下半屏
		y_register -= player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)  // collision detect
		{
			player.y -= player.v_y;
			if (player.y <= H / 2)
			{
				int i = H / 2 - player.y;
				player.y = H / 2;
				Map2_BackGroundRect.y += i;
			}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	else if (key_cmd.w == 1 && player.y <= H / 2 && Map2_BackGroundRect.y + player.v_y > 0)
	{
		// 此时地图(快)到头，人在上半屏
		y_register -= player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)  // collision detect
		{
			Map2_BackGroundRect.y = 0;
			if (player.y - player.v_y > player.h / 2)
			{
				player.y -= player.v_y;
			}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.s == 1 && player.y <= H / 2 && Map2_BackGroundRect.y - player.v_y >= -H)
	{
		// 此时地图不到头，人在上半屏
		y_register += player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)
		{
			player.y += player.v_y;
			if (player.y > H / 2)
			{
				int i = player.y - H / 2;
				player.y = H / 2;
				Map2_BackGroundRect.y -= i;
			}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	else if (key_cmd.s == 1 && player.y >= H / 2 && Map2_BackGroundRect.y - player.v_y <= -H)
	{
		// 此时地图（快）到头，人在下半屏
		y_register += player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)
		{
			Map2_BackGroundRect.y = -H;
			if (player.y + player.v_y <= H - player.h / 2)
			{
				player.y += player.v_y;
			}
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.a == 1)
	{
		// 此时地图不到头，人在右半屏
		x_register -= player.v_x;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)  // collision detect
		{
			player.x -= player.v_x;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.d == 1)
	{
		// 此时地图不到头，人在左半屏
		x_register += player.v_x;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, start, end) == 0)  // collision detect
		{
			player.x += player.v_x;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	// update collision box
	Object_Update();

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map2_BackGroundTexture, NULL, &Map2_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();

	if (key_cmd.E == 1)
	{
		if (player.x >= Map2_BackGroundRect.x + 170 + player.w / 2 && player.y >= Map2_BackGroundRect.y + 1030 + player.h / 2 && player.y <= Map2_BackGroundRect.y + 1072 + player.h / 2)
		{
			is_change = 1;
			map_num = 13;
		}
		else if (player.x >= Map2_BackGroundRect.x + 156 + player.w / 2 && player.y >= Map2_BackGroundRect.y + 400 + player.h / 2 && player.y <= Map2_BackGroundRect.y + 463 + player.h / 2)
		{
			is_change = 1;

			map_num = 15;
		}
		else if (player.x <= Map2_BackGroundRect.x + 58 + player.w / 2 && player.y >= Map2_BackGroundRect.y + 715 + player.h / 2 && player.y <= Map2_BackGroundRect.y + 764 + player.h / 2)
		{
			is_change = 1;
			map_num = 1;
		}
	}
}
void Map_3(int start, int end)
{
	Player_move(start, end);
	if (key_cmd.E == 1)
	{
		if (player.x <= 125)
		{
			is_change = 1;
			map_num = 12;
		}
		else if (player.x >= 430 && player.x <= 550 && player.y <= 150)
		{
			is_change = 1;
			map_num = 142;
		}
		else if (player.x >= 1025 && player.x <= 1135 && player.y <= 150)
		{
			is_change = 1;
			map_num = 141;
		}
	}

	// 限制移动
	if (player.y >= 400)
	{
		player.y = 400;
	}
	if (player.y <= 90)
	{
		player.y = 90;
	}
	if (player.x >= 1112)
	{
		player.x = 1112;
	}
	if (player.x <= 59)
	{
		player.x = 59;
	}
	// 渲染disk
	
	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map3_BackGroundTexture, NULL, &Map3_BackGroundRect);
	if (is_disk3 == 1 && map5_is_dialogue == 1)
	{
		SDL_RenderCopy(Puzzle1_Renderer, disk_BackGroundTexture, NULL, &disk_BackGroundRect[0]);
		if (Collision_Detect(player.x - player.w / 2, player.y - player.h / 2, player.r, 50, 50) == 1)
		{
			is_disk3 = 0;
			if (is_disk3 == 0 && is_disk4 == 0 && is_disk6 == 0)
			{
				SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
				SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
				SDL_RenderPresent(Puzzle1_Renderer);

				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_3, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_4, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_5, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_6, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_7, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_8, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_9, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				if (presentstate == 0)
				{
					running = false;
					QUIT();
				}
				is_ID = 1;
			}
		}
	}
	// 渲染玩家动画
	PrintPlayer();
}
void Map_4(int start, int end)
{
	Player_move(start, end);
	if (key_cmd.E == 1)
	{
		if (player.x >= 80 && player.x <= 188 && player.y <= 160)
		{
			is_change = 1;
			map_num = 15;
		}
		else if (player.x >= 670 && player.x <= 785 && player.y <= 160)
		{
			is_change = 1;
			map_num = 16;
		}
		else if (player.x >= 670 && player.x <= 785 && player.y >= 450)
		{
			is_change = 1;
			map_num = 131;
		}
		else if (player.x >= 80 && player.x <= 188 && player.y >= 450)
		{
			is_change = 1;
			map_num = 132;
		}
	}

	// 限制移动
	if (player.y >= 495)
	{
		player.y = 495;
	}
	if (player.y <= 114)
	{
		player.y = 114;
	}
	if (player.x >= 1127)
	{
		player.x = 1127;
	}
	if (player.x <= 96)
	{
		player.x = 96;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map4_BackGroundTexture, NULL, &Map4_BackGroundRect);
	if (is_disk4 == 1 && map5_is_dialogue == 1)
	{
		SDL_RenderCopy(Puzzle1_Renderer, disk_BackGroundTexture, NULL, &disk_BackGroundRect[1]);
		if (Collision_Detect(player.x - player.w / 2, player.y - player.h / 2, player.r, 51, 51) == 1)
		{
			is_disk4 = 0;
			if (is_disk3 == 0 && is_disk4 == 0 && is_disk6 == 0)
			{
				SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
				SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
				SDL_RenderPresent(Puzzle1_Renderer);

				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_3, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_4, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_5, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_6, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_7, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_8, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_9, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				if (presentstate == 0)
				{
					running = false;
					QUIT();
				}
				is_ID = 1;
			}
		}
	}
	// 渲染玩家动画
	PrintPlayer();
}
void Map_5(int start, int end)
{
	Player_move(start, end);
	if (key_cmd.E == 1)
	{
		if (player.x >= 585 && player.x <= 650 && player.y >= 465)
		{
			is_change = 1;
			map_num = 14;
		}
		else if (player.x >= 1020 && player.y <= 310 && player.y >= 245)
		{
			is_change = 1;
			map_num = 16;
		}
		else if (player.x <= 235 && player.y <= 315 && player.y >= 235)
		{
			is_change = 1;
			map_num = 12;
		}
		else if (player.x >= 560 && player.x <= 666 && player.y <= 195 && is_ID == 1)
		{
			is_change = 1;
			map_num = 17;
		}
	}

	// 限制移动
	if (player.y >= 490)
	{
		player.y = 490;
	}
	if (player.y <= 124)
	{
		player.y = 124;
	}
	if (player.x >= 1058)
	{
		player.x = 1058;
	}
	if (player.x <= 193)
	{
		player.x = 193;
	}

	// 渲染背景
	if (is_ID == 1 && map_ID_opeNDoor == 1)
	{
		SDL_RenderCopy(Puzzle1_Renderer, Map5_2_BackGroundTexture, NULL, &Map5_BackGroundRect);
	}
	else
	{
		SDL_RenderCopy(Puzzle1_Renderer, Map5_BackGroundTexture, NULL, &Map5_BackGroundRect);
	}
	// 渲染玩家动画
	PrintPlayer();
	// dialogue
	if (player.y < 171 && map5_is_dialogue == 0)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);

		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_3, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_4, first_DC_4_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_5, first_DC_5_2, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_6, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_7, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_8, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_9, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, first_DC_10, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		map5_is_dialogue = 1;
	}
	if (player.y < 171 && key_cmd.E == 1 && is_ID == 1 && map_ID_opeNDoor == 0)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderCopy(Puzzle1_Renderer, txt_Pic_fOr_diAlOGue[10], NULL, &rECt_dialogue_pic_mAIn);
		SDL_RenderPresent(Puzzle1_Renderer);

		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_1, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_2, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_3, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_4, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_5, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_6, oPEn_ID_dOOr_6_2, Blank, (char*)"Avatars/Aside.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_7, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_8, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_9, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_10, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_11, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_12, oPEn_ID_dOOr_12_2, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_13, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_14, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, oPEn_ID_dOOr_15, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		map_ID_opeNDoor = 1;
	}
}
void Map_6(int start, int end)
{
	Player_move(start, end);
	if (key_cmd.E == 1)
	{
		if (player.x <= 530 && player.y <= 480 && player.y >= 420)
		{
			is_change = 1;
			map_num = 15;
		}
		else if (player.x <= 670 && player.x >= 587 && player.y >= 580)
		{
			is_change = 1;
			map_num = 14;
		}
	}

	// 限制移动
	if (player.y >= 613)
	{
		player.y = 613;
	}
	if (player.x <= 491)
	{
		player.x = 491;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map6_BackGroundTexture, NULL, &Map6_BackGroundRect);
	if (is_disk6 == 1 && map5_is_dialogue ==1)
	{
		SDL_RenderCopy(Puzzle1_Renderer, disk_BackGroundTexture, NULL, &disk_BackGroundRect[2]);
		if (Collision_Detect(player.x - player.w / 2, player.y - player.h / 2, player.r, 52, 52) == 1)
		{
			is_disk6 = 0;
			if (is_disk3 == 0 && is_disk4 == 0 && is_disk6 == 0)
			{
				SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
				SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
				SDL_RenderPresent(Puzzle1_Renderer);

				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_3, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_4, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_5, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_6, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_7, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_8, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
				present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, gEt_3_dicks_9, Blank, nAMe_DC, (char*)"Avatars/DC.png");
				if (presentstate == 0)
				{
					running = false;
					QUIT();
				}
				is_ID = 1;
			}
		}
	}
	// 渲染玩家动画
	PrintPlayer();
}
void Map_7(int start, int end)
{
	Player_move(start, end);
	if (key_cmd.E == 1)
	{
		if (player.x <= 205 && player.x >= 95 && player.y >= 475)
		{
			is_change = 1;
			map_num = 15;
		}
		else if (player.x <= 1200 && player.x >= 1100 && player.y <= 320)
		{
			is_change = 1;
			map_num = 18;
		}
	}

	// 限制移动
	if (player.y >= 502)
	{
		player.y = 502;
	}
	if (player.y <= 264)
	{
		player.y = 264;
	}
	if (player.x >= 1179)
	{
		player.x = 1179;
	}
	if (player.x <= 108)
	{
		player.x = 108;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map7_BackGroundTexture, NULL, &Map7_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();
}
int map_8_kill_flag = 0;
void Map_8()
{
	if (map_8_kill_flag == 0 && boss1_result == 1)
	{
		SDL_RenderCopy(Puzzle1_Renderer, Map8_BackGroundTexture, NULL, &Map8_BackGroundRect);
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);

		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_1, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_2, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_3, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");

		SDL_RenderCopy(Puzzle1_Renderer, choice_BackGroundTexture, NULL, &choice_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);
		kill_Scientist =cHooSe_oF_bOSs1();
		
		SDL_SetRenderDrawColor(Puzzle1_Renderer, 0, 0, 0, 255);
		SDL_RenderClear(Puzzle1_Renderer);
		SDL_RenderCopy(Puzzle1_Renderer, Map8_BackGroundTexture, NULL, &Map8_BackGroundRect);
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		switch (kill_Scientist)
		{
		case 0:
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_1, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_3, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_4, Blank, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_5, Blank, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_6, Blank, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_7, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_8, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_9, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_10, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_11, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_12, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_13, aft_bOSs1_c2_13_2, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c2_14, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		case 1:
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_bOSs1_c1_1, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		default:
			break;
		}
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		map_8_kill_flag = 1;
	}
	int x_register = player.x;
	int y_register = player.y;

	// 处理地图移动
	if (key_cmd.w == 1)
	{
		y_register -= player.v_y;
		if (1)  // collision detect
		{
			player.y -= player.v_y;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.s == 1)
	{
		y_register += player.v_y;
		if (1)
		{
			player.y += player.v_y;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.a == 1 && Map8_BackGroundRect.x + player.v_x < 0 && player.x >= W / 2)
	{
		// 此时地图不到头，人在右半屏
		player.x -= player.v_x;
		if (player.x <= W / 2)
		{
			int i = W / 2 - player.x;
			player.x = W / 2;
			Map8_BackGroundRect.x += i;
		}
		/*Puzzle1_BackGroundRect.x += player.v_x;*/
	}
	else if (key_cmd.a == 1 && Map8_BackGroundRect.x + player.v_x >= 0)
	{
		// 此时地图(快)到头了，人在左半屏
		player.x -= player.v_x;
		Map8_BackGroundRect.x = 0;
		if (player.x < player.w / 2)
		{
			player.x = player.w / 2;
		}
	}
	if (key_cmd.d == 1 && Map8_BackGroundRect.x - player.v_x > -Map8_BackGroundRect.w + W && player.x <= W / 2)
	{
		// 此时地图不到头，人在左半屏
		player.x += player.v_x;
		if (player.x >= W / 2)
		{
			int i = player.x - W / 2;
			player.x = W / 2;
			Map8_BackGroundRect.x -= i;
		}
		if (player.x <= player.w && key_cmd.E == 1)
		{
			is_change = 1;
		}
	}
	else if (key_cmd.d == 1 && Map8_BackGroundRect.x - player.v_x <= -Map8_BackGroundRect.w + W)
	{
		// 此时地图(快)到头了，人在右半屏
		player.x += player.v_x;
		if (player.x >= W - player.w / 2)
		{
			player.x = W - player.w / 2;
		}
	}

	if (key_cmd.E == 1)
	{
		if (player.x <= 65)
		{
			is_change = 1;
			map_num = 17;
		}

		else if (player.x >= 1170 && SDL_GetTicks64() - Last_E_time >= 250)
		{
			is_change = 1;
			map_num = 5;
		}
	}
	if (player.x >= W / 2 && !dialogue_Wyvern)
	{
		if (!dialogue_Wyvern)
		{
			SDL_RenderCopy(Puzzle1_Renderer, Map8_BackGroundTexture, NULL, &Map8_BackGroundRect);
			SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
			SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
			SDL_RenderPresent(Puzzle1_Renderer);
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_1, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_2, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_3, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_4, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_5, Blank, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_6, Blank, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_7, Blank, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_8, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_9, Blank, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_10, bef_bOSs1_10_2, nAMe_Wyvern, (char*)"Avatars/Wyvern.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_bOSs1_11, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
			if (presentstate == 0)
			{
				running = false;
				QUIT();
			}
			dialogue_Wyvern = 1;
		}
		is_change = 1;
		map_num = 5;
	}

	// 限制移动
	if (player.y >= 405)
	{
		player.y = 405;
	}
	if (player.y <= 362)
	{
		player.y = 362;
	}
	if (player.x >= W - player.w / 2)
	{
		player.x = W - player.w / 2;
	}
	if (player.x <= player.w/2)
	{
		player.x = player.w / 2;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map8_BackGroundTexture, NULL, &Map8_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();
}
void Map_21()
{
	Player_move(19, 19);
	if (key_cmd.E == 1)
	{
		if (player.x >= 1069)
		{
			is_change = 1;
			map_num = 22;
		}
	}

	// 限制移动
	if (player.y >= Map21_BackGroundRect.h + Map21_BackGroundRect.y - player.h/2-1)
	{
		player.y = Map21_BackGroundRect.h + Map21_BackGroundRect.y - player.h/2-1;
	}
	if (player.y <= 520)
	{
		player.y = 520;
	}
	if (player.x >= Map21_BackGroundRect.w + Map21_BackGroundRect.x - player.w / 2 - 1)
	{
		player.x = Map21_BackGroundRect.w + Map21_BackGroundRect.x - player.w / 2 - 1;
	}
	if (player.x <= Map21_BackGroundRect.x + player.w / 2)
	{
		player.x = Map21_BackGroundRect.x + player.w / 2;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map21_BackGroundTexture, NULL, &Map21_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();
	if (!dialogue_aFTEr_pLAne)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_1, Blank, Blank, (char*)"Avatars/Aside.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_3, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_4, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_5, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		dialogue_aFTEr_pLAne = 1;
	}
	if (!dialogue_Lamy && player.x >= W/4)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_6, Blank, nAMe_who, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_7, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_8, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_9, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_10, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_11, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_12, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_13, Blank, Blank, (char*)"Avatars/Aside.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_14, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_15, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_16, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_17, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_18, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_19, aft_plane_19_2, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_20, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_21, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_22, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_23, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_24, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_25, Blank, nAMe_Lamy, (char*)"Avatars/Lamy.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_26, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_27, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_28, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, aft_plane_29, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		dialogue_Lamy = 1;
	}

}
void Map_22()
{
	Player_move(19, 19);

	// 限制移动
	if (player.y >= Map22_BackGroundRect.h + Map22_BackGroundRect.y - player.h / 2 - 1)
	{
		player.y = Map22_BackGroundRect.h + Map22_BackGroundRect.y - player.h / 2 - 1;
	}
	if (player.y <= 520)
	{
		player.y = 520;
	}
	if (player.x >= Map22_BackGroundRect.w + Map22_BackGroundRect.x - player.w / 2 - 1)
	{
		player.x = Map22_BackGroundRect.w + Map22_BackGroundRect.x - player.w / 2 - 1;
	}
	if (player.x <= Map22_BackGroundRect.x + player.w / 2)
	{
		player.x = Map22_BackGroundRect.x + player.w / 2;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map22_BackGroundTexture, NULL, &Map22_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();
	if (player.x >= 927)
	{
		if (is_change == 0 && parkour_result == 2)
		{
			SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
			SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
			SDL_RenderPresent(Puzzle1_Renderer);
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_rUn_1, Blank,  nAMe_Ellie, (char*)"Avatars/Ellie.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_rUn_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
			present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, bef_rUn_3, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
			if (presentstate == 0)
			{
				running = false;
				QUIT();
			}
			is_change = 1;
			map_num = 23;
		}
		else if(parkour_result == -1 && key_cmd.E == 1)
		{
			is_change = 1;
			map_num = 23;
		}
	}
}
void Map_24()
{
	Player_move(19, 19);
	if (key_cmd.E == 1)
	{
		if (player.y <= 490 + player.h/2 && SDL_GetTicks64() - Last_E_time >= 250)
		{
			is_change = 1;
			map_num = 25;
		}
	}

	// 限制移动
	if (player.y >= Map24_BackGroundRect.h + Map24_BackGroundRect.y - player.h / 2 - 1)
	{
		player.y = Map24_BackGroundRect.h + Map24_BackGroundRect.y - player.h / 2 - 1;
	}
	if (player.y <= 505)
	{
		player.y = 505;
	}
	if (player.x >= 656)
	{
		player.x = 656;
	}
	if (player.x <= 591)
	{
		player.x = 591;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map24_BackGroundTexture, NULL, &Map24_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();
	if(!rOCk_hOLe_dialogue)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);

		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, rOCk_hOLe_D_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, rOCk_hOLe_D_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, rOCk_hOLe_D_3, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, rOCk_hOLe_D_4, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, rOCk_hOLe_D_5, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, rOCk_hOLe_D_6, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, rOCk_hOLe_D_7, rOCk_hOLe_D_7_2, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, rOCk_hOLe_D_8, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		rOCk_hOLe_dialogue = 1;
	}
}
void Puzzle_1()
{
	// dragon决策
	if (puzzle1.round == 1)
	{
		SDL_Delay(200);
		key_cmd.E = 0;
		// 确认是否可以必胜
		if (puzzle1.player_row + 19 != puzzle1.player_column && puzzle1.player_column < puzzle1.player_row + 19 && puzzle1.player_row == puzzle1.register_row)  // 在本行必胜位置左侧
		{
			if (key_cmd.s == 1)
			{
				key_cmd.s = 0;
			}
			puzzle1.is_controlled = 1;  // 标记已被控制过
			key_cmd.d = 1;  // 往右走
		}
		else if (puzzle1.player_row + 19 != puzzle1.player_column && puzzle1.player_column > puzzle1.player_row + 19 && puzzle1.player_column == puzzle1.register_column)  // 在本行必胜位置右侧
		{
			if (puzzle1.player_row < puzzle1.player_column - 19)  // 在本列必胜位置上面
			{
				if (key_cmd.d == 1)
				{
					key_cmd.d = 0;
				}
				puzzle1.is_controlled = 1;  // 标记已被控制过
				key_cmd.s = 1;  // 往下走
			}
		}
		else if (puzzle1.player_row + 19 == puzzle1.player_column)  // 在本行必胜位置
		{
			if (puzzle1.is_controlled == 1)
			{
				key_cmd.E = 1;  // 已经必胜
			}
			else  // 此时必输
			{
				if (last_cmd % 2 == 0)
				{
					int step = last_cmd % (12 - puzzle1.player_row);
					if (step == 0 && (12 - puzzle1.player_row) == 1)  // 在最后一行
					{
						key_cmd.d = 1;  // 往右走
					}
					else if (step == 0 && (12 - puzzle1.player_row) != 1)
					{
						key_cmd.s = 1;  // 往下走
					}
					else
					{
						key_cmd.s = step;  // 往下走
					}
				}
				else if (last_cmd % 2 == 1)
				{
					int step = last_cmd % (31 - puzzle1.player_column);
					if (step == 0 && (31 - puzzle1.player_column) == 1)  // 在最后一列
					{
						key_cmd.s = 1;  // 往下走
					}
					else if (step == 0 && (31 - puzzle1.player_column) != 1)
					{
						key_cmd.d = 1;  // 往右走
					}
					else if (puzzle1.player_column >= 29)
					{
						key_cmd.s = 1;  // 往下走
					}
					else
					{
						key_cmd.d = step;  // 往右走
					}
				}
			}
			puzzle1.is_controlled = 1;
		}
		else if (key_cmd.a == 0 && key_cmd.s == 0 && key_cmd.d == 0 && key_cmd.w == 0)  // dragon移动完毕
		{
			key_cmd.E = 1;
		}
	}


	// 根据移动命令处理移动(一次穿梭，只能同行或同列移动)
	now_cmd = SDL_GetTicks64();
	if (now_cmd - last_cmd > 200 || puzzle1.round == 1)  // 避免player连续操作(dragon 无所谓)
	{
		if (key_cmd.w >= 1 && puzzle1.player_row > 0)
		{
			if (puzzle1.player_column == puzzle1.register_column)
			{
				if (calendar[puzzle1.player_row - 1][puzzle1.player_column] == 1)
				{
					puzzle1.player_row -= 1;
				}
				else
				{
					puzzle1.player_row -= 2;
				}
				puzzle1.is_controlled = 1;  // 标记已被控制过
			}
		}
		if (key_cmd.s >= 1 && puzzle1.player_row < 11)
		{
			if (puzzle1.player_column == puzzle1.register_column)
			{
				if (calendar[puzzle1.player_row + 1][puzzle1.player_column] == 1)
				{
					puzzle1.player_row += 1;
				}
				else
				{
					puzzle1.player_row += 2;  // 在边界时，自动跳转到命令方向上最近的合法日期
				}
				puzzle1.is_controlled = 1;  // 标记已被控制过
			}
		}
		if (key_cmd.a >= 1 && puzzle1.player_column > 0 && calendar[puzzle1.player_row][puzzle1.player_column - 1] == 1)
		{
			if (puzzle1.player_row == puzzle1.register_row)
			{
				puzzle1.player_column -= 1;
			}
		}
		if (key_cmd.d >= 1 && puzzle1.player_column < 30 && calendar[puzzle1.player_row][puzzle1.player_column + 1] == 1)
		{
			if (puzzle1.player_row == puzzle1.register_row)
			{
				puzzle1.player_column += 1;
			}
			puzzle1.is_controlled = 1;  // 标记已被控制过
		}
		last_cmd = now_cmd;
	}


	// render
	Heart_BackGroundRect.x = 42 + puzzle1.player_column * puzzle1.puzzle_1_w;
	Heart_BackGroundRect.y = 96 + puzzle1.puzzle_1_h / 2 - puzzle1.puzzle_1_w / 2 + puzzle1.player_row * puzzle1.puzzle_1_h;

	SDL_RenderCopy(Puzzle1_Renderer, Puzzle_1_BackGroundTexture, NULL, &Puzzle_1_BackGroundRect);  // calendar
	if (puzzle1.round == 0)
	{
		SDL_RenderCopy(Puzzle1_Renderer, Heart_BackGroundTexture, NULL, &Heart_BackGroundRect);  // heart
	}
	else if (puzzle1.round == 1)
	{
		SDL_RenderCopy(Puzzle1_Renderer, Dragon_Heart_BackGroundTexture, NULL, &Heart_BackGroundRect);  // dragon_heart
	}

	// dialogue
	if (puzzle1.is_dialogue == 0 && puzzle1.round == 1)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);
		SDL_Delay(2000);

		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_15, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_16, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_17, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_18, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_19, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_20, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, Puzz1_21, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		puzzle1.is_dialogue = 1;
	}

	// 分类处理Enter防止在dragon操作时player按下Enter
	if (key_cmd.E == 1 && puzzle1.round == 0 && puzzle1.is_controlled == 1)  // Player按下
	{
		if (puzzle1.player_row > puzzle1.register_row || puzzle1.player_column > puzzle1.register_column)  // 只能去未来
		{
			// 记录穿梭位置
			puzzle1.register_row = puzzle1.player_row;
			puzzle1.register_column = puzzle1.player_column;

			// init all key
			key_cmd.a = 0;
			key_cmd.s = 0;
			key_cmd.d = 0;
			key_cmd.w = 0;
			key_cmd.E = 0;
			// initialize
			puzzle1.is_controlled = 0;
			// 更改round
			puzzle1.round = 1;

			// 播放音效
			Mix_PlayChannel(-1, SoundEffect, 0);

			// 判断是否胜利
			if (puzzle1.register_row == 11 && puzzle1.register_column == 30)
			{
				puzzle1.result = 0;
			}
		}
		else
		{
			// 播放音效
			Mix_PlayChannel(-1, Error_SoundEffect, 0);
		}
	}
	else if (key_cmd.E == 1 && puzzle1.round == 1 && puzzle1.is_controlled == 1)
	{
		// 记录穿梭位置
		puzzle1.register_row = puzzle1.player_row;
		puzzle1.register_column = puzzle1.player_column;

		// init all key
		key_cmd.a = 0;
		key_cmd.s = 0;
		key_cmd.d = 0;
		key_cmd.w = 0;
		key_cmd.E = 0;
		// 更改round
		puzzle1.round = 0;
		// initialize
		puzzle1.is_controlled = 0;

		// 播放音效
		Mix_PlayChannel(-1, SoundEffect, 0);

		// 判断是否胜利
		if (puzzle1.register_row == 11 && puzzle1.register_column == 30)
		{
			puzzle1.result = 1;
		}
	}
}
//void Game_over()
//{
//	if(key_cmd.E == 1)
//	{
//		is_change = 1;
//	}
//	// 渲染背景
//	SDL_RenderCopy(Puzzle1_Renderer, GameOver_BackGroundTexture, NULL, &GameOver_BackGroundRect);
//}
int Find_Max(int a, int b)
{
	if (abs(a) >= abs(b))
	{
		return abs(a);
	}
	else
	{
		return abs(b);
	}
}

void Bullet_Print()
{
	int i = 0;
	srand((unsigned int)time(NULL));  // input time as a random seed
	for (i = 0; i < Bullet_num / 4; i++)
	{
		// left

		// determine if it's exist
		if (Bullet[i].is_exist == 1)
		{
			if (Bullet[i].x + Bullet[i].v_x <= Plane_fight_BackGroundRect.x + Plane_fight_BackGroundRect.w + Bullet[i].r
				&& Bullet[i].x + Bullet[i].v_x >= Plane_fight_BackGroundRect.x - Bullet[i].r
				&& Bullet[i].y + Bullet[i].v_y <= Plane_fight_BackGroundRect.y + Plane_fight_BackGroundRect.h + Bullet[i].r
				&& Bullet[i].y + Bullet[i].v_y >= Plane_fight_BackGroundRect.y - Bullet[i].r)
			{
				if (abs(Bullet[i].v_x) <= Bullet_Max_Speed && abs(Bullet[i].v_y) <= Bullet_Max_Speed)
				{
					// if bullet don't go out
					if (Bullet[i].v_x != 0)
					{
						// ensure the bullet has a speed > 0
						Bullet[i].x += Bullet[i].v_x;
					}
					else
					{
						// if the bullet has a speed 0 than it's a normal bullet
						Bullet[i].x += Bullet_Normal_Speed;
					}
					if (Bullet[i].v_y != 0)
					{
						Bullet[i].y += Bullet[i].v_y;
					}
					else
					{
						Bullet[i].y += 0;
					}
				}
				else
				{
					//// 子弹速度限幅
					//Bullet[i].v_x = Bullet[i].v_x * (Bullet_Max_Speed / Find_Max(Bullet[i].v_x, Bullet[i].v_y));
					//Bullet[i].v_y = Bullet[i].v_y * (Bullet_Max_Speed / Find_Max(Bullet[i].v_x, Bullet[i].v_y));
					//Bullet[i].x += Bullet[i].v_x;
					//Bullet[i].y += Bullet[i].v_y;  // 不可，因为速度又为零了

					// special bullet(sin? or other?)
					Bullet[i].x += Bullet_Max_Speed;
					Bullet[i].y -= Bullet_Max_Speed;
				}
				Bullet_BackGroundRect[i].x = Bullet[i].x - Bullet[1].r;
				Bullet_BackGroundRect[i].y = Bullet[i].y - Bullet[1].r;
			}
			else
			{
				Bullet[i].is_exist = 0;  // disappear
			}
		}
		else if (Bullet[i].is_exist == 0)
		{
			//srand((unsigned int)time(NULL));  // input time as a random seed
			if (SDL_GetTicks64() % Bullet_Generate_Ratio == 0)
			{
				// re-generate
				Bullet[i].x = Plane_fight_BackGroundRect.x;
				Bullet[i].y = (rand() % Plane_fight_BackGroundRect.h + Plane_fight_BackGroundRect.y);
				Bullet_BackGroundRect[i].x = Bullet[i].x - Bullet[1].r;
				Bullet_BackGroundRect[i].y = Bullet[i].y - Bullet[1].r;
				if ((object[7].x - Bullet[i].x + object[7].y - Bullet[i].y) != 0)
				{
					Bullet[i].v_x = Bullet_Speed * ((object[7].x - Bullet[i].x) / (object[7].x - Bullet[i].x + object[7].y - Bullet[i].y));
					Bullet[i].v_y = Bullet_Speed * ((object[7].y - Bullet[i].y) / (object[7].x - Bullet[i].x + object[7].y - Bullet[i].y)); // 速度不确定，方向指向主角
				}
				else
				{
					Bullet[i].v_x = 0;
					Bullet[i].v_y = 0;
				}
				Bullet[i].is_exist = 1;  // 重新生成
			}
		}
	}
	for (i = Bullet_num / 4; i < Bullet_num / 2; i++)
	{
		// front

		// determine if it's exist
		if (Bullet[i].is_exist == 1)
		{
			if (Bullet[i].x + Bullet[i].v_x <= Plane_fight_BackGroundRect.x + Plane_fight_BackGroundRect.w + Bullet[i].r
				&& Bullet[i].x + Bullet[i].v_x >= Plane_fight_BackGroundRect.x - Bullet[i].r
				&& Bullet[i].y + Bullet[i].v_y <= Plane_fight_BackGroundRect.y + Plane_fight_BackGroundRect.h + Bullet[i].r
				&& Bullet[i].y + Bullet[i].v_y >= Plane_fight_BackGroundRect.y - Bullet[i].r)
			{
				if (abs(Bullet[i].v_x) <= Bullet_Max_Speed && abs(Bullet[i].v_y) <= Bullet_Max_Speed)
				{
					if (Bullet[i].v_x != 0)
					{
						Bullet[i].x += Bullet[i].v_x;
					}
					else
					{
						Bullet[i].x += 0;
					}
					if (Bullet[i].v_y != 0)
					{
						Bullet[i].y += Bullet[i].v_y;
					}
					else
					{
						Bullet[i].y += Bullet_Normal_Speed;
					}
				}
				else
				{
					//// 子弹速度限幅
					//Bullet[i].v_x *= (Bullet_Max_Speed / Find_Max(Bullet[i].v_x, Bullet[i].v_y));
					//Bullet[i].v_y *= (Bullet_Max_Speed / Find_Max(Bullet[i].v_x, Bullet[i].v_y));
					//Bullet[i].x += Bullet[i].v_x;
					//Bullet[i].y += Bullet[i].v_y;
					// special bullet(sin? or other?)
					Bullet[i].x -= Bullet_Max_Speed;
					Bullet[i].y += Bullet_Max_Speed;
				}
				Bullet_BackGroundRect[i].x = Bullet[i].x - Bullet[1].r;
				Bullet_BackGroundRect[i].y = Bullet[i].y - Bullet[1].r;
			}
			else
			{
				Bullet[i].is_exist = 0;  // disappear
			}
		}
		else if (Bullet[i].is_exist == 0)
		{
			//srand((unsigned int)time(NULL));  // input time as a random seed
			if (SDL_GetTicks64() % Bullet_Generate_Ratio == 0)
			{
				Bullet[i].x = (rand() % Plane_fight_BackGroundRect.w + Plane_fight_BackGroundRect.x);
				Bullet[i].y = Plane_fight_BackGroundRect.y;
				Bullet_BackGroundRect[i].x = Bullet[i].x - Bullet[1].r;
				Bullet_BackGroundRect[i].y = Bullet[i].y - Bullet[1].r;
				if ((object[7].x - Bullet[i].x + object[7].y - Bullet[i].y) != 0)
				{
					Bullet[i].v_x = Bullet_Speed * ((object[7].x - Bullet[i].x) / (object[7].x - Bullet[i].x + object[7].y - Bullet[i].y));
					Bullet[i].v_y = Bullet_Speed * ((object[7].y - Bullet[i].y) / (object[7].x - Bullet[i].x + object[7].y - Bullet[i].y)); // 速度不确定，方向指向主角
					Bullet[i].is_exist = 1;  // 重新生成
				}
				else
				{
					Bullet[i].v_x = 0;
					Bullet[i].v_y = 0;
				}
			}
		}
	}
	for (i = Bullet_num / 2; i < 3 * Bullet_num / 4; i++)
	{
		// right

		// determine if it's exist
		if (Bullet[i].is_exist == 1)
		{
			if (Bullet[i].x + Bullet[i].v_x <= Plane_fight_BackGroundRect.x + Plane_fight_BackGroundRect.w + Bullet[i].r
				&& Bullet[i].x + Bullet[i].v_x >= Plane_fight_BackGroundRect.x - Bullet[i].r
				&& Bullet[i].y + Bullet[i].v_y <= Plane_fight_BackGroundRect.y + Plane_fight_BackGroundRect.h + Bullet[i].r
				&& Bullet[i].y + Bullet[i].v_y >= Plane_fight_BackGroundRect.y - Bullet[i].r)
			{
				if (abs(Bullet[i].v_x) <= Bullet_Max_Speed && abs(Bullet[i].v_y) <= Bullet_Max_Speed)
				{
					if (Bullet[i].v_x != 0)
					{
						Bullet[i].x += Bullet[i].v_x;
					}
					else
					{
						Bullet[i].x += (-Bullet_Normal_Speed);
					}
					if (Bullet[i].v_y != 0)
					{
						Bullet[i].y += Bullet[i].v_y;
					}
					else
					{
						Bullet[i].y += 0;
					}
				}
				else
				{
					//// 子弹速度限幅
					//Bullet[i].v_x = Bullet[i].v_x * (Bullet_Max_Speed / (Find_Max(Bullet[i].v_x, Bullet[i].v_y)));
					//Bullet[i].v_y = Bullet[i].v_y * (Bullet_Max_Speed / (Find_Max(Bullet[i].v_x, Bullet[i].v_y)));
					//Bullet[i].x += Bullet[i].v_x;
					//Bullet[i].y += Bullet[i].v_y;
					// special bullet(sin? or other?)
					Bullet[i].x -= Bullet_Max_Speed;
					Bullet[i].y -= Bullet_Max_Speed;
				}
				Bullet_BackGroundRect[i].x = Bullet[i].x - Bullet[1].r;
				Bullet_BackGroundRect[i].y = Bullet[i].y - Bullet[1].r;
			}
			else
			{
				Bullet[i].is_exist = 0;  // disappear
			}
		}
		else if (Bullet[i].is_exist == 0)
		{
			//srand((unsigned int)time(NULL));  // input time as a random seed
			if (SDL_GetTicks64() % Bullet_Generate_Ratio == 0)
			{
				Bullet[i].x = Plane_fight_BackGroundRect.w + Plane_fight_BackGroundRect.x;
				Bullet[i].y = (rand() % Plane_fight_BackGroundRect.h + Plane_fight_BackGroundRect.y);
				Bullet_BackGroundRect[i].x = Bullet[i].x - Bullet[1].r;
				Bullet_BackGroundRect[i].y = Bullet[i].y - Bullet[1].r;
				if ((object[7].x - Bullet[i].x + object[7].y - Bullet[i].y) != 0)
				{
					Bullet[i].v_x = Bullet_Speed * ((object[7].x - Bullet[i].x) / (object[7].x - Bullet[i].x + object[7].y - Bullet[i].y));
					Bullet[i].v_y = Bullet_Speed * ((object[7].y - Bullet[i].y) / (object[7].x - Bullet[i].x + object[7].y - Bullet[i].y)); // 速度不确定，方向指向主角
				}
				else
				{
					Bullet[i].v_x = 0;
					Bullet[i].v_y = 0;
				}
				Bullet[i].is_exist = 1;  // 重新生成
			}
		}
	}
	for (i = 3 * Bullet_num / 4; i < Bullet_num; i++)
	{
		// back(rear)

		// determine if it's exist
		if (Bullet[i].is_exist == 1)
		{
			if (Bullet[i].x + Bullet[i].v_x <= Plane_fight_BackGroundRect.x + Plane_fight_BackGroundRect.w + Bullet[i].r
				&& Bullet[i].x + Bullet[i].v_x >= Plane_fight_BackGroundRect.x - Bullet[i].r
				&& Bullet[i].y + Bullet[i].v_y <= Plane_fight_BackGroundRect.y + Plane_fight_BackGroundRect.h + Bullet[i].r
				&& Bullet[i].y + Bullet[i].v_y >= Plane_fight_BackGroundRect.y - Bullet[i].r)
			{
				if (abs(Bullet[i].v_x) <= Bullet_Max_Speed && abs(Bullet[i].v_y) <= Bullet_Max_Speed)
				{
					if (Bullet[i].v_x != 0)
					{
						Bullet[i].x += Bullet[i].v_x;
					}
					else
					{
						Bullet[i].x += 0;
					}
					if (Bullet[i].v_y != 0)
					{
						Bullet[i].y += Bullet[i].v_y;
					}
					else
					{
						Bullet[i].y += (-Bullet_Normal_Speed);
					}
				}
				else
				{
					//// 子弹速度限幅
					//Bullet[i].v_x = Bullet[i].v_x * (Bullet_Max_Speed / (Find_Max(Bullet[i].v_x, Bullet[i].v_y)));
					//Bullet[i].v_y = Bullet[i].v_y * (Bullet_Max_Speed / (Find_Max(Bullet[i].v_x, Bullet[i].v_y)));
					//Bullet[i].x += Bullet[i].v_x;
					//Bullet[i].y += Bullet[i].v_y;
					// special bullet(sin? or other?)
					Bullet[i].x += Bullet_Max_Speed;
					Bullet[i].y += Bullet_Max_Speed;
				}
				Bullet_BackGroundRect[i].x = Bullet[i].x - Bullet[1].r;
				Bullet_BackGroundRect[i].y = Bullet[i].y - Bullet[1].r;
			}
			else
			{
				Bullet[i].is_exist = 0;  // disappear
			}
		}
		else if (Bullet[i].is_exist == 0)
		{
			//srand((unsigned int)time(NULL));  // input time as a random seed
			if (SDL_GetTicks64() % Bullet_Generate_Ratio == 0)
			{
				Bullet[i].x = (rand() % Plane_fight_BackGroundRect.w + Plane_fight_BackGroundRect.x);
				Bullet[i].y = Plane_fight_BackGroundRect.h + Plane_fight_BackGroundRect.y;
				Bullet_BackGroundRect[i].x = Bullet[i].x - Bullet[1].r;
				Bullet_BackGroundRect[i].y = Bullet[i].y - Bullet[1].r;
				if ((object[7].x - Bullet[i].x + object[7].y - Bullet[i].y) != 0)
				{
					Bullet[i].v_x = Bullet_Speed * ((object[7].x - Bullet[i].x) / (object[7].x - Bullet[i].x + object[7].y - Bullet[i].y));
					Bullet[i].v_y = Bullet_Speed * ((object[7].y - Bullet[i].y) / (object[7].x - Bullet[i].x + object[7].y - Bullet[i].y)); // 速度不确定，方向指向主角
				}
				else
				{
					Bullet[i].v_x = 0;
					Bullet[i].v_y = 0;
				}
				Bullet[i].is_exist = 1;  // 重新生成
			}
		}
	}
	//Bullet[1].v_x = 0;
	//Bullet[1].v_y = 0;
	//Bullet[1].x = Plane_fight_BackGroundRect.w / 3;
	//Bullet[1].y = Plane_fight_BackGroundRect.h / 3;
	//Bullet_BackGroundRect[1].x = Bullet[1].x - Bullet[1].r;
	//Bullet_BackGroundRect[1].y = Bullet[1].y - Bullet[1].r;
	//Bullet[1].is_exist = 1;
	// render bullet
	for (int i = 0; i < Bullet_num; i++)
	{
		if (Bullet[i].is_exist == 1)
		{
			//SDL_SetRenderDrawColor(Puzzle1_Renderer, 255, 255, 255, 255);  // white
			SDL_RenderCopy(Puzzle1_Renderer, Bullet_BackGroundTexture, NULL, &Bullet_BackGroundRect[i]);
			/*SDL_RenderDrawRect(Puzzle1_Renderer, &Bullet_BackGroundRect[i]);
			SDL_SetRenderDrawColor(Puzzle1_Renderer, 0, 0, 0, 255);*/
		}
	}
}

void Plane_Object_Update()
{
	object[7].w = Plane_BackGroundRect.h / 2;
	object[7].h = Plane_BackGroundRect.h / 2;
	object[7].x = Plane_BackGroundRect.x;
	object[7].y = Plane_BackGroundRect.y + object[7].h / 3.5;
	Object_INIT_Point(7);
}

void Are_You_Tough_Man()
{
	// 处理移动
	if (key_cmd.w == 1)
	{
		Plane_BackGroundRect.y -= Plane_Speed;
	}
	if (key_cmd.s == 1)
	{
		Plane_BackGroundRect.y += Plane_Speed;
	}
	if (key_cmd.a == 1)
	{
		Plane_BackGroundRect.x -= Plane_Speed;
	}
	if (key_cmd.d == 1)
	{
		Plane_BackGroundRect.x += Plane_Speed;
	}
	// 限制移动
	if (Plane_BackGroundRect.y <= Plane_fight_BackGroundRect.y)
	{
		Plane_BackGroundRect.y = Plane_fight_BackGroundRect.y;
	}
	if (Plane_BackGroundRect.y >= Plane_fight_BackGroundRect.h - Plane_BackGroundRect.h)
	{
		Plane_BackGroundRect.y = Plane_fight_BackGroundRect.h - Plane_BackGroundRect.h;
	}
	if (Plane_BackGroundRect.x >= Plane_fight_BackGroundRect.w - Plane_BackGroundRect.w)
	{
		Plane_BackGroundRect.x = Plane_fight_BackGroundRect.w - Plane_BackGroundRect.w;
	}
	if (Plane_BackGroundRect.x <= Plane_fight_BackGroundRect.x)
	{
		Plane_BackGroundRect.x = Plane_fight_BackGroundRect.x;
	}

	Plane_Object_Update();

	// collision detec
	for (int i = 0; i < Bullet_num; i++)
	{
		//if (Is_collide_Rect(object[7], Bullet[i].x - Bullet[i].r, Bullet[i].y - Bullet[i].r, Bullet[i].r * 2, Bullet_BackGroundRect[i].h) == 1 && SDL_GetTicks64() - last_hit > No_Hit_Time)  // collision
		//{
		//	hit_count += 1;
		//	last_hit = SDL_GetTicks64();
		//}
		if (Is_collide(object[7], Bullet[i].r * 2, Bullet[i].r * 2, Bullet[i].x, Bullet[i].y, Bullet[i].r) == 1 && SDL_GetTicks64() - last_hit > No_Hit_Time)  // collision
		{
			hit_count += 1;
			last_hit = SDL_GetTicks64();
			Bullet[i].is_exist = false;  // after hit bullet disappear
		}
	}

	// 渲染图片
	int BG_speed = 5;
	for (int i = 0; i < 2; i++)
	{
		Plane_fight_BackGroundRect_B[i].y += BG_speed;
		if (Plane_fight_BackGroundRect_B[i].y >= H)
		{
			Plane_fight_BackGroundRect_B[i].y = -Plane_fight_BackGroundRect_B[i].h;
		}
		SDL_RenderCopy(Puzzle1_Renderer, Plane_fight_BackGroundTexture, NULL, &Plane_fight_BackGroundRect_B[i]);
	}

	// 渲染玩家
	SDL_RenderCopy(Puzzle1_Renderer, Plane_BackGroundTexture, NULL, &Plane_BackGroundRect);
	//// 渲染玩家碰撞箱（用于调试）
	//SDL_SetRenderDrawColor(Puzzle1_Renderer, 255, 255, 255, 255);  // white
	//int H_register = Plane_BackGroundRect.h;
	//int y_register = Plane_BackGroundRect.y;
	//int W_register = Plane_BackGroundRect.w;
	//int x_register = Plane_BackGroundRect.x;
	//Plane_BackGroundRect.h = object[7].h;
	//Plane_BackGroundRect.y = object[7].y;
	//Plane_BackGroundRect.w = object[7].w;
	//Plane_BackGroundRect.x = object[7].x;
	//SDL_RenderDrawRect(Puzzle1_Renderer, &Plane_BackGroundRect);
	//Plane_BackGroundRect.h = H_register;
	//Plane_BackGroundRect.y = y_register;
	//Plane_BackGroundRect.w = W_register;
	//Plane_BackGroundRect.x = x_register;
	//SDL_SetRenderDrawColor(Puzzle1_Renderer, 0, 0, 0, 255);

	if (!tough_enough_dialogue)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 150);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		SDL_RenderPresent(Puzzle1_Renderer);
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, tOUgh_1, Blank, nAMe_Ellie, (char*)"Avatars/Ellie.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, tOUgh_2, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, tOUgh_3, Blank, nAMe_DC, (char*)"Avatars/DC.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, tOUgh_4, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, tOUgh_5, Blank, nAMe_Prince, (char*)"Avatars/Prince.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, tOUgh_6, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		present(Puzzle1_Window, Puzzle1_Renderer, Date_Font, tOUgh_6_2, Blank, nAMe_Emma, (char*)"Avatars/Emma.png");
		if (presentstate == 0)
		{
			running = false;
			QUIT();
		}
		Start_Plane_time = SDL_GetTicks64();
		tough_enough_dialogue = 1;
	}

	// 渲染Bullet
	Bullet_Print();


}

void Map_Shift(int map_num, int x, int y)
{
	/*
	作用为淡出地图，请在render_present前最后一个使用！因为它要盖住所有纹理。
	*/
	int d_t = 1;  // unit: s
	int F_N = FR * d_t;
	int add = 255 / F_N;
	alpha += add;
	if (alpha >= 255)
	{
		if (map_num == 2)
		{
			Mix_HaltMusic();
			// play Music
			Mix_VolumeMusic(32);  // 0~128
			Mix_PlayMusic(Puzzle_1_bgm, -1);  // 播放音乐
		}
		else if (map_num == 1)
		{
			//player.x = 1074;
			//player.y = 440;  // 防止卡住
		}
		else if (map_num == 0)
		{
			Puzzle1_BackGroundRect.x = W / 2 - Puzzle1_BackGroundSurface->w / 2;  // 居中
			Puzzle1_BackGroundRect.y = -H;
			Puzzle1_BackGroundRect.w = Puzzle1_BackGroundSurface->w;
			Puzzle1_BackGroundRect.h = H * 2;
			player.x = W / 2;
			player.y = H - player.h;  // 防止卡住
		}
		else if (map_num == 3)
		{
			hit_count = 0;
			Bullet_Generate_Ratio = 20;
			Bullet_INIT();
			Plane_BackGroundRect.w = Plane_BackGroundSurface->w / 1.5;
			Plane_BackGroundRect.h = Plane_BackGroundSurface->h / 1.5;
			Plane_BackGroundRect.x = W / 2 - Plane_BackGroundRect.w / 2;
			Plane_BackGroundRect.y = H / 2 - Plane_BackGroundRect.h / 2;
			Plane_Object_Update();
			Object_INIT_Point(7);
		}
		else if (map_num == 21)
		{
			Mix_HaltMusic();
			Mix_PlayMusic(SoundBackGround, -1);  // 播放音乐
		}
		else if (map_num == 23)
		{
			parkour_result = 2;
		}
		else if (map_num == 24)
		{
			Mix_HaltMusic();
			Mix_PlayMusic(Before_boss2_bgm, -1);  // 播放音乐
		}
		else if (map == 5 && map_num == 18)
		{
			SDL_SetRenderDrawColor(Puzzle1_Renderer, 0, 0, 0, 255);
			SDL_RenderClear(Puzzle1_Renderer);
		}
		
		if (boss1_result == 3 && map_num == 18)
		{
			Last_E_time = SDL_GetTicks64();
			boss1_result = 2;
		}
		
		if (boss2_result == 3 && map_num == 24)
		{
			Last_E_time = SDL_GetTicks64();
			boss2_result = 2;
		}

		if (puzzle1.result == 1)
		{
			// init puzzle 1
			Puzzle_1_Init();
			// halt music
			Mix_HaltMusic();
			// play Music
			Mix_PlayMusic(SoundBackGround, -1);  // 播放音乐
		}
		else if (puzzle1.result == 0)
		{
			// init puzzle 1
			Puzzle_1_Init();
		}

		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 255);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		// 归零
		alpha = 0;
		is_change = 0;
		map = map_num;
		player.x = x;
		player.y = y;
		key_cmd.E = 0;

		save();
	}
	else
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, alpha);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
	}
}
void save()
{
	// save game
	gameData.playerplacex = player.x;
	gameData.playerplacey = player.y;
	gameData.map = map_num;
	gameData.s2 = kill_Scientist;
	gameData.ID = is_ID;
	gameData.disk = disk_num;
	gameData.boss1_result = boss1_result;
	gameData.boss2_result = boss2_result;
	gameData.is_time_machine_dialogue = is_time_machine_dialogue;
	gameData.parkour_result = parkour_result;
	gameData.lose_count = lose_count;
	saveGame(gameData, currentSave);
}
void QUIT()
{
	int quit_i;
	/*
*	QUIT
*	Functions:关闭所有子系统
*	Parameter:NULL
*	Return Value:NULL
*/
	save();
	// all quit
	SDL_FreeSurface(choice_BackGroundSurface);
	SDL_FreeSurface(Puzzle1_BackGroundSurface);
	SDL_FreeSurface(Player1_BackGroundSurface);
	SDL_FreeSurface(Player0_BackGroundSurface);
	SDL_FreeSurface(Player2_BackGroundSurface);
	SDL_FreeSurface(Player3_BackGroundSurface);
	SDL_FreeSurface(Player4_BackGroundSurface);
	SDL_FreeSurface(Player5_BackGroundSurface);
	SDL_FreeSurface(Player6_BackGroundSurface);
	SDL_FreeSurface(Player7_BackGroundSurface);
	SDL_FreeSurface(Player8_BackGroundSurface);
	SDL_FreeSurface(Player9_BackGroundSurface);
	SDL_FreeSurface(Player12_BackGroundSurface);
	SDL_FreeSurface(Shifter_BackGroundSurface);
	SDL_FreeSurface(Map1_BackGroundSurface);
	SDL_FreeSurface(Map2_BackGroundSurface);
	SDL_FreeSurface(Map3_BackGroundSurface);
	SDL_FreeSurface(Map4_BackGroundSurface);
	SDL_FreeSurface(Map5_BackGroundSurface);
	SDL_FreeSurface(Map5_2_BackGroundSurface);
	SDL_FreeSurface(Map6_BackGroundSurface);
	SDL_FreeSurface(Map7_BackGroundSurface);
	SDL_FreeSurface(Map8_BackGroundSurface);
	SDL_FreeSurface(Map20_BackGroundSurface);
	SDL_FreeSurface(Map21_BackGroundSurface);
	SDL_FreeSurface(Map22_BackGroundSurface);
	SDL_FreeSurface(Map23_BackGroundSurface);
	SDL_FreeSurface(Map24_BackGroundSurface);
	SDL_FreeSurface(Heart_BackGroundSurface);
	SDL_FreeSurface(Dragon_Heart_BackGroundSurface);
	SDL_FreeSurface(Plane_BackGroundSurface);
	SDL_FreeSurface(Bullet_BackGroundSurface);
	SDL_FreeSurface(GameOver_BackGroundSurface);

	Mix_FreeChunk(SoundEffect);
	Mix_FreeChunk(Error_SoundEffect);
	Mix_FreeMusic(SoundBackGround);
	Mix_FreeMusic(Puzzle_1_bgm);
	Mix_FreeMusic(Puzzle_2_bgm);
	Mix_FreeMusic(Before_boss2_bgm);

	SDL_DestroyTexture(choice_BackGroundTexture);
	SDL_DestroyTexture(Puzzle1_BackGroundTexture);
	SDL_DestroyTexture(Player0_BackGroundTexture);
	SDL_DestroyTexture(Player1_BackGroundTexture);
	SDL_DestroyTexture(Player2_BackGroundTexture);
	SDL_DestroyTexture(Player3_BackGroundTexture);
	SDL_DestroyTexture(Player4_BackGroundTexture);
	SDL_DestroyTexture(Player5_BackGroundTexture);
	SDL_DestroyTexture(Player6_BackGroundTexture);
	SDL_DestroyTexture(Player7_BackGroundTexture);
	SDL_DestroyTexture(Player8_BackGroundTexture);
	SDL_DestroyTexture(Player9_BackGroundTexture);
	SDL_DestroyTexture(Player12_BackGroundTexture);
	SDL_DestroyTexture(Shifter_BackGroundTexture);
	SDL_DestroyTexture(Map1_BackGroundTexture);
	SDL_DestroyTexture(Map2_BackGroundTexture);
	SDL_DestroyTexture(Map3_BackGroundTexture);
	SDL_DestroyTexture(Map4_BackGroundTexture);
	SDL_DestroyTexture(Map5_BackGroundTexture);
	SDL_DestroyTexture(Map5_2_BackGroundTexture);
	SDL_DestroyTexture(Map6_BackGroundTexture);
	SDL_DestroyTexture(Map7_BackGroundTexture);
	SDL_DestroyTexture(Map8_BackGroundTexture);
	SDL_DestroyTexture(Map20_BackGroundTexture);
	SDL_DestroyTexture(Map21_BackGroundTexture);
	SDL_DestroyTexture(Map22_BackGroundTexture);
	SDL_DestroyTexture(Map23_BackGroundTexture);
	SDL_DestroyTexture(Map24_BackGroundTexture);
	SDL_DestroyTexture(Heart_BackGroundTexture);
	SDL_DestroyTexture(Dragon_Heart_BackGroundTexture);
	SDL_DestroyTexture(Plane_BackGroundTexture);
	SDL_DestroyTexture(Bullet_BackGroundTexture);
	SDL_DestroyTexture(GameOver_BackGroundTexture);

	for (quit_i = 0; quit_i < 12; quit_i++)
	{
		SDL_FreeSurface(surf_Pic_fOr_diAlOGue[quit_i]);
		SDL_DestroyTexture(txt_Pic_fOr_diAlOGue[quit_i]);
	}

	TTF_CloseFont(Date_Font);
	Mix_CloseAudio();

	SDL_DestroyWindow(Puzzle1_Window);
	SDL_DestroyRenderer(Puzzle1_Renderer);

	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
	TTF_Quit();

	is_quit = 1;
}

void Key_detect()
{
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	if (keystates[SDL_SCANCODE_A])
	{
		key_cmd.a = 1;
		/*printf("A: %d\n", start_t);  // 事实证明，keystates方法一次可以检测所有按键的状态*/
	}
	else if (keystates[SDL_SCANCODE_A] == 0)
	{
		key_cmd.a = 0;
	}
	if (keystates[SDL_SCANCODE_W])
	{
		key_cmd.w = 1;
		/*printf("W: %d\n", start_t);*/
	}
	else if (keystates[SDL_SCANCODE_W] == 0)
	{
		key_cmd.w = 0;
	}
	if (keystates[SDL_SCANCODE_D])
	{
		key_cmd.d = 1;
	}
	else if (keystates[SDL_SCANCODE_D] == 0)
	{
		key_cmd.d = 0;
	}
	if (keystates[SDL_SCANCODE_S])
	{
		key_cmd.s = 1;
	}
	else if (keystates[SDL_SCANCODE_S] == 0)
	{
		key_cmd.s = 0;
	}
	if (keystates[SDL_SCANCODE_RETURN] == 1)
	{
		key_cmd.E = 1;
	}
	else if (keystates[SDL_SCANCODE_RETURN] == 0)
	{
		key_cmd.E = 0;
	}
}

void Center_Text(int x, int y, int w, int h, const char* text)
{
	/*
	* function: output a text in the centre of certain rectangle 
	int x: rectangle's left-top point's x
	int y: rectangle's left-top point's y
	int w: rectangle's width
	int h: rectangle's height
	const char* text: output tex
	*/
	SDL_Surface* DateSurface = TTF_RenderUTF8_Blended(Date_Font, text, FontColor);
	SDL_Texture* DateTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, DateSurface);  // 转换为纹理
	int Text_x, Text_y;
	Text_x = x + w / 2 - (DateSurface->w) / 2;
	Text_y = y + h / 2 - (DateSurface->h) / 2;
	SDL_Rect TextRect = { Text_x , Text_y, DateSurface->w, DateSurface->h };
	SDL_RenderCopy(Puzzle1_Renderer, DateTexture, NULL, &TextRect);
}

void Puzzle_1_Init()
{
	puzzle1.register_row = 0;
	puzzle1.register_column = 0;
	puzzle1.player_row = 0;
	puzzle1.player_column = 0;
	puzzle1.puzzle_1_w = (1133 - 42) / 29 + (1133 - 42) * 1.5 / (29 * 22);
	puzzle1.puzzle_1_h = (604 - 96) / 12 + (604 - 96) * 1.3 / (12 * 12);
	puzzle1.round = 0;  // 0 为player回合 1 为dragon回合
	puzzle1.is_controlled = 0;  // 1 代表已被（dragon）控制过  0 代表没被（dragon）控制过
	puzzle1.result = 10; // 1 代表 dragon win，0 代表 player win
}

void Object_INIT_Point(int i)
{
	object[i].l_u[0] = object[i].x;
	object[i].l_u[1] = object[i].y;
	object[i].r_u[0] = object[i].x + object[i].w;
	object[i].r_u[1] = object[i].y;
	object[i].l_d[0] = object[i].x;
	object[i].l_d[1] = object[i].y + object[i].h;
	object[i].r_d[0] = object[i].x + object[i].w;
	object[i].r_d[1] = object[i].y + object[i].h;
}

void Object_INIT()  // init all object
{

	object[0].x = 0;
	object[0].y = 0;
	object[0].w = 517;
	object[0].h = H;
	Object_INIT_Point(0);
	object[6].x = 0;
	object[6].y = 0;
	object[6].w = 601;
	object[6].h = 351;
	Object_INIT_Point(6);

	object[1].x = 737;
	object[1].y = 0;
	object[1].w = W / 2 - Puzzle1_BackGroundSurface->w / 2;
	object[1].h = H;
	Object_INIT_Point(1);
	// 650 0 W/2 351
	object[5].x = 650;
	object[5].y = 0;
	object[5].w = W / 2;
	object[5].h = 351;
	Object_INIT_Point(5);

	// two trees	
	object[2].x = 463;
	object[2].y = 477;
	object[2].w = 594 - 463;
	object[2].h = 606 - 477;
	Object_INIT_Point(2);

	object[3].x = 655;
	object[3].y = 503;
	object[3].w = 785 - 655;
	object[3].h = 605 - 503;
	Object_INIT_Point(3);

	object[4].x = 678;
	object[4].y = 452;
	object[4].w = 785 - 678;
	object[4].h = 605 - 452;
	Object_INIT_Point(4);

	object[19].x = 0;
	object[19].y = 0;
	object[19].w = 0;
	object[19].h = 0;
	Object_INIT_Point(19);

	// Plane
	Plane_Object_Update();
	Object_INIT_Point(7);

	// MAP2
	Object_Update();

	// MAP5 map==15
	object[18].x = 177;
	object[18].y = 0;
	object[18].w = 557 - 177;
	object[18].h = 196 - 0;
	Object_INIT_Point(18);

	object[20].x = 676;
	object[20].y = 5;
	object[20].w = 1065 - 676;
	object[20].h = 202 - 5;
	Object_INIT_Point(20);

	object[21].x = 185;
	object[21].y = 367;
	object[21].w = 562 - 185;
	object[21].h = 540 - 367;
	Object_INIT_Point(21);

	object[22].x = 670;
	object[22].y = 367;
	object[22].w = 1102 - 670;
	object[22].h = 543 - 367;
	Object_INIT_Point(22);

	// MAP6 map==16
	object[23].x = 441;
	object[23].y = 6;
	object[23].w = 527 - 441;
	object[23].h = 231 - 6;
	Object_INIT_Point(23);

	object[24].x = 441;
	object[24].y = 212;
	object[24].w = 574 - 441;
	object[24].h = 393 - 212;
	Object_INIT_Point(24);

	object[25].x = 475;
	object[25].y = 502;
	object[25].w = 578 - 475;
	object[25].h = 649 - 502;
	Object_INIT_Point(25);

	object[26].x = 671;
	object[26].y = 214;
	object[26].w = 815 - 671;
	object[26].h = 648 - 214;
	Object_INIT_Point(26);

	object[27].x = 495;
	object[27].y = 2;
	object[27].w = 756 - 495;
	object[27].h = 48 - 2;
	Object_INIT_Point(27);

	object[28].x = 717;
	object[28].y = 1;
	object[28].w = 795 - 717;
	object[28].h = 230 - 1;
	Object_INIT_Point(28);

	// MAP4 map==14
	object[29].x = 194;
	object[29].y = 115;
	object[29].w = 672 - 194;
	object[29].h = 225 - 115;
	Object_INIT_Point(29);

	object[30].x = 787;
	object[30].y = 115;
	object[30].w = 1187 - 787;
	object[30].h = 225 - 115;
	Object_INIT_Point(30);

	object[31].x = 780;
	object[31].y = 351;
	object[31].w = 1200 - 780;
	object[31].h = 540 - 351;
	Object_INIT_Point(31);

	object[32].x = 192;
	object[32].y = 351;
	object[32].w = 673 - 192;
	object[32].h = 536 - 351;
	Object_INIT_Point(32);

	// MAP3 map==13
	object[33].x = 872;
	object[33].y = 95;
	object[33].w = 1023 - 872;
	object[33].h = 212 - 95;
	Object_INIT_Point(33);

	object[34].x = 543;
	object[34].y = 97;
	object[34].w = 874 - 543;
	object[34].h = 205 - 97;
	Object_INIT_Point(34);

	object[35].x = 541;
	object[35].y = 347;
	object[35].w = 1133 - 541;
	object[35].h = 536 - 347;
	Object_INIT_Point(35);

	object[36].x = 46;
	object[36].y = 326;
	object[36].w = 137 - 46;
	object[36].h = 369 - 326;
	Object_INIT_Point(36);

	object[37].x = 0;
	object[37].y = 96;
	object[37].w = 430 - 0;
	object[37].h = 204 - 96;
	Object_INIT_Point(37);

	object[38].x = 138;
	object[38].y = 346;
	object[38].w = 433 - 138;
	object[38].h = 507 - 346;
	Object_INIT_Point(38);

	// MAP7 map==17
	object[39].x = 193;
	object[39].y = 424;
	object[39].w = 1195 - 193;
	object[39].h = 577 - 424;
	Object_INIT_Point(39);

	object[40].x = 265;
	object[40].y = 365;
	object[40].w = 1063 - 265;
	object[40].h = 429 - 365;
	Object_INIT_Point(40);

	// disk
	object[50].x = disk_BackGroundRect[0].x;
	object[50].y = disk_BackGroundRect[0].y;
	object[50].w = disk_BackGroundRect[0].w;
	object[50].h = disk_BackGroundRect[0].h;
	Object_INIT_Point(50);
	object[51].x = disk_BackGroundRect[1].x;
	object[51].y = disk_BackGroundRect[1].y;
	object[51].w = disk_BackGroundRect[1].w;
	object[51].h = disk_BackGroundRect[1].h;
	Object_INIT_Point(51);
	object[52].x = disk_BackGroundRect[2].x;
	object[52].y = disk_BackGroundRect[2].y;
	object[52].w = disk_BackGroundRect[2].w;
	object[52].h = disk_BackGroundRect[2].h;
	Object_INIT_Point(52);
}
void Object_Update()
{
	object[8].x = 1+Map2_BackGroundRect.x;
	object[8].y = 838+ Map2_BackGroundRect.y;
	object[8].w = 216;
	object[8].h = 1172-838;
	Object_INIT_Point(8);

	object[9].x = 211 + Map2_BackGroundRect.x;
	object[9].y = 1137 + Map2_BackGroundRect.y;
	object[9].w = 452-211;
	object[9].h = 1163 - 1152;
	Object_INIT_Point(9);

	object[10].x = 339 + Map2_BackGroundRect.x;
	object[10].y = 530 + Map2_BackGroundRect.y;
	object[10].w = 453 - 339;
	object[10].h = 1037 - 530;
	Object_INIT_Point(10);

	object[11].x = 457 + Map2_BackGroundRect.x;
	object[11].y = 1 + Map2_BackGroundRect.y;
	object[11].w = 581 - 457;
	object[11].h = 1154 - 1;
	Object_INIT_Point(11);

	object[12].x = 340 + Map2_BackGroundRect.x;
	object[12].y = 244 + Map2_BackGroundRect.y;
	object[12].w = 450 - 340;
	object[12].h = 420 - 244;
	Object_INIT_Point(12);

	object[13].x = 1 + Map2_BackGroundRect.x;
	object[13].y = 241 + Map2_BackGroundRect.y;
	object[13].w = 215 - 1;
	object[13].h = 716 - 241;
	Object_INIT_Point(13);

	object[14].x = 36 + Map2_BackGroundRect.x;
	object[14].y = 1 + Map2_BackGroundRect.y;
	object[14].w = 141 - 36;
	object[14].h = 241 - 1;
	Object_INIT_Point(14);

	object[15].x = 121 + Map2_BackGroundRect.x;
	object[15].y = 4 + Map2_BackGroundRect.y;
	object[15].w = 420 - 121;
	object[15].h = 73;
	Object_INIT_Point(15);

	object[16].x = 409 + Map2_BackGroundRect.x;
	object[16].y = 2 + Map2_BackGroundRect.y;
	object[16].w = 479 - 409;
	object[16].h = 245;
	Object_INIT_Point(16);

	object[17].x = -155 + Map2_BackGroundRect.x;
	object[17].y = 445 + Map2_BackGroundRect.y;
	object[17].w = 2 + 155;
	object[17].h = 889 - 445;
	Object_INIT_Point(17);
}
int Is_SameQuadrant(Object object, int x, int y) // detect if the rect are in the same quadrant
{
	if (object.l_d[0] > x && object.l_d[1] < y)
	{
		// I quadrant
		return 1;
	}
	if (object.r_d[0] < x && object.r_d[1] < y)
	{
		// II quadrant
		return 2;
	}
	if (object.r_u[0] < x && object.r_u[1] > y)
	{
		// III quadrant
		return 3;
	}
	if (object.l_u[0] > x && object.l_u[1] > y)
	{
		// IV quadrant
		return 4;
	}
	return 0;
}

int Is_collide_Rect(Object object, int x, int y, int w, int h)  // detect if they(rect and rect) are collided
{
	/*
	detect if they(rect and rect) are collided
	int x : left-top x
	int y : left-top y
	*/
	int result = 1;  // 0 represents no collision, 1 represents collision

	//  horizontal detect
	int x_1 = (object.l_u[0] + object.r_u[0]) / 2;
	int x_2 = x + w / 2;
	if (abs(x_1 - x_2) > (object.w + w) / 2)
	{
		result = 0;
	}

	//  vertical detect
	int y_1 = (object.l_u[1] + object.l_d[1]) / 2;
	int y_2 = y + h / 2;
	if (abs(y_1 - y_2) > (object.h + h) / 2)
	{
		result = 0;
	}

	return result;
}

int Is_collide(Object object, int player_w, int player_h, int x, int y, int r)  // detect if there are collide (abandon...)
{
	/*
	Object object : rectangle object
	int player_w : round object width
	int player_h : round object height
	int x : round object centre x
	int y : round object centre y
	int r : round object radius

	detect if they(rect and circle) are collided(x,y)
	*/
	int quadrant_num = Is_SameQuadrant(object, x, y);
	int result = 0;

	if (quadrant_num)
	{
		// case 1 rect in the same quadrant
		switch (quadrant_num)
		{
		case 1:
			if (pow((object.l_d[0] - x), 2) + pow((object.l_d[1] - y), 2) <= pow(r, 2))  // collision
			{
				return 1;
			}
			break;
		case 2:
			if (pow((object.r_d[0] - x), 2) + pow((object.r_d[1] - y), 2) <= pow(r, 2))  // collision
			{
				return 1;
			}
			break;
		case 3:
			if (pow((object.r_u[0] - x), 2) + pow((object.r_u[1] - y), 2) <= pow(r, 2))  // collision
			{
				return 1;
			}
			break;
		case 4:
			if (pow((object.l_u[0] - x), 2) + pow((object.l_u[1] - y), 2) <= pow(r, 2))  // collision
			{
				return 1;
			}
			break;
		default:
			return -1;
		}
	}
	else
	{
		// case 2 rect in multiple quadrants
		result = Is_collide_Rect(object, x - r, y - r, player_w, player_h);
	}

	return result;
}  

int Collision_Detect(int x, int y, int r, int start, int end)
{
	/*
	detect all object from start to end(including start&end)

	int x : left-top x
	int y : left-top y
	
	*/
	int i = start;
	for (i = start; i <= end; i++)
	{
		if (Is_collide_Rect(object[i], x, y, player.w, player.h) == 1)
		{
			return 1;
		}
	}
	return 0;
}

void Bullet_INIT()  // init all bullet
{
	int i = 0;

	srand((unsigned int)time(NULL));  // input time as a random seed

	for (i = 0; i < Bullet_num / 4; i++)
	{
		// left
		Bullet[i].x = Plane_fight_BackGroundRect.x;
		Bullet[i].y = (rand() % Plane_fight_BackGroundRect.h + Plane_fight_BackGroundRect.y);
		Bullet_BackGroundRect[i].x = Bullet[i].x;
		Bullet_BackGroundRect[i].y = Bullet[i].y;
		Bullet[i].v_x = Bullet_Speed;
		Bullet[i].v_y = 0;
		Bullet[i].is_exist = false;
	}
	for (i = Bullet_num / 4; i < Bullet_num / 2; i++)
	{
		// front
		Bullet[i].x = (rand() % Plane_fight_BackGroundRect.w + Plane_fight_BackGroundRect.x);
		Bullet[i].y = Plane_fight_BackGroundRect.y;
		Bullet_BackGroundRect[i].x = Bullet[i].x;
		Bullet_BackGroundRect[i].y = Bullet[i].y;
		Bullet[i].v_x = 0;
		Bullet[i].v_y = Bullet_Speed;
		Bullet[i].is_exist = false;
	}
	for (i = Bullet_num / 2; i < 3 * Bullet_num / 4; i++)
	{
		// right
		Bullet[i].x = Plane_fight_BackGroundRect.w + Plane_fight_BackGroundRect.x;
		Bullet[i].y = (rand() % Plane_fight_BackGroundRect.h + Plane_fight_BackGroundRect.y);
		Bullet_BackGroundRect[i].x = Bullet[i].x;
		Bullet_BackGroundRect[i].y = Bullet[i].y;
		Bullet[i].v_x = -Bullet_Speed;
		Bullet[i].v_y = 0;
		Bullet[i].is_exist = false;
	}
	for (i = 3 * Bullet_num / 4; i < Bullet_num; i++)
	{
		// back(rear)
		Bullet[i].x = (rand() % Plane_fight_BackGroundRect.w + Plane_fight_BackGroundRect.x);
		Bullet[i].y = Plane_fight_BackGroundRect.h + Plane_fight_BackGroundRect.y;
		Bullet_BackGroundRect[i].x = Bullet[i].x;
		Bullet_BackGroundRect[i].y = Bullet[i].y;
		Bullet[i].v_x = 0;
		Bullet[i].v_y = -Bullet_Speed;
		Bullet[i].is_exist = false;
	}
}