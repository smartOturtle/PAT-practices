#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    int kindSize;
    double demand;
    cin >> kindSize >> demand;
    vector<pair<double, double>> eachWeightPrice(kindSize);
    for (auto& weightPrice : eachWeightPrice)cin >> weightPrice.first;
    for (auto& weightPrice : eachWeightPrice)cin >> weightPrice.second;
    sort(eachWeightPrice.begin(), eachWeightPrice.end(),
        [](auto lhs, auto rhs) { return lhs.second / lhs.first > rhs.second / rhs.first; });
    double totalProfit = 0;
    for (auto weightPrice : eachWeightPrice)
    {
        if (demand >= weightPrice.first)
        {
            totalProfit += weightPrice.second;
            demand -= weightPrice.first;
        }
        else
        {
            totalProfit += (weightPrice.second / weightPrice.first)*demand;
            break;
        }
    }
    printf("%.2lf", totalProfit);
}
