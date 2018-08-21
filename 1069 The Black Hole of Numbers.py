num = '{:0>4}'.format(input())
while True:
    ascend = ''.join(sorted(num))
    descend = ''.join(reversed(ascend))
    num = '{:04d}'.format(int(descend) - int(ascend))
    print(descend, '-', ascend, '=', num)
    if num == '0000' or num == '6174':
        break
