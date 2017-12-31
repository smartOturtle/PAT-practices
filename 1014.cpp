#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
vector<int> serveTime;
int windowSize, windowCapacity, customerSize, querySize;
vector<int> queryTable;
void Process()
{
	int currentTime = 480, customerIdx = 0;
	queryTable.assign(customerSize, -1);
	vector<deque<int>> windows(windowSize);
	for (int i = 0; i < windowCapacity; ++i)
	{
		for (auto && window : windows)
		{
			window.push_back(customerIdx++);
			if (customerIdx == customerSize)break;
		}
		if (customerIdx == customerSize)break;
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> heap;
	for (int i = 0; i < windowSize; ++i)
	{
		if (!windows[i].empty())
			heap.push({ serveTime[windows[i].front()] + currentTime, i });
	}
	while (!heap.empty())
	{
		auto completeCust = heap.top();
		auto& completedWindow = windows[completeCust.second];
		currentTime = completeCust.first;
		queryTable[completedWindow.front()] = currentTime;
		heap.pop();
		completedWindow.pop_front();
		if (currentTime<17 * 60)
		{
			if (customerIdx<customerSize)
				completedWindow.push_back(customerIdx++);
			if (!completedWindow.empty())
				heap.push({ serveTime[completedWindow.front()] + currentTime, completeCust.second });
		}
	}
}
int main()
{
	cin >> windowSize >> windowCapacity >> customerSize >> querySize;
	serveTime.resize(customerSize);
	for (int i = 0; i < customerSize; ++i)
		cin >> serveTime[i];
	Process();
	for (int i = 0; i < querySize; ++i)
	{
		int idx;
		cin >> idx;
		idx--;
		if (queryTable[idx] == -1)cout << "Sorry\n";
		else   printf("%02d:%02d\n", queryTable[idx] / 60, queryTable[idx] % 60);
	}
}
