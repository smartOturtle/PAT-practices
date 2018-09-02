#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_map>
#include <numeric>
using namespace std;

int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<int> a1(nums.begin(), nums.begin() + N / 2);
    vector<int> a2(nums.begin() + N / 2, nums.end());
    cout << a2.size() - a1.size() << " " << accumulate(a2.begin(), a2.end(), 0) - accumulate(a1.begin(), a1.end(), 0);
}
