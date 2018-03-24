#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;
vector<vector<int>> eachFollowers;
void BFS(int id,int maxLayer)
{
	deque<bool> visted(eachFollowers.size());
	queue<int> q;
	q.push(id);
	visted[id] = true;
	int layer = 1, last = eachFollowers[id].size(),cnt=0;
	for (int i=0;layer<maxLayer&&!q.empty();++i)
	{
		for (auto follower : eachFollowers[q.front()])
		{
			if(!visted[follower])
			{
				q.push(follower);
				visted[follower] = true;
				cnt++;
			}
		}
		q.pop();
		if(i==last)
		{
			i = 0;
			last = q.size();
			layer++;
		}
	}
	cout << cnt << '\n';
}
int main(int argc, char* argv[])
{
	int userSize, maxLayer;
	cin >> userSize >> maxLayer;
	eachFollowers.resize(userSize);
	for (int i = 0; i < userSize; ++i)
	{
		int followSize;
		cin >> followSize;
		for (int j = 0; j < followSize; ++j)
		{
			int id;
			cin >> id;
			eachFollowers[id-1].push_back(i);
		}
	}
	int querySize;
	cin >> querySize;
	for (int i = 0; i < querySize; ++i)
	{
		int queryId;
		cin >> queryId;
		BFS(queryId - 1, maxLayer);
	}
}
