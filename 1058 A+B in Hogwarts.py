def to_knut(currency):
    radix = [17, 29, 1]
    total_sum = 0
    for i, value in enumerate(currency.split('.')):
        total_sum = (total_sum + int(value)) * radix[i]
    return total_sum


a, b = input().split()
ab_sum = to_knut(a) + to_knut(b)
print(ab_sum // (17 * 29), ab_sum // 29 % 17, ab_sum % 29, sep='.')
