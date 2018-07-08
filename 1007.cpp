from itertools import islice

input()
seq = [int(i) for i in input().split(' ')]
if all(i < 0 for i in seq):
    print(0, seq[0], seq[-1])
else:
    largest_sum = seq[0]
    begin_value = seq[0]
    last_value = seq[0]
    current_sum = seq[0]
    current_begin_value = seq[0]
    for i in islice(seq, 1, None):
        if current_sum < 0:
            current_sum = 0
            current_begin_value = i
        current_sum += i
        if current_sum > largest_sum:
            largest_sum, begin_value, last_value = current_sum, current_begin_value, i
    print(largest_sum, begin_value, last_value)
