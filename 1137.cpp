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

struct Student
{
    int onlineScore = -1;
    int midScore = -1;
    int finalScore = -1;
    int totalScore = -2;
    int TotalScore()
    {
        if (totalScore != -2)return totalScore;
        if (onlineScore < 200)return totalScore= -1;
        int score = 0;
        if (finalScore > midScore)score = finalScore;
        else { score = round(0.4*midScore + 0.6*finalScore); }
        return totalScore= score;
    }
    void Print()
    {
        cout << onlineScore << " " << midScore << " " << finalScore << " " << TotalScore() << '\n';
    }
};
int main(int argc, char* argv[])
{
    int onlineJudgeSize, midTestSize, finalTestSize;
    cin >> onlineJudgeSize >> midTestSize >> finalTestSize;
    unordered_map<string, Student> idStudentMap;
    for (int i = 0; i < onlineJudgeSize; ++i)
    {
        string id;
        int score;
        cin >> id >> score;
        idStudentMap[id].onlineScore = score;
    }
    for (int i = 0; i < midTestSize; ++i)
    {
        string id;
        int score;
        cin >> id >> score;
        idStudentMap[id].midScore = score;
    }
    for (int i = 0; i < finalTestSize; ++i)
    {
        string id;
        int score;
        cin >> id >> score;
        idStudentMap[id].finalScore = score;
    }
    vector<pair<const string,Student>*> idStudents;
    for (auto && idStudent : idStudentMap)
    {
        if(idStudent.second.TotalScore()>=60)idStudents.push_back(&idStudent);
    }
    sort(idStudents.begin(), idStudents.end(), 
        [](decltype(idStudents)::value_type lhs,decltype(idStudents)::value_type rhs)
    {
        if (lhs->second.TotalScore() == rhs->second.TotalScore())return lhs->first < rhs->first;
        return lhs->second.TotalScore() > rhs->second.TotalScore();
    });
    for (auto idStudent : idStudents)
    {
        cout << idStudent->first << " ";
        idStudent->second.Print();
    }
}

