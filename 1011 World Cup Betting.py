def input_item():
    item = max((float(v), t) for t, v in zip('WTL', input().split(' ')))
    print(item[1], end=' ')
    return item[0]


odd = input_item()
odd *= input_item()
odd *= input_item()
print("{:.2f}".format((odd * 0.65 - 1) * 2))
