import string

weekdays = {'A': 'MON', 'B': 'TUE', 'C': 'WED', 'D': 'THU', 'E': 'FRI', 'F': 'SAT', 'G': 'SUN'}
hours = {k: v for k, v in zip(string.digits + string.ascii_uppercase, range(24))}
first_pair = [input(), input()]
second_pair = [input(), input()]
first_common = True
for c, _ in filter(lambda p: p[0] == p[1], zip(*first_pair)):
    if first_common:
        if c in weekdays:
            weekday = weekdays[c]
            first_common = False
    elif c in hours:
        hour = hours[c]
        break
for i, (c1, c2) in enumerate(zip(*second_pair)):
    if str.isalpha(c1) and c1 == c2:
        minute = i
        break
print(weekday, '{:02d}:{:02d}'.format(hour, minute))
