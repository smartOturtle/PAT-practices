#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> coins;
vector<int> solution;
void Find(int idx,int amount)
{
  static vector<int> accumulateCoins;
  if(idx>=coins.size()||coins[idx]>amount)return;
  accumulateCoins.push_back(coins[idx]);
  int remain = amount - coins[idx];
  if(remain>0&&coins[idx]<=remain)
  {
    int lastNum=-1;
    for (int i = idx + 1; i < coins.size(); ++i)
    {
      if(lastNum==coins[i])continue;
      Find(i, remain);
      lastNum=coins[i];
      if(!solution.empty())return;
    }
  }
  else if (remain==0)solution=accumulateCoins;
  accumulateCoins.pop_back();
}
int main(int argc, char* argv[])
{
  int coinSize, amount;
  cin >> coinSize >> amount;
  for (int i = 0; i < coinSize; ++i)
  {
    int value;
    scanf("%d",&value);
    if (value <= amount)coins.push_back(value);
  }
  sort(coins.begin(), coins.end());
  int lastNum=-1;
  for (int i = 0; i < coins.size(); ++i)
  {
    if(lastNum==coins[i])continue;
    Find(i, amount);
    lastNum=coins[i];
    if(!solution.empty())break;
  }
  if (solution.empty())cout << "No Solution";
  else
  {
    cout << solution.front();
    for (int i = 1; i < solution.size(); ++i)
    {
      printf(" %d",solution[i]);
    }
  }
}
