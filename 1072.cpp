#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, M, K, D;
vector<vector<int> > gragh;
pair<double, double> dijkstra(int s)
{
	vector<int> dis(N + M + 1, INT32_MAX);
	vector<bool> used(N + M + 1, false);
	dis[s] = 0;
	while (true)
	{
		int v = -1;
		for (int u = 1; u <= N + M; u++)
		{
			if (!used[u] && (v == -1 || dis[u]<dis[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;
		for (int u = 1; u <= N + M; u++)
		{
			dis[u] = min(dis[u], dis[v] + gragh[v][u]);
		}
	}
	double min = INT32_MAX, cost = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dis[i] > D)
		{
			return make_pair(-1, 0);
		}
		if (dis[i]<min)
		{
			min = dis[i];
		}
		cost += dis[i];
	}
	return make_pair(min, cost / N);
}

int main()
{
	scanf("%d%d%d%d", &N, &M, &K, &D);
	int from, to, dis, i;
	gragh.resize(N + M + 1, vector<int>(N + M + 1, INT32_MAX));
	string str;
	for (i = 0; i<K; i++)
	{
		cin >> str;
		if (isalpha(str[0]))	from = stoi(str.substr(1)) + N;
		else	from = stoi(str);

		cin >> str;
		if (isalpha(str[0]))	to = stoi(str.substr(1)) + N;
		else	to = stoi(str);
		scanf("%d", &dis);
		gragh[from][to] = dis;
		gragh[to][from] = dis;
	}
	int index = -1;
	double ave=0, min = -1;
	for (i = N + 1; i <= N + M; i++)
	{
		pair<double, double> p = dijkstra(i);
		if (p.first <= -1)continue;
		if (p.first>min || (p.first == min && p.second<ave))
		{
			index = i;
			min = p.first;
			ave = p.second;
		}
	}
	if (index == -1)printf("No Solution\n");
	else
	{
		printf("G%d\n", index - N);
		printf("%.1f %.1f\n", min, ave);
	}
	return 0;
}
