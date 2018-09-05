s = input()
for i in range(10):
    if all(p[0] == p[1] for p in zip(s, reversed(s))):
        print(s, 'is a palindromic number.')
        break
    else:
        print(s, '+', ''.join(reversed(s)), '=', int(s) + int(''.join(reversed(s))))
        s = str(int(s) + int(''.join(reversed(s))))
else:
    print('Not found in 10 iterations.')
