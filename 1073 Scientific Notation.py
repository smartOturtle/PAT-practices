num = input()
if num[0] == '-':
    print('-', end='')
num, _, exp = num.partition('E')
num = ''.join(c for c in num if str.isdigit(c))
exp = int(exp)
if exp < 0:
    print('0.' + ('0' * abs(exp + 1)) + num)
else:
    if len(num) <= exp + 1:
        print(num + ('0' * (exp + 1 - len(num))))
    else:
        print(num[:exp + 1], num[exp + 1:], sep='.')
