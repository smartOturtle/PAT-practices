#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;

struct Student
{
	string name;
	string id;
	int grade;
	Student(string name,string id,int grade):
	name(name),id(id),grade(grade)
	{
		
	}
};
int main(int argc, char* argv[])
{
	int N;
	cin >> N;
	vector<Student> students;
	for (int i = 0; i < N; ++i)
	{
		string name;
		string id;
		int grade;
		cin >> name >> id >> grade;
		students.emplace_back(name, id, grade);
	}
	pair<int, int> range;
	cin >> range.first >> range.second;
	students.erase(remove_if(students.begin(),students.end(),
		[range](const Student& student)
		{return student.grade<range.first || student.grade>range.second;}),
		students.end());
	if (students.empty()){ cout << "NONE"; }
	else
	{
		sort(students.begin(), students.end(), 
			[](const Student& lhs, const Student& rhs)
			{return lhs.grade > rhs.grade;});
		for (auto && student : students)
		{
			cout << student.name << " " << student.id<<'\n';
		}
	}
}
