with open('SDL2_test/enter.h', encoding='utf-8', errors='replace') as f:
    src = f.read()

depth = 0
in_str = False
in_char = False
in_line_comment = False
in_block_comment = False
line = 1
issues = []
i = 0
while i < len(src):
    c = src[i]
    if c == '\n':
        line += 1
        in_line_comment = False
    elif in_line_comment:
        pass
    elif in_block_comment:
        if c == '*' and i+1 < len(src) and src[i+1] == '/':
            in_block_comment = False
            i += 1
    elif in_str:
        if c == '\\':
            i += 1
        elif c == '"':
            in_str = False
    elif in_char:
        if c == '\\':
            i += 1
        elif c == "'":
            in_char = False
    else:
        if c == '/' and i+1 < len(src) and src[i+1] == '/':
            in_line_comment = True
        elif c == '/' and i+1 < len(src) and src[i+1] == '*':
            in_block_comment = True
        elif c == '"':
            in_str = True
        elif c == "'":
            in_char = True
        elif c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth < 0:
                issues.append((line, 'extra }'))
                depth = 0
    i += 1

print(f'Final depth: {depth}, last line: {line}')
if issues:
    print('Extra closes:', issues[:5])
if depth > 0:
    print(f'WARNING: {depth} unclosed braces at EOF')
