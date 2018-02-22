#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
using Name = array<char, 9>;
struct Person
{
	int age;
	int money;
	Name name;
	bool operator <(const Person& person)
	{
		if (money == person.money)
		{
			if(age==person.age)return name < person.name;
			return age < person.age;
		}
		return money > person.money;
	}
	Person(Name name,int money,int age):name(name),money(money),age(age)
	{}
};
int main(int argc, char* argv[])
{
	int peopleSize, querySize;
	cin >> peopleSize >> querySize;
	vector<Person> people;
	for (int i = 0; i < peopleSize; ++i)
	{
		Name name;
		int age, money;
		scanf("%s %d %d", name.data(), &age, &money);
		people.emplace_back( name,money,age );
	}
	sort(people.begin(), people.end());
	for (int i = 0; i < querySize; ++i)
	{
		int size;
		pair<int, int> ageRange;
		scanf("%d %d %d", &size, &ageRange.first, &ageRange.second);
		printf("Case #%d:\n", i + 1);
		int alreadyOutputSize=0;
		for (auto && person : people)
		{
			if(person.age>=ageRange.first&&person.age<=ageRange.second)
			{
				printf("%s %d %d\n", person.name.data(), person.age, person.money);
				alreadyOutputSize++;
			}
			if(alreadyOutputSize>=size)break;
		}
		if (alreadyOutputSize == 0)printf("None\n");
	}
}
