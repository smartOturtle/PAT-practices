value, radix = map(int, input().split())
num = []
while value:
    value, m = divmod(value, radix)
    num.append(m)
if all(map(lambda pair: pair[0] == pair[1], zip(num[:len(num) // 2], reversed(num)))):
    print('Yes')
else:
    print('No')
print(*reversed(num) if num else [0])
