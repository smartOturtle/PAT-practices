#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
vector<int> serveTime;
int windowSize, windowCapacity, customerSize, querySize;
vector<int> queryTable;
//时间驱动
void Process()
{
	int currentTime = 480, customerIdx = 0;
	queryTable.assign(customerSize, -1);
	vector<deque<int>> windows(windowSize);
	for (int i = 0; i < windowCapacity; ++i)
		for (auto && window : windows)	
			window.push_back(customerIdx++);
	vector<pair<int, int>> serveQueue;
	for (int i = 0; i < windowSize; ++i)
	{
		if (!windows[i].empty())
			serveQueue.emplace_back(serveTime[windows[i].front()], i);
	}
	using Pred = greater<pair<int, int>>;
	make_heap(serveQueue.begin(), serveQueue.end(), Pred());
	while (!serveQueue.empty())
	{
		auto completeCust = serveQueue.front();
		auto& completeWindow = windows[completeCust.second];
		//record and update 
		queryTable[completeWindow.front()] = (currentTime += completeCust.first);
		for (auto && customer : serveQueue)
		{
			customer.first -= completeCust.first;
		}
		//pop
		pop_heap(serveQueue.begin(), serveQueue.end(), Pred());
		serveQueue.pop_back();
		completeWindow.pop_front();
		//push
		if (currentTime<17 * 60)
		{
			if (customerIdx<customerSize)
				completeWindow.push_back(customerIdx++);
			if (!completeWindow.empty())
			{
				serveQueue.emplace_back(serveTime[completeWindow.front()], completeCust.second);
				push_heap(serveQueue.begin(), serveQueue.end(), Pred());
			}
		}
	}
}
int main()
{
	//serveTime 8:00~17:00
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
