#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;
struct Person
{
	int id;
	char name[9];
	int score;
	Person(int id,char* name,int score):
		id(id), score(score)
	{
		strcpy(this->name, name);
	}
	void Print()
	{
		printf("%06d %s %d\n", id, name, score);
	}
};

int main()
{	
	using Pred = function<bool(const Person&,const Person&)>;
	vector<Pred> predicates
	{
		[](const Person& a,const Person& b) { return a.id < b.id; },
		[](const Person& a,const Person& b)
		{
			if (strcmp(a.name,b.name)==0)return a.id < b.id;
			return strcmp(a.name,b.name)<0;
		},
		[](const Person& a,const Person& b)
		{
			if (a.score == b.score)return a.id < b.id;
			return a.score < b.score;
		},
	};
	int size, orderby;
	scanf("%d %d", &size, &orderby);
	vector<Person> people;
	people.reserve(size);
	int id;
	int score;
	for (int i = 0; i < size; ++i)
	{
		char name[9];
		scanf("%d %s %d", &id, &name, &score);
		people.emplace_back(id, name, score);
	}
	sort(people.begin(), people.end(), predicates[orderby - 1]);
	for (auto && person : people)
		person.Print();
}
