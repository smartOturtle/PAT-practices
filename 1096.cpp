#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> Test(int num,int begin)
{
    vector<int> temp;
    for (int i = begin; num != 1; ++i)
    {
        if (num%i==0)
        {
            num /= i;
            temp.push_back(i);
        }
        else break;
    }
    return temp;
}
int main(int argc, char* argv[])
{
    int num;
    cin >> num;
    vector<int> factors;
    for (int i = 2; i <= sqrt(num); ++i)
    {
        auto temp = Test(num, i);
        if (temp.size() > factors.size())swap(temp, factors);
    }
    if (factors.empty())
    {
        cout << 1 << '\n';
        cout << num;
    }
    else
    {
        cout << factors.size() << '\n';
        cout << factors.front();
        for (int i = 1; i < factors.size(); ++i)
        {
            cout << "*" << factors[i];
        }
    }
}
