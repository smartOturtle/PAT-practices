#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
bool Cmp(const string& lhs,const string& rhs)
{
    if (lhs.size() == rhs.size())return lhs < rhs;
    return lhs + rhs < rhs + lhs;
}
int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    vector<string> nums(size);
    for (auto& num : nums)cin >> num;
    sort(nums.begin(), nums.end(),&Cmp);
    auto s=accumulate(nums.begin(), nums.end(),""s);
    auto firstNotZero = s.find_first_not_of('0');
    cout<<s.substr(firstNotZero==string::npos?s.size()-1:firstNotZero);
}
