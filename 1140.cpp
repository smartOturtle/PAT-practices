#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    string s;
    int N;
    cin >> s >> N;
    for (int i = 0; i < N-1; ++i)
    {
        string temp;
        char c = s.front();
        int cCnt = 1;
        for (int j = 1; j < s.size(); ++j)
        {
            if (s[j] == c) { cCnt++; }
            else
            {
                temp.push_back(c);
                temp += to_string(cCnt);
                c = s[j];
                cCnt = 1;
            }
        }
        temp.push_back(c);
        temp += to_string(cCnt);
        swap(s, temp);
    }
    cout << s;
}

