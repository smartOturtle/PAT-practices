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
bool IsCollide(pair<int,int> lhs,pair<int,int> rhs)
{
    if (lhs.first == rhs.first || lhs.second == rhs.second)return true;
    if (abs(lhs.first - rhs.first) ==abs (lhs.second - rhs.second))return true;
    return false;
}
int main(int argc, char* argv[])
{
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        int queenSize;
        cin >> queenSize;
        vector<pair<int, int>> nQueenPos;
        for (int j = 1; j <= queenSize; ++j)
        {
            int rowIdx;
            cin >> rowIdx;
            nQueenPos.push_back({ j,rowIdx });
        }
        bool hasCollide = false;
        for (int j = 0; j < queenSize; ++j)
        {
            for (int k = j+1; k < queenSize; ++k)
            {
                hasCollide = IsCollide(nQueenPos[j], nQueenPos[k]);
                if(hasCollide){goto out;}
            }
        }
        out:
        if (hasCollide)cout << "NO\n";
        else { cout << "YES\n"; }
    }
}


