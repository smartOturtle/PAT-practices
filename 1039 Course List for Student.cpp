#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <numeric>
using namespace std;
using Name = array<char, 5>;
vector<vector<int>> students(26*26*26*10);
int ToIdx(const Name& name)
{
    auto result= accumulate(name.begin(), name.end()-2, 0, [](int result, char c) { return result * 26 + c-'A'; });
    return result * 10 + name[3] - '0';
}
int main(int argc, char* argv[])
{
    int querySize, courseSize;
    cin >> querySize >> courseSize;
    for (int i = 0; i < courseSize; ++i)
    {
        int courseID, studentSize;
        cin >> courseID >> studentSize;
        for (int j = 0; j < studentSize; ++j)
        {
            Name name;
            scanf("%s",name.data());
            students[ToIdx(name)].push_back(courseID);
        }
    }
    for (int i = 0; i < querySize; ++i)
    {
        Name name;
        scanf("%s", name.data());
        auto idx = ToIdx(name);
        printf("%s %d", name.data(), students[idx].size());
        sort(students[idx].begin(), students[idx].end());
        for (auto id : students[idx])printf(" %d",id);
        printf("\n");
    }
}

