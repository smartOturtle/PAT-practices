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
    bool IsFaster(const Street& rhs)const
    {
        if (time == rhs.time)return span < rhs.span;
        return time < rhs.time;
    }
    bool IsShorter(const Street& rhs)const
    {
        if (length == rhs.length)return time < rhs.time;
        return length < rhs.length;
    }
    Street Extend(const Street& street)const
    {
        Street result = street;
        result.length += length;
        result.time += time;
        result.span += span;
        return result;
    }
};
//pass const ref is equals to pass value
template<typename T,typename IdxType=int>
pair<T, deque<IdxType>> Dijkstra(
                                 vector<vector<T>> map, 
                                 IdxType from,
                                 IdxType to,
                                 T init=T(),
                                 function<bool(T, T)> binaryPred=less<T>(),
                                 function<T(T, T)> plusFunc=plus<T>())
{
    vector<IdxType> pre(map.size(), -1);
    deque<bool> visited(map.size());
    auto dist = map[from];
    dist[from] = init;
    while (true)
    {
        IdxType idx = -1;
        T minStreet;
        for (IdxType i = 0; i < map.size(); ++i)
        {
            if (!visited[i] && binaryPred(dist[i], minStreet))
            {
                idx = i;
                minStreet = dist[idx];
            }
        }
        if (idx == IdxType(-1))break;
        visited[idx] = true;
        for (IdxType i = 0; i < map.size(); ++i)
        {
            if (binaryPred(plusFunc(dist[idx],map[idx][i]), dist[i]))
            {
                dist[i] = plusFunc(dist[idx], map[idx][i]);
                pre[i] = idx;
            }
        }
    }
    auto result = dist[to];
    deque<IdxType> via;
    if (from != to)for (IdxType i = to; i != IdxType(-1); i = pre[i])via.push_front(i);
    return make_pair(result, via);
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
    auto shortest = Dijkstra<Street>(map, from, to, Street(0, 0),&Street::IsShorter, &Street::Extend );
    auto fastest = Dijkstra<Street>(map, from, to, Street(0, 0), &Street::IsFaster, &Street::Extend);
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
