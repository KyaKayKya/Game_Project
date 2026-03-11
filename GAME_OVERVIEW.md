# ILLUMINATI: 时间悖论 — 游戏完整技术说明

> 适用于：向其他 AI 说明项目结构，以便增加新内容或修改游戏流程。
> 项目路径：`E:\Game_Project-main\SDL2_test\`
> 技术栈：C++ / SDL2 / MSVC 2019 / Windows x64

---

## 一、游戏概述

- **类型**：多模式冒险解谜游戏（探索 + 战斗 + 解谜 + 躲避）
- **窗口**：1250 × 650 像素，40fps（每帧 25ms）
- **剧情**：玩家扮演**王子（Prince）**，与科学家 **Ellie** 乘坐时间机从末世未来回到过去，阻止光明会（Illuminati）用生化武器毁灭世界。需要对抗两个 Boss（被控制的科学家 Wyvern 和最终Boss龙 Dragon），并拆除生化炸弹。
- **结局**：受 `kill_Scientist`（是否击杀 Wyvern）和各 Boss 战结果影响，有多种结局对话。

---

## 二、文件结构与模块职责

| 文件 | 行数 | 职责 |
|------|------|------|
| `Main.cpp` | ~4650 | 主循环、所有地图渲染与切换、全局资源加载 |
| `SDL2_test.h` | ~150 | 全局宏定义、结构体声明（Player/Puzzle1/GameData 等） |
| `enter.h` | ~400 | 窗口初始化、存档读写、音频设备管理 |
| `BOSS1.cpp` / `BOSS.h` | ~2000 | Boss1（Wyvern）战斗逻辑、AI、动画 |
| `BOSS2.cpp` / `BOSS2.h` | ~3000 | Boss2（Dragon）战斗逻辑、108帧动画 |
| `Puzzle1.cpp` | ~1500 | 时间机日历谜题 UI 与交互 |
| `3.cpp` / `3.h` | ~1000 | 电路拆弹谜题（开关/电线/逻辑门） |
| `dialogue(1.cpp` | ~450 | 对话系统：逐字动画、点击跳过 |
| `Run Game.h` | ~1500 | 森林躲避小游戏 |
| `test2.cpp` / `test2.h` | ~800 | 图鉴/说明书 UI（图文翻页） |
| `log_in.cpp` | ~500 | 主菜单、存档槽选择界面 |
| `SDL2_test.cpp` | — | 程序入口（调用 Puzzle1.cpp 的 main） |

---

## 三、游戏完整流程（按 map 编号）

```
主菜单 log_in.cpp
  ↓ 选择存档槽（S/save1.dat ~ save3.dat）
map = 0   传送室（开场对话：Ellie × Prince，展示破败城市图片）
map = 1   实验室走廊（过渡，玩家自由移动）
map = 2   Puzzle1：时间机日历谜题
map = 3   飞机躲避战（Are You Tough Enough?）
           ↓ 通过后
map = 12  实验室顶部（探索，收集 3 块硬盘 disk_num）
map = 13  地下通道1      ↕ 通过门口 ENTER_MAP14_RIGHT/LEFT 等宏切换
map = 14  地下通道2
map = 15  地下通道3
map = 16  配电室
map = 17  深洞穴
map = 18  岔路口
map = 5   Boss1 战：Wyvern（战后选 Y=击杀 / N=拯救，写入 kill_Scientist）
map = 20  飞机跑道准备（对话）
map = 21  森林1（自由移动）
map = 22  森林2（自由移动）
map = 23  森林躲避游戏 run_forest_run()
map = 24  岩石洞穴（最后对话）
map = 25  Boss2 战：Dragon（最终Boss）
map = 26  Puzzle3：电路拆炸弹
  ↓
结局（取决于 kill_Scientist 与 boss1/boss2_result）
```

### 地图切换函数
```cpp
Map_Shift(int 目标map, int 玩家出生X, int 玩家出生Y);
// 带淡出淡入效果，然后设置 player.x / player.y 并切换 map
```

### 门口虚拟地图号（SDL2_test.h）
```cpp
#define ENTER_MAP14_RIGHT 141  // Map3 右门 → Map4
#define ENTER_MAP14_LEFT  142  // Map3 左门 → Map4
#define ENTER_MAP13_RIGHT 131  // Map4 右门 → Map3
#define ENTER_MAP13_LEFT  132  // Map4 左门 → Map3
```

---

## 四、关键全局变量

| 变量 | 类型 | 含义 |
|------|------|------|
| `map` | int | 当前运行的地图号 |
| `map_num` | int | 切换目标地图号（可含门口虚拟值） |
| `is_change` | int | 触发地图切换标志 |
| `presentstate` | int | 对话框状态（1=运行, 0=退出, 2=暂停） |
| `player` | Player | 玩家位置/速度/尺寸/碰撞半径 |
| `puzzle1` | Puzzle1 | 时间谜题状态 |
| `boss1_result` | int | Boss1结果（0=quit, 1=win, 3=lose） |
| `boss2_result` | int | Boss2结果（同上） |
| `parkour_result` | int | 森林跑酷结果（-1=lose, 1=win） |
| `kill_Scientist` | bool | 选择击杀(true)/拯救(false) Wyvern |
| `disk_num` | int | 已收集硬盘数，≥3 才能拿到 ID 卡 |
| `is_ID` | bool | 是否持有 ID 卡（开特定区域的门） |
| `lose_count` | int | 飞机躲避失败次数（影响难度） |

---

## 五、结构体定义（SDL2_test.h）

```cpp
typedef struct Player {
    int x, y;      // 中心坐标
    int v_x, v_y;  // 速度（默认 7 像素/帧）
    int w, h;      // 宽 42.5px，高 72.5px
    int r;         // 碰撞圆半径 = w/2
} Player;

typedef struct {
    int register_row, register_column; // 出发月/日
    int player_row, player_column;     // 当前目标月/日
    int round;         // 0=玩家回合, 1=幽灵回合
    int is_controlled; // 是否被幽灵控制过
    int result;        // 1=龙赢, 0=玩家赢, 10=未决
    int last_result;
    int is_dialogue;
} Puzzle1;

typedef struct {
    int playerplacex, playerplacey;
    int map;
    int disk;
    bool s2;       // kill_Scientist
    bool ID;       // is_ID
    int is_time_machine_dialogue;
    int boss1_result, boss2_result;
    int lose_count, parkour_result;
    // + 9 个对话完成标志（防重复触发）
} GameData;
```

---

## 六、对话系统

### 函数签名
```cpp
int present(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font,
            char* a,       // 第一行对白
            char* b,       // 第二行对白（可为空串）
            char* name,    // 角色名
            char* picture);// 角色头像路径（如 "Avatars/Prince.png"）
```

### 工作流程
1. 显示背景（半透明 Shifter 纹理 Alpha=150）
2. 渲染对话框区域 `{150, 400, 1100, 180}`
3. 显示角色头像
4. `word_appear()` 逐字渲染（`SDL_Delay(speed)` 控速）
5. **点击对话框任意位置**跳过（动画中跳到完整文字，完整后跳下一句）

### 角色列表
```cpp
char Name[8][10] = {"Ellie", "Prince", "Emma", "DC", "Wyvern", "Lamy", "Dragon", "???"};
```

### 防重复对话标志（enter.h / GameData）
```
enter_is_dialogue        // 开场对话
tough_enough_dialogue    // 飞机对话
dialogue_aFTEr_pLAne     // 飞机后
dialogue_Lamy            // Lamy 出现
rOCk_hOLe_dialogue       // 岩洞
dialogue_beFOre_Puzz3    // Puzzle3 前
map5_is_dialogue         // Map5
dialogue_Emma            // Emma
dialogue_Wyvern          // Wyvern
```
每个标志首次触发后设为 1，游戏存档中保存，避免重复播放。

---

## 七、碰撞系统

```cpp
// 圆形（玩家）
typedef struct Circle { int x, y, r, v_x, v_y; bool is_exist; } Circle;

// 矩形（障碍物）
typedef struct Object { int x, y, w, h; int l_u[2], r_u[2], l_d[2], r_d[2]; } Object;

// 碰撞检测
int Is_collide(Object object, int player_w, int player_h, int x, int y, int r);
int Collision_Detect(int x, int y, int r, int start, int end);
// start~end 是 Object 数组里要检测的障碍物编号范围
```

玩家移动：`WASD` → `SDL_GetKeyboardState` → `Player_move(start, end)`

---

## 八、谜题系统

### Puzzle1 — 时间机日历（map=2）
- **目标**：从 10月10日 前进到 12月31日
- **规则**：
  1. 同一轮只能前进，不能后退
  2. 只能"同月不同日" 或 "不同月同日"
  3. 不能原地不动
- **回合制**：`round=0` 玩家操作，`round=1` 时间幽灵操作
- **魔法日期提示**：月份数 + 19（1月→第20日，2月→第21日……）

### Puzzle3 — 电路拆炸弹（map=26）
- **组件类型**（3.h）：
  - `SWITCH`（红）：可无限次切换开/关
  - `WIRE`（绿）：传导电流，可一次性切断
  - `AND_GATE`（蓝）：两个输入都为真才输出
  - `OR_GATE`（黄）：任意一个输入为真即输出
- **目标**：3 个绿灯全亮，警告红灯不亮
- **交互**：鼠标点击 → `checkMouseClick(mouseX, mouseY)`

---

## 九、Boss 系统

### Boss1 — Wyvern（map=5）
- 玩家 HP / Boss HP 均为 100
- **攻击模式**：飞行生物波次×3、青蛙追踪弹跳、星型射弹
- 双方都有治疗器（HeAler）可拾取
- **战后选择**：按 Y 击杀 / 按 N 拯救（`kill_Scientist`），影响结局对话

### Boss2 — Dragon（map=25）
- 108 帧龙动画（`sURf_surfboss[108]`）
- **攻击模式**：
  - 箭形激光（高速聚焦）
  - 重型炸弹（3 块区域轰炸，`aTTaCk_aReA_oF_eXtRa_bIg_bOMbS[3]`）
  - 护盾（`txt_shIEld`，激活时无敌）

---

## 十、存档系统

```
保存路径：SDL2_test/S/save1.dat / save2.dat / save3.dat（二进制）
void saveGame(GameData data, int saveNum);
void loadGame(GameData* data, int saveNum);
```
保存内容：玩家位置、当前地图、硬盘数、ID卡状态、各对话标志、Boss结果等。

---

## 十一、资源目录

```
SDL2_test/assets/
├── Audio/         # bgm.flac, bar.mp3, Bingo.mp3, puzzle1.mp3, Plane.mp3 等
├── character/     # 玩家各方向动画帧（spr_mainchar*.png）、heart.png、dragon_heart.png
├── Font/          # Allan-Regular.ttf（游戏主字体）
├── Ingame/        # 地图背景(map_1.png~map_8.png)、各谜题图片、UI 元素
└── Menu/          # 主菜单相关图片
SDL2_test/Avatars/ # 角色头像（Prince.png, Ellie.png, Emma.png, DC.png, Wyvern.png, Dragon.png）
SDL2_test/dialogue/ # 对话框图片
SDL2_test/Files For BOSS1/ # Boss1 战斗资源
SDL2_test/Files For BOSS2/ # Boss2 战斗资源（箭、炸弹、龙动画等）
```

---

## 十二、增加新内容的建议方向

### 增加新地图/关卡
1. 在 `Main.cpp` 的 `LOAD()` 函数中添加新背景图加载
2. 在主循环 `switch(map)` 中添加新的 `case`
3. 在合适的位置调用 `Map_Shift(新map号, x, y)` 触发切换
4. 在 `GameData` 中添加新的状态标志并更新存档

### 增加新对话
1. 在 `Main.cpp` 顶部全局区声明对白字符串
2. 在 `GameData` 中添加完成标志（防重复）
3. 在合适的 `map` 分支里调用 `present(window, renderer, font, a, b, name, picture)`

### 增加新 Boss
1. 新建 `BOSS3.cpp` / `BOSS3.h`，参考 BOSS2 的结构
2. 在 `SDL2_test.vcxproj` 中添加该文件
3. 在 `Main.cpp` 的新 `case map=N` 里调用 Boss 函数

### 修改游戏难度
- 玩家速度：`Player_move` 中的 `v_x / v_y`（默认 7）
- 对话速度：`word_appear` 里的 `SDL_Delay(speed)`
- Boss HP：BOSS1.cpp / BOSS2.cpp 顶部的 HP 初始值

---

## 十三、已知问题（改进时注意）

| 问题 | 建议 |
|------|------|
| 多个分散 `SDL_PollEvent` 会互相抢事件 | 统一改为 `while(SDL_PollEvent)` |
| 全局变量约 50+ 个 | 新增状态尽量加到 `GameData` |
| 资源路径全部硬编码 | 新增资源时注意相对路径（以 exe 所在目录为根） |
| SDL 纹理/表面未释放 | 新增资源记得调用 `SDL_DestroyTexture` / `SDL_FreeSurface` |
| 命名混乱（`cHooSe_oF_bOSs1` 式） | 新增内容建议遵循统一的 snake_case 或 camelCase |
| 无暂停系统 | 可在主循环加 ESC 暂停逻辑 |
