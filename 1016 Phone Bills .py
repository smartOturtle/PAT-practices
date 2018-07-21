from collections import *

rates = [int(i) / 100 for i in input().split()]
record_size = int(input())
records = []
for i in range(record_size):
    records.append(tuple(input().split()))
records.sort(key=lambda r: r[1])
match_pair = {}
users = defaultdict(list)
month = None
for name, time, tag in records:
    month = time[:2]
    if tag == 'on-line':
        match_pair[name] = time
    elif name in match_pair:
        users[name].append((match_pair[name], time))
        del match_pair[name]


def duration_cost(start, end):
    def base(t):
        _, d, h, m = [int(i) for i in t.split(':')]
        return d * sum(60 * i for i in rates) + sum(rates[i] * 60 for i in range(h)) + m * rates[h], (
                d * 24 + h) * 60 + m

    start_fee, start_time = base(start)
    end_fee, end_time = base(end)
    return end_time - start_time, end_fee - start_fee


for name,pairs in sorted(users.items()):
    print(name, month)
    total_amount = 0
    for start, end in pairs:
        print(start[3:], end[3:], '{} ${:.2f}'.format(*duration_cost(start, end)))
        total_amount += duration_cost(start, end)[1]
    print('Total amount: ${:.2f}'.format(total_amount))
