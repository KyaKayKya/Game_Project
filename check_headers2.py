import os
os.chdir('e:/Game_Project-main')
files = ['SDL2_test/BOSS.h', 'SDL2_test/parkour.h', 'SDL2_test/BOSS2.h', 'SDL2_test/SDL2_test.h']
for fname in files:
    with open(fname, 'rb') as f:
        content = f.read().decode('utf-8', errors='replace')
    depth = 0
    in_ml_comment = False
    in_string = False
    in_char = False
    lines = content.split('\n')
    for line in lines:
        j = 0
        while j < len(line):
            c = line[j]
            if in_ml_comment:
                if c == '*' and j+1 < len(line) and line[j+1] == '/':
                    in_ml_comment = False
                    j += 1
            elif in_string:
                if c == '\\':
                    j += 1
                elif c == '"':
                    in_string = False
            elif in_char:
                if c == '\\':
                    j += 1
                elif c == "'":
                    in_char = False
            else:
                if c == '/' and j+1 < len(line) and line[j+1] == '*':
                    in_ml_comment = True
                    j += 1
                elif c == '/' and j+1 < len(line) and line[j+1] == '/':
                    break
                elif c == '"':
                    in_string = True
                elif c == "'":
                    in_char = True
                elif c == '{':
                    depth += 1
                elif c == '}':
                    depth -= 1
            j += 1
    print(fname, 'final depth:', depth)
