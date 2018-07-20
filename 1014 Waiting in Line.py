import collections

window_size, max_capacity, _, _ = list(map(int, input().split(' ')))
windows = [collections.deque() for i in range(window_size)]
customers = list(map(int, input().split(' ')))
current_time = 8 * 60
for idx, duration in enumerate(customers):
    min_length_window = min(windows, key=len)
    if len(min_length_window) == max_capacity:
        earliest = min(windows, key=lambda w: w[0])
        current_time = earliest.popleft()
        min_length_window = earliest
    min_length_window.append((current_time if len(min_length_window) == 0 else min_length_window[-1]) + duration)
    customers[idx] = min_length_window[-1] if min_length_window[-1] - duration < 17 * 60 else -1
for idx in map(lambda i: int(i) - 1, input().split(' ')):
    if customers[idx] != -1:
        print('{:02d}'.format(customers[idx] // 60), '{:02d}'.format(customers[idx] % 60), sep=':')
    else:
        print('Sorry')
