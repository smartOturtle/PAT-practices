#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
vector<int> nodeWeights;
vector<vector<int>> tree;
vector<vector<int>> paths;
int nodeSize, noLeafSize, givenWeight;
void DFS(int idx,int totalWeight)
{
    static vector<int> path;
    path.push_back(nodeWeights[idx]);
    for (auto childIdx : tree[idx])
    {
        DFS(childIdx, totalWeight + nodeWeights[idx]);
    }
    if(tree[idx].empty()&&totalWeight+nodeWeights[idx]==givenWeight)
    {
        paths.push_back(path);
    }
    path.pop_back();
}
int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    cin >> nodeSize >> noLeafSize >> givenWeight;
    nodeWeights.resize(nodeSize);
    tree.resize(nodeSize);
    for (auto&weight : nodeWeights)cin >> weight;
    for (int i = 0; i < noLeafSize; ++i)
    {
        int nodeIdx,childSize;
        cin >> nodeIdx>>childSize;
        tree[nodeIdx].resize(childSize);
        for (auto&childIdx : tree[nodeIdx])cin >> childIdx;
    }
    DFS(0, 0);
    sort(paths.begin(), paths.end(), greater<vector<int>>());
    for (auto && path : paths)
    {
        cout << path.front();
        for (int i = 1; i < path.size(); ++i)
        {
            cout <<" "<< path[i];
        }
        cout << '\n';
    }
}
