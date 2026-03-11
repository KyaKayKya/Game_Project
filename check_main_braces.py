data = open(r'E:\Game_Project-main\SDL2_test\Main.cpp', 'rb').read()
text = data.decode('gbk', errors='replace')
lines = text.split('\n')

for i in range(560):
    l = lines[i]
    if 'char ' in l and '{' in l and '"' in l:
        depth = 0
        in_str = False
        for c in l:
            if not in_str:
                if c == '"':
                    in_str = True
                elif c == '{':
                    depth += 1
                elif c == '}':
                    depth -= 1
            else:
                if c == '"':
                    in_str = False
        if depth != 0:
            print(i+1, 'NET BRACES:', depth, repr(l[:100]))

print('Done checking')
