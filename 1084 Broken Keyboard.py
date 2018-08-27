from collections import OrderedDict

type_out = input()
appeared = set(input())
broken = OrderedDict((str.capitalize(key), 1) for key in type_out if key not in appeared).keys()
print(*broken, sep='')
