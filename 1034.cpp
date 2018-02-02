#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
unordered_map<string, unordered_map<string, int>> records;
map<pair<string,string>, bool> checkEdge;
unordered_map<string, bool> checkVertex;
int K;

struct DFS
{
	int size = 1;
	pair<string, int> head;
	int groupWeight = 0;
	pair<string, int> operator()(const string& name)
	{
		int totalWeight = 0;
		for (auto && record : records[name])
		{
			totalWeight += record.second;
			auto edge = minmax(record.first, name);
			if (!checkEdge[edge])
			{
				checkEdge[edge] = true;
				groupWeight += record.second;
				if(!checkVertex[record.first])
				{
					++size;
					checkVertex[record.first] = true;
				}
				operator()(record.first);
			}
		}
		if (head.second < totalWeight)head = make_pair(name, totalWeight);
		if (size <= 2 || groupWeight <= K)return {};
		return make_pair(head.first, size);
	}
};
int main(int argc, char* argv[])
{
	int size;
	cin >> size >> K;
	for (int i = 0; i < size; ++i)
	{
		string a, b;
		int length;
		cin >> a >> b >> length;
		records[a][b] += length;
		records[b][a] += length;
	}
	map<string,int> groups;
	for (auto && record : records)
	{
		if (!checkVertex[record.first])
		{
			checkVertex[record.first] = true;
			auto result = DFS()(record.first);
			if (result != pair<string, int>{})groups.insert(result);
		}
	}
	cout << groups.size() << '\n';
	for (auto && group : groups)
	{
		cout << group.first << " " << group.second << '\n';
	}
}
