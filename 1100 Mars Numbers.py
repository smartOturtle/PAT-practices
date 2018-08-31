first_figures = {k: v for k, v in zip(range(13), 'tret jan feb mar apr may jun jly aug sep oct nov dec'.split())}
second_figures = {k * 13: v for k, v in zip(range(1, 13), 'tam hel maa huh tou kes hei elo syy lok mer jou'.split())}
first_calls = {k: v for v, k in first_figures.items()}
second_calls = {k: v for v, k in second_figures.items()}


def to_calls(n: int):
    second, first = n - n % 13, n % 13
    if second:
        return second_figures[second] + (' ' + first_figures[first] if first else '')
    else:
        return first_figures[first]


def to_num(s: str):
    num = s.split()
    if len(num) == 1:
        if num[0] in first_calls:
            return first_calls[num[0]]
        else:
            return second_calls[num[0]]
    return second_calls[num[0]] + first_calls[num[1]]


for i in range(int(input())):
    s = input()
    if s[0].isdigit():
        print(to_calls(int(s)))
    else:
        print(to_num(s))
