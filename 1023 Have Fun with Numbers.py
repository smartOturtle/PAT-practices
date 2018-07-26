from collections import Counter

a = input()
counter = Counter()
for c in a:
    counter[c] += 1
a = int(a) * 2
for c in str(a):
    counter[c] -= 1
if any(counter.values()):
    print('No')
else:
    print('Yes')
print(a)
