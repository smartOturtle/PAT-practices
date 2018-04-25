#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
    int coupleSize;
    cin >> coupleSize;
    map<string, string> couples;
    for (int i = 0; i < coupleSize; ++i)
    {
        string a, b;
        cin >> a >> b;
        couples[a] = b;
        couples[b] = a;
    }
    int partyPeopleSize;
    cin >> partyPeopleSize;
    set<string> people;
    for (int i = 0; i < partyPeopleSize; ++i)
    {
        string id;
        cin >> id;
        people.insert(id);
    }
    vector<string> singles;
    for (auto id : people)
    {
        if (couples.find(id) == couples.end() || people.find(couples[id]) == people.end())
            singles.push_back(id);
    }
    cout << singles.size() << "\n";
    if (!singles.empty())cout << singles.front();
    for (int i = 1; i < singles.size(); ++i)
    {
        cout << " " << singles[i];
    }
}

