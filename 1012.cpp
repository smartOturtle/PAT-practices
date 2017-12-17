#include<iostream>
#include <list>
#include <array>
#include <unordered_map>
#include <functional>
using namespace std;
enum class Subject:char { A, C, M, E };
ostream& operator<<(ostream& os, Subject c)
{
  switch (c)
  {
  case Subject::A: os << "A"; break;
  case Subject::C: os << "C"; break;
  case Subject::M: os << "M"; break;
  case Subject::E: os << "E"; break;
  default: os.setstate(ios_base::failbit);
  }
  return os;
}
//first is grade,second is rank
using Grades = array<pair<int, int>, 4>;
unordered_map<int, Grades> students;
void Input()
{
  int id, c, m, e;
  cin >> id >> c >> m >> e;
  auto a = (c + m + e) / 3;
  students.insert({ id,Grades{ pair<int,int>{a,-1},{ c,-1 },{ m,-1 },{ e,-1 } } });
}
void Process()
{
  array<array<list<int>,101>, 4> rankLists;
  for (auto && student : students)
    for (int i = 0; i < rankLists.size(); ++i)
    {
      auto grade = student.second[i].first;
      rankLists[i][grade].push_back(student.first);
    }
  for (int i = 0; i < rankLists.size(); ++i)//the ith type grade
  {
    int rank = 1;
    for (int grade = rankLists[i].size() - 1; grade >= 0; --grade)
    {
      auto& bucket = rankLists[i][grade];
      for (auto id : bucket)
        students[id][i].second = rank;
      rank += bucket.size();
    }
  }
}
void Query(int id)
{
  auto pos = students.find(id);
  if (pos == students.end())cout << "N/A\n";
  else
  {
    auto& grades = pos->second;
    pair<int, int> result{ INT16_MAX,-1 };
    for (int i = 0; i < grades.size(); ++i)
      if (grades[i].second < result.first)result = { grades[i].second ,i };
    cout << result.first << " " << Subject(result.second) << '\n';
  }
}
int main()
{
  int studentSize, querySize;
  cin >> studentSize >> querySize;
  for (int i = 0; i < studentSize; ++i) Input();
  Process();
  for (int i = 0; i < querySize; ++i)
  {
    int id;
    cin >> id;
    Query(id);
  }
}
