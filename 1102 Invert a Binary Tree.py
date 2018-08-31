from collections import *

node_size = int(input())
nodes = []
appeared_indices = [False for i in range(node_size)]
for i in range(node_size):
    left, right = input().split()
    left = int(left) if left != '-' else -1
    right = int(right) if right != '-' else -1
    if left != -1:
        appeared_indices[left] = True
    if right != -1:
        appeared_indices[right] = True
    nodes.append([right, left])

for idx, v in enumerate(appeared_indices):
    if not v:
        root = idx


def level_order():
    queue = deque()
    queue.append(root)
    output = []
    while queue:
        output.append(queue[0])
        queue.extend(i for i in nodes[queue[0]] if i != -1)
        queue.popleft()
    print(*output)


traversal = []


def in_order(idx):
    if idx == -1:
        return
    in_order(nodes[idx][0])
    traversal.append(idx)
    in_order(nodes[idx][1])


level_order()
in_order(root)
print(*traversal)
