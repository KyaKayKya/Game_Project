content = open('SDL2_test/enter.h', encoding='utf-8', errors='replace').read()
start2 = content.find('static int mainMenu()')
i = start2
while content[i] != '{': i += 1
func_start = i
d = 0
in_str = False
in_lcom = False
in_bcom = False
i = func_start
end2 = -1
while i < len(content):
    c = content[i]
    if c == '\n':
        in_lcom = False
    elif in_lcom:
        pass
    elif in_bcom:
        if c == '*' and i+1 < len(content) and content[i+1] == '/':
            in_bcom = False
            i += 1
    elif in_str:
        if c == '\\':
            i += 1
        elif c == '"':
            in_str = False
    else:
        if c == '/' and i+1 < len(content) and content[i+1] == '/':
            in_lcom = True
        elif c == '/' and i+1 < len(content) and content[i+1] == '*':
            in_bcom = True
        elif c == '"':
            in_str = True
        elif c == '{':
            d += 1
        elif c == '}':
            d -= 1
            if d == 0:
                end2 = i
                break
    i += 1

ls = content[:func_start].count('\n') + 1
if end2 >= 0:
    le = content[:end2].count('\n') + 1
    print(f'mainMenu proper: lines {ls}-{le}')
    after = content[end2:end2+120]
    print(repr(after))
else:
    print('mainMenu NOT CLOSED, depth at EOF:', d)
