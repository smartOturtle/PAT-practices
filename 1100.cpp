#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

vector<string> lowerDigitNumbers = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov",  "dec"};
vector<string> higherDigitNumbers = { "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
int main(int argc, char* argv[])
{
    int numSize;
    cin >> numSize;
    getchar();
    for (int i = 0; i < numSize; ++i)
    {
        string num;
        getline(cin, num);
        if (isdigit(num.front()))
        {
            int earthValue = stoi(num);
            int higher = earthValue / 13;
            int lower = earthValue % 13;
            if (higher != 0)
            {
                printf("%s", higherDigitNumbers[higher - 1].c_str());
                if (lower != 0)cout << ' '<< lowerDigitNumbers[lower];
            }
            else cout << lowerDigitNumbers[lower];
        }
        else
        {
            stringstream ss;
            ss << num;
            pair<string,string> digits;
            ss >> digits.first;
            if (!ss.eof())ss >> digits.second;
            int higher = 0, lower = 0;
            auto higherPos = find(higherDigitNumbers.begin(), higherDigitNumbers.end(), digits.first);
            if (higherPos != higherDigitNumbers.end())
            {
                higher = higherPos - higherDigitNumbers.begin() + 1;
                if (!digits.second.empty())
                    lower = find(lowerDigitNumbers.begin(), lowerDigitNumbers.end(), digits.second) - lowerDigitNumbers.begin();
            }
            else
            {
                lower = find(lowerDigitNumbers.begin(), lowerDigitNumbers.end(), digits.first) - lowerDigitNumbers.begin();
            }
            cout << higher * 13 + lower;
        }
        cout << '\n';
    }
}
