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
    vector<int> cached(amount+1);
    for (int i = 0; i < coinSize; ++i)
    {
        cin >> coins[i + 1];
    }
    sort(coins.begin() + 1, coins.end(), greater<int>());
    deque<deque<bool>> selected(coinSize + 1, deque<bool>(amount + 1));
    for (int i = 1; i <= coinSize; ++i)
    {
        for (int j = amount; j >=coins[i]; --j)
        {
            if (cached[j - coins[i]] + coins[i] >= cached[j])
            {
                cached[j] = cached[j - coins[i]] + coins[i];
                selected[i][j] = true;
            }
        }
    }
    if (cached[amount] != amount)cout << "No Solution";
    else
    {
        vector<int> solution;
        for (int i = coinSize, j = amount; j>0&&i>=0; --i)
        {
            if (selected[i][j])
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
