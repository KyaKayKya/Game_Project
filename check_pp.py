import os; os.chdir('e:/Game_Project-main')
with open('SDL2_test/enter.h', 'rb') as f:
    data = f.read()
lines = data.split(b'\n')
print('Preprocessor directives:')
for i, line in enumerate(lines, 1):
    stripped = line.strip()
    if stripped.startswith(b'#'):
        safe = stripped[:70].decode('ascii', errors='replace')
        print(f'  Line {i}: {safe}')
