input()
friend_ids={sum(int(c) for c in s) for s in input().split() }
print(len(friend_ids))
print(*sorted(friend_ids))
