from collections import Counter

chain = Counter(input())
need = Counter(input())
if all((chain[c] >= v for c, v in need.items())):
    print('Yes', sum(chain.values()) - sum(need.values()))
else:
    print('No', sum(map(lambda p: max(0, p[1] - chain[p[0]]), need.items())))
