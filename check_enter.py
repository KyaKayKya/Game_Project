import re

data = open(r'E:\Game_Project-main\SDL2_test\enter.h', 'rb').read()
text = data.decode('gbk', errors='replace')
lines = text.split('\n')
depth = 0
bad = []
for i, l in enumerate(lines):
    ci = l.find('//')
    check = l[:ci] if ci >= 0 else l
    check = re.sub(r'"[^"]*"', '""', check)
    for c in check:
        if c == '{':
            depth += 1
            bad.append(i+1)
        elif c == '}':
            depth -= 1
            if bad:
                bad.pop()
print('enter.h final depth:', depth)
if depth != 0:
    print('Unclosed at lines:', bad[-10:])
else:
    print('Balanced!')
print('Total lines:', len(lines))
