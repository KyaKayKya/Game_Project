with open('SDL2_test/enter.h', 'rb') as f:
    content = f.read().decode('utf-8', errors='replace')

lines = content.split('\n')
depth = 0
in_ml_comment = False
in_string = False
in_char = False
LIMIT = 167

for lineno, line in enumerate(lines[:LIMIT], 1):
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
                if depth > 0:
                    safe = line.strip()[:60].encode('ascii', errors='replace').decode('ascii')
                    print(f'  OPEN  depth={depth} line {lineno}: {safe}')
            elif c == '}':
                depth -= 1
        j += 1

print(f'\nDepth at end of line {LIMIT}: {depth}')
# Also show last 5 open that haven't closed
