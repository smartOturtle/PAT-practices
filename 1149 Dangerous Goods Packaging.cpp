#include<iostream>
#include<set>
#include<vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <unordered_set>
using namespace std;
template<typename C, typename T>
bool In(const T& key, const C& c) { return c.find(key) != c.end(); }
#define CONT_RANGE(c) c.begin(),c.end()
unordered_map<int, vector<int>> pairs;
int main()
{
    iostream::sync_with_stdio(false);
    int pairSize, listSize;
    cin >> pairSize >> listSize;
    for (int i = 0; i < pairSize; ++i)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;
        pairs[lhs].push_back(rhs);
        pairs[rhs].push_back(lhs);
    }
    for (int i = 0; i < listSize; ++i)
    {
        int length;
        cin >> length;
        unordered_set<int> goods;
        for (int j = 0; j < length; ++j)
        {
            int id;
            cin >> id;
            goods.insert(id);
        }
        for (auto id : goods)for (auto notIn : pairs[id]) { if (In(notIn, goods)){ cout << "No\n"; goto out; } }
        cout << "Yes\n";
        out:;
    }
}
