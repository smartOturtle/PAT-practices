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
    string given,need;
    cin >> given >> need;
    unordered_map<char, int> charCnts;
    for (auto value : given)
    {
        charCnts[value]++;
    }
    int lackSize = need.size();
    for (auto value : need)
    {
        if (charCnts[value]>0)
        {
            lackSize--;
            charCnts[value]--;
        }
    }
    if (lackSize == 0)cout << "Yes " << given.size() - need.size();
    else { cout << "No " << lackSize; }
}
