#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    unordered_map<int, vector<int>> tree;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int id;
        cin >> id;
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j)
        {
            int childId;
            cin >> childId;
            tree[id] .push_back(childId) ;
        }
    }
    queue<int> q;
    q.push(01);
    int levelLeaveSize = 0;
    int levelSize = 1;
    int levelCount = 0;
    vector<int> eachLevelLeaveSize;
    while (!q.empty())
    {
        if(tree[q.front()].empty())
        {
            levelLeaveSize++;
        }
        else for (auto id : tree[q.front()])q.push(id);
        q.pop();
        ++levelCount;
        if(levelCount==levelSize)
        {
            levelCount = 0;
            levelSize = q.size();
            eachLevelLeaveSize.push_back(levelLeaveSize);
            levelLeaveSize = 0;
        }
    }
    cout << eachLevelLeaveSize.front();
    for (int i = 1; i < eachLevelLeaveSize.size(); ++i)
    {
        cout << " " << eachLevelLeaveSize[i];
    }
}
