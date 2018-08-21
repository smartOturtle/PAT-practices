#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
vector<int> levelOrder;
vector<int> nodes;
using Iter = vector<int>::iterator;
queue<function<void()>> taskQueue;
void Travelsal(Iter first,Iter last)
{
    if(first==last)return;
    int level = log2(last - first + 1);
    int completedSize = pow(2, level)-1;
    int restSize = last - first - completedSize;
    auto parent = last - (max<int>(0,restSize-pow(2,level)/2)+(completedSize - 1) / 2) - 1;
    levelOrder.push_back(*parent);
    taskQueue.push([first,parent]() { Travelsal(first, parent); });
    taskQueue.push([parent,last]() { Travelsal(parent + 1, last); });
}
int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    nodes.resize(size);
    for (auto& value : nodes)cin >> value;
    sort(nodes.begin(), nodes.end());
    taskQueue.push([]() { Travelsal(nodes.begin(), nodes.end()); });
    while (!taskQueue.empty())
    {
        taskQueue.front()();
        taskQueue.pop();
    }
    cout << levelOrder.front();
    for (int i =1; i < levelOrder.size(); ++i)
    {
        cout << " " << levelOrder[i];
    }
}
