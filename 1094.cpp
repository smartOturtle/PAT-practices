#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
    int N, nonLeafSize;
    cin >> N >> nonLeafSize;
    vector<vector<int>> pedegree(N);
    for (int i = 0; i < nonLeafSize; ++i)
    {
        int id,childrenSize;
        cin >> id >> childrenSize;
        pedegree[id - 1].resize(childrenSize);
        for (int j = 0; j < childrenSize; ++j)
        {
            cin>>pedegree[id - 1][j];
            pedegree[id - 1][j]--;
        }
    }
    queue<int> q;
    q.push(0);
    int layer = 1, last = 1;
    pair<int, int> maxSizeLayer = {1,1};
    for(int i=1;!q.empty();++i)
    {
        for (auto value : pedegree[q.front()])
        {
            q.push(value);
        }
        q.pop();
        if(i==last)
        {
            last = q.size();
            layer++;
            i = 0;
            if (last > maxSizeLayer.first)maxSizeLayer = { last,layer };
        }
    }
    cout << maxSizeLayer.first << " " << maxSizeLayer.second;
}
