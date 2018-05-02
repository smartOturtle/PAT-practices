#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    vector<long long> list;
    for (int i = 0; i < size; ++i)
    {
        long long value;
        cin >> value;
        if(value>0)list.push_back(value);
    }
    if (list.empty())
    {
        cout << 1;
        return 0;
    }
    sort(list.begin(), list.end());
    auto prev = list.front();
    for (int i = 1; i < list.size(); ++i)
    {
        if (list[i] > prev + 1)
        {
            cout << prev + 1;
            return 0;
        }
        prev = list[i];
    }
    cout << list.back() + 1;
}
