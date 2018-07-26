node_size = int(input())
graph = [[] for i in range(node_size)]
for i in range(node_size - 1):
    one, other = map(lambda i: int(i) - 1, input().split())
    graph[one].append(other)
    graph[other].append(one)
visited = [False for i in range(node_size)]
max_depth = 1
max_depth_nodes = []


def dfs(idx: int, depth: int):
    global visited, graph, max_depth, max_depth_nodes
    visited[idx] = True
    if depth > max_depth:
        max_depth = depth
        max_depth_nodes = [idx]
    elif depth == max_depth:
        max_depth_nodes.append(idx)
    for i in graph[idx]:
        if not visited[i]:
            dfs(i, depth + 1)


cnt = 0
for i in range(node_size):
    if not visited[i]:
        cnt += 1
        dfs(i, 1)
if cnt != 1:
    print('Error: {} components'.format(cnt))
else:
    temp = max_depth_nodes
    max_depth_nodes = []
    visited = [False for i in range(node_size)]
    dfs(temp[0], 1)
    max_depth_nodes = set(max_depth_nodes)
    max_depth_nodes.update(temp)
    for i in sorted(max_depth_nodes):
        print(i + 1)
