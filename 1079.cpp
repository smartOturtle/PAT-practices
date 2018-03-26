#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
vector<vector<int>> supplyChain;
int N;
double prmitivePrice, incRate;
double totalSale=0;
void DFS(int idx,double price)
{
	if(supplyChain[idx].front()==0)
	{
		totalSale += supplyChain[idx].back()*price;
	}
	else
	{
		for (auto value : supplyChain[idx])
		{
			DFS(value, (incRate / 100 + 1) * price);
		}
	}
}
int main(int argc, char* argv[])
{
	//id are numbered from 0 to N-1
	//root id is 0
	cin >> N >> prmitivePrice >> incRate;
	supplyChain.resize(N,vector<int>());
	for (int i = 0; i < N; ++i)
	{
		int nodeSize;
		cin >> nodeSize;
		if(nodeSize==0)
		{
			//front 0 stands for a supplier
			supplyChain[i].push_back(0);
			int amount;
			cin >> amount;
			supplyChain[i].push_back(amount);
		}
		else
		{
			supplyChain[i].resize(nodeSize);
			for (int j = 0; j < nodeSize; ++j)
			{
				cin >> supplyChain[i][j];
			}
		}
	}
	DFS(0, prmitivePrice);
	printf("%.1lf", totalSale);
}
