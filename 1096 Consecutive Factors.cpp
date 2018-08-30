#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> factors;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        int temp = n;
        vector<int> tempFactors;
        for (int j = i; j <= sqrt(n); ++j)
        {
            if (temp%j == 0)
            {
                temp /= j;
                tempFactors.push_back(j);
            }
            else break;
        }
        if (tempFactors.size() > factors.size())swap(tempFactors, factors);
    }
    if (factors.empty())factors.push_back(n);
    cout << factors.size() << "\n";
    cout << factors.front();
    for (int i = 1; i < factors.size(); ++i)
    {
        cout << '*' << factors[i];
    }
}

