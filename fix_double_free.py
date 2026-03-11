"""
Remove duplicate SDL_FreeSurface calls that are now redundant.
After fix_surfaces.py ran, each surface is freed right after CreateTextureFromSurface.
Old FreeSurface calls in cleanup sections are now double-frees and must be removed.
"""
import re

files = [
    'SDL2_test/dialogue(1.cpp',
    'SDL2_test/Puzzle1.cpp',
    'SDL2_test/Main.cpp',
    'SDL2_test/BOSS1.cpp',
    'SDL2_test/BOSS2.cpp',
]

for filepath in files:
    with open(filepath, 'rb') as f:
        data = f.read()
    crlf = b'\r\n' in data
    eol = b'\r\n' if crlf else b'\n'
    raw_lines = data.split(eol)
    
    # Find surfaces that are already freed right after CreateTextureFromSurface
    already_freed = set()
    for i, line in enumerate(raw_lines):
        m = re.search(rb'SDL_CreateTextureFromSurface\s*\(\s*\w+\s*,\s*(\w+)\s*\)', line)
        if m:
            surf = m.group(1)
            # Check if next line is SDL_FreeSurface(surf)
            if i + 1 < len(raw_lines):
                next_l = raw_lines[i + 1].strip()
                free_call = b'SDL_FreeSurface(' + surf + b');'
                if next_l == free_call:
                    already_freed.add((i + 1, surf))  # line index of the inserted FreeSurface

    # Now remove subsequent FreeSurface calls for those same surface names
    # A surface name is "already freed" if it appears in already_freed set
    freed_names = set(s for _, s in already_freed)
    freed_line_indices = set(i for i, _ in already_freed)

    result = []
    removed = 0
    for i, line in enumerate(raw_lines):
        if i in freed_line_indices:
            # This is the inserted line (right after CreateTex) - keep it
            result.append(line)
            continue
        # Check if this is a redundant FreeSurface call
        is_redundant = False
        for surf in freed_names:
            free_call = b'SDL_FreeSurface(' + surf + b');'
            if line.strip() == free_call:
                is_redundant = True
                break
        if is_redundant:
            removed += 1
            # Skip it (don't append to result)
        else:
            result.append(line)

    out = eol.join(result)
    with open(filepath, 'wb') as f:
        f.write(out)
    fname = filepath.split('/')[-1]
    print('%s: removed %d duplicate SDL_FreeSurface calls' % (fname, removed))
