#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;

struct Bird
{
    int rootIdx = -1;
    Bird(){}
};
unordered_map<int, Bird> birds;
int Find(int idx)
{
    if (birds[idx].rootIdx < 0)return idx;
    return birds[idx].rootIdx = Find(birds[idx].rootIdx);
}
void Union(int lhs,int rhs)
{
    auto lhsRoot = Find(lhs);
    auto rhsRoot = Find(rhs);
    if(lhsRoot==rhsRoot)return;
    if (birds[lhsRoot].rootIdx < birds[rhsRoot].rootIdx)swap(lhsRoot, rhsRoot);
    birds[rhsRoot].rootIdx += birds[lhsRoot].rootIdx;
    birds[lhsRoot].rootIdx = rhsRoot;
}
int main(int argc, char* argv[])
{
    int picSize;
    cin >> picSize;
    for (int i = 0; i < picSize; ++i)
    {
        int birdSize;
        cin >> birdSize;
        int firstBirdId;
        cin >> firstBirdId;
        birds[firstBirdId];
        for (int j = 1; j < birdSize; ++j)
        {
            int birdId;
            cin >> birdId;
            Union(firstBirdId, birdId);
        }
    }
    int treeSize= count_if(birds.begin(), birds.end(), [](pair<int, Bird> value) { return value.second.rootIdx < 0; });
    cout << treeSize << " " << birds.size() << '\n';
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        pair<int, int> pair;
        cin >> pair.first >> pair.second;
        if (Find(pair.first) == Find(pair.second))cout << "Yes\n";
        else { cout << "No\n"; }
    }
}

