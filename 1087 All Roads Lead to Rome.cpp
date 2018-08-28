#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

struct Route
{
    int cost = 0xffffff;
    int happiness=0;
    int span=0;
    Route operator+(const Route& rhs)const
    {
        return { cost + rhs.cost,happiness + rhs.happiness,span + rhs.span };
    }
    bool operator<(const Route& rhs)const
    {
        return  make_tuple(cost, -happiness, span) < make_tuple(rhs.cost, -rhs.happiness, span);
    }
};
int main(int argc, char* argv[])
{
    int cicySize, routeSize;
    string start;
    cin >> cicySize >> routeSize>>start;
    unordered_map<string, unordered_map<string,Route>> graph;
    unordered_map<string, int> eachHappiness;
    for (int i = 0; i < cicySize-1; ++i)
    {
        string id;
        int happiness;
        cin >> id >> happiness;
        eachHappiness[id] = happiness;
    }
    for (int i = 0; i < routeSize; ++i)
    {
        string lhs, rhs;
        int cost;
        cin >> lhs >> rhs >> cost;
        graph[lhs][rhs] = { cost,eachHappiness[rhs],1 };
        graph[rhs][lhs] = { cost,eachHappiness[lhs],1 };
    }
    unordered_set<string> notVisited;
    for (auto && idxRoute : graph)notVisited.insert(idxRoute.first);
    auto dist = graph[start];
    dist[start].cost = 0;
    unordered_map<string,string> path;
    unordered_map<string, int> pathSize;
    pathSize[start] = 1;
    while (!notVisited.empty())
    {
        auto idx = *min_element(notVisited.begin(), notVisited.end(),
            [&](const string& lhs, const string& rhs) { return dist[lhs] < dist[rhs]; });
        notVisited.erase(idx);
        for(auto& v:notVisited)
        {
            auto expand = dist[idx] + graph[idx][v];
            if (expand.cost == dist[v].cost)pathSize[v] += pathSize[idx];
            else if (expand.cost < dist[v].cost)pathSize[v] = pathSize[idx];
            if(expand<dist[v])
            {
                dist[v] = expand;
                path[v] = idx;
            }
        }
    }
    auto rom = "ROM"s;
    cout << pathSize[rom] <<" "<< dist[rom].cost << " " 
    << dist[rom].happiness << " " << dist[rom].happiness / dist[rom].span<<'\n';
    cout << start;
    vector<string> via;
    for (auto idx = rom; !idx.empty(); idx = path[idx])via.push_back(idx);
    for (auto iter = via.rbegin(); iter != via.rend(); ++iter)cout << "->" << *iter;
}

