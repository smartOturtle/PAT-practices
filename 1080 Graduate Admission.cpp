#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;
struct Student
{
    int id;
    pair<int, int> finalAndExam;
    vector<int> choices;
    bool operator>(const Student& rhs)const { return finalAndExam > rhs.finalAndExam; }
    bool operator==(const Student& rhs)const { return finalAndExam == rhs.finalAndExam; }
};
int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int studentSize, schoolSize, choiceSize;
    cin >> studentSize >> schoolSize >> choiceSize;
    vector<Student> students(studentSize);
    vector<vector<int>> schools(schoolSize);
    vector<int> schoolQuotas(schoolSize);
    for (auto& quota : schoolQuotas)cin >> quota;
    for (int studentID = 0; studentID<studentSize; ++studentID)
    {
        auto& student = students[studentID];
        student.id = studentID;
        int exam, interview;
        cin >> exam >> interview;
        student.finalAndExam = { (exam + interview) / 2,exam };
        student.choices.resize(choiceSize);
        for (auto& schoolID : student.choices)cin >> schoolID;
    }
    sort(students.begin(), students.end(), greater<Student>());
    vector<vector<reference_wrapper<Student>>> groupingByRank;
    groupingByRank.push_back({ students.front() });
    for (int i = 1; i < students.size(); ++i)
    {
        if (students[i] == groupingByRank.back().back())groupingByRank.back().push_back(students[i]);
        else groupingByRank.push_back({ students[i] });
    }
    for (auto && group : groupingByRank)
    {
        unordered_map<int, bool> ignoreQuota;
        for (Student& student : group)
        {
            for (auto id : student.choices)
            {
                if (schools[id].size() < schoolQuotas[id] || ignoreQuota[id])
                {
                    schools[id].push_back(student.id);
                    ignoreQuota[id] = true;
                    break;
                }
            }
        }
    }
    for (auto& school : schools)
    {
        if (!school.empty())
        {
            sort(school.begin(), school.end());
            cout << school.front();
            for (int i = 1; i < school.size(); ++i)
            {
                cout << " " << school[i];
            }
        }
        cout << '\n';
    }
}
