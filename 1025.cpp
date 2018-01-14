#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;

struct Testee
{
	int area;
	int score=0;
	int rank = 0;
	string id;
	bool operator >(const Testee& rhs)const noexcept
	{
		if (score == rhs.score)return id < rhs.id;
		return score > rhs.score;
	}
	explicit  Testee(string id,int area,int score)
	:area(area),score(score),id(id)
	{
		
	}
};
void ForeachByRank(vector<Testee>& testees,function<void(Testee&,int)> func)
{
	int rank = 0, prescore = -1, sameSize = 1;
	for (auto& testee : testees)
	{
		if (testee.score!= prescore)
		{
			prescore = testee.score;
			rank += sameSize;
			sameSize = 1;
		}
		else sameSize++;
		func(testee, rank);
	}
}
int main()
{
	int areaSize;
	cin >> areaSize;
	vector<Testee> testees;
	for (int i = 0; i < areaSize; ++i)
	{
		int testeeSize;
		cin >> testeeSize;
		vector<Testee> part;
		for (int j = 0; j < testeeSize; ++j)
		{
			string id;
			int score;
			cin >> id >> score;
			part.emplace_back(id, i+1, score);
		}
		sort(part.begin(), part.end(), greater<Testee>());
		ForeachByRank(part,[](Testee& testee,int rank)
		{
			testee.rank = rank;
		});
		testees.insert(testees.end(), part.begin(), part.end());
	}
	cout << testees.size() << '\n';
	sort(testees.begin(), testees.end(), greater<Testee>());
	ForeachByRank(testees, [](Testee& testee, int rank)
	{
		cout << testee.id << " " << rank << " " << testee.area <<" "<< testee.rank;
		cout << "\n";
	});
}
