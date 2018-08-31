#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <stack>
using namespace std;

int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    vector<int> seq(size);
    for (auto& value : seq)cin >> value;
    auto sorted = seq;
    sort(sorted.begin(), sorted.end());
    vector<int> candidates;
    int leftMax = seq.front();
    for (int i = 0; i < size; ++i)
    {
        leftMax = max(leftMax, seq[i]);
        if (leftMax<=sorted[i]&&sorted[i]==seq[i])candidates.push_back(sorted[i]);
    }
    sort(candidates.begin(), candidates.end());
    cout << candidates.size() << '\n';
    if (!candidates.empty())cout << candidates.front();
    for (int i = 1; i < candidates.size(); ++i)
    {
        cout << ' ' << candidates[i];
    }
    cout << '\n';
}
