from math import *

pronounce = {k: v for k, v in zip(range(10), 'ling yi er san si wu liu qi ba jiu'.split())}
pronounce.update(
    [(10, 'Shi'), (100, 'Bai'), (1000, 'Qian'), (10 ** 5, 'Shi'), (10 ** 6, 'Bai'), (10 ** 7, 'Qian'), (10 ** 8, 'Yi')])
s = []
n = int(input())
if n < 0:
    print('Fu', end=' ')
    n = abs(n)
need_set_wan = n % 10 ** 8 // 10 ** 4 > 0
while n:
    d = int(log10(n))
    s.append(pronounce[n // 10 ** d])
    if d == 0:
        break
    if 10 ** d in pronounce:
        s.append(pronounce[10 ** d])
    n %= 10 ** d
    if n < 10000 and need_set_wan:
        s.append('Wan')
        need_set_wan = False
    if 0 < n < 10 ** (d - 1):
        s.append(pronounce[0])
print(*(s if s else ['ling']))
