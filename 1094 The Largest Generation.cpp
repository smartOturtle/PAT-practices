#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
    int peopleSize,noLeafSize;
    cin >> peopleSize >> noLeafSize;
    vector<vector<int>> tree(peopleSize+1);
    for (int i = 0; i < noLeafSize; ++i)
    {
        int id;
        int childSize;
        cin >> id >> childSize;
        tree[id].resize(childSize);
        for (auto& value:tree[id])cin >> value;
    }
    int level = 1;
    int levelSize=1;
    queue<int> q;
    q.push(1);
    pair<int, int> levelAndItsSize{1,1};
    for (int i = 1; !q.empty(); ++i)
    {
        for (auto id : tree[q.front()])q.push(id);
        q.pop();
        if(i==levelSize)
        {
            i = 0;
            levelSize = q.size();
            level++;
            if (levelAndItsSize.second < levelSize)levelAndItsSize = { level,q.size() };
        }
    }
    cout << levelAndItsSize.second << " " << levelAndItsSize.first;
}
