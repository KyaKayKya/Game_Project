import os; os.chdir('e:/Game_Project-main')
with open('SDL2_test/enter.h', 'rb') as f:
    data = f.read()

lines = data.split(b'\n')
print('Checking for GBK second-byte = 0x5C (backslash) that could cause line continuation...')
for lineno, line in enumerate(lines, 1):
    i = 0
    while i < len(line):
        b = line[i]
        if b >= 0x81 and i + 1 < len(line):
            b2 = line[i+1]
            if b2 == 0x5C:  # backslash
                print(f'Line {lineno} pos {i}: GBK lead 0x{b:02x} + backslash 0x5C')
                print(f'  Line content: {repr(line[:60])}')
            if b2 >= 0x40 and b2 <= 0x7E:  # valid GBK second byte range
                i += 2
                continue
        i += 1

print('\nChecking for UTF-8 line-ending that might cause line continuation...')
for lineno, line in enumerate(lines, 1):
    if line and line[-1] >= 0x80:
        print(f'Line {lineno} ends with high byte 0x{line[-1]:02x}: {repr(line[-10:])}')
    if line and line[-1] == 0x5C:
        print(f'Line {lineno} ends with backslash: {repr(line[-10:])}')

print('Done.')
