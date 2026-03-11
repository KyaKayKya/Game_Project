#define _CRT_SECURE_NO_WARNINGS
#include "pause_menu.h"
#include "SDL2_test.h"

/* ============================================================
 *  NEW PAUSE MENU  -  pure SDL2 rendering, no external images
 *  Pause() returns:  0 = resume game,  -1 = quit to desktop
 * ============================================================ */

static int currentFrame = 0;   /* kept so closeSDL_1 compiles */

/* ---- text helpers ----------------------------------------- */

static void pm_textC(TTF_Font* f, const char* s, SDL_Color c, int cx, int y)
{
    if (!f || !s || !renderer) return;
    SDL_Surface* sur = TTF_RenderText_Solid(f, s, c);
    if (!sur) return;
    SDL_Rect r = { cx - sur->w / 2, y, sur->w, sur->h };
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, sur);
    SDL_FreeSurface(sur);
    if (!tex) return;
    SDL_RenderCopy(renderer, tex, NULL, &r);
    SDL_DestroyTexture(tex);
}

static void pm_textL(TTF_Font* f, const char* s, SDL_Color c, int x, int y)
{
    if (!f || !s || !renderer) return;
    SDL_Surface* sur = TTF_RenderText_Solid(f, s, c);
    if (!sur) return;
    SDL_Rect r = { x, y, sur->w, sur->h };
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, sur);
    SDL_FreeSurface(sur);
    if (!tex) return;
    SDL_RenderCopy(renderer, tex, NULL, &r);
    SDL_DestroyTexture(tex);
}

/* ---- How-to-Play sub-screen -------------------------------- */

static void pm_help_screen()
{
    TTF_Font* hdF = TTF_OpenFont("2.ttf", 26);
    TTF_Font* bdF = TTF_OpenFont("2.ttf", 20);
    if (!hdF && !bdF) return;
    if (!hdF) hdF = bdF;
    if (!bdF) bdF = hdF;

    /* type: 0=big title  1=section header  2=body  3=blank */
    struct HLine { const char* text; int type; };
    static const HLine lines[] = {
        { "HOW  TO  PLAY",                                        0 },
        { "",                                                      3 },
        { "MOVEMENT",                                             1 },
        { "  Arrow Keys / WASD   Move your character",           2 },
        { "  E                   Interact with objects / NPC",   2 },
        { "  Enter               Skip or confirm dialogue",      2 },
        { "  ESC                 Open this Pause menu",          2 },
        { "",                                                      3 },
        { "COLLECTIBLES",                                         1 },
        { "  Disks               Find all disks to unlock story progress", 2 },
        { "",                                                      3 },
        { "MINIGAMES  &  BOSSES",                                 1 },
        { "  Logic Puzzle        Arrange logic gates to complete the circuit", 2 },
        { "  Parkour             Jump across platforms, do not fall", 2 },
        { "  Boss 1 (Lamy)       Survive the timed encounter",   2 },
        { "  Boss 2              Dodge bombs and incoming projectiles", 2 },
        { "",                                                      3 },
        { "TIPS",                                                 1 },
        { "  Save often via the Pause menu (Save Game option)",  2 },
        { "  Talk to every character to advance the story",      2 },
        { "  Explore each map fully - hidden disks are everywhere", 2 },
    };
    const int N = (int)(sizeof(lines) / sizeof(lines[0]));

    SDL_Color title_c  = { 255, 220,  60, 255 };
    SDL_Color header_c = { 100, 160, 255, 255 };
    SDL_Color body_c   = { 200, 200, 200, 255 };
    SDL_Color white    = { 255, 255, 255, 255 };
    SDL_Color yellow   = { 255, 220,  60, 255 };

    SDL_Rect backBtn = { 555, 596, 140, 36 };
    bool running = true;

    while (running) {
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        bool backHov = (mx >= backBtn.x && mx < backBtn.x + backBtn.w &&
                        my >= backBtn.y && my < backBtn.y + backBtn.h);

        SDL_SetRenderDrawColor(renderer, 8, 10, 22, 255);
        SDL_RenderClear(renderer);

        SDL_Rect panel = { 60, 20, 1130, 600 };
        SDL_SetRenderDrawColor(renderer, 14, 18, 38, 255);
        SDL_RenderFillRect(renderer, &panel);
        SDL_SetRenderDrawColor(renderer, 80, 100, 200, 255);
        SDL_RenderDrawRect(renderer, &panel);

        int y = 48;
        for (int i = 0; i < N; i++) {
            const char* txt = lines[i].text;
            int type = lines[i].type;
            if (type == 3) { y += 10; continue; }
            TTF_Font* f = (type == 2) ? bdF : hdF;
            SDL_Color c = (type == 0) ? title_c
                        : (type == 1 ? header_c : body_c);
            if (type == 0)
                pm_textC(f, txt, c, 625, y);
            else
                pm_textL(f, txt, c, 95, y);
            y += (type == 0 ? 36 : (type == 1 ? 30 : 25));
        }

        SDL_SetRenderDrawColor(renderer,
                               backHov ? 60 : 30, backHov ? 80 : 40, 180, 255);
        SDL_RenderFillRect(renderer, &backBtn);
        SDL_SetRenderDrawColor(renderer, 100, 130, 255, 255);
        SDL_RenderDrawRect(renderer, &backBtn);
        pm_textC(bdF, "< BACK  (ESC)",
                 backHov ? yellow : white,
                 backBtn.x + backBtn.w / 2, backBtn.y + 8);

        SDL_RenderPresent(renderer);

        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT)
                running = false;
            if (ev.type == SDL_KEYDOWN &&
                ev.key.keysym.sym == SDLK_ESCAPE)
                running = false;
            if (ev.type == SDL_MOUSEBUTTONDOWN &&
                ev.button.button == SDL_BUTTON_LEFT) {
                int bx = ev.button.x, by = ev.button.y;
                if (bx >= backBtn.x && bx < backBtn.x + backBtn.w &&
                    by >= backBtn.y && by < backBtn.y + backBtn.h)
                    running = false;
            }
        }
        SDL_Delay(16);
    }

    if (hdF != bdF) TTF_CloseFont(hdF);
    if (bdF)        TTF_CloseFont(bdF);
}

/* ---- main Pause() ----------------------------------------- */

/* Returns: 0 = resume game,  -1 = quit to desktop */
int Pause()
{
    TTF_Font* titleF = TTF_OpenFont("2.ttf", 44);
    TTF_Font* itemF  = TTF_OpenFont("2.ttf", 28);
    TTF_Font* hintF  = TTF_OpenFont("2.ttf", 18);

    if (!titleF) titleF = itemF;
    if (!hintF)  hintF  = itemF;
    if (!itemF) {
        if (titleF && titleF != itemF) TTF_CloseFont(titleF);
        return 0;
    }

    SDL_Color white    = { 255, 255, 255, 255 };
    SDL_Color yellow   = { 255, 220,  60, 255 };
    SDL_Color lgrey    = { 170, 170, 170, 255 };
    SDL_Color green    = {  80, 210, 110, 255 };
    SDL_Color red_col  = { 220,  70,  70, 255 };
    SDL_Color hint_col = {  90,  90, 110, 255 };

    /* panel geometry */
    const int PW = 430, PH = 400;
    const int PX = (1250 - PW) / 2;   /* 410 */
    const int PY = (650  - PH) / 2;   /* 125 */

    /* menu items */
    struct MenuItem { const char* label; SDL_Color baseCol; };
    MenuItem items[4] = {
        { "Resume Game",     white   },
        { "Save Game",       green   },
        { "How to Play",     lgrey   },
        { "Quit to Desktop", red_col },
    };
    const int N = 4;
    const int ITEM_W = 340, ITEM_H = 48;
    const int ITEM_X = PX + (PW - ITEM_W) / 2;
    int itemY[4];
    for (int i = 0; i < N; i++)
        itemY[i] = PY + 118 + i * 62;

    int    selected  = 0;
    int    result    = 0;
    bool   running   = true;
    bool   saveFlash = false;
    Uint32 saveTime  = 0;

    while (running) {
        int mx, my;
        SDL_GetMouseState(&mx, &my);

        /* black base + tinted overlay */
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer, 15, 20, 50, 210);
        { SDL_Rect full = { 0, 0, 1250, 650 };
          SDL_RenderFillRect(renderer, &full); }

        /* panel */
        { SDL_Rect panel = { PX, PY, PW, PH };
          SDL_SetRenderDrawColor(renderer, 14, 18, 42, 255);
          SDL_RenderFillRect(renderer, &panel);
          SDL_SetRenderDrawColor(renderer, 80, 110, 220, 255);
          SDL_RenderDrawRect(renderer, &panel);
          SDL_Rect inner = { PX+2, PY+2, PW-4, PH-4 };
          SDL_SetRenderDrawColor(renderer, 40, 55, 120, 255);
          SDL_RenderDrawRect(renderer, &inner); }

        /* separator line */
        SDL_SetRenderDrawColor(renderer, 80, 110, 220, 255);
        SDL_RenderDrawLine(renderer, PX+20, PY+86, PX+PW-20, PY+86);

        /* title */
        pm_textC(titleF, "PAUSED", yellow, 625, PY + 26);

        /* menu items */
        for (int i = 0; i < N; i++) {
            bool hover = (mx >= ITEM_X && mx < ITEM_X + ITEM_W &&
                          my >= itemY[i] && my < itemY[i] + ITEM_H);
            bool sel   = (i == selected);

            if (hover || sel) {
                SDL_Rect ibg = { ITEM_X, itemY[i], ITEM_W, ITEM_H };
                SDL_SetRenderDrawColor(renderer,
                    sel ? 35 : 28, sel ? 48 : 38, sel ? 110 : 80, 220);
                SDL_RenderFillRect(renderer, &ibg);
                SDL_SetRenderDrawColor(renderer,
                    sel ? 100 : 70, sel ? 130 : 90, 220, 255);
                SDL_RenderDrawRect(renderer, &ibg);
            }

            if (sel)
                pm_textL(itemF, ">", yellow, ITEM_X + 8, itemY[i] + 10);

            SDL_Color col = (hover || sel) ? yellow : items[i].baseCol;
            pm_textC(itemF, items[i].label, col,
                     ITEM_X + ITEM_W / 2, itemY[i] + 10);
        }

        /* save flash */
        if (saveFlash) {
            if (SDL_GetTicks() - saveTime < 1800)
                pm_textC(hintF, "Game saved successfully!", green,
                         625, PY + PH + 12);
            else
                saveFlash = false;
        }

        /* keyboard hint */
        pm_textC(hintF,
                 "Up/Down: select    Enter: confirm    ESC: resume",
                 hint_col, 625, PY + PH - 22);

        SDL_RenderPresent(renderer);

        /* events */
        bool doActivate = false;
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) {
                result = -1; running = false; break;
            }
            if (ev.type == SDL_KEYDOWN) {
                switch (ev.key.keysym.sym) {
                case SDLK_ESCAPE:    result = 0; running = false;                break;
                case SDLK_UP:        selected = (selected - 1 + N) % N;         break;
                case SDLK_DOWN:      selected = (selected + 1)      % N;        break;
                case SDLK_RETURN:
                case SDLK_KP_ENTER:  doActivate = true;                          break;
                default: break;
                }
            }
            if (ev.type == SDL_MOUSEBUTTONDOWN &&
                ev.button.button == SDL_BUTTON_LEFT) {
                int bx = ev.button.x, by = ev.button.y;
                for (int i = 0; i < N; i++) {
                    if (bx >= ITEM_X && bx < ITEM_X + ITEM_W &&
                        by >= itemY[i] && by < itemY[i] + ITEM_H) {
                        selected = i;
                        doActivate = true;
                        break;
                    }
                }
            }
        }

        if (doActivate && running) {
            switch (selected) {
            case 0:  result = 0;  running = false;                       break;
            case 1:  save(); saveFlash = true; saveTime = SDL_GetTicks(); break;
            case 2:  pm_help_screen();                                    break;
            case 3:  result = -1; running = false;                        break;
            }
        }

        SDL_Delay(16);
    }

    if (titleF != itemF) TTF_CloseFont(titleF);
    if (hintF  != itemF) TTF_CloseFont(hintF);
    TTF_CloseFont(itemF);
    return result;
}

/* ---- kept for enter.h compatibility ----------------------- */
void closeSDL_1()
{
    currentFrame = 0;
    /* Previously freed 150 BMP animation frames.
       No longer used in new design. */
}
