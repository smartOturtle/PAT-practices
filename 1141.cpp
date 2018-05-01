#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
string ToLower(string s)
{
    for (auto && c : s)
    {
        c = tolower(c);
    }
    return s;
}
int main(int argc, char* argv[])
{
    int testeeSize;
    cin >> testeeSize;
    unordered_map<string, pair<double,int>> institutions;
    for (int i = 0; i < testeeSize; ++i)
    {
        string id;
        int score;
        string school;
        cin >> id >> score >> school;
        institutions[ToLower(school)].second++;
        switch (id.front())
        {
        case 'A':
            institutions[ToLower(school)].first += score;
            break;
        case 'B':
            institutions[ToLower(school)].first += score/1.5;
            break;
        case 'T':
            institutions[ToLower(school)].first += 1.5*score;
            break;
        }
    }
    using WeightSize = pair<int, int>;
    using Ins = pair<string, WeightSize>;
    vector<Ins> rankList;
    for (auto && institution : institutions)
        rankList.push_back(institution);
    sort(rankList.begin(), rankList.end(),
        [](const Ins& lhs, const Ins& rhs)
    {
        if(lhs.second.first==rhs.second.first)
        {
            if (lhs.second.second == rhs.second.second)
                return lhs.first < rhs.first;
            return lhs.second.second < rhs.second.second;
        }
        return lhs.second.first > rhs.second.first;
    });
    cout << rankList.size()<<'\n';
    int rank=1, sameSocreSize=0, preScore=-1;
    for (auto && institution : rankList)
    {
        if (institution.second.first == preScore)sameSocreSize++;
        else
        {
            rank += sameSocreSize;
            sameSocreSize = 1;
            preScore = institution.second.first;
        }
        cout << rank << " " << institution.first << " " << institution.second.first << " "<< institution.second.second<<'\n';
    }
}

