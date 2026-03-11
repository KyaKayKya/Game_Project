import re

fname = 'SDL2_test.h'
path = r'E:\Game_Project-main\SDL2_test\SDL2_test.h'
data = open(path, 'rb').read()
text = data.decode('gbk', errors='replace')
lines = text.split('\n')
depth = 0
bad = []
for i, l in enumerate(lines):
    ci = l.find('//')
    check = l[:ci] if ci >= 0 else l
    # Remove string literals to avoid counting { in strings
    result = ''
    in_str = False
    for c in check:
        if not in_str:
            if c == '"':
                in_str = True
            else:
                result += c
        else:
            if c == '"':
                in_str = False
    # count braces in result
    for c in result:
        if c == '{':
            depth += 1
            bad.append(i+1)
        elif c == '}':
            depth -= 1
            if bad:
                bad.pop()
if depth != 0:
    print(fname, 'depth=%d' % depth, 'unclosed at:', bad[-10:])
else:
    print(fname, 'OK')
print('Total lines:', len(lines))
