#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int size, amount;
    cin >> size >> amount;
    vector<int> sortedCoins(size);
    unordered_map<int, int> existCoins;
    for (auto && coin : sortedCoins)
    {
        cin >> coin;
        existCoins[coin]++;
    }
    sort(sortedCoins.begin(), sortedCoins.end());
    for (auto coin : sortedCoins)
    {
        existCoins[coin]--;
        if (existCoins[amount - coin])
        {
            cout << coin << " " << amount - coin;
            return 0;
        }
        existCoins[coin]++;
    }
    cout << "No Solution";
}
