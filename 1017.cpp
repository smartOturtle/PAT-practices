#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int main()
{
  int customerSize,windowSize;
  cin >> customerSize >> windowSize;
  vector<pair<int,int>> customers;
  for (int i = 0; i < customerSize; ++i)
  {
    int hh, mm, ss;
    int processingTime;
    scanf("%d:%d:%d %d", &hh, &mm, &ss,&processingTime);
    auto arrivedTime = (hh*60+mm)*60+ss;
    if(arrivedTime<=17*3600)
      customers.emplace_back(arrivedTime,processingTime*60);
  }
  sort(customers.begin(), customers.end());
  int currentTime = 8 * 3600;
  priority_queue<int, vector<int>, greater<int>> heap;
  vector<int> waitingTime;
  for (int i = 0; i < customers.size(); ++i)
  {
    while(!heap.empty() && customers[i].first>heap.top()
      ||heap.size()==windowSize)
    {
      currentTime = heap.top();
      heap.pop();
    }
    if (customers[i].first > currentTime)
    {
      currentTime = customers[i].first;
    }
    waitingTime.push_back(currentTime - customers[i].first);
    heap.push(customers[i].second+currentTime);
  }
  float totalWaitingTime=0;
  for (auto && time : waitingTime)
  {
    totalWaitingTime += time;
  }
  if (customers.size() == 0)cout << "0.0";
  else printf("%.1f", totalWaitingTime / 60 / customers.size());
}
