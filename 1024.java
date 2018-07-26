num, max_step = map(int, input().split())
for i in range(max_step):
    num_str = str(num)
    if all(p[0] == p[1] for p in zip(num_str, reversed(num_str))):
        print(num, i, sep='\n')
        break
    num += int(num_str[::-1])
else:
    print(num, max_step, sep='\n')
