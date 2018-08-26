from fractions import *

input()
result = Fraction()
for f in input().split():
    result += Fraction(f)
if result.numerator // result.denominator:
    print(result.numerator // result.denominator, end='')
    result._numerator %= result._denominator
    if result.numerator:
        print(' ', result, sep='')
else:
    print(result)
