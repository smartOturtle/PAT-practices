#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <tuple>
#include <list>
using namespace std;

struct Road
{
	int dist = INT16_MAX;
	int cost = INT16_MAX;
	Road(int dist,int cost):dist(dist),cost(cost){}
	Road(){}
	bool operator >(const Road& road)const
	{
		if (dist == road.dist)return cost > road.cost;
		return dist > road.dist;
	}
	Road operator+(const Road& road)const
	{
		return { dist + road.dist,cost + road.cost };
	}
};
vector<vector<Road>> gragh;
int main()
{
	int citySize, roadSize, start, end;
	scanf("%d %d %d %d", &citySize, &roadSize, &start, &end);
	gragh.resize(citySize, vector<Road>(citySize));
	for (int i = 0; i < roadSize; ++i)
	{
		int city1, city2, dist, cost;
		scanf("%d %d %d %d", &city1, &city2, &dist, &cost);
		gragh[city1][city2] = { dist,cost };
		gragh[city2][city1] = { dist,cost };
	}
	auto& dist = gragh[start];
	dist[start] = {0,0};
	vector<bool> checked(citySize);
	vector<int> path(citySize,-1);
	while (true)
	{
		int idx = -1;
		for (int i = 0; i < citySize; ++i)
			if (dist[i].dist<INT16_MAX && !checked[i])
				if(	idx == -1 || dist[idx].dist < dist[i].dist)idx = i;
		if(idx==-1)break;
		checked[idx] = true;
		for (int i = 0; i < citySize; ++i)
			if(gragh[i][idx].dist<INT16_MAX&&!checked[i])
			{
				auto road = dist[i]+gragh[idx][i];
				if (dist[idx] > road)tie(dist[idx], path[idx]) = make_tuple(road, i);
			}
	}
	vector<int> l;
	for (int i = end; i != -1; i = path[i])
		l.push_back(i);
	l.push_back(start);
	for (auto i = l.rbegin(); i != l.rend(); ++i)printf("%d ", *i);
	printf("%d %d", dist[end].dist, dist[end].cost);
}
