#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
using namespace std;
vector<vector<int>> graph;
unordered_map<int, int> retailers;
int memberSize;
double unitPrice;
double rate;
double totalSales = 0;
void DFS(int idx,double price,double rate)
{
    if (graph[idx].empty())totalSales += retailers[idx] * price;
    else for (auto subIdx : graph[idx])DFS(subIdx, price*(1 + rate), rate);
}
int main(int argc, char* argv[])
{
    cin >> memberSize >> unitPrice >> rate;
    graph.resize(memberSize);
    rate /= 100;
    for (int i = 0; i < memberSize; ++i)
    {
        int distributeSize;
        cin >> distributeSize;
        if (distributeSize == 0)cin >> retailers[i];
        else for (int j = 0; j < distributeSize; ++j)
        {
            int id;
            cin >> id;
            graph[i].push_back(id);
        }
    }
    DFS(0, unitPrice, rate);
    printf("%.1lf", totalSales);
}
