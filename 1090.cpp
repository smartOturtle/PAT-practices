#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> supplyChain;
int N;
double permitivePrice, incrementRate;
int root = 0;
pair<double, int> highestPriceAndIdx = {};
void DFS(int idx,double price)
{
    for (auto && value : supplyChain[idx])
    {
        DFS(value, price*(1 + incrementRate / 100.0));
    }
    if (price > highestPriceAndIdx.first)highestPriceAndIdx = { price,1 };
    else if (price == highestPriceAndIdx.first) { highestPriceAndIdx.second++; }
}
int main(int argc, char* argv[])
{
    cin >> N >> permitivePrice >> incrementRate;
    supplyChain.resize(N);
    for (int i = 0; i < N; ++i)
    {
        int supplierIdx;
        cin >> supplierIdx;
        if(supplierIdx!=-1)supplyChain[supplierIdx].push_back(i);
        else { root = i; }
    }
    DFS(root, permitivePrice);
    printf("%.2lf %d", highestPriceAndIdx.first, highestPriceAndIdx.second);
}
