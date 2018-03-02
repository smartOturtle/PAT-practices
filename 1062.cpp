#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int peopleSize, lowerBound, higherLine;
struct Person
{
	enum Type
	{
		Sage,NobleMan,FoolMan,SmallMan
	};
	string id;
	int talent;
	int virtue;
	Person(string id,int talent,int virtue):
		id(id),talent(talent),virtue(virtue)
	{
		
	}
	Type GetType()const
	{
		if(virtue>=higherLine)
		{
			if (talent >= higherLine)return Sage;
			return NobleMan;
		}
		else
		{
			if (virtue >= talent)return FoolMan;
			return SmallMan;
		}
	}
	bool operator<(const Person& person )const
	{
		if (GetType() == person.GetType())
		{
			if(talent + virtue == person.talent + person.virtue)
			{
				if(virtue==person.virtue)return id < person.id;
				return virtue > person.virtue;
			}
			return talent + virtue > person.talent + person.virtue;
		}
		return GetType() < person.GetType();
	}
	void Print()
	{
		printf("%s %d %d\n", id.c_str(), virtue, talent);
	}
};
vector<Person> people;
int main(int argc, char *argv[])
{
	cin >> peopleSize >> lowerBound >> higherLine;
	for (int i = 0; i < peopleSize; ++i)
	{
		string id;
		int virtue, talent;
		cin >> id >> virtue >> talent ;
		if(talent>=lowerBound&&virtue>=lowerBound)
			people.emplace_back(id, talent, virtue);
	}
	sort(people.begin(), people.end());
	cout << people.size()<<'\n';
	for (auto&& person : people)
	{
		person.Print();
	}
}
