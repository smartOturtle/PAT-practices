#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;
unordered_map<char, string> digitStringMap
{
    { '0',"ling" },{ '1',"yi" },{ '2',"er" },{ '3',"san" },{ '4',"si" },{ '5',"wu" },
{ '6',"liu" },{ '7',"qi" },{ '8',"ba" },{ '9',"jiu" },
};
unordered_map<int, string> magnititudeStringMap
{
    { 1,"Shi" },{ 2,"Bai" },{ 3,"Qian" },{ 4,"Wan" },
{ 5,"Shi" },{ 6,"Bai" },{ 7,"Qian" },{ 8,"Yi" },
};
int main(int argc, char* argv[])
{
    string num;
    cin >> num;
    reverse(num.begin(), num.end());
    if (num.back() == '-')
    {
        cout << "Fu ";
        num.pop_back();
    }
    deque<string> s;
    bool hasSetWan = false;
    for (int i = 0; i < num.size(); ++i)
    {
        if (num[i] != '0')
        {
            if (i > 0 &&
                num[i - 1] == '0'&&
                any_of(num.begin(), num.begin() + (i - 1),
                    [](char c) { return c != '0'; }))
            {
                s.push_front(digitStringMap['0']);
            }
            if (magnititudeStringMap.find(i) != magnititudeStringMap.end())
            {
                if (i == 4)hasSetWan = true;
                else if (i>4 && i<8 && !hasSetWan)
                {
                    s.push_front(magnititudeStringMap[4]);
                    hasSetWan = true;
                }
                s.push_front(magnititudeStringMap[i]);
            }
            s.push_front(digitStringMap[num[i]]);
        }
    }
    if (s.empty())cout << digitStringMap['0'];
    else { cout << s.front(); }
    for (int i = 1; i < s.size(); ++i)
    {
        cout << " " << s[i];
    }
}
