#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

int main(int argc, char* argv[])
{
    int numSize;
    cin >> numSize;
    for (int i = 0; i < numSize; ++i)
    {
        string s;
        cin >> s;
        int numA = stoi(s.substr(0, s.size() / 2));
        int numB = stoi(s.substr(s.size() / 2));
        int num = stoi(s);
        if (numA == 0 || numB == 0)cout << "No";
        else if (num % (numA * numB) == 0)cout << "Yes";
        else { cout << "No"; }
        cout << '\n';
    }
}
