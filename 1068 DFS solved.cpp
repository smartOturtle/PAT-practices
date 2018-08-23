#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> values;
vector<int> solution;
void DFS(int idx, int amount)
{
    static vector<int> path;
    path.push_back(values[idx]);
    int remain = amount - values[idx];
    if (remain == 0)
    {
        solution = path;
        return path.clear();
    }
    if (remain>= values[idx])
    {
        int lastNum = -1;
        for (int i = idx + 1; i < values.size(); ++i)
        {
            if (lastNum != values[i])
            {
                DFS(i, remain);
                lastNum = values[i];
            }
            if (!solution.empty())return;
        }
    }
    path.pop_back();
    for (int i = idx + 1; i < values.size(); ++i)
        if (values[i] != values[idx])return DFS(i, amount);
}
int main(int argc, char* argv[])
{
    int coinSize, amount;
    cin >> coinSize >> amount;
    for (int i = 0; i < coinSize; ++i)
    {
        int value;
        scanf("%d", &value);
        if (value <= amount)values.push_back(value);
    }
    sort(values.begin(), values.end());
    DFS(0, amount);
    if (solution.empty())cout << "No Solution";
    else
    {
        cout << solution.front();
        for (int i = 1; i < solution.size(); ++i)
        {
            printf(" %d", solution[i]);
        }
    }
}
