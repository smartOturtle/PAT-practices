from fractions import *

a, b = map(Fraction, input().split())
ab_plus = a + b
ab_minus = a - b
ab_times = a * b
ab_divide = a / b if b != 0 else 'Inf'


def convert(f: Fraction):
    prefix = '(-' if f < 0 else ''
    suffix = ')' if prefix else ''
    f = abs(f)
    int_part, fraction_part = divmod(f.numerator, f.denominator)
    if int_part == 0:
        if fraction_part == 0:
            return '0'
        else:
            main_part = '{}/{}'.format(fraction_part, f.denominator)
    else:
        if fraction_part == 0:
            main_part = str(int_part)
        else:
            main_part = '{} {}/{}'.format(int_part, fraction_part, f.denominator)
    return prefix + main_part + suffix


print(convert(a), '+', convert(b), '=', convert(ab_plus))
print(convert(a), '-', convert(b), '=', convert(ab_minus))
print(convert(a), '*', convert(b), '=', convert(ab_times))
print(convert(a), '/', convert(b), '=', convert(ab_divide) if ab_divide != 'Inf' else ab_divide)
