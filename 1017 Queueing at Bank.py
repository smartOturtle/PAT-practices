from functools import reduce
from heapq import *

customer_size, window_size = [int(i) for i in input().split()]
customers = []
for i in range(customer_size):
    customer = input().split()
    customer[0] = reduce(lambda a, b: a * 60 + int(b), customer[0].split(':'), 0)
    customer[1] = int(customer[1]) * 60
    customers.append(customer)
customers = sorted(c for c in customers if c[0] <= 17 * 60 * 60)
total_waiting_time = 0
windows = [8 * 60 * 60 for i in range(window_size)]
for arriving_time, processing_time in customers:
    if windows[0] > arriving_time:
        total_waiting_time += windows[0] - arriving_time
        heapreplace(windows, windows[0] + processing_time)
    else:
        heapreplace(windows, arriving_time + processing_time)
print('{:.1f}'.format(total_waiting_time / len(customers) / 60 if customers else 0))
