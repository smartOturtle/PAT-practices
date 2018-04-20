#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_map>
using namespace std;

int main(int argc, char* argv[])
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    unordered_map<char, bool> stuckedKeys;
    vector<decltype(stuckedKeys)::iterator> detectedOrder;
    for (int i = 0; i < s.size(); )
    {
        int j = i+1;
        if (stuckedKeys.find(s[i]) == stuckedKeys.end() || stuckedKeys[s[i]])
        {
            for (; j < s.size(); ++j)if (s[j] != s[i])break;
            if (((j - i) % k) != 0)stuckedKeys[s[i]] = false;
            else if (stuckedKeys.find(s[i]) == stuckedKeys.end())
            {
                detectedOrder.push_back(stuckedKeys.insert({ s[i],true }).first);
            }
        }
        i = j;
    }
    detectedOrder.erase(remove_if(detectedOrder.begin(), detectedOrder.end(),
        [](decltype(detectedOrder)::value_type value) { return value->second != true; }),detectedOrder.end());
    for (auto iter : detectedOrder)
    {
        cout << iter->first;
    }
    cout << '\n';
    for (int i = 0; i < s.size(); ++i)
    {
        cout << s[i];
        if (stuckedKeys[s[i]])i = i + k-1;
    }
}
