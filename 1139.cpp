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

struct Person
{
    static bool IsMale(string id) { return id.front()=='-'; }
    bool isMale;
    unordered_map<bool, vector<string>> friendsByGender;
    unordered_set<string> friends;
    Person(){}
};
unordered_map<string, Person> people;
void Query(string lhsId,string rhsId)
{
    if (people.find(lhsId) == people.end() || people.find(rhsId) == people.end())
    {
        cout << "0\n";
        return;
    }
    auto& lhs = people[lhsId];
    auto& rhs = people[rhsId];
    vector<pair<string, string>> pairs;
    for (auto& lhsFriendId : lhs.friendsByGender[lhs.isMale])
    {
        if (lhsFriendId != rhsId&&lhsFriendId!=lhsId)
            for (auto& rhsFriendId : rhs.friendsByGender[rhs.isMale])
            {
                if (lhsFriendId!=rhsFriendId&&
                    rhsFriendId != lhsId &&rhsFriendId!=rhsId&&
                    people[lhsFriendId].friends.find(rhsFriendId) != people[lhsFriendId].friends.end())
                {
                    pairs.push_back({ lhsFriendId,rhsFriendId });
                }
            }
    }
    sort(pairs.begin(), pairs.end());
    cout << pairs.size()<<'\n';
    for (auto&& pair : pairs)
    {
        cout << pair.first << " " << pair.second << '\n';
    }
}
int main(int argc, char* argv[])
{
    int personSize, pairFriendSize;
    cin >> personSize >> pairFriendSize;
    for (int i = 0; i < pairFriendSize; ++i)
    {
        string lhsId, rhsId;
        cin >> lhsId >> rhsId;
        bool lhsIsMale = Person::IsMale(lhsId);
        bool rhsIsMale = Person::IsMale(rhsId);
        if (lhsId.front() == '-')lhsId = lhsId.substr(1);
        if (rhsId.front() == '-')rhsId = rhsId.substr(1);
        people[lhsId].isMale = lhsIsMale;
        people[rhsId].isMale= rhsIsMale;
        people[lhsId].friendsByGender[rhsIsMale].push_back(rhsId);
        people[lhsId].friends.insert(rhsId);
        people[rhsId].friendsByGender[lhsIsMale].push_back(lhsId);
        people[rhsId].friends.insert(lhsId);
    }
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        string lhsId, rhsId;
        cin >> lhsId >> rhsId;
        if (lhsId.front() == '-')lhsId = lhsId.substr(1);
        if (rhsId.front() == '-')rhsId = rhsId.substr(1);
        Query(lhsId, rhsId);
    }
}


