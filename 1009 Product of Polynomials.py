from collections import defaultdict


def poly_factory()->defaultdict:
    seq = input().split(' ')
    poly = defaultdict(float)
    for i in range(1, len(seq), 2):
        poly[int(seq[i])] = float(seq[i + 1])
    return poly


def poly_mul(p1, p2):
    poly = defaultdict(float)
    for key1, value1 in p1.items():
        for key2, value2 in p2.items():
            poly[key1 + key2] += value1 * value2
    return poly


result = sorted((i for i in poly_mul(poly_factory(), poly_factory()).items() if i[1]), reverse=True)
print(len(result), *(('{} {:.1f}'.format(s[0], s[1]) for s in result)))
