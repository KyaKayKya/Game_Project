// 定义存档文件名
#define SAVE_FILE "F:\\gamesave.dat"

// 游戏数据结构，这里只是一个示例
typedef struct {
    int playerHealth;//生命
    int map;//第几张的地图
    int scientist2;//科学家二死或没死
    int playerequipments_1;//玩家装备1
    int playerequipments_2;//玩家装备2
    int playerequipments_3;//玩家装备3
    int playerequipments_4;//玩家装备4
    int map_x;//地图位置x
    int map_y;//地图位置y


    // 其他需要保存的游戏数据
} GameData;

// 保存游戏数据到文件
// 保存游戏数据到文件
void saveGame(GameData data) {
    FILE *file = fopen(SAVE_FILE, "wb"); // 使用二进制模式打开文件
    if (file) {
        fwrite(&data, sizeof(GameData), 1, file);
        fclose(file);
        printf("游戏存档成功\n");
    } else {
        printf("无法保存游戏存档\n");
    }
}

// 从文件加载游戏数据
GameData loadGame() {
    GameData data;
    FILE *file = fopen(SAVE_FILE, "rb");
    if (file) {
        fread(&data, sizeof(GameData), 1, file);
        fclose(file);
        printf("游戏存档加载成功\n");
    } else {
        printf("无法加载游戏存档\n");
    }
    return data;
}
..........
int main(int argc, char *argv[]){
    // 初始化SDL
..........
    // 创建游戏窗口
..........
    // 创建渲染器
..........
    // 游戏数据
    GameData gameData;

    // 标记是否需要加载存档
    bool loadSave = false;

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)){
      if (event.type == SDL_KEYDOWN) {
                // 按下S键保存存档
                if (event.key.keysym.sym == SDLK_s) {
                    saveGame(gameData);
                }
                // 按下L键加载存档
                if (event.key.keysym.sym == SDLK_l) {
                    loadSave = true;
                }
          ..........
      }
        ..........
    }
..............
  // 如果需要加载存档，则加载存档并重置标记
        if (loadSave) {
            gameData = loadGame();
            loadSave = false;
        }
    }
}
