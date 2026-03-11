import os

base = 'SDL2_test/'
renames = {
    '3.h': 'puzzle3.h',
    'test2.h': 'pause_menu.h',
    'Run Game.h': 'parkour.h',
}

for fname in os.listdir(base):
    if not (fname.endswith('.cpp') or fname.endswith('.h')):
        continue
    fpath = base + fname
    raw = open(fpath, 'rb').read()
    text = raw.decode('gbk', errors='replace')
    new_text = text
    for old, new in renames.items():
        new_text = new_text.replace('#include "' + old + '"', '#include "' + new + '"')
    if new_text != text:
        print('Updated: ' + fname)
        open(fpath, 'wb').write(new_text.encode('gbk', errors='replace'))

print('done')
