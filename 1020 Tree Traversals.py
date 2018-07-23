from collections import *
from itertools import *

input()
post_order = [int(i) for i in input().split()]
in_order = [int(i) for i in input().split()]


def build_tree(idx, in_slice):
    if idx < 0 or not in_slice:
        return None
    in_idx = sum(1 for i in takewhile(lambda v: v != post_order[idx], in_slice))
    return [post_order[idx], build_tree(idx - (len(in_slice)-in_idx), in_slice[:in_idx]),
            build_tree(idx - 1, in_slice[in_idx + 1:])]


root = build_tree(len(post_order) - 1, in_order)
queue = deque([root])
level_order = []
while queue:
    level_order.append(queue[0][0])
    queue.extend(n for n in queue.popleft()[1:] if n)
print(*level_order)
