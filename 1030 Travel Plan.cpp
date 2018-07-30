#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

struct Road
{
    int dist = INT16_MAX;
    int cost = INT16_MAX;
    Road(int dist, int cost) :dist(dist), cost(cost) {}
    Road() {}
    bool operator <(const Road& road)const
    {
        if (dist == road.dist)return cost < road.cost;
        return dist < road.dist;
    }
    Road operator+(const Road& road)const
    {
        return { dist + road.dist,cost + road.cost };
    }
};
int main()
{
    int citySize, roadSize, start, end;
    scanf("%d %d %d %d", &citySize, &roadSize, &start, &end);
    vector<vector<Road>> graph(citySize, vector<Road>(citySize));
    for (int i = 0; i < roadSize; ++i)
    {
        int city1, city2, dist, cost;
        cin >> city1 >> city2 >> dist >> cost;
        graph[city1][city2] = { dist,cost };
        graph[city2][city1] = { dist,cost };
    }
    auto dist = graph[start];
    dist[start] = { 0,0 };
    vector<int> path(citySize, -1);
    set<int> notVisited;
    for (int i = 0; i < citySize; ++i)notVisited.insert(i);
    while (!notVisited.empty())
    {
        auto idx = *min_element(notVisited.begin(), notVisited.end(), [&](int a, int b) { return dist[a] < dist[b]; });
        notVisited.erase(idx);
        for(auto i : notVisited)
            if(dist[idx]+graph[idx][i]<dist[i])
            {
                dist[i] = dist[idx] + graph[idx][i];
                path[i] = idx;
            }
    }
    vector<int> l;
    for (int i = end; i != -1; i = path[i])l.push_back(i);
    l.push_back(start);
    for (auto i = l.rbegin(); i != l.rend(); ++i)printf("%d ", *i);
    printf("%d %d", dist[end].dist, dist[end].cost);
}
