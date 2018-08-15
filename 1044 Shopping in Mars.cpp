#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char* argv[])
{
    int size, amount;
    cin >> size >> amount;
    vector<int> chain(size);
    for (auto& value : chain)cin >> value;
    vector<pair<int, int>> cutOptions;
    int start=0;
    int closestValue = INT32_MAX;
    int currentValue = 0;
    for (int i = 0; i < chain.size(); ++i)
    {
        currentValue += chain[i];
        while (start <= i && currentValue >= amount)
        {
            if (currentValue == closestValue)cutOptions.push_back({ start,i });
            else if (currentValue < closestValue)cutOptions.assign({ { start,i } });
            closestValue = min(closestValue, currentValue);
            currentValue -= chain[start];
            start++;    
        }
    }
    sort(cutOptions.begin(), cutOptions.end());
    for (auto option : cutOptions)
    {
        cout << option.first+1 << '-' << option.second+1 << '\n';
    }
}
