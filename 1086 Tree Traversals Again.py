node_size = int(input())
stack = []
pre_order = []
in_order = []
for i in range(2 * node_size):
    operation = input().split()
    if operation[0] == 'Push':
        stack.append(int(operation[1]))
        pre_order.append(stack[-1])
    else:
        in_order.append(stack[-1])
        stack.pop()
post_order = []


def solve(pre_first, pre_last, in_first, in_last):
    if pre_first >= pre_last:
        return
    in_idx = in_first
    while in_order[in_idx] != pre_order[pre_first]:
        in_idx += 1
    left_size = in_idx - in_first
    solve(pre_first + 1, pre_first + left_size + 1, in_first, in_idx)
    solve(pre_first + left_size + 1, pre_last, in_idx + 1, in_last)
    post_order.append(pre_order[pre_first])


solve(0, node_size, 0, node_size)
print(*post_order)
