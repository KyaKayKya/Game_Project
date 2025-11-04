#include "SDL2_test.h"
#include "BOSS.h"
/*
*
*	Global Variable
*
*/
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
SDL_Rect Plane_fight_BackGroundRect;
// Plane
SDL_Surface* Plane_BackGroundSurface = NULL;  // 图形
SDL_Texture* Plane_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Plane_BackGroundRect;
// Bullet
const int Bullet_num = 60;
SDL_Surface* Bullet_BackGroundSurface = NULL;  // 图形
SDL_Texture* Bullet_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Bullet_BackGroundRect[Bullet_num];
// left、right
SDL_Surface* Player0_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player0_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Player0_BackGroundRect;
SDL_Surface* Player1_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player1_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Player1_BackGroundRect;
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

TTF_Font *Date_Font = NULL;

Mix_Chunk* SoundEffect;
Mix_Chunk* Error_SoundEffect;
Mix_Music* SoundBackGround;
Mix_Music* Puzzle_1_bgm;

SDL_Color FontColor = { 255, 255, 255, 255 };  // RGBA
Keycontrol key_cmd;  // 键盘控制结构体
Player player; // 玩家结构体
Puzzle1 puzzle1;  // 谜题结构体
Object object[10];  // 地图中碰撞箱结构体
Circle Bullet[Bullet_num];  // 弹幕结构体

//const int W = 1250;
//const int H = 650;

int is_quit = 0;  // 标志是否QUIT过
int map = 10;  // 0代表地图0；1代表客厅；2代表puzzle1；3代表真男人; 5 代表boss1
int map_num = 2;  // 代表要换的地图
int F_counter = 0;  // 帧计数器
int is_change = 0;  // 1代表要换地图了
int alpha = 0;  // 透明度
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

int hit_count = 0;  // 记录被击中次数
int Bullet_Generate_Ratio = 6;  // 生成bullet参数
Uint64 last_hit = 0;  // 两次碰撞间隔
Uint64 Start_Plane_time = 0;  // 开始游玩的时候

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
	player.w = 17*2.5;
	player.h = 29*2.5;
	player.x = player.w/2;
	player.y = H / 2;
	player.r = player.w / 2;

	// init puzzle1
	puzzle1.player_column = 0;
	puzzle1.player_row = 0;
	puzzle1.register_column = 0;
	puzzle1.register_row = 0;

	// init scale
	int scale = 2;

	// create window
	Puzzle1_Window = SDL_CreateWindow("TimeTravel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
	Puzzle1_Renderer = SDL_CreateRenderer(Puzzle1_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// open audio
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 3, 4096) == -1)
		printf("Failed to Open Audio!\n");

	// load everything
	LOAD();

	// Init object
	Object_INIT();

	// init volume
	Mix_HaltMusic();
	Mix_Volume(-1, 0);
	int sound_channel_1 = Mix_PlayChannel(-1, SoundEffect, 0);  // 播放音效
	Mix_Volume(sound_channel_1, 32);
	Mix_VolumeMusic(64);  // 0~128

	// play Music
	Mix_PlayMusic(SoundBackGround, -1);  // 播放音乐

//log_in:

	// 入场
	textFadeInOut(Puzzle1_Window, Puzzle1_Renderer, Date_Font, "Click to start", FontColor);
	while (map != 0)
	{
		Map_Shift(0, player.x, player.y);
		// represent
		SDL_RenderPresent(Puzzle1_Renderer);
	}
	bool running = true;
	while (running)
	{
		// start to get time
		start_t = SDL_GetTicks64();

		// clear
		SDL_RenderClear(Puzzle1_Renderer);
		while (SDL_PollEvent(&MainEvent))
		{
			switch (MainEvent.type)
			{
			case SDL_QUIT:
				QUIT();
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (MainEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					QUIT();
					running = false;
					break;
				default:
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				// functions here
				/*printf("Button down at (% d, % d)\n", MainEvent.button.x, MainEvent.button.y);*/
				break;

			case SDL_MOUSEBUTTONUP:
				/*printf("Button up at (% d, % d)\n", MainEvent.button.x, MainEvent.button.y);*/
				break;
			default:
				break;
			}
		}
		if (is_quit == 0)
		{
			if (map == 0)
			{
				Key_detect();

				Map_0();
				Center_Text(0, 0, W, H / 6, "Hallway");
				if (is_change == 1)
				{
					// 换地图
					map_num = 1;
					Map_Shift(map_num, W/2 + Map1_BackGroundSurface->w * 3/2 - player.w/2,player.y);
				}
			}
			else if (map == 1)
			{
				Key_detect();

				Map_1();
				Center_Text(0, 0, W - 100, H / 6 - 10, "Don't Jump In!");
				if (is_change == 1)
				{
					// 换地图
					if (map_num == 0)
					{
						Map_Shift(map_num, player.w/2, player.y);
					}
					else if (map_num == 2)
					{
						Map_Shift(map_num, player.w / 2, player.h / 2);
					}
					else if (map_num == 3)
					{
						Map_Shift(map_num, player.w / 2, player.h / 2);
					}
					else if (map_num == 5)
					{
						Map_Shift(map_num, player.w / 2, player.h / 2);
					}
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
				const char* Month[12] = { "January","February","March","April","May","June","July","August","September","October","November","December"};
				
				sprintf(date, "%s %d -> %s %d", Month[puzzle1.register_row], puzzle1.register_column+1, Month[puzzle1.player_row], puzzle1.player_column+1);

				Center_Text(0, 0, W, H / 6-20, date);

				// 判断结果
				if (puzzle1.result == 1)
				{
					// dragon win
					Map_Shift(1, W/2, H/2 + player.h*2);
				}else if (puzzle1.result == 0)
				{
					// play Music
					Mix_HaltMusic();
					// player win
					Map_Shift(5, player.w / 2, player.h / 2);
					/*goto log_in;*/
				}
			}
			else if (map == 3)
			{
				Key_detect();

				Are_You_Tough_Man();

				if (SDL_GetTicks64()- Start_Plane_time < 5000)
				{
					Bullet_Generate_Ratio = 40;
				}else if (SDL_GetTicks64() - Start_Plane_time > 5000 && SDL_GetTicks64() - Start_Plane_time < 8000)
				{
					Bullet_Generate_Ratio = 30;
				}
				else if (SDL_GetTicks64() - Start_Plane_time > 8000 && SDL_GetTicks64() - Start_Plane_time < 10000)
				{
					Bullet_Generate_Ratio = 25;
				}
				else if (SDL_GetTicks64() - Start_Plane_time > 10000)
				{
					Bullet_Generate_Ratio = 6;
				}

				// 输出秒数
				/*char hit_num[60];*/
				int Time = 20000;  // 定时器倒计时(ms)
				char time[60];
				int msecond = SDL_GetTicks64() - Start_Plane_time;
				int second = (Time - msecond) / 1000;
				msecond = (Time - msecond) % 1000;
				sprintf(time, "%d.%ds", second, msecond);
				Center_Text(0, 0, W, H/3, time);
				/*if (hit_count <= 1)
				{
					sprintf(hit_num, "Hitten %d time", hit_count);
				}
				else
				{
					sprintf(hit_num, "Hitten %d times", hit_count);
				}
				Center_Text(0, 0, W, H/5, hit_num);*/

				if (hit_count >= 1 || second>=20)
				{
					Map_Shift(1, 600 + player.w / 2, 600 - player.h / 2);
				}
			}
			else if (map == 5)
			{
				Mix_HaltMusic();
				running = bOss1_For_sciENtist2();
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
	// Map0
	Puzzle1_BackGroundSurface = IMG_Load("assets/Ingame/bg_asgore_hallway_0.png");
	Puzzle1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Puzzle1_BackGroundSurface);  // 转换为纹理
	Puzzle1_BackGroundRect.x = 0;  // 左上角
	Puzzle1_BackGroundRect.y = H/2 - Puzzle1_BackGroundSurface->h/2;
	Puzzle1_BackGroundRect.w = Puzzle1_BackGroundSurface->w;
	Puzzle1_BackGroundRect.h = Puzzle1_BackGroundSurface->h;
	// Map1
	Map1_BackGroundSurface = IMG_Load("assets/Ingame/bg_asgoreparlor_0.png");
	Map1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Map1_BackGroundSurface);  // 转换为纹理
	Map1_BackGroundRect.x = W/2 - Map1_BackGroundSurface->w * 3/2;  // 居中
	Map1_BackGroundRect.y = H / 2 - Map1_BackGroundSurface->h*3 / 2;
	Map1_BackGroundRect.w = Map1_BackGroundSurface->w*3;
	Map1_BackGroundRect.h = H;
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
	Heart_BackGroundRect.y = 96+puzzle1.puzzle_1_h/2 - puzzle1.puzzle_1_w/2;
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
	// 左右
	Player0_BackGroundSurface = IMG_Load("assets/character/spr_maincharal_0.png");
	Player0_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player0_BackGroundSurface);  // 转换为纹理
	Player0_BackGroundRect.x = player.x - player.w / 2;
	Player0_BackGroundRect.y = player.y - player.h / 2;
	Player0_BackGroundRect.w = player.w;
	Player0_BackGroundRect.h = player.h;
	Player1_BackGroundSurface = IMG_Load("assets/character/spr_maincharal_1.png");
	Player1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player1_BackGroundSurface);  // 转换为纹理
	Player1_BackGroundRect.x = player.x - player.w / 2;
	Player1_BackGroundRect.y = player.y - player.h / 2;
	Player1_BackGroundRect.w = player.w;
	Player1_BackGroundRect.h = player.h;
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
	Plane_BackGroundRect.w = Plane_BackGroundSurface->w/1.5;
	Plane_BackGroundRect.h = Plane_BackGroundSurface->h/1.5;
	Plane_BackGroundRect.x = W / 2 - Plane_BackGroundRect.w / 2;
	Plane_BackGroundRect.y = H / 2 - Plane_BackGroundRect.h / 2;
	// Bullet
	Bullet_BackGroundSurface = IMG_Load("assets/Ingame/bullet.png");
	Bullet_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Bullet_BackGroundSurface);  // 转换为纹理
	for (int i = 0; i < Bullet_num; i++)
	{
		Bullet_BackGroundRect[i].w = Plane_BackGroundSurface->h / 6;
		Bullet_BackGroundRect[i].h = Plane_BackGroundSurface->h / 6;  // the size of bullet is one six of the plane's Surface height
		Bullet[i].r = Bullet_BackGroundRect[i].w / 2;
	}
	// Plane_BG_IMG
	Plane_fight_BackGroundRect.x = 0;
	Plane_fight_BackGroundRect.y = 0;
	Plane_fight_BackGroundRect.w = W;
	Plane_fight_BackGroundRect.h = H;


	Date_Font = TTF_OpenFont("assets/Font/Allan-Regular.ttf", 50);

	SoundEffect = Mix_LoadWAV("assets/Audio/teleport.mp3");
	Error_SoundEffect = Mix_LoadWAV("assets/Audio/error.mp3");
	SoundBackGround = Mix_LoadMUS("assets/Audio/bar.mp3");
	Puzzle_1_bgm = Mix_LoadMUS("assets/Audio/puzzle1.mp3");
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
		if (F_counter >= F_N && F_counter < 2 * F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (F_counter >= 0 && F_counter < F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player1_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (F_counter >= 2 * F_N)
		{
			F_counter = 0;
			SDL_RenderCopyEx(Puzzle1_Renderer, Player1_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
	}
	else if (key_cmd.d == 0 && key_cmd.a == 1)
	{
		key_cmd.l_cmd = char("a");
		if (F_counter >= F_N && F_counter < 2 * F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
		}
		else if (F_counter >= 0 && F_counter < F_N)
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player1_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
		}
		else if (F_counter >= 2 * F_N)
		{
			F_counter = 0;
			SDL_RenderCopyEx(Puzzle1_Renderer, Player1_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
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
void Map_0()
{
	int x_register = player.x;
	int y_register = player.y;

	// 处理地图移动
	if (key_cmd.w == 1)
	{
		y_register -= player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 1) == 0)  // collision detect
		{
			player.y -= player.v_y;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.s == 1)
	{
		y_register += player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 0, 1) == 0)
		{
			player.y += player.v_y;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.a == 1 && Puzzle1_BackGroundRect.x + player.v_x < 0 && player.x >= W/2)
	{
		// 此时地图不到头，人在右半屏
		player.x -= player.v_x;
		if (player.x <= W / 2)
		{
			int i = W / 2 - player.x;
			player.x = W / 2;
			Puzzle1_BackGroundRect.x += i;
		}
		/*Puzzle1_BackGroundRect.x += player.v_x;*/
	}
	else if (key_cmd.a == 1 && Puzzle1_BackGroundRect.x + player.v_x >= 0)
	{
		// 此时地图(快)到头了，人在左半屏
		player.x -= player.v_x;
		Puzzle1_BackGroundRect.x = 0;
		if (player.x < player.w/2)
		{
			player.x = player.w / 2;
		}
	}
	if (key_cmd.d == 1 && Puzzle1_BackGroundRect.x - player.v_x > -Puzzle1_BackGroundSurface->w+W && player.x <= W / 2)
	{
		// 此时地图不到头，人在左半屏
		player.x += player.v_x;
		if (player.x >= W / 2)
		{
			int i = player.x - W / 2;
			player.x = W / 2;
			Puzzle1_BackGroundRect.x -= i;
		}
		if (player.x <= player.w && key_cmd.E == 1)
		{
			is_change = 1;
		}
	}
	else if (key_cmd.d == 1 && Puzzle1_BackGroundRect.x - player.v_x <= -Puzzle1_BackGroundSurface->w + W)
	{
		// 此时地图(快)到头了，人在右半屏
		player.x += player.v_x;
		if (player.x >= W - player.w / 2)
		{
			player.x = W - player.w / 2;
		}
	}
	if (Puzzle1_BackGroundRect.x == 0 && key_cmd.E == 1 && player.x <= player.w)
	{
		is_change = 1;
	}
	// 处理碰撞体积
	//if (player.y <= 310)
	//{
	//	player.y = 310;
	//}
	//if (player.y >= 418)
	//{
	//	player.y = 418;
	//}
	if (player.x >= 1194)
	{
		player.x = 1194;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Puzzle1_BackGroundTexture, NULL, &Puzzle1_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();
}
void Map_1()
{
	int x_register = player.x;
	int y_register = player.y;

	// 处理移动
	if (key_cmd.w == 1)
	{
		y_register -= player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 2, 6) == 0)  // collision detect
		{
			player.y -= player.v_y;
		}
		x_register = player.x;
		y_register = player.y;  // 防止影响后续判断
	}
	if (key_cmd.s == 1)
	{
		y_register += player.v_y;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 2, 6) == 0)  // collision detect
		{
			player.y += player.v_y;
		}
		x_register = player.x;
		y_register = player.y;
	}
	if (key_cmd.a == 1)
	{
		x_register -= player.v_x;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 2, 6) == 0)  // collision detect
		{
			player.x -= player.v_x;
		}
		x_register = player.x;
		y_register = player.y;
	}
	if (key_cmd.d == 1)
	{
		x_register += player.v_x;
		if (Collision_Detect(x_register - player.w / 2, y_register - player.h / 2, player.r, 2, 6) == 0)  // collision detect
		{
			player.x += player.v_x;
		}
		x_register = player.x;
		y_register = player.y;
	}
	if (key_cmd.E == 1)
	{
		if (player.x >= W / 2 + Map1_BackGroundSurface->w * 3 / 2 - player.w)
		{
			is_change = 1;
			map_num = 0;
		}
		else if (player.x >= 374 && player.x <= 790 && player.y >= 118 && player.y <= 332)
		{
			is_change = 1;
			map_num = 2;
		}
		else if (player.x >= 147 && player.x <= 220 && player.y >= 363 - player.h / 2 && player.y <= 523 - player.h / 2)
		{
			is_change = 1;
			map_num = 5;
		}
		else if (player.x >= 556 + player.w/2 && player.x <= 648 + player.w / 2 && player.y >= 516 - player.h / 2)
		{
			is_change = 1;
			map_num = 3;
		}
	}

	// 限制移动
	if (player.y <= 0)
	{
		player.y = 0;
	}
	if (player.y >= H)
	{
		player.y = H;
	}
	if (player.x >= W / 2 + Map1_BackGroundSurface->w * 3 / 2 - player.w / 2)
	{
		player.x = W / 2 + Map1_BackGroundSurface->w * 3 / 2 - player.w / 2;
	}
	if (player.x <= W / 2 - Map1_BackGroundSurface->w * 3 / 2 + player.w / 2)
	{
		player.x = W / 2 - Map1_BackGroundSurface->w * 3 / 2 + player.w / 2;
	}

	// 渲染背景
	SDL_RenderCopy(Puzzle1_Renderer, Map1_BackGroundTexture, NULL, &Map1_BackGroundRect);
	// 渲染玩家动画
	PrintPlayer();
}

void Puzzle_1()
{
	// dragon决策
	if(puzzle1.round == 1)
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
		if (key_cmd.d >= 1 && puzzle1.player_column < 30 && calendar[puzzle1.player_row][puzzle1.player_column+1] == 1)
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
	}else if (puzzle1.round == 1)
	{
		SDL_RenderCopy(Puzzle1_Renderer, Dragon_Heart_BackGroundTexture, NULL, &Heart_BackGroundRect);  // dragon_heart
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
		if (Is_collide(object[7], Bullet[i].r*2, Bullet[i].r*2, Bullet[i].x, Bullet[i].y, Bullet[i].r) == 1 && SDL_GetTicks64() - last_hit > No_Hit_Time)  // collision
		{
			hit_count += 1;
			last_hit = SDL_GetTicks64();
			Bullet[i].is_exist = false;  // after hit bullet disappear
		}
	}

	// 渲染图片
	SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Plane_fight_BackGroundRect);

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

	// 渲染Bullet
	Bullet_Print();

	
}
/*
	作用为淡出地图，请在render_present前最后一个使用！因为它要盖住所有纹理。
*/
void Map_Shift(int map_num, int x, int y)
{
	int d_t = 1;  // unit: s
	int F_N = FR * d_t;
	int add = 255 / F_N;
	alpha += add;
	if (alpha >= 255)
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, 255);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
		// 归零
		alpha = 0;
		is_change = 0;
		if (map == 3 && map_num == 1)
		{
			player.x = W/2;
			player.y = H- player.h*2;  // 方便快速重开
			map = map_num;
		}
		else
		{
			map = map_num;
			player.x = x;
			player.y = y;
			if (map_num == 2)
			{
				Mix_HaltMusic();
				// play Music
				Mix_VolumeMusic(32);  // 0~128
				Mix_PlayMusic(Puzzle_1_bgm, -1);  // 播放音乐
			}
			if (map_num == 1)
			{
				player.x = 1074;
				player.y = 440;  // 防止卡住
			}
			if (map_num == 0)
			{
				player.x = 3;
				player.y = 350;  // 防止卡住
			}
			if (map_num == 3)
			{
				hit_count = 0;
				Start_Plane_time = SDL_GetTicks64();
				Bullet_Generate_Ratio = 20;
				Bullet_INIT();
				Plane_BackGroundRect.w = Plane_BackGroundSurface->w / 1.5;
				Plane_BackGroundRect.h = Plane_BackGroundSurface->h / 1.5;
				Plane_BackGroundRect.x = W / 2 - Plane_BackGroundRect.w / 2;
				Plane_BackGroundRect.y = H / 2 - Plane_BackGroundRect.h / 2;
				Plane_Object_Update();
				Object_INIT_Point(7);
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
		}
	}
	else
	{
		SDL_SetTextureAlphaMod(Shifter_BackGroundTexture, alpha);
		SDL_RenderCopy(Puzzle1_Renderer, Shifter_BackGroundTexture, NULL, &Shifter_BackGroundRect);
	}
}

/*
*	QUIT
*	Functions:关闭所有子系统
*	Parameter:NULL
*	Return Value:NULL
*/
void QUIT()
{
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
	SDL_FreeSurface(Shifter_BackGroundSurface);
	SDL_FreeSurface(Map1_BackGroundSurface);
	SDL_FreeSurface(Heart_BackGroundSurface);
	SDL_FreeSurface(Dragon_Heart_BackGroundSurface);
	SDL_FreeSurface(Plane_BackGroundSurface);
	SDL_FreeSurface(Bullet_BackGroundSurface);
	
	Mix_FreeChunk(SoundEffect);
	Mix_FreeChunk(Error_SoundEffect);
	Mix_FreeMusic(SoundBackGround);
	Mix_FreeMusic(Puzzle_1_bgm);

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
	SDL_DestroyTexture(Shifter_BackGroundTexture);
	SDL_DestroyTexture(Map1_BackGroundTexture);
	SDL_DestroyTexture(Heart_BackGroundTexture);
	SDL_DestroyTexture(Dragon_Heart_BackGroundTexture);
	SDL_DestroyTexture(Plane_BackGroundTexture);
	SDL_DestroyTexture(Bullet_BackGroundTexture);

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
	// y = 280
	object[0].x = 0;
	object[0].y = 250;
	object[0].w = W;
	object[0].h = 30;
	Object_INIT_Point(0);
	
	// y = 456
	object[1].x = 0;
	object[1].y = 456;
	object[1].w = W;
	object[1].h = 10;
	Object_INIT_Point(1);

	// y = 317，x = 994
	object[2].x = 994;
	object[2].y = 0;
	object[2].w = 100;
	object[2].h = 317;
	Object_INIT_Point(2);

	// y = 112 x = 873
	object[3].x = 873;
	object[3].y = 0;
	object[3].w = 100;
	object[3].h = 112;
	Object_INIT_Point(3);

	// y = 68
	object[4].x = 0;
	object[4].y = 0;
	object[4].w = W;
	object[4].h = 68;
	Object_INIT_Point(4);

	// x = 338 y = 131
	object[5].x = 0;
	object[5].y = 0;
	object[5].w = 338;
	object[5].h = 131;
	Object_INIT_Point(5);

	// x = 338 y = 131
	object[5].x = 0;
	object[5].y = 0;
	object[5].w = 338;
	object[5].h = 131;
	Object_INIT_Point(5);

	// x = 256 y = 313
	object[6].x = 0;
	object[6].y = 0;
	object[6].w = 256;
	object[6].h = 313;
	Object_INIT_Point(6);

	// Plane
	Plane_Object_Update();
	Object_INIT_Point(7);
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
	*/
	int result = 1;  // 0 represents no collision, 1 represents collision

	//  horizontal detect
	int x_1 = (object.l_u[0] + object.r_u[0]) / 2;
	int x_2 = x + w/2;
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

int Is_collide(Object object,int player_w,int player_h, int x,int y, int r)  // detect if there are collide
{
	/*
	Object object : rectangle object
	int player_w : round object width
	int player_h : round object height
	int x : round object left-top x
	int y : round object left-top y
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
