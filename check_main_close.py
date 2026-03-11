import re

data = open(r'E:\Game_Project-main\SDL2_test\Main.cpp', 'rb').read()
# Split by literal newline bytes
lines = data.split(b'\n')

depth = 0
opens_stack = []  # (line_num, char_pos)

# Process each line starting from main() at line 561 (index 560)
main_start = 560  # 0-indexed line 560 = line 561 (1-indexed)

for i in range(main_start, min(len(lines), main_start + 920)):
    try:
        l = lines[i].decode('gbk', errors='ignore')
    except:
        l = lines[i].decode('latin-1', errors='ignore')
    
    # Remove line comments
    ci = l.find('//')
    if ci >= 0:
        l = l[:ci]
    
    # Remove string literals  
    result = ''
    in_str = False
    escape = False
    for c in l:
        if escape:
            escape = False
            if in_str:
                continue
        if c == '\\' and in_str:
            escape = True
            continue
        if c == '"' and not in_str:
            in_str = True
        elif c == '"' and in_str:
            in_str = False
        elif not in_str:
            result += c
    
    for c in result:
        if c == '{':
            depth += 1
            opens_stack.append(i + 1)
        elif c == '}':
            depth -= 1
            if opens_stack:
                opens_stack.pop()
    
    if depth == 0 and i > main_start:
        print(f'main() closes at line {i + 1}')
        break
    
    # Print depth when at depth 1 (we should be here when main hasn't ended)
    if depth == 0 and i > main_start:
        break

print(f'Final depth: {depth}')
if opens_stack:
    print(f'Unclosed opens at lines: {opens_stack[-10:]}')
print(f'Checked up to line {i + 1}')
