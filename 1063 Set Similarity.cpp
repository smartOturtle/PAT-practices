#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include <unordered_set>
using namespace std;


int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int setSize;
    cin >> setSize;
    vector<unordered_set<int>> sets(setSize);
    for (auto && s : sets)
    {
        int elementSize;
        cin >> elementSize;
        for (int i = 0; i < elementSize; ++i)
        {
            int value;
            cin >> value;
            s.insert(value);
        }
    }
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;
        lhs--, rhs--;
        int commonSize = accumulate(sets[lhs].begin(), sets[lhs].end(), 0,
            [&](int size, int value)
        {
            if (sets[rhs].find(value) != sets[rhs].end())++size;
            return size;
        });
        printf("%.1lf%%\n", 100.0*commonSize / (sets[lhs].size() + sets[rhs].size() - commonSize));
    }
}

