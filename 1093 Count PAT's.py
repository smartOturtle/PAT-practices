s = input()
t_size = sum(1 for c in s if c == 'T')
p_size = 0
cnt = 0
for c in s:
    if c == 'P':
        p_size += 1
    elif c == 'A':
        cnt += p_size * t_size
    else:
        t_size -= 1
print(cnt % 1000000007)
