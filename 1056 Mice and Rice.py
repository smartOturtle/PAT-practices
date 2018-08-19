_, capacity = map(int, input().split())
mice_weights = list(map(int, input().split()))
order = list(map(int, input().split()))
mice_rank = mice_weights.copy()
while len(order) != 1:
    next_turn = []
    for i in range(0, len(order), capacity):
        next_turn.append(max(order[i:min(i + capacity, len(order))], key=lambda idx: mice_weights[idx]))
    for idx in order:
        mice_rank[idx] = len(next_turn) + 1
    order, next_turn = next_turn, order
mice_rank[order[0]] = 1
print(*mice_rank)
