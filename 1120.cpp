#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
    set<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        nums.insert(sum);
    }
    cout << nums.size()<<'\n';
    cout << *nums.begin();
    for (auto i = ++nums.begin(); i != nums.end(); ++i)cout << " " << *i;
}

