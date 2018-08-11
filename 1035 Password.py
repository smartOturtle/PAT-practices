char_dict = {'1': '@', '0': '%', 'l': 'L', 'O': 'o'}
size = int(input())
modified_passwords = []
for i in range(size):
    user_id, password = input().split()
    previous = password
    password = ''.join(c if c not in char_dict else char_dict[c] for c in password)
    if password != previous:
        modified_passwords.append((user_id, password))
if modified_passwords:
    print(len(modified_passwords))
    for user_id, password in modified_passwords:
        print(user_id, password)
elif size == 1:
    print('There is 1 account and no account is modified')
else:
    print('There are {} accounts and no account is modified'.format(size))
