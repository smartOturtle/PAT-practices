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
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
    int forwardSize, skipNum, firstWinnerIdx;
    cin >> forwardSize >> skipNum >> firstWinnerIdx;
    unordered_set<string> hasGets;
    vector<string> names;
    for (int i =0; i <forwardSize ; ++i)
    {
        string s;
        cin >> s;
        names.push_back(s);
    }
    int i = 1;
    for (auto && name : names)
    {
        if(hasGets.find(name)!=hasGets.end())continue;
        if(i>=firstWinnerIdx&&(i-firstWinnerIdx)%skipNum==0)
        {
            cout << name << '\n';
            hasGets.insert(name);
        }
        ++i;
    }
    if (hasGets.empty())cout << "Keep going...\n";
}


