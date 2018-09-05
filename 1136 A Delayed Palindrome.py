s = input()
for i in range(10):
    if all(p[0] == p[1] for p in zip(s, reversed(s))):
        print(s, 'is a palindromic number.')
        break
    else:
        result=int(s) + int(''.join(reversed(s)))
        print(s, '+', ''.join(reversed(s)), '=', result)
        s = str(result)
else:
    print('Not found in 10 iterations.')
