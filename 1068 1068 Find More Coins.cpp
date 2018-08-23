#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
vector<int> solution;
int coinSize, amount;
template<typename Iter>
void DFS(Iter first,Iter last,int currentAmount)
{
    static vector<int> coins;
    if (currentAmount == amount)solution = coins;
    if(first==last||*first>(amount-currentAmount))return;
    coins.push_back(*first);
    DFS(first + 1, last, currentAmount + *first);
    coins.pop_back();
    if(!solution.empty())return;
    for (auto iter=first+1;iter!=last;++iter)
    {
        if(*iter!=*first)return DFS(iter, last, currentAmount);
    }
}
int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    cin >> coinSize >> amount;
    vector<int> coins(coinSize);
    for (auto& value : coins)cin >> value;
    sort(coins.begin(), coins.end());
    DFS(coins.begin(), coins.end(), 0);
    if(!solution.empty())
    {
        cout << solution.front();
        for (int i = 1; i < solution.size(); ++i)
        {
            cout << " " << solution[i];
        }
    }
    else { cout << "No Solution"; }
}
