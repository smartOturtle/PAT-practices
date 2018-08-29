#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int memberSize;
    double initPrice;
    double rate;
    cin >> memberSize >> initPrice >> rate;
    rate /= 100;
    vector<int> chains(memberSize);
    for (int i = 0; i < memberSize; ++i)cin >> chains[i];
    pair<double, int> highestRateSize{};
    vector<double> rates(memberSize);
    function<double(int)> calculate = [&](int idx)
    {
        if (idx == -1)return 1.0;
        if (rates[idx] != 0.0)return rates[idx];
        return rates[idx] =(1+ rate )* calculate(chains[idx]);
    };
    for (auto idx : chains)
    {
        double totalRate = calculate(idx);
        if (totalRate == highestRateSize.first)highestRateSize.second++;
        else if(totalRate>highestRateSize.first) { highestRateSize = { totalRate,1 }; }
    }
    printf("%.2lf %d", (highestRateSize.first)*initPrice, highestRateSize.second);
}
