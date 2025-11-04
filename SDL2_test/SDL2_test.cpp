//#include "SDL2_test.h"
///*
//*
//*	Global Variable
//*
//*/
//SDL_Window* Window = NULL;  // 窗口
//SDL_Renderer* Renderer = NULL;  // 画笔
//SDL_Surface* MainBackGroundSurface = NULL;  // 图形
//SDL_Texture* MainBackGroundTexture = NULL;  // 纹理（将图形转换成画笔能识别的轨迹）
//SDL_Rect MainBackGroundRect;  // Texture 
//
//SDL_Surface* PlayBackGroundSurface = NULL;  // 图形
//SDL_Texture* PlayBackGroundTexture = NULL;
//SDL_Rect PlayBackGroundRect;
//
//TTF_Font* TitleFont = NULL;
//SDL_Surface* TitleSurface = NULL;
//SDL_Texture* TitleTexture = NULL;
//SDL_Rect TitleRect;
//SDL_Color FontColor = { 0, 255, 255, 255 };  // RGBA
//
//Sentence title;  // title结构体
//Keycontrol key_cmd;  // 键盘控制结构体
//
//Mix_Chunk* SoundEffect = Mix_LoadWAV("assets/Audio/Bingo.mp3");
//Mix_Music *SoundBackGround = Mix_LoadMUS("assets/Audio/bgm.flac");
//
//int W = 1080;
//int H = 720;
//int v_t = 5;
//int is_quit = 0;  // 标志是否QUIT过
//
//int map = 0;
///*
//*
//*	Main
//*
//*/
//int main(int argc, char *argv[])
//{
//	// 帧率控制
//	Uint64 start_t, end_t;
//	int delay;
//
//	// initialize and quit
//	SDL_Init(SDL_INIT_EVERYTHING);
//	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
//	Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
//	Mix_Volume(-1, MIX_MAX_VOLUME);
//	TTF_Init();
//
//	// create window
//	Window = SDL_CreateWindow("SDL2_test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
//	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
//
//	// open audio
//	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048);
//	Mix_HaltMusic();
//	Mix_PlayMusic(SoundBackGround, 0);
//	printf("Music Volume: %d\n", Mix_GetMusicVolume(SoundBackGround));
//
//	// main event
//	SDL_Event MainEvent;
//
//	// load images
//	LOAD();
//
//	// render image
//	SDL_RenderClear(Renderer);
//	SDL_RenderCopy(Renderer, MainBackGroundTexture, NULL,&MainBackGroundRect);
//	SDL_RenderPresent(Renderer);  // 命令画笔显示
//	while (1)
//	{
//		start_t = SDL_GetTicks64();
//
//		while (SDL_PollEvent(&MainEvent))
//		{
//			switch (MainEvent.type)
//			{
//			case SDL_QUIT:
//				QUIT();
//				break;
//
//			case SDL_KEYDOWN:
//				switch (MainEvent.key.keysym.sym)
//				{
//				case SDLK_RETURN:
//					PLAY();
//					break;
//
//				case SDLK_ESCAPE:
//					QUIT();
//					break;
//
//				default:
//					break;
//				}
//				/*if (MainEvent.key.keysym.sym == SDLK_w)
//				{
//					key_cmd.w = 1;
//					Title();
//				}
//				if (MainEvent.key.keysym.sym == SDLK_s)
//				{
//					key_cmd.s = 1;
//					Title();
//				}
//				if (MainEvent.key.keysym.sym == SDLK_a)
//				{
//					key_cmd.a = 1;
//					Title();
//				}
//				if (MainEvent.key.keysym.sym == SDLK_d)
//				{
//					key_cmd.d = 1;
//					Title();
//				}*/
//				break;
//			/*case SDL_KEYUP:
//				if (MainEvent.key.keysym.sym == SDLK_w)
//				{
//					key_cmd.w = 0;
//					Title();
//				}
//				if (MainEvent.key.keysym.sym == SDLK_s)
//				{
//					key_cmd.s = 0;
//					Title();
//				}
//				if (MainEvent.key.keysym.sym == SDLK_a)
//				{
//					key_cmd.a = 0;
//					Title();
//				}
//				if (MainEvent.key.keysym.sym == SDLK_d)
//				{
//					key_cmd.d = 0;
//					Title();
//				}
//				break;*/
//			case SDL_MOUSEBUTTONDOWN:
//				// functions here
//				printf("Button down at (% d, % d)\n", MainEvent.button.x, MainEvent.button.y);
//				break;
//
//			case SDL_MOUSEBUTTONUP:
//				if (MainEvent.button.x > 742 && MainEvent.button.x < 840 && MainEvent.button.y>615 && MainEvent.button.y < 645)
//				{
//					map = 1;
//					PLAY();
//				}
//				if (MainEvent.button.x > 194 && MainEvent.button.x < 296 && MainEvent.button.y>612 && MainEvent.button.y < 643)
//				{
//					QUIT();
//				}
//				printf("Button up at (% d, % d)\n", MainEvent.button.x, MainEvent.button.y);
//				break;
//
//			case SDL_MOUSEMOTION:
//				// functions here
//				break;
//
//			default:
//				break;
//			}
//		}
//
//		if (is_quit == 1)
//		{
//			break;
//		}
//
//		if (map == 1)
//		{
//			const Uint8* keystates = SDL_GetKeyboardState(NULL);
//
//			if (keystates[SDL_SCANCODE_A])
//			{
//				key_cmd.a = 1;
//				/*printf("A: %d\n", start_t);  // 事实证明，keystates方法一次可以检测所有按键的状态*/
//			}
//			else if (keystates[SDL_SCANCODE_A] == 0)
//			{
//				key_cmd.a = 0;
//			}
//			if (keystates[SDL_SCANCODE_W])
//			{
//				key_cmd.w = 1;
//				/*printf("W: %d\n", start_t);*/
//			}
//			else if (keystates[SDL_SCANCODE_W] == 0)
//			{
//				key_cmd.w = 0;
//			}
//			if (keystates[SDL_SCANCODE_D])
//			{
//				key_cmd.d = 1;
//			}
//			else if (keystates[SDL_SCANCODE_D] == 0)
//			{
//				key_cmd.d = 0;
//			}
//			if (keystates[SDL_SCANCODE_S])
//			{
//				key_cmd.s = 1;
//			}
//			else if (keystates[SDL_SCANCODE_S] == 0)
//			{
//				key_cmd.s = 0;
//			}
//
//			Title();
//		}
//
//		end_t = SDL_GetTicks64();
//		delay = FT - (end_t - start_t);
//		if (delay > 0)
//		{
//			SDL_Delay(delay);
//		}
//	}
//
//	if (is_quit == 0)
//	{
//		QUIT();
//	}
//
//	return 0;
//}
///*
//*
//*	Function
//*
//*/
//
///*
//*	LOAD
//*	Functions: load images
//*	Parameter:NULL
//*	Return Value:NULL
//*/
//void LOAD()
//{
//	MainBackGroundSurface = IMG_Load("assets/Menu/Name.jpg");
//	MainBackGroundTexture = SDL_CreateTextureFromSurface(Renderer, MainBackGroundSurface);  // 转换为纹理
//	MainBackGroundRect.x = 0;  // 左上角
//	MainBackGroundRect.y = 0;
//	MainBackGroundRect.w = W;
//	MainBackGroundRect.h = H;
//	/*MainBackGroundRect.w = MainBackGroundSurface->w;
//	MainBackGroundRect.h = MainBackGroundSurface->h;*/
//
//	PlayBackGroundSurface = IMG_Load("assets/Ingame/1.png");
//	PlayBackGroundTexture = SDL_CreateTextureFromSurface(Renderer, PlayBackGroundSurface);  // 转换为纹理
//	PlayBackGroundRect.x = 0;  // 左上角
//	PlayBackGroundRect.y = 0;
//	PlayBackGroundRect.w = W;
//	PlayBackGroundRect.h = H;
//
//	TitleFont = TTF_OpenFont("assets/Font/Allan-Regular.ttf", 50);
//	title.x = 0;
//	title.y = 0;
//
//	key_cmd.w = 0;
//	key_cmd.s = 0;
//	key_cmd.a = 0;
//	key_cmd.d = 0;
//}	
//void PrintPlay()
//{
//	SDL_RenderCopy(Renderer, PlayBackGroundTexture, NULL, &PlayBackGroundRect);
//}
//void PLAY()
//{
//	SDL_RenderClear(Renderer);
//	SDL_RenderCopy(Renderer, PlayBackGroundTexture, NULL, &PlayBackGroundRect);
//	SDL_RenderPresent(Renderer);  // 命令画笔显示
//}
//
//void Title()
//{
//	TitleSurface = TTF_RenderUTF8_Blended(TitleFont, "Player", FontColor);
//	TitleTexture = SDL_CreateTextureFromSurface(Renderer, TitleSurface);  // 转换为纹理
//	// calc displacement
//	if (key_cmd.w == 1)
//	{
//		title.y -= v_t;
//	}
//	if (key_cmd.s == 1)
//	{
//		title.y += v_t;
//	}
//	if (key_cmd.a == 1)
//	{
//		title.x -= v_t;
//	}
//	if (key_cmd.d == 1)
//	{
//		title.x += v_t;
//	}
//	// 限幅
//	if (title.x <= 0)
//	{
//		title.x = 0;
//	}
//	else if (title.x >= W- TitleSurface->w)
//	{
//		title.x = W - TitleSurface->w;
//	}
//	if (title.y <= 0)
//	{
//		title.y = 0;
//	}
//	else if (title.y >= H- TitleSurface->h)
//	{
//		title.y = H - TitleSurface->h;
//	}
//	SDL_RenderClear(Renderer);
//	PrintPlay();
//	TitleRect = { title.x,title.y,TitleSurface->w,TitleSurface->h };
//	SDL_RenderCopy(Renderer, TitleTexture, NULL, &TitleRect);
//	SDL_RenderPresent(Renderer);  // 命令画笔显示
//}
///*
//*	QUIT
//*	Functions:关闭所有子系统
//*	Parameter:NULL
//*	Return Value:NULL
//*/
//void QUIT()
//{
//	SDL_FreeSurface(MainBackGroundSurface);
//	SDL_FreeSurface(PlayBackGroundSurface);
//	SDL_FreeSurface(TitleSurface);
//	Mix_FreeChunk(SoundEffect);
//	Mix_FreeMusic(SoundBackGround);
//
//	SDL_DestroyTexture(MainBackGroundTexture);
//	SDL_DestroyTexture(PlayBackGroundTexture);
//	SDL_DestroyTexture(TitleTexture);
//
//	TTF_CloseFont(TitleFont);
//	Mix_CloseAudio();
//
//	SDL_DestroyWindow(Window);
//	SDL_DestroyRenderer(Renderer);
//
//	SDL_Quit();
//	IMG_Quit();
//	Mix_Quit();
//	TTF_Quit();
//
//	is_quit = 1;
//}