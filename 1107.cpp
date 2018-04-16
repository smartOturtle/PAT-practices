#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <functional>
using namespace std;
vector<int> clusters(1001);
//0 as nonlegeal
int Find(int idx)
{
    if (clusters[idx] <=0)return idx;
    return clusters[idx] = Find(clusters[idx]);
}
bool Union(int lhs,int rhs)
{
    auto lhsRoot = Find(lhs);
    auto rhsRoot = Find(rhs);
    if (lhsRoot == rhsRoot)return false;
    if (clusters[lhsRoot] > clusters[rhsRoot])swap(lhsRoot, rhsRoot);
    clusters[lhsRoot] += clusters[rhsRoot];
    clusters[rhsRoot] = lhsRoot;
    return true;
}
int main(int argc, char* argv[])
{
    int peopleSize;
    cin >> peopleSize;
    for (int i = 0; i < peopleSize; ++i)
    {
        int hobitSize;
        scanf("%d:", &hobitSize);
        vector<int> hobits(hobitSize);
        for (auto&& hobitIdx : hobits)
        {
            cin >> hobitIdx;
        }
        for (int j = 1; j < hobits.size(); ++j)
        {
            Union(hobits.front(), hobits[j]);
        }
        clusters[Find(hobits.front())]--;
    }
    vector<int> clustersSize;
    for (auto cluster : clusters)
    {
        if (cluster < 0)clustersSize.push_back(-cluster);
    }
    sort(clustersSize.begin(), clustersSize.end(), greater<int>());
    cout << clustersSize.size()<<'\n';
    cout << clustersSize.front();
    for (int i = 1; i < clustersSize.size(); ++i)
    {
        cout << " " << clustersSize[i];
    }
}

