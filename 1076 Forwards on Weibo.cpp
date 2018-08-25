#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
    int userSize, maxLevel;
    cin >> userSize>>maxLevel;
    vector<vector<int>> graph(userSize+1);
    for (int i = 1; i <= userSize; ++i)
    {
        int followSize;
        cin >> followSize;
        for (int j = 0; j < followSize; ++j)
        {
            int id;
            cin >> id;
            graph[id].push_back(i);
        }
    }
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        int id;
        cin >> id;
        queue<int> q;
        int cnt = 0;
        int level =0;
        int currentLevelSize = 1;
        q.push(id);
        deque<bool> visited(userSize + 1);
        visited[id] = true;
        for (int j = 1; level<maxLevel&&!q.empty(); ++j)
        {
            for (auto followId : graph[q.front()])
            {
                if(!visited[followId])q.push(followId);
                visited[followId] = true;
            }
            q.pop();
            if(j==currentLevelSize)
            {
                level++;
                cnt += q.size();
                currentLevelSize = q.size();
                j = 0;
            }
        }
        cout << cnt << '\n';
    }
}

