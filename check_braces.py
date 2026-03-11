import re

data = open(r'SDL2_test\Main.cpp', 'rb').read()
text = data.decode('gbk', errors='replace')
lines = text.split('\n')

depth = 0
bad_opens = []
for i in range(min(560, len(lines))):
    l = lines[i]
    # Remove line comments
    ci = l.find('//')
    if ci >= 0:
        l = l[:ci]
    # Remove string literals (simple, no escaped quotes)
    l = re.sub(r'"[^"]*"', '""', l)
    for c in l:
        if c == '{':
            depth += 1
            bad_opens.append(i+1)
        elif c == '}':
            depth -= 1
            if bad_opens:
                bad_opens.pop()

print('Depth at line 560 (before main):', depth)
if depth != 0:
    print('Unbalanced! Unclosed at lines:', bad_opens[-10:])
else:
    print('Balanced - braces are fine before main()')
