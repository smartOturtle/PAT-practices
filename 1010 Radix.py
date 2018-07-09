import string
from functools import *

convert = {str(i): i for i in range(10)}
convert.update(i for i in zip(string.ascii_lowercase, range(10, 50)))
first_num, second_num, tag, radix = [i for i in input().split(' ')]
radix = int(radix)
if tag != '1':
    first_num, second_num = second_num, first_num
decimal_value = reduce(lambda a, b: a * radix + b, (convert[i] for i in first_num))
min_radix = max(convert[i] for i in second_num) + 1
max_radix = decimal_value + 1
while min_radix <= max_radix:
    middle = (min_radix + max_radix) // 2
    value = reduce(lambda a, b: a * middle + b, (convert[i] for i in second_num))
    if value == decimal_value:
        print(middle)
        break
    if value < decimal_value:
        min_radix = middle + 1
    else:
        max_radix = middle - 1
else:
    print('Impossible')
