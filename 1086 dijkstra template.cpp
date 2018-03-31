#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
#include <array>
#include <unordered_map>
#include <map>
using namespace std;
using Name = array<char, 4>;

struct Road
{
	int distance;
	int happiness;
	int span;
	static constexpr int notValid = INT16_MAX;
	Road(int distance,int happiness):
	distance(distance),happiness(happiness),span(1)
	{
	}
	Road():distance(notValid),happiness(0),span(0)
	{
	}
	bool IsValid()const
	{
		return distance != notValid;
	}
	bool operator <(const Road& road)const
	{
		if (distance == road.distance)
		{
			if (happiness == road.happiness)return span < road.span;
			return happiness > road.happiness;
		}
		return distance < road.distance;
	}
	bool operator==(const Road& road)const
	{
		return happiness == road.happiness&&distance == road.distance;
	}
	Road operator+(const Road& road)const
	{
		Road result=road;
		result.distance += distance;
		result.happiness += happiness;
		result.span += span;
		return result;
	}
};
int main(int argc, char* argv[])
{
	//input
	int citySize, routeSize;
	Name start;
	scanf("%d%d%s", &citySize, &routeSize, start.data());
	map<Name, int> nameIdxMap;
	map<int, Name> idxNameMap;
	nameIdxMap[start] = 0;
	idxNameMap[0] = start;
	vector<int> citiesHappiness{ 0 };
	for (int i = 1; i < citySize; ++i)
	{
		Name name;
		scanf("%s", name.data());
		nameIdxMap[name] = i;
		idxNameMap[i] = name;
		int happiness;
		cin >> happiness;
		citiesHappiness.push_back(happiness);
	}
	vector<vector<Road>> gragh(citySize, vector<Road>(citySize));
	for (int i = 0; i < routeSize; ++i)
	{
		Name from,to;
		int distance;
		scanf("%s%s%d", from.data(), to.data(),&distance);
		auto fromIdx = nameIdxMap[from], toIdx = nameIdxMap[to];
		gragh[fromIdx][toIdx] = { distance,citiesHappiness[toIdx], };
		gragh[toIdx][fromIdx] = { distance,citiesHappiness[fromIdx] };
	}
	//dijkstra
	vector<int> pathSize(citySize);
	vector<int> path(citySize, -1);
	deque<bool> visited(citySize);
	auto& dist = gragh[0];
	pathSize[0] = 1;
	dist[0].distance =0;
	while (true)
	{
		int v = -1;
		for (int i = 0; i < citySize; ++i)
		{
			if(!visited[i]&&dist[i].IsValid())
			if(v==-1||dist[i].distance<dist[v].distance)
			{
				v = i;
			}
		}
		if(v==-1)break;
		visited[v] = true;
		for (int i = 0; i < citySize; ++i)
		{
			if(!visited[i])
			{
				if(gragh[v][i].distance+dist[v].distance<dist[i].distance)
				{
					pathSize[i] = pathSize[v];
				}
				else if(gragh[v][i].distance + dist[v].distance==dist[i].distance)
				{
					pathSize[i] += pathSize[v];
				}
				if (gragh[v][i] + dist[v]<dist[i])
				{
					path[i] = v;
					dist[i] = gragh[v][i] + dist[v];
				}
			}
		}
	}
	//output
	int romIdx = nameIdxMap[Name{ "ROM" }];
	deque<int> viaCitys;
	for (int i = romIdx; i != -1; i = path[i])
		viaCitys.push_front(i);
	cout << pathSize[romIdx] << " " << dist[romIdx].distance << " "
			<< dist[romIdx].happiness << " " << dist[romIdx].happiness / dist[romIdx].span<<'\n';
	printf("%s", start.data());
	for (int i = 0; i < viaCitys.size(); ++i)
	{
		printf("->%s", idxNameMap[viaCitys[i]].data());
	}
}

