#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <queue>
using namespace std;

struct Road
{
    int length=0xffffff;
    int time=0xffffff;
    int span=1;
    Road operator+(const Road& rhs)const { return { length + rhs.length,time + rhs.time,span + rhs.span }; }
};
vector<vector<Road>> graph;
auto Dijkstra(int start,int end, function<bool(Road, Road)> surpass)
{
    auto dist = graph[start];
    dist[start] = { 0,0,0 };
    vector<int> pre(graph.size(), -1);
    set<int> notVisited;
    for (int i = 0; i < graph.size(); ++i)notVisited.insert(i);
    while (!notVisited.empty())
    {
        auto idx = *min_element(notVisited.begin(), notVisited.end(), [&](int lhs, int rhs) { return surpass(dist[lhs], dist[rhs]); });
        notVisited.erase(idx);
        for(auto v:notVisited)
        {
            if(surpass(dist[idx]+graph[idx][v], dist[v]))
            {
                pre[v] = idx;
                dist[v] = dist[idx] + graph[idx][v];
            }
        }
    }
    deque<int> path;
    for (int i = end; i != -1; i = pre[i])path.push_front(i);
    return make_pair(dist[end],path);
}
int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int vertexSize, roadSize;
    cin >> vertexSize >> roadSize;
    graph.resize(vertexSize, vector<Road>(vertexSize));
    for (int i = 0; i < roadSize; ++i)
    {
        int lhs, rhs, oneWay, length, time;
        cin >> lhs >> rhs >> oneWay >> length >> time;
        graph[lhs][rhs] = { length,time,1 };
        if (!oneWay)graph[rhs][lhs] = { length,time,1 };
    }
    int start, end;
    cin >> start >> end;
    auto shorter=[](Road lhs,Road rhs)
    {
        return make_tuple(lhs.length, lhs.time) < make_tuple(rhs.length, rhs.time);
    };
    auto faster=[](Road lhs,Road rhs)
    {
        return make_tuple(lhs.time, lhs.span) < make_tuple(rhs.time, rhs.span);
    };
    auto shortest= Dijkstra(start, end, shorter);
    auto fastest= Dijkstra(start, end, faster);
    if(shortest.second==fastest.second)
    {
        printf("Distance = %d; Time = %d: %d", shortest.first.length, fastest.first.time, start);
        for (auto idx : shortest.second)printf(" -> %d", idx);
    }
    else
    {
        printf("Distance = %d: %d", shortest.first.length, start);
        for (auto idx : shortest.second)printf(" -> %d", idx);
        printf("\n");
        printf("Time = %d: %d", fastest.first.time, start);
        for (auto idx : fastest.second)printf(" -> %d", idx);
    }
}
