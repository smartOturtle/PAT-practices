#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int size;
    cin >> size;
    vector<int> nums(size);
    unordered_map<int, int> counter;
    for (auto& n : nums)
    {
        cin >> n;
        counter[n]++;
    }
    auto pos= find_if(nums.begin(), nums.end(), [&](int num) { return counter[num] == 1; });
    if (pos != nums.end())cout << *pos;
    else cout << "None";
}
