from itertools import *

max_capacity, station_size, problem_idx, road_size = map(int, input().split())
stations_bike_size = list(chain([0], map(int, input().split())))
graph = [[1e9 for i in range(station_size + 1)] for i in range(station_size + 1)]
dist = [1e9 for i in range(station_size + 1)]
dist[0] = 0
for i in range(road_size):
    start, end, time = map(int, input().split())
    graph[start][end] = time
    graph[end][start] = time
not_visited = set(i for i in range(station_size + 1))
pre_nodes = [[] for i in range(station_size + 1)]
while not_visited:
    min_idx = min(not_visited, key=lambda i: dist[i])
    not_visited.remove(min_idx)
    for idx in not_visited:
        if dist[idx] > dist[min_idx] + graph[min_idx][idx]:
            dist[idx] = dist[min_idx] + graph[min_idx][idx]
            pre_nodes[idx] = [min_idx]
        elif dist[idx] == dist[min_idx] + graph[min_idx][idx]:
            pre_nodes[idx].append(min_idx)
path = []
min_need = 1e9
min_surplus = 1e9
perfect_path = None


def dfs(idx):
    global path, min_need, min_surplus, perfect_path
    if idx == 0:
        need, surplus = 0, 0
        for idx in reversed(path):
            surplus += stations_bike_size[idx] - max_capacity // 2
            if surplus < 0:
                need -= surplus
                surplus = 0
        if need < min_need or (need == min_need and surplus < min_surplus):
            min_need, min_surplus, perfect_path = need, surplus, path[::-1]
    else:
        path.append(idx)
        for i in pre_nodes[idx]:
            dfs(i)
        path.pop()


dfs(problem_idx)
print(min_need, '->'.join(chain('0', (str(i) for i in perfect_path))), min_surplus)
