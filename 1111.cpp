#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>
using namespace std;

struct Street
{
    static constexpr int NotValid = INT16_MAX;
    int length;
    int time;
    int span;
    bool IsValid()const { return length < NotValid; }
    Street() :length(NotValid), time(NotValid), span(0) {}
    Street(int length, int time) :length(length), time(time), span(1) {}

    Street Extend(const Street& street)const
    {
        Street result = street;
        result.length += length;
        result.time += time;
        result.span += span;
        return result;
    }
};
bool IsFaster(const Street& lhs, const Street& rhs)
{
    if (lhs.time == rhs.time)return lhs.span < rhs.span;
    return lhs.time < rhs.time;
}
bool IsShorter(const Street& lhs, const Street& rhs)
{
    if (lhs.length == rhs.length)return lhs.time < rhs.time;
    return lhs.length < rhs.length;
}
pair<Street, deque<int>> Dijkstra(vector<vector<Street>> map, function<bool(Street, Street)> p, int from, int to)
{
    vector<int> pre(map.size(), -1);
    deque<bool> visited(map.size());
    auto dist = map[from];
    dist[from] = Street(0, 0);
    while (true)
    {
        int idx = -1;
        Street minStreet;
        for (int i = 0; i < map.size(); ++i)
        {
            if (!visited[i]&& p(dist[i],minStreet))
            {
                idx = i;
                minStreet = dist[idx];
            }
        }
        if (idx == -1)break;
        visited[idx] = true;
        for (int i = 0; i < map.size(); ++i)
        {
            if (p(dist[idx].Extend(map[idx][i]), dist[i]))
            {
                dist[i] = dist[idx].Extend(map[idx][i]);
                pre[i] = idx;
            }
        }
    }
    auto street = dist[to];
    deque<int> via;
    if(from!=to)for (int i = to; i != -1; i = pre[i])via.push_front(i);
    return make_pair(street, via);
}
int main(int argc, char* argv[])
{
    int vertexSize, streetSize;
    cin >> vertexSize >> streetSize;
    vector<vector<Street>> map(vertexSize, vector<Street>(vertexSize));
    for (int i = 0; i < streetSize; ++i)
    {
        int v1, v2, oneWay, length, time;
        cin >> v1 >> v2 >> oneWay >> length >> time;
        map[v1][v2] = Street(length, time);
        if (!oneWay)map[v2][v1] = map[v1][v2];
    }
    int from, to;
    cin >> from >> to;
    auto shortest = Dijkstra(map, IsShorter, from, to);
    auto fastest = Dijkstra(map, IsFaster, from, to);
    if (fastest.second == shortest.second)
    {
        cout << "Distance = " << shortest.first.length << "; Time = " << fastest.first.time << ": " << from;
        for (auto && idx : shortest.second)cout << " -> " << idx;
    }
    else
    {
        cout << "Distance = " << shortest.first.length << ": " << from;
        for (auto && idx : shortest.second)cout << " -> " << idx;
        cout << '\n';
        cout << "Time = " << fastest.first.time << ": " << from;
        for (auto && idx : fastest.second)cout << " -> " << idx;
    }
}

