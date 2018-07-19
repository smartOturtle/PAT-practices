#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFindSet
{
    unordered_map<int,int> container;
    UnionFindSet(int size,int except)
    {
        for (int i = 1; i <= size; ++i)if (i != except)container[i] = -1;
    }
    int Find(int idx)
    {
        if (container[idx] < 0)return idx;
        return container[idx] = Find(container[idx]);
    }
    void Union(int lhs,int rhs)
    {
        int lhsRoot = Find(lhs);
        int rhsRoot = Find(rhs);
        if(lhsRoot!=rhsRoot)
        {
            if (lhsRoot < rhsRoot)swap(lhsRoot, rhsRoot);
            container[rhsRoot] += container[lhsRoot];
            container[lhsRoot] = rhsRoot;
        }
    }
};
int main(int argc, char* argv[])
{
    istream::sync_with_stdio(false);
    int citySize, roadSize, checkSize;
    cin >> citySize >> roadSize >> checkSize;
    vector<pair<int, int>> edges(roadSize);
    for (auto& edge : edges)cin >> edge.first >> edge.second;
    for (int i = 0; i < checkSize; ++i)
    {
        int except;
        cin >> except;
        UnionFindSet ufset(citySize, except);
        for (auto edge : edges)if (edge.first != except && edge.second != except)ufset.Union(edge.first, edge.second);
        cout << count_if(ufset.container.begin(), ufset.container.end(), [](pair<int, int> item) { return item.second < 0; })-1<<'\n';
    }
}
