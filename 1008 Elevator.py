def calculate(stops):
    current_floor = 0
    for next_stop in stops:
        if next_stop > current_floor:
            yield (next_stop - current_floor) * 6 + 5
        else:
            yield (current_floor - next_stop) * 4 + 5
        current_floor = next_stop


print(sum(calculate([int(i) for i in input().split(' ')][1:])))
