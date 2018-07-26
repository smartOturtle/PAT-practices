#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <array>
#include <numeric>
using namespace std;

struct Testee
{
    string id;
    int score;
    int location;
    int locationRank;
    int finalRank;
};
int main(int argc, char* argv[])
{
    int locationSize;
    cin >> locationSize;
    map<string, Testee> testees;
    for (int i = 0; i < locationSize; ++i)
    {
        int testeeSize;
        cin >> testeeSize;
        array<vector<string>, 101> scoreGroup;
        for (int j = 0; j < testeeSize; ++j)
        {
            string id;
            int score;
            cin >> id >> score;
            scoreGroup[score].push_back(id);
            testees[id].score = score;
            testees[id].location = i + 1;
        }
        accumulate(scoreGroup.rbegin(), scoreGroup.rend(), 1, [&](int rank, const vector<string>& group)
        {
            for (auto& id : group)testees[id].locationRank = rank;
            return rank + group.size();
        });
    }
    cout << testees.size() << "\n";
    array<vector<string>, 101> scoreGroup;
    for (auto& idTestee : testees)scoreGroup[idTestee.second.score].push_back(idTestee.first);
    accumulate(scoreGroup.rbegin(), scoreGroup.rend(), 1, [&](int rank, const vector<string>& group)
    {
        for (auto& id : group)testees[id].finalRank = rank;
        return rank + group.size();
    });
    for (auto groupIter = scoreGroup.rbegin(); groupIter != scoreGroup.rend(); ++groupIter)
        for (auto && id : *groupIter)
        {
            auto& testee = testees[id];
            cout << id << ' ' <<testee.finalRank << ' ' << testee.location << ' ' << testee.locationRank << '\n';
        }
}
