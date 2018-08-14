#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int main(int argc, char* argv[])
{
    string s;
    getline(cin, s);
    int maxLength = 1;
    for (int i = 0; i < s.size() -1; ++i)
    {
        maxLength = max<int>(maxLength, (mismatch(s.begin() + i, s.end(), s.rend() - i - 1, s.rend()).first - (s.begin() + i)) * 2-1);
    }
    for (int i = 0; i < s.size() - 1; ++i)
    {
        maxLength = max<int>(maxLength, (mismatch(s.begin() + i, s.end(), s.rend() - i, s.rend()).first - (s.begin() + i)) * 2);
    }
    cout << maxLength;
}
