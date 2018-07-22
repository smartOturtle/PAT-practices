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
visited = [False for i in range(station_size + 1)]
pre_nodes = [[] for i in range(station_size + 1)]
while True:
    min_idx = -1
    min_time = 1e9
    for idx, time in enumerate(dist):
        if not visited[idx] and time < min_time:
            min_idx, min_time = idx, time
    if min_idx == -1:
        break
    visited[min_idx] = True
    for idx, time in enumerate(graph[min_idx]):
        if visited[idx]:
            continue
        if dist[idx] > dist[min_idx] + time:
            dist[idx] = dist[min_idx] + time
            pre_nodes[idx] = [min_idx]
        elif dist[idx] == dist[min_idx] + time:
            pre_nodes[idx].append(min_idx)
paths = []
path = []


def dfs(idx):
    global path
    global paths
    if idx == 0:
        paths.append(path[::-1])
    else:
        path.append(idx)
        for i in pre_nodes[idx]:
            dfs(i)
        path.pop()


dfs(problem_idx)
min_need = 1e9
min_surplus = 1e9
perfect_path = None
for path in paths:
    need, surplus = 0, 0
    for idx in path:
        surplus += stations_bike_size[idx] - max_capacity // 2
        if surplus < 0:
            need -= surplus
            surplus = 0
    if need < min_need or (need == min_need and surplus < min_surplus):
        min_need, min_surplus, perfect_path = need, surplus, path
print(min_need, '->'.join(chain('0', (str(i) for i in perfect_path))), min_surplus)
