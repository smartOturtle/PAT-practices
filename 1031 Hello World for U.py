import math

s = input()
n = len(s)
n2 = max([3, math.ceil((n + 2) / 3)])
if (n - n2) % 2:
    n2 += 1
n1 = (n - n2) // 2
for i in range(n1):
    print(s[i] + ' ' * (n2 - 2) + s[-1 - i])
print(s[n1:n1 + n2])
