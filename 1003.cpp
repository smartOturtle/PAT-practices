#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
void dijkstra(vector<vector<pair<int, int>>>& gragh, int start, int end)
{
  vector<bool> collected(gragh.size(), false);
  vector<int> count(gragh.size(), 1);
  auto& dist = gragh[start];
  auto teamSize = gragh[start][start].second;
  if (start == end)teamSize = 0;
  while (true)
  {
    int idx=-1;
    for (int i = 0; i < gragh.size(); ++i)
      if(!collected[i]&&dist[i].first<INT16_MAX)
      {
        if (idx < 0 || dist[i].first < dist[idx].first)idx = i;
      }
    if(idx==-1)break;
    collected[idx] = true;
    for (int i = 0; i < gragh[idx].size(); ++i)
    {
      auto& edge = gragh[idx][i];
      if (edge.first != INT16_MAX &&!collected[i])
      {
        if (dist[i].first > dist[idx].first + edge.first)
        {
          dist[i].first = dist[idx].first + edge.first;
          dist[i].second = dist[idx].second + edge.second;
          count[i] = count[idx];
        }
        else if (dist[i].first == dist[idx].first + edge.first)
        {
          if (dist[i].second<dist[idx].second + edge.second)
            dist[i].second = dist[idx].second + edge.second;
          count[i] += count[idx];
        }
      }
    }
  }
  cout << count[end] << " " << dist[end].second + teamSize;
}
int main()
{
  int citySize, roadSize, start, end;
  cin >> citySize >> roadSize >> start >> end;
  vector<vector<pair<int, int>>> gragh(citySize, vector<pair<int, int>>(citySize, { INT16_MAX ,-INT16_MAX }));
  for (int i = 0; i < citySize; ++i)
  {
    int teamSize;
    cin >> teamSize;
    gragh[i][i].second = teamSize;
  }
  for (int i = 0; i < roadSize; ++i)
  {
    int first, last, length;
    cin >> first >> last >> length;
    gragh[first][last] = { length,gragh[last][last].second };
    gragh[last][first] = { length,gragh[first][first].second };
  }
  dijkstra(gragh, start, end);
}
