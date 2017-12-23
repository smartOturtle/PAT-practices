#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int ToDuration(const string& time)
{
	int result = stoi(time.substr(0, 2))*60;
	result += stoi(time.substr(3, 2));
	result *= 60;
	result += stoi(time.substr(6, 2));
	return result;
}
int currentTime = 8 * 3600;
vector<int> heap;
using Pred = greater<int>;
//入队顺序驱动
int main()
{
	int customerSize,windowSize;
	cin >> customerSize >> windowSize;
	vector<pair<int,int>> customers;
	for (int i = 0; i < customerSize; ++i)
	{
		string arrivedTime;
		int processingTime;
		cin >> arrivedTime>>processingTime;
		auto time = ToDuration(arrivedTime);
		if(time<=17*3600)customers.emplace_back(time,processingTime*60);
	}
	sort(customers.begin(), customers.end());
	vector<int> waitingTime;
	for (int i = 0; i < customers.size(); ++i)
	{
		while(!heap.empty() && customers[i].first>heap.front()
			||heap.size()==windowSize)
		{
			currentTime = heap.front();
			pop_heap(heap.begin(), heap.end(), Pred());
			heap.pop_back();
		}
		if (customers[i].first > currentTime)
		{
			currentTime = customers[i].first;
		}
		waitingTime.push_back(currentTime - customers[i].first);
		heap.push_back(customers[i].second+currentTime);
		push_heap(heap.begin(), heap.end(), Pred());
	}
	float totalWaitingTime=0;
	for (auto && time : waitingTime)
	{
		totalWaitingTime += time;
	}
	if (customers.size() == 0)cout << "0.0";
	else printf("%.1f", totalWaitingTime / 60 / customers.size());
}
