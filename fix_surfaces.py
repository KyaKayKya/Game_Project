"""
Fix use-after-free: move SDL_FreeSurface(X) to after the last use of X->w or X->h.
The fix_surfaces.py script inserted FreeSurface right after CreateTextureFromSurface,
but sometimes the surface dimensions are still needed for rect calculations.
"""
import re

files = [
    'SDL2_test/Main.cpp',
    'SDL2_test/Puzzle1.cpp',
]

for filepath in files:
    with open(filepath, 'rb') as f:
        data = f.read()
    crlf = b'\r\n' in data
    eol = b'\r\n' if crlf else b'\n'
    lines = list(data.split(eol))

    fixes = 0
    i = 0
    while i < len(lines):
        line = lines[i]
        # Find: SDL_FreeSurface(X) where X is still used in next lines
        m = re.search(rb'^\s*SDL_FreeSurface\((\w+)\)\s*;', line)
        if m:
            surf = m.group(1)
            # Look ahead up to 20 lines for last use of surf->w or surf->h
            last_use = -1
            for j in range(i + 1, min(len(lines), i + 20)):
                if surf + b'->w' in lines[j] or surf + b'->h' in lines[j]:
                    last_use = j
                elif b'SDL_FreeSurface' in lines[j] or b'SDL_CreateTextureFromSurface' in lines[j]:
                    # stop scanning if we hit another create/free
                    break
            if last_use > i:
                # Move SDL_FreeSurface line from i to after last_use
                free_line = lines.pop(i)
                # After pop, last_use index shifted by -1
                lines.insert(last_use, free_line)
                fixes += 1
                # Don't increment i - check the same position again
                continue
        i += 1

    out = eol.join(lines)
    with open(filepath, 'wb') as f:
        f.write(out)
    fname = filepath.split('/')[-1]
    print('%s: moved %d SDL_FreeSurface calls to after last dimension use' % (fname, fixes))
