from math import *


def is_prime(n: int):
    if n == 2:
        return True
    if n == 1 or n % 2 == 0:
        return False
    for i in range(3, int(sqrt(n) + 1), 2):
        if n % i == 0:
            return False
    return True


def next_prime(n: int):
    while not is_prime(n):
        n += 1
    return n


table_size, _ = map(int, input().split())
table = [-1 for i in range(next_prime(table_size))]


def insert(n: int):
    for i in range(len(table) + 1):
        test_pos = (n + i * i) % len(table)
        if table[test_pos] == -1:
            table[test_pos] = n
            return test_pos
    return '-'


print(*map(lambda n: insert(int(n)), input().split()))
