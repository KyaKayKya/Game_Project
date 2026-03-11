import re

files = ['BOSS.h', 'Run Game.h', 'BOSS2.h', 'test2.h', '3.h', 'SDL2_test.h']
for fname in files:
    path = r'E:\Game_Project-main\SDL2_test\\' + fname
    try:
        data = open(path, 'rb').read()
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
        if depth != 0:
            print(fname, 'depth=%d' % depth, 'unclosed at:', bad[-5:])
        else:
            print(fname, 'OK')
    except Exception as e:
        print(fname, 'ERROR:', e)
