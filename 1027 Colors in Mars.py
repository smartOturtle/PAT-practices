colors = [i for i in input().split()]
to_char = {i: str(i) for i in range(10)}
to_char.update({10: 'A', 11: 'B', 12: 'C'})
for i, color in enumerate(colors):  # str and int are value semantic, for loop only product a copy of the init
    num = int(color)                # using the index is the only way to substitute it 
    s = []
    while num:
        num, m = divmod(num, 13)
        s.append(to_char[m])
    if s:
        colors[i] = ''.join(c for c in reversed(s))
print('#', *('{:0>2}'.format(i) for i in colors), sep='')
