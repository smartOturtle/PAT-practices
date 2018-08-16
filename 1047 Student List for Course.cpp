#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
using Name = array<char, 5>;
int main(int argc, char* argv[])
{
	int studentSize, courseSize;
	cin >> studentSize >> courseSize;
	vector<vector<Name>> courses(courseSize);
	for (int i = 0; i < studentSize; ++i)
	{
		Name name;
		int size;
		scanf("%s %d", name.data(), &size);
		for (int j = 0; j < size; ++j)
		{
			int courseId;
			scanf("%d", &courseId);
			courses[courseId - 1].push_back(name);
		}
	}
	for (int i = 0; i < courses.size(); ++i)
	{
		sort(courses[i].begin(), courses[i].end());
		printf("%d %d\n", i + 1, courses[i].size());
		for (auto && name : courses[i])
		{
			printf("%s\n", name.data());
		}
	}
}
