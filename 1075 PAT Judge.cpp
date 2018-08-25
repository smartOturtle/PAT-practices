#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
struct User
{
    int userId;
    bool hasPassed=false;
    int perfectSize=0;
    int totalScore=0;
    vector<int> problems=vector<int>(5,-1);
    bool operator>(const User& rhs)const
    {
        if(totalScore==rhs.totalScore)
        {
            if (perfectSize == rhs.perfectSize)return userId < rhs.userId;
            return perfectSize > rhs.perfectSize;
        }
        return totalScore > rhs.totalScore;
    }
};
int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int userSize, problemSize, submisssionSize;
    cin >> userSize >> problemSize >> submisssionSize;
    vector<int> problems(problemSize);
    for (auto& value : problems)cin >> value;
    unordered_map<int, User> users;
    for (int i = 0; i < submisssionSize; ++i)
    {
        int userId, problemId, score;
        cin >> userId >> problemId >> score;
        auto& user= users[userId];
        user.userId = userId;
        if (score >= 0)user.hasPassed = true;
        user.problems[problemId - 1] = max({ user.problems[problemId - 1], score,0 });
    }
    for (auto& idUser : users)
    {
        auto& user = idUser.second;
        user.perfectSize = count_if(user.problems.begin(), user.problems.begin()+problemSize, 
            [&problems,i=0](int value)mutable  { return problems[i++] == value; });
        user.totalScore = accumulate(user.problems.begin(), user.problems.end(), 0,
            [](int lhs, int rhs) { return rhs == -1 ? lhs : lhs + rhs; });
    }
    vector<reference_wrapper<User>> sorted;
    for (auto& p : users)if(p.second.hasPassed)sorted.push_back(p.second);
    sort(sorted.begin(), sorted.end(), greater<User>());
    int preScore = -1, rank = 1, sameSize = 0;
    for (User& user : sorted)
    {
        if (user.totalScore != preScore)
        {
            rank += sameSize;
            sameSize = 1;
            preScore = user.totalScore;
        }
        else { sameSize++; }
        printf("%d %05d %d", rank, user.userId, user.totalScore);
        for (int i = 0; i < problemSize; ++i)
        {
            if (user.problems[i] != -1)printf(" %d", user.problems[i]);
            else { printf(" -"); }
        }
        printf("\n");
    }
}
