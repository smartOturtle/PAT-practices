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
    int N;
    cin >> N;
    vector<int> ropes(N);
    for (auto && rope : ropes)
    {
        cin >> rope;
    }
    sort(ropes.begin(), ropes.end());
    int totalLength = ropes.front();
    for (int i = 1; i < ropes.size(); ++i)
    {
        totalLength += ropes[i];
        totalLength /= 2;
    }
    cout << totalLength;
}
