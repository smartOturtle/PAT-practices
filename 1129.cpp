#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
using namespace std;

using Item = pair<int,int>;
struct Cmp
{
    bool operator()(Item lhs,Item rhs)const
    {
        if (lhs.second == rhs.second)return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    }
};
int main(int argc, char* argv[])
{
    int querySize, maxNum;
    cin >> querySize >> maxNum;
    int queryItemId;
    cin >> queryItemId;
    set<Item,Cmp> itemRank;
    unordered_map<int, decltype(itemRank)::iterator> itemPosMap{{queryItemId,itemRank.insert({ queryItemId,1 }) .first}};
    for (int i = 1; i < querySize; ++i)
    {
        cin >> queryItemId;
        cout << queryItemId << ":";
        int j = 1;
        for (auto item : itemRank)
        {
            if(j>maxNum)break;
            cout << " " << item.first;
            ++j;
        }
        int preFreq = 0;
        if(itemPosMap.find(queryItemId)!=itemPosMap.end())
        {
            preFreq = itemPosMap[queryItemId]->second;
            itemRank.erase(itemPosMap[queryItemId]);
        }
        itemPosMap[queryItemId] = itemRank.insert({ queryItemId,preFreq + 1 }).first;
        cout << '\n';
    }
}
