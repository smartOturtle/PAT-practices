#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <functional>
using namespace std;
int main(int argc, char* argv[])
{
	int coinSize, amount;
	cin >> coinSize >> amount;
	vector<int> coins(coinSize + 1);
	vector<vector<int>> cached(coinSize + 1, vector<int>(amount + 1));
	for (int i = 0; i < coinSize; ++i)
	{
		cin >>coins[i+1];
	}
	sort(coins.begin()+1, coins.end(),greater<int>());
	deque<deque<bool>> selected(coinSize + 1, deque<bool>(amount + 1));
	for (int i = 1; i <= coinSize; ++i)
	{
		for (int j = coins[i]; j <=amount; ++j)
		{
			if (cached[i - 1][j - coins[i]] + coins[i] >= cached[i - 1][j])
			{
				cached[i][j] = cached[i - 1][j - coins[i]] + coins[i];
				selected[i][j] = true;
			}
			else cached[i][j] = cached[i - 1][j];
		}
	}
	if (cached[coinSize][amount] != amount)cout << "No Solution";
	else
	{
		vector<int> solution;
		for (int i = coinSize,j=amount; j>0; --i)
		{
			if(selected[i][j])
			{
				solution.push_back(coins[i]);
				j -= coins[i];
			}
		}
		cout << solution.front();
		for (int i = 1; i < solution.size(); ++i)
		{
			cout << " " << solution[i];
		}
	}
}
