#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
using IdxType = string;

struct Road
{
    int distance;
    int happiness;
    int span;
    static constexpr int notValid = INT16_MAX;
    Road(int distance, int happiness,int span=1) :distance(distance), happiness(happiness), span(span){}
    Road() :distance(notValid), happiness(0), span(0){}
    bool operator <(const Road& road)const
    {
        if (distance == road.distance)
        {
            if (happiness == road.happiness)return span < road.span;
            return happiness > road.happiness;
        }
        return distance < road.distance;
    }
    Road operator+(const Road& road)const
    {
        return { distance + road.distance,happiness + road.happiness,span + road.span };
    }
};
int main(int argc, char* argv[])
{
    //input
    int citySize, routeSize;
    IdxType start;
    cin >> citySize >> routeSize >> start;
    map<IdxType, int> citiesHappiness;
    map<IdxType, map<IdxType, Road>> gragh;
    set<IdxType> notVisited={start};
    for (int i = 1; i < citySize; ++i)
    {
        IdxType name;
        int happiness;
        cin >>name>> happiness;
        notVisited.insert(name);
        citiesHappiness[name]=happiness;
    }
    for (int i = 0; i < routeSize; ++i)
    {
        IdxType from, to;
        int distance;
        cin >> from >> to >> distance;
        gragh[from][to] = { distance,citiesHappiness[to], };
        gragh[to][from] = { distance,citiesHappiness[from] };
    }
    //dijkstra
    map<IdxType,int> pathSize;
    pathSize[start] = 1;
    map<IdxType,IdxType> path;
    auto dist = gragh[start];
    dist[start].distance = 0;
    while (!notVisited.empty())
    {
        auto v = *min_element(notVisited.begin(), notVisited.end(), [&](IdxType a, IdxType b) { return dist[a]< dist[b]; });
        notVisited.erase(v);
        for (auto i : notVisited)
        {
            auto extendRoad = gragh[v][i] + dist[v];
            if (extendRoad.distance<dist[i].distance)pathSize[i] = pathSize[v];
            else if (extendRoad.distance == dist[i].distance)pathSize[i] += pathSize[v];
            if (extendRoad<dist[i])
            {
                path[i] = v;
                dist[i] = extendRoad;
            }
        }
    }
    //output
    deque<IdxType> viaCitys;
    string rom = "ROM";
    for (auto i = rom; i != IdxType{}; i = path[i])viaCitys.push_front(i);
    cout << pathSize[rom] << " " << dist[rom].distance << " "
        << dist[rom].happiness << " " << dist[rom].happiness / dist[rom].span << '\n';
    cout << start;
    for (auto&name : viaCitys)cout << "->" << name;
}
