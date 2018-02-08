#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Name = char[5];
constexpr int maxSize = 26 * 26 * 26 * 10;
struct RegisterTable
{
  vector<vector<int>> students;
  RegisterTable():students(maxSize){}
  decltype(students)::value_type& operator[](const char* name)
  {
    int idx = (name[0] - 'A')*26;
    idx =(idx + (name[1] - 'A'))*26;
    idx = (idx + (name[2] - 'A')) * 10;
    idx += name[3] - '0';
    return students[idx];
  }
};
int main(int argc, char* argv[])
{
  int querySize, courseSize;
  cin >> querySize >> courseSize;
  RegisterTable registerTable;
  for (int i = 0; i < courseSize; ++i)
  {
    int courseId, studentSize;
    scanf("%d %d", &courseId, &studentSize);
    for (int j = 0; j < studentSize; ++j)
    {
      Name name;
      scanf("%s", name);
      registerTable[name].push_back(courseId);
    }
  }
  for (int i = 0; i < querySize; ++i)
  {
    Name name;
    scanf("%s", name);
    auto& courses = registerTable[name];
    printf("%s %d", name, courses.size());
    sort(courses.begin(), courses.end());
    for (auto && id : courses)
    {
      printf(" %d", id);
    }
    printf("\n");
  }
}
