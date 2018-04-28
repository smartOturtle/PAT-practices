#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;
unordered_map<int,unordered_map<int, int>> stations(10000);

struct Query
{
    vector<int> path;
    int minTransfer = 10000;
    deque<bool> visited;
    int from;
    int to;
    vector<int> temp;
    void DFS(int id,int line,int transfer)
    {
        if(temp.size()>path.size()||(temp.size() == path.size() && minTransfer<=transfer))return;
        temp.push_back(id);
        if(id==to)
        {
            if(temp.size()<path.size()||(temp.size()==path.size()&&minTransfer>transfer))
            {
                minTransfer = transfer;
                path = temp;
            }
            return temp.pop_back();
        }
        for (auto && next : stations[id])
        {
            if(!visited[next.first])
            {
                visited[next.first] = true;
                if (next.second == line) { DFS(next.first, next.second, transfer); }
                else { DFS(next.first, next.second, transfer + 1); }
                visited[next.first] = false;
            }
        }
        temp.pop_back();
    }
    Query(int from,int to):from(from),to(to),visited(10000),path(10000)
    {
        
    }
    void operator()()
    {
        DFS(from, -1, 0);
        cout << path.size()-1<< '\n';
        int lineStart = path[0];
        int lineIdx = stations[path[0]][path[1]];
        int preidx = path[1];
        for (int i = 2; i < path.size(); ++i)
        {
            if (stations[preidx][path[i]] != lineIdx)
            {
                printf("Take Line#%d from %04d to %04d.\n", lineIdx, lineStart, preidx);
                lineIdx = stations[preidx][path[i]];
                lineStart = preidx;
            }
            preidx = path[i];
        }
        printf("Take Line#%d from %04d to %04d.\n", lineIdx, lineStart, preidx);
    }
};
int main(int argc, char* argv[])
{
    int subwayLineSize;
    cin >> subwayLineSize;
    for (int i = 1; i <= subwayLineSize; ++i)
    {
        int stationSize;
        cin >> stationSize;
        int preStationIdx;
        cin >> preStationIdx;
        for (int j = 1; j < stationSize; ++j)
        {
            int currentStaionIdx;
            cin >> currentStaionIdx;
            stations[preStationIdx][currentStaionIdx]=i;
            stations[currentStaionIdx][preStationIdx]=i;
            preStationIdx = currentStaionIdx;
        }
    }
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        int from, to;
        cin>>from >> to;
        Query(from, to)();
    }
}

