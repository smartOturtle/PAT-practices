sentence_size = int(input())
sentences = []
for i in range(sentence_size):
    sentences.append(input())
kuchiguse = []
for s in zip(*map(reversed, sentences)):
    if all(map(lambda char: char == s[0], s)):
        kuchiguse.append(s[0])
    else:
        break
if kuchiguse:
    print(''.join(reversed(kuchiguse)))
else:
    print('nai')
