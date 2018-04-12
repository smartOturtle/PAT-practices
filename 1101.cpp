#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <map>
#include <algorithm>
using namespace std;
//every partition point's idx is the eventual 
//it's front elements must less equal than it
//equivalent to it is greater equal than the maximum among previous elements 
//BTW,the STL's algorithm is_partitioned is used to test 
//whether we can partition the range by the given unary predicate 
int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    vector<int> init(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> init[i];
    }
    auto sorted = init;
    sort(sorted.begin(), sorted.end());
    int leftMax = 0;
    vector<int> candidates;
    for (int i = 0; i < init.size(); ++i)
    {
        if(init[i]==sorted[i]&&init[i]>=leftMax)
        {
            candidates.push_back(init[i]);
        }
        leftMax = max(leftMax, init[i]);
    }
    sort(candidates.begin(), candidates.end());
    cout << candidates.size()<<'\n';
    if (!candidates.empty())cout << candidates.front();
    for (int i = 1; i < candidates.size(); ++i)
    {
        cout << ' ' << candidates[i];
    }
    cout << '\n';
}
