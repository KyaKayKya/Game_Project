# 代码结构分析 & 重构指南

> 本文档面向开发者，梳理当前代码的结构问题与优化路径。

---

## 一、当前编译单元（实际参与编译的文件）

```
SDL2_test.vcxproj 中 ClCompile 的文件：
  Main.cpp          ← 主循环 + 所有地图逻辑
  BOSS1.cpp         ← Boss1 战斗
  BOSS2.cpp         ← Boss2 战斗
  3.cpp             ← Puzzle3 电路谜题
  Run Game.cpp      ← 跑酷小游戏
  test2.cpp         ← 暂停菜单 / 图片幻灯片
  dialogue(1.cpp    ← 对话框渲染工具函数

未参与编译（遗留文件）：
  Puzzle1.cpp       ← 旧版独立原型，与 Main.cpp 大量重复，可安全删除
  SDL2_test.cpp     ← 全部注释掉的早期代码，可安全删除
  log_in.cpp        ← textFadeInOut_1 的实现，但此函数已被 enter.h 中同名版本覆盖
```

---

## 二、全局变量重复定义（最高优先级修复）

以下变量在 `Main.cpp` 和 `Puzzle1.cpp` 中均有定义，由于 `Puzzle1.cpp` 不参与编译暂无冲突，但一旦加入编译就会报链接错误：

| 变量 | Main.cpp | Puzzle1.cpp |
|---|---|---|
| `SDL_Window* Puzzle1_Window` | ✅ 定义 | ❌ 重复定义 |
| `SDL_Renderer* Puzzle1_Renderer` | ✅ 定义 | ❌ 重复定义 |
| `Player player` | ✅ 定义 | ❌ 重复定义 |
| `Object object[]` | `[100]` | `[10]` ← 大小还不同 |
| `Circle Bullet[]` | ✅ 定义 | ❌ 重复定义 |
| `int map` | 初值 `0` | 初值 `10` ← 初值还不同 |
| `SDL_Color FontColor` | ✅ 定义 | ❌ 重复定义 |
| `const int Bullet_num` | `60` | `60` |
| `Mix_Music* SoundBackGround` 等 | ✅ 定义 | ❌ 重复定义 |

**建议**：直接删除 `Puzzle1.cpp` 和 `SDL2_test.cpp`。

---

## 三、头文件包含函数实现（链接陷阱）

`enter.h` **不是普通头文件**，它包含完整的函数实现体和全局变量定义：

```
enter.h 中包含的实体（非声明）：
  SDL_Surface* surf = NULL;          ← 变量定义
  TTF_Font* font = NULL;             ← 变量定义
  SDL_Texture* imageTexture = NULL;  ← 变量定义
  Uint8* audio_buf_1; 等音频变量      ← 变量定义
  GameData gameData;                 ← 变量定义
  void loadGame(...)  { ... }        ← 函数实现
  void saveGame(...)  { ... }        ← 函数实现
  void callback_1(...)  { ... }      ← 函数实现
  void init_audio_1() { ... }        ← 函数实现
  int textFadeInOut(...) { ... }     ← 函数实现
  int Load_IN() { ... }              ← 函数实现
```

> ⚠️ 如果 `enter.h` 被多个 `.cpp` include，**必然产生重复符号链接错误**。目前只有 `Main.cpp` include 它，所以暂时没问题。

**建议**：将 `enter.h` 拆分为：
- `save_system.h`：只放 `GameData` 结构体声明 + 函数声明
- `save_system.cpp`：放所有函数实现和变量定义

---

## 四、全局宏别名混乱

各模块用不同的宏别名指向同一个 `Puzzle1_Window` / `Puzzle1_Renderer`：

| 文件 | 宏别名 |
|---|---|
| `BOSS.h` | `#define win Puzzle1_Window` / `#define rdr1 Puzzle1_Renderer` |
| `BOSS2.h` | `#define win Puzzle1_Window` / `#define rdr1 Puzzle1_Renderer` |
| `enter.h` | `#define win Puzzle1_Window` / `#define rdr Puzzle1_Renderer` |
| `Run Game.h` | `#define window Puzzle1_Window` / `#define renderer Puzzle1_Renderer` |
| `test2.h` | `#define window Puzzle1_Window` / `#define renderer Puzzle1_Renderer` |
| `3.h` | `#define window Puzzle1_Window` / `#define renderer Puzzle1_Renderer` |

同一个渲染器，五个不同名字（`rdr`、`rdr1`、`renderer`、`Puzzle1_Renderer`）。

**建议**：统一名称后删除所有别名宏，各文件直接用 `extern SDL_Window* Puzzle1_Window`。

---

## 五、函数重复 / 签名冲突

### `textFadeInOut` — 三个版本
| 位置 | 说明 |
|---|---|
| `log_in.cpp` | `textFadeInOut_1()` — 简单淡入淡出，点击任意位置退出 |
| `log_in.cpp` 顶部 | `#define textFadeInOut(...) textFadeInOut_1(...)` — 宏转发 |
| `enter.h` | 完整实现，包含背景图叠加，按 Enter 退出 |

两个实现行为不同，`enter.h` 版本才是实际使用的。`log_in.cpp` 的版本和宏已被覆盖，可以删除整个 `log_in.cpp`。

### `show_instruction` — 两个不兼容签名
| 位置 | 参数 |
|---|---|
| `dialogue(1.cpp` | `(renderer, book1, book2, next, before, yes)` — 6 个参数，显示两页图片 |
| `test2.cpp` | `(renderer, next, before, yes)` — 4 个参数，简化版 |

同名但参数数量不同，调用方必须明确用哪个版本，建议重命名区分。

### `TestText` vs `TestText_2`
| 位置 | 说明 |
|---|---|
| `BOSS.h` | 声明 `void TestText(int)` |
| `BOSS1.cpp` | 实现 `void TestText(int)` |
| `BOSS2.h` | 原声明 `void TestText(int)` ← **已修复为 `TestText_2`** |
| `BOSS2.cpp` | 实现 `void TestText_2(int)` |

---

## 六、未持久化的对话标志（存读档丢失）

以下对话标志控制「是否已看过该段对话」，但 **未被保存到 `GameData`**，读档后会重新触发：

| 变量 | 触发时机 |
|---|---|
| `map5_is_dialogue` | 进入 Map5（地图2区域）时的 DC 介绍对话 ← **已修复** |
| `dialogue_Emma` | Map1 中遇到 Emma 的对话 ← **已修复** |
| `dialogue_Wyvern` | Map8 进入 Boss 前走廊时遇到 Wyvern 的对话 ← **已修复** |
| `dialogue_beFOre_Puzz3` | Map26 拆弹前的说明对话 ← **已修复** |
| `enter_is_dialogue` | 游戏开场对话 ← **已修复** |
| `tough_enough_dialogue` | 飞机战前对话 ← **已修复** |
| `dialogue_aFTEr_pLAne` | 飞机战后对话 ← **已修复** |
| `rOCk_hOLe_dialogue` | 岩洞入口对话 ← **已修复** |
| `dialogue_Lamy` | 遇到 Lamy 的对话 ← **已修复** |

**全部对话标志已加入 `GameData` 并在 `save()`/`load` 中同步。**

---

## 七、地图 ID 魔法数字

主循环 `map == 13` 分支中有 `map_num = 141`、`map_num = 142`：

```cpp
// Main.cpp — Map_3() / Map_4() 分支  ← 已用常量替换
if (map_num == ENTER_MAP14_RIGHT) { Map_Shift(14, 723, 491); }
else if (map_num == ENTER_MAP14_LEFT) { Map_Shift(14, 134, 487); }
else if (map_num == ENTER_MAP13_RIGHT) { Map_Shift(13, 1076, 110); }
else if (map_num == ENTER_MAP13_LEFT)  { Map_Shift(13, 484, 118);  }
```

`141`/`142` 表示「去 Map14 但从不同入口进入」，混用了 Map ID 和入口编码。

**✅ 已修复**：已在 `SDL2_test.h` 中添加 `ENTER_MAP14_RIGHT/LEFT`、`ENTER_MAP13_RIGHT/LEFT` 常量，并在 `Map_3()`、`Map_4()` 函数和主循环中统一替换。

---

## 八、`bool running` 的作用域问题

```cpp
// Main.cpp 全局作用域
bool running = true;  // 第 560 行，在 main() 外部
```

`running` 被定义在全局作用域，而 `Are_You_Tough_Man()`、Boss 分支等函数中都可以直接写 `running = false` 来结束主循环。这是全局控制流，难以追踪。

**建议**：将 `running` 移入 `main()` 内，通过返回值或全局 `is_quit` 标志统一退出。

---

## 九、存档路径缺陷

```cpp
// enter.h
#define SAVE_FILE "S/gamesave.dat"
// 实际路径: S/gamesave.dat1.dat / S/gamesave.dat2.dat / S/gamesave.dat3.dat
```

- 目录 `S/` 不存在时 `fopen` 会静默失败，游戏无任何报错提示
- 文件名后缀为 `.dat1.dat`，是 `SAVE_FILE` 字符串拼接数字再拼 `.dat` 形成的

**✅ 已修复**：
1. 在 `saveGame()` 中添加 `_mkdir("S")` 确保目录存在（需 `<direct.h>`）
2. `SAVE_FILE` 改为 `"S/save"`，文件名变为 `S/save1.dat`（原为 `S/gamesave.dat1.dat`）

> ⚠️ 注意：旧存档文件名已变更，旧存档无法自动读取，需手动重命名。

---

## 十、推荐重构优先级

| 优先级 | 项目 | 影响 | 状态 |
|---|---|---|---|
| 🔴 高 | 删除 `Puzzle1.cpp` 和 `SDL2_test.cpp` | 消除潜在链接冲突 | ⏸ 暂缓（文件已排除编译，未删除）|
| 🔴 高 | 将剩余 3 个对话标志加入 `GameData` | 读档体验 | ✅ 已完成 |
| 🟡 中 | 将 `enter.h` 拆分为 `.h` + `.cpp` | 防止未来链接错误 | ⏸ 暂缓（当前只有 Main.cpp 包含 enter.h，无冲突风险）|
| 🟡 中 | 统一渲染器/窗口变量名，删除别名宏 | 可读性 | ⏸ 暂缓（涉及 BOSS 文件数百处替换，风险较高）|
| 🟡 中 | `bool running` 移入 `main()` 作用域 | 控制流清晰 | ⏸ 暂缓（需修改多个函数签名）|
| 🟢 低 | 地图入口魔法数字改为常量 | 可维护性 | ✅ 已完成 |
| 🟢 低 | 存档目录自动创建 + 文件名优化 | 健壮性 | ✅ 已完成 |
| 🟢 低 | 重命名 `show_instruction` 区分两个版本 | 防止混用 | ⏸ 暂缓（两个版本分属不同 TU，当前无实际冲突）|
