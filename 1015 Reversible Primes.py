from math import *


def is_prime(n):
    if n == 2:
        return True
    if n == 1 or n % 2 == 0:
        return False
    for i in range(3, ceil(sqrt(n)+1), 2):
        if n % i == 0:
            return False
    return True


def reverse_in_radix(n, radix):
    a = []
    while n:
        n, m = divmod(n, radix)
        a.append(str(m))
    return int(''.join(a), radix)


get = [int(i) for i in input().split()]
while get[0] >= 0:
    if is_prime(get[0]) and is_prime(reverse_in_radix(get[0], get[1])):
        print('Yes')
    else:
        print('No')
    get = [int(i) for i in input().split()]
