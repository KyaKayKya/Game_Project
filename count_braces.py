import os; os.chdir('e:/Game_Project-main')
with open('SDL2_test/enter.h', 'rb') as f:
    data = f.read()
opens = data.count(b'{')
closes = data.count(b'}')
print('Raw open brace count:', opens)
print('Raw close brace count:', closes)
print('Difference:', opens - closes)
