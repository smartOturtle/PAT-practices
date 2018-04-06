#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <array>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
    long long cnt = 0;
    string s;
    cin >> s;
    int pCnt=0,tCnt= count(s.begin(), s.end(), 'T');
    for (auto value : s)
    {
        if (value == 'P')pCnt++;
        else if (value == 'A')cnt += pCnt * tCnt;
        else if (value == 'T')tCnt--;
    }
    cout << cnt% 1000000007;
}
