#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
using namespace std;

vector<vector<int>> chain; 
int nodeSize;
double initPrice, incRate;
pair<double, int> minPriceAndSize = {INT32_MAX,0};
void DFS(int id,double price)
{
    if(chain[id].empty())
    {
        if (minPriceAndSize.first > price)minPriceAndSize = { price,1 };
        else if (abs(minPriceAndSize.first - price) < 1E-6) { minPriceAndSize.second++; }
    }
    else for (auto subId : chain[id])
    {
        DFS(subId, price*(incRate / 100 + 1));
    }

}
int main(int argc, char* argv[])
{
    cin >> nodeSize >> initPrice >> incRate;
    chain.resize(nodeSize);
    for (int i = 0; i < nodeSize; ++i)
    {
        int subordinateSize;
        cin >> subordinateSize;
        chain[i].resize(subordinateSize);
        for (int j = 0; j < subordinateSize; ++j)
        {
            cin>>chain[i][j];
        }
    }
    DFS(0, initPrice);
    printf("%.4lf %d", minPriceAndSize.first, minPriceAndSize.second);
}
