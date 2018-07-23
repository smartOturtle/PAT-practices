#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;
unordered_map<int, array<int, 4>> students;
int main(int argc, char* argv[])
{
    int studentSize, querySize;
    cin >> studentSize >> querySize;
    for (int i = 0; i < studentSize; ++i)
    {
        int id, c, m, e;
        cin >> id >> c >> m >> e;
        students[id] = { (c + m + e) / 3,c,m,e };
    }
    for (int i = 0; i < 4; ++i)
    {
        array<vector<int>, 101> rankList;
        for (auto idScores : students) rankList[idScores.second[i]].push_back(idScores.first);
        accumulate(rankList.rbegin(), rankList.rend(), 1, [&](int rank, vector<int>& group)
        {
            for (auto id : group)students[id][i] = rank;
            return rank + group.size();
        });
    }
    for (int i = 0; i < querySize; ++i)
    {
        int id;
        cin >> id;
        if(students.find(id)!=students.end())
        {
            auto best = min_element(students[id].begin(), students[id].end());
            cout << *best <<' '<< "ACME"[best - students[id].begin()]<<'\n';
        }
        else { cout << "N/A\n"; }
    }
}
