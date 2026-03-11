import os; os.chdir('e:/Game_Project-main')
with open('SDL2_test/enter.h', 'rb') as f:
    lines = f.read().split(b'\n')
for i, line in enumerate(lines, 1):
    if b'loadTexture' in line and b'SDL_Texture' in line and b'const char' in line:
        print('Line', i, ':', line.decode('ascii', errors='replace')[:60])
    if b'void renderTextOneByOne' in line:
        print('Line', i, ':', line.decode('ascii', errors='replace')[:60])
    if b'void closeSDL' in line:
        print('Line', i, ':', line.decode('ascii', errors='replace')[:60])
