#include "SDL2_test.h"
/*
*
*	Global Variable
*
*/
SDL_Window* Puzzle1_Window = NULL;  // 窗口
SDL_Renderer* Puzzle1_Renderer = NULL;  // 画笔
SDL_Surface* Puzzle1_BackGroundSurface = NULL;  // 图形
SDL_Texture* Puzzle1_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Puzzle1_BackGroundRect;  // Texture 

SDL_Surface* Player0_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player0_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Player0_BackGroundRect;  // Texture 

SDL_Surface* Player1_BackGroundSurface = NULL;  // 图形
SDL_Texture* Player1_BackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
SDL_Rect Player1_BackGroundRect;  // Texture 

TTF_Font* Date_Font = NULL;
//SDL_Surface* DateSurface = NULL;
//SDL_Texture* DateTexture = NULL;
//SDL_Rect DateRect;
SDL_Color FontColor = { 255, 255, 255, 255 };  // RGBA
Keycontrol key_cmd;  // 键盘控制结构体
Player player; // 玩家结构体
int W = 1250;
int H = 650;
int is_quit = 0;  // 标志是否QUIT过
int map = 0;  // 0代表地图0；1代表puzzle1；
char last_cmd[2];  // 代表上一个命令


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

	// create window
	Puzzle1_Window = SDL_CreateWindow("TimeTravel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
	Puzzle1_Renderer = SDL_CreateRenderer(Puzzle1_Window, -1, SDL_RENDERER_ACCELERATED);

	// open audio

	// load images
	LOAD();

	while (1)
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
				break;
			case SDL_KEYDOWN:
				switch (MainEvent.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					QUIT();
					break;

				default:
					break;
				}
				break;
			default:
				break;
			}
		}
		if (is_quit == 1)
		{
			break;
		}
		if (map == 0)
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

			Map_0();
			Center_Text(0, 0, W, H / 6, "Map_0_Test");
		}
		else if (map == 1)
		{
			Center_Text(0, 0, W, H / 6, "Puzzle_1_Test");
		}

		// represent
		SDL_RenderPresent(Puzzle1_Renderer);

		end_t = SDL_GetTicks64();
		delay = FT - (end_t - start_t);
		if (delay > 0)
		{
			SDL_Delay(delay);
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
	Mix_Volume(-1, MIX_MAX_VOLUME);
	TTF_Init();
}
void LOAD()
{
	Puzzle1_BackGroundSurface = IMG_Load("assets/Ingame/bg_asgore_hallway_0.png");
	Puzzle1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Puzzle1_BackGroundSurface);  // 转换为纹理
	Puzzle1_BackGroundRect.x = 0;  // 左上角
	Puzzle1_BackGroundRect.y = H/2 - Puzzle1_BackGroundSurface->h/2;
	Puzzle1_BackGroundRect.w = Puzzle1_BackGroundSurface->w;
	Puzzle1_BackGroundRect.h = Puzzle1_BackGroundSurface->h;

	Player0_BackGroundSurface = IMG_Load("assets/character/spr_maincharal_0.png");
	Player0_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player0_BackGroundSurface);  // 转换为纹理
	Player0_BackGroundRect.x = player.x;  // 左上角
	Player0_BackGroundRect.y = player.y;
	Player0_BackGroundRect.w = player.w;
	Player0_BackGroundRect.h = player.h;

	Player1_BackGroundSurface = IMG_Load("assets/character/spr_maincharal_1.png");
	Player1_BackGroundTexture = SDL_CreateTextureFromSurface(Puzzle1_Renderer, Player1_BackGroundSurface);  // 转换为纹理
	Player1_BackGroundRect.x = player.x;  // 左上角
	Player1_BackGroundRect.y = player.y;
	Player1_BackGroundRect.w = player.w;
	Player1_BackGroundRect.h = player.h;

	Date_Font = TTF_OpenFont("assets/Font/Allan-Regular.ttf", 50);
}
void PrintPlayer()
{

}
void Map_0()
{
	// 处理键盘操作
	if (key_cmd.w == 1)
	{
		player.y -= player.v_y;
	}
	if (key_cmd.s == 1)
	{
		player.y += player.v_y;
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

	// 渲染图片
	SDL_RenderCopy(Puzzle1_Renderer, Puzzle1_BackGroundTexture, NULL, &Puzzle1_BackGroundRect);

	Player0_BackGroundRect = { player.x - player.w / 2, player.y - player.h / 2, player.w, player.h };

	if (key_cmd.d == 1 && key_cmd.a == 0)
	{
		key_cmd.l_cmd = char("d");
		SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL,&Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
	}else if (key_cmd.d == 0 && key_cmd.a == 1)
	{
		key_cmd.l_cmd = char("a");
		SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
	}
	else if (key_cmd.d == 0 && key_cmd.a == 0)
	{
		if (key_cmd.l_cmd == char("d"))
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}else if (key_cmd.l_cmd == char("a"))
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_NONE);
		}
		else
		{
			SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
	}
	else
	{
		SDL_RenderCopyEx(Puzzle1_Renderer, Player0_BackGroundTexture, NULL, &Player0_BackGroundRect, 0, NULL, SDL_FLIP_HORIZONTAL);
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

	SDL_DestroyTexture(Player0_BackGroundTexture);
	SDL_DestroyTexture(Player1_BackGroundTexture);
	SDL_DestroyTexture(Puzzle1_BackGroundTexture);

	TTF_CloseFont(Date_Font);
	
	SDL_DestroyWindow(Puzzle1_Window);
	SDL_DestroyRenderer(Puzzle1_Renderer);

	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
	/*Mix_CloseAudio();*/

	is_quit = 1;
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