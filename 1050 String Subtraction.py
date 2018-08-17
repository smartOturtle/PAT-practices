s = input()
exclude = {c for c in input()}
print(*(c for c in s if c not in exclude), sep='')
