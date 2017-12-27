#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int capacity, n, sp, roadSize;
vector<vector<int>> stations, pre;
deque<int> weight, path, temppath,dist;
int minNeed = INT16_MAX, minBack = INT16_MAX;
void dfs(int v)
{
  temppath.push_front(v);
  for (auto && value : pre[v])
    dfs(value);
  if (pre[v].empty())
  {
    int need = 0, back = 0;
    for (auto && idx : temppath)
    {
      back += weight[idx];
      if (back<0)
      {
        need += -back;
        back = 0;
      }
    }
    if (need < minNeed)
    {
      path = temppath;
      minNeed = need;
      minBack = back;
    }
    else if (need == minNeed && minBack>back)
    {
      path = temppath;
      minBack = back;
    }
  }
  temppath.pop_front();
}
int main()
{
  cin >> capacity >> n >> sp >> roadSize;
  stations.assign(n + 1, vector<int>(n + 1, INT16_MAX));
  dist.resize(stations.size(), INT16_MAX);
  weight.resize(stations.size());
  for (int i = 1; i < stations.size(); ++i)
  {
    cin >> weight[i];
    weight[i] -= capacity / 2;
  }
  for (int i = 0; i < roadSize; ++i)
  {
    int start, end, time;
    cin >> start >> end >> time;
    stations[start][end] = time;
    stations[end][start] = time;
  }
  pre.assign(stations.size(), {});
  vector<bool> collected(stations.size());
  auto& dist = stations[0];
  dist[0] = 0;
  while (true)
  {
    int idx = -1;
    for (int i = 0; i < stations.size(); ++i)
    {
      if (!collected[i] && dist[i] != INT16_MAX)
        if (idx < 0 || dist[i] < dist[idx])idx = i;
    }
    if (idx == -1)break;
    collected[idx] = true;
    for (int i = 0; i < stations.size(); ++i)
    {
      auto& edge = stations[idx][i];
      if (edge != INT16_MAX && !collected[i])
      {
        if (dist[i]>dist[idx] + edge)
        {
          dist[i] = dist[idx] + edge;
          pre[i].assign({ idx });
        }
        else if (dist[i] == dist[idx] + edge)pre[i].push_back(idx);
      }
    }
  }
  dfs(sp);
  printf("%d 0", minNeed);
  for (int i = 1; i < path.size(); i++)
    printf("->%d", path[i]);
  printf(" %d", minBack);
}
