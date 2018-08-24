#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <functional>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    unordered_map<string, int> wordCounter;
    string s;
    getline(cin, s);
    string stringBuilder;
    for (auto c : s)
    {
        if (isalnum(c))stringBuilder.push_back(tolower(c));
        else if(!stringBuilder.empty())
        {
            wordCounter[stringBuilder]++;
            stringBuilder.clear();
        }
    }
    if (!stringBuilder.empty())
    {
        wordCounter[stringBuilder]++;
        stringBuilder.clear();
    }
    auto wordCount=*max_element(wordCounter.begin(), wordCounter.end(),
        [](auto lhs, auto rhs)
    {
        if (lhs.second == rhs.second)return lhs.first > rhs.first;
        return lhs.second < rhs.second;
    });
    cout << wordCount.first << " " << wordCount.second;
}
