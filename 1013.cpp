#include<iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> gragh;
struct Set
{
	bool Union(int a,int b)
	{
		auto rootA = Find(a);
		auto rootB = Find(b);
		if(rootA==rootB)return false;
		if (container[rootA] < container[rootB])
		{
			container[rootA] += container[rootB];
			container[rootB] = rootA;
		}
		else
		{
			container[rootB] += container[rootA];
			container[rootA] = rootB;
		}
		return true;
	}
	int Find(int i)
	{
		if (container[i] < 0)return i;
		return container[i] = Find(container[i]);
	}
	Set(int size):container(size,-1){}
	vector<int> container;
};
void SpanTree(int idx,int size)
{
	Set s(size);
	for (auto && value : gragh)
	{
		if (value.first != idx && value.second != idx)
			s.Union(value.first, value.second);
	}	
	int cnt=-2;
	for (auto value : s.container)
		if (value < 0)cnt++;
	cout << cnt<<'\n';
}
int main()
{
	int citySize, roadSize, checkSize;
	cin >> citySize >> roadSize >> checkSize;
	gragh.resize(citySize);
	for (int i = 0; i < roadSize; ++i)
	{
		int city1, city2;
		cin >> city1 >> city2;
		gragh.push_back({ city1-1,city2-1 });
	}
	for (int i = 0; i < checkSize; ++i)
	{
		int idx;
		cin >> idx;
		SpanTree(idx-1, citySize);
	}
}
