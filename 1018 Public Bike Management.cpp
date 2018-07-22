#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;
int capacity, n, endIdx, roadSize;
vector<vector<int>> gragh, pre;
deque<int> stationWeights, path, temppath, dist;
int minNeed = INT16_MAX, minBack = INT16_MAX;
void DFS(int v)
{
    temppath.push_front(v);
    for (auto value : pre[v])dfs(value);
    if (pre[v].empty())
    {
        int need = 0, back = 0;
        for (auto && idx : temppath)
        {
            back += stationWeights[idx];
            if (back<0)
            {
                need += -back;
                back = 0;
            }
        }
        if (need < minNeed || (need == minNeed && minBack>back))
            tie(path, minNeed, minBack) = { temppath,need,back };
    }
    temppath.pop_front();
}
int main()
{
    cin >> capacity >> n >> endIdx >> roadSize;
    gragh.assign(n + 1, vector<int>(n + 1, INT16_MAX));
    dist.resize(gragh.size(), INT16_MAX);
    stationWeights.resize(gragh.size());
    for (int i = 1; i < gragh.size(); ++i)
    {
        cin >> stationWeights[i];
        stationWeights[i] -= capacity / 2;
    }
    for (int i = 0; i < roadSize; ++i)
    {
        int start, end, time;
        cin >> start >> end >> time;
        gragh[start][end] = time;
        gragh[end][start] = time;
    }
    pre.assign(gragh.size(), {});
    deque<bool> collected(gragh.size());
    auto dist = gragh[0];
    dist[0] = 0;
    while (true)
    {
        int idx = -1;
        int min = INT16_MAX;
        for (int i = 0; i < gragh.size(); ++i)
            if (!collected[i] && dist[i] < min)tie(idx, min) = { i,dist[i] };
        if (idx == -1)break;
        collected[idx] = true;
        for (int i = 0; i < gragh.size(); ++i)
        {
            auto weight = gragh[idx][i];
            if (dist[i]>dist[idx] + weight)
            {
                dist[i] = dist[idx] + weight;
                pre[i].assign({ idx });
            }
            else if (dist[i] == dist[idx] + weight)pre[i].push_back(idx);
        }
    }
    DFS(endIdx);
    printf("%d 0", minNeed);
    for (int i = 1; i < path.size(); i++)printf("->%d", path[i]);
    printf(" %d", minBack);
}
