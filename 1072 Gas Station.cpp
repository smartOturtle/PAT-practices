#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <functional>
#include <string>
#include <unordered_set>
#include <array>
#include <numeric>
using namespace std;
int houseSize, candidateSize, roadSize, maxRange;
int GetIdx()
{
    string s;
    cin >> s;
    if (s.front() == 'G')return stoi(s.substr(1)) + houseSize-1;
    return stoi(s)-1;
}
array<int,3> Dijkstra(const vector<vector<int>>& graph,int candidateIdx)
{
    unordered_set<int> unchecked;
    for (int i = 0; i < houseSize+candidateSize; ++i)
    {
        unchecked.insert(i);
    }
    auto dist = graph[candidateIdx];
    dist[candidateIdx] = 0;
    while (!unchecked.empty())
    {
        auto idx = *min_element(unchecked.begin(), unchecked.end(), 
            [&dist](int lhs, int rhs) { return dist[lhs] < dist[rhs]; });
        unchecked.erase(idx);
        for(auto v:unchecked)dist[v] = min(dist[v], dist[idx] + graph[idx][v]);
    }
    vector<int>::iterator minIter, maxiter;
    tie(minIter, maxiter) = minmax_element(dist.begin(), dist.begin()+houseSize);
    if (*maxiter > maxRange)return { -1 };
    return { *minIter,accumulate(dist.begin(), dist.begin() + houseSize,0),candidateIdx };
}
int main(int argc, char* argv[])
{
    cin >> houseSize >> candidateSize >> roadSize >> maxRange;
    int vertexSize = houseSize + candidateSize;
    vector<vector<int>> graph(vertexSize,vector<int>(vertexSize,0xffffff));
    for (int i = 0; i < roadSize; ++i)
    {
        int lhs = GetIdx();
        int rhs = GetIdx();
        int dist;
        cin >> dist;
        graph[lhs][rhs] = dist;
        graph[rhs][lhs] = dist;
    }
    array<int, 3> solution = { -1 };
    for (int i = 0; i < candidateSize; ++i)
    {
        solution = max(solution, Dijkstra(graph, houseSize+ i),[](auto& lhs,auto& rhs)
        {
            if (lhs[0] == rhs[0])return make_pair(lhs[1], lhs[2]) > make_pair(rhs[1], rhs[2]);
            return lhs[0] < rhs[0];
        });
    }
    if (solution[0] <0)cout << "No Solution";
    else
    {
        printf("G%d\n", solution[2] - houseSize + 1);
        printf("%.1lf %.1lf", 1.0*solution[0], solution[1] / double(houseSize));
    }
}
