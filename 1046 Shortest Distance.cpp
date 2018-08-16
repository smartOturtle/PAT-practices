#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int size;
    cin >> size;
    vector<int> cycle(size);
    for (auto& value : cycle)cin >> value;
    auto cycleLength = accumulate(cycle.begin(), cycle.end(), 0);
    for_each(cycle.begin(), cycle.end(),
        [previous = 0](int& value)mutable  {swap(previous, value); previous += value; });
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        int first, last;
        cin >> first >> last;
        tie(first, last) = minmax(first-1, last-1);
        cout << min(cycle[last] - cycle[first], cycleLength - cycle[last] + cycle[first])<<'\n';
    }
}
