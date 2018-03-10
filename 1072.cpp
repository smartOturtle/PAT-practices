#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <deque>
using namespace std;
int houseSize, candidateSize, roadSize, maxServiceDis;
vector<vector<int> > gragh;
void Dijkstra(int idx)
{
	auto& dis=gragh[idx];
	deque<bool> visited(houseSize + candidateSize, false);
	dis[idx] = 0;
	while (true)
	{
		int v = -1;
		for (int i =0; i < houseSize + candidateSize; i++)
		{
			if (!visited[i]&&dis[i]<INT16_MAX && (v == -1 || dis[i]<dis[v])) v = i;
		}
		if (v == -1) return;
		visited[v] = true;
		for (int i = 0; i <houseSize + candidateSize; i++)
		{
			if(!visited[i])dis[i] = min(dis[i], dis[v] + gragh[v][i]);
		}
	}
}

int ToIndex(const string& str)
{
	if (isalpha(str[0]))	return  stoi(str.substr(1)) + houseSize - 1;
	return  stoi(str)-1;
}
int main()
{
	scanf("%d%d%d%d", &houseSize, &candidateSize, &roadSize, &maxServiceDis);
	gragh.resize(houseSize + candidateSize, vector<int>(houseSize + candidateSize, INT16_MAX));
	for (int i = 0; i<roadSize; i++)
	{
		string str;
		cin >> str;
		int from = ToIndex(str);
		cin >> str;
		int to = ToIndex(str);
		int dis;
		scanf("%d", &dis);
		gragh[from][to] = dis;
		gragh[to][from] = dis;
	}
	int index = -1;
	double sum=0, minDis = -1;
	for (int i = houseSize ; i < houseSize + candidateSize; i++)
	{
		Dijkstra(i);
		auto& eachDis = gragh[i];
		auto minMax = minmax_element(eachDis.begin(), eachDis.begin() + houseSize);
		if(*minMax.second>maxServiceDis)continue;
		double tempSum = accumulate(eachDis.begin(), eachDis.begin() + houseSize, 0);
		if(minDis<*minMax.first|| *minMax.first == minDis&&tempSum<sum)
		{
			index = i;
			sum = tempSum;
			minDis = *minMax.first;
		}
	}
	if (index == -1)printf("No Solution\n");
	else
	{
		printf("G%d\n", index - houseSize+1);
		printf("%.1f %.1f\n", minDis, sum/houseSize);
	}
}
