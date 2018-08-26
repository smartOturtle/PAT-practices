from fractions import *

input()
result = Fraction()
for f in input().split():
    result += Fraction(f)
is_negative = '-' if result < 0 else ''
result = abs(result)
if result.numerator > result.denominator:
    print(is_negative, result.numerator // result.denominator, sep='', end='')
    result._numerator %= result._denominator
    if result.numerator:
        print(' ', is_negative, result, sep='')
else:
    print(is_negative, result, sep='')
