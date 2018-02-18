#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	int size, amount;
	cin >> size >> amount;
	vector<int> coins(size);
	unordered_map<int,int> exist;
	for (int i = 0; i < size; ++i)
	{
		cin >> coins[i];
		exist[coins[i]]++;
	}
	sort(coins.begin(), coins.end());
	for (auto coin : coins)
	{
		if(exist.find(amount-coin)!=exist.end())
		{
			if(amount-coin!=coin||exist[coin]>1)
			{
				cout << coin << " " << amount - coin;
				return 0;
			}
		}
	}
	cout << "No Solution";
}
