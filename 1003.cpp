#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <deque>
using namespace std;

struct Road
{
    int length = INT16_MAX;
    int teamSize = 0;
    Road() = default;
    Road(int length,int teamSize) :length(length), teamSize(teamSize) {}
    Road Extend(const Road& rhs)const{return {length + rhs.length,teamSize + rhs.teamSize };}
};
void Dijkstra(const vector<vector<Road>>& gragh, int start, int dest)
{
    deque<bool> visited(gragh.size());
    vector<int> wayCounts(gragh.size(), 1);
    auto dist = vector<Road>(gragh.size());
    dist[start].length = 0;
    while (true)
    {
        Road min;
        int idx = -1;
        for (int i = 0; i < gragh.size(); ++i)if (!visited[i] && dist[i].length < min.length)tie(min, idx) = { dist[i],i };
        if (idx == -1)break;
        visited[idx] = true;
        for (int i = 0; i < gragh.size(); ++i)
        {
            auto extendRoad = dist[idx].Extend(gragh[idx][i]);
            if (extendRoad.length<dist[i].length)
            {
                dist[i] = extendRoad;
                wayCounts[i] = wayCounts[idx];
            }
            else if (extendRoad.length==dist[i].length)
            {
                if (extendRoad.teamSize > dist[i].teamSize)dist[i] = extendRoad;
                wayCounts[i] += wayCounts[idx];
            }
        }
    }
    cout << wayCounts[dest] << " " << dist[dest].teamSize + gragh[start][start].teamSize;
}
int main()
{
    int citySize, roadSize, start, end;
    cin >> citySize >> roadSize >> start >> end;
    vector<vector<Road>> gragh(citySize, vector<Road>(citySize));
    for (int i = 0; i < citySize; ++i)
    {
        int teamSize;
        cin >> teamSize;
        gragh[i][i].teamSize = teamSize;
    }
    for (int i = 0; i < roadSize; ++i)
    {
        int first, last, length;
        cin >> first >> last >> length;
        gragh[first][last] = { length,gragh[last][last].teamSize };
        gragh[last][first] = { length,gragh[first][first].teamSize };
    }
    Dijkstra(gragh, start, end);
}
