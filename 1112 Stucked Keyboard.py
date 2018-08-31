from collections import OrderedDict

k = int(input())
sentence = input()
chars = OrderedDict({c: 1 for c in sentence})
temp = sentence
for c in chars:
    temp = ''.join(temp.split(c * k))
stucked = OrderedDict({c: 1 for c in chars if c not in set(temp)})
print(*stucked, sep='')
for c in stucked:
    sentence = sentence.replace(c * k, c)
print(sentence)
