#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Node
{
	vector<int> children;
	int weight;
};
vector<Node> nodes;
int nodeSize, nonLeafNodeSize, givenWeight;
vector<vector<int>> paths;
void DFS(int parent,int totalWeight)
{
	static vector<int> path;
	path.push_back(nodes[parent].weight);
	totalWeight += nodes[parent].weight;
	for (auto child : nodes[parent].children)
	{
		DFS(child, totalWeight);
	}
	if (nodes[parent].children.empty() && totalWeight == givenWeight)
	{
		paths.push_back(path);
	}
	path.pop_back();
}
int main(int argc, char* argv[])
{
	cin >> nodeSize >> nonLeafNodeSize >> givenWeight;
	nodes.resize(nodeSize);
	for (int i = 0; i < nodeSize; ++i)
	{
		cin >> nodes[i].weight;
	}
	for (int i = 0; i < nonLeafNodeSize; ++i)
	{
		int parent,childrenSize;
		cin >> parent >> childrenSize;
		for (int j = 0; j < childrenSize; ++j)
		{
			int child;
			cin >> child;
			nodes[parent].children.push_back(child);
		}
	}
	DFS(0, 0);
	sort(paths.begin(), paths.end(),greater<vector<int>>());
	for (auto && path : paths)
	{
		cout << path[0];
		for (int i = 1; i < path.size(); ++i)
		{
			cout << " " << path[i];
		}
		cout << '\n';
	}
}
