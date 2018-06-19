from collections import defaultdict


def poly_factory():
    seq = input().split(' ')
    poly = defaultdict(float)
    for i in range(1, len(seq), 2):
        poly[int(seq[i])] = float(seq[i + 1])
    return poly


def poly_add(p1, p2):
    poly = p1.copy()
    for key, value in p2.items():
        poly[key] += value
    keys = [key for key in poly.keys()]
    return poly


result = sorted((i for i in poly_add(poly_factory(), poly_factory()).items() if i[1]), reverse=True)
print(len(result), *(('{} {:.1f}'.format(s[0], s[1]) for s in result)))
