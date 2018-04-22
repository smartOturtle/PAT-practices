#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <sstream>
using namespace std;
bool IsPrime(int num)
{
    if (num == 2)return true;
    if (num == 1 || num % 2 == 0)return false;
    for (int i = 3; i <=sqrt(num) ; i+=2)
    {
        if (num%i == 0)return false;
    }
    return true;
}
int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    unordered_map<string, pair<int, bool>> queryTable;
    for (int i = 1; i <= n; ++i)
    {
        string id;
        cin >> id;
        queryTable[id].first = i;
    }
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        string id;
        cin >> id;
        cout << id << ": ";
        if(queryTable.find(id)==queryTable.end())cout << "Are you kidding?";
        else
        {
            if (queryTable[id].second == true)cout << "Checked";
            else
            {
                if (queryTable[id].first == 1)cout << "Mystery Award";
                else if (IsPrime(queryTable[id].first)) { cout << "Minion"; }
                else { cout << "Chocolate"; }
                queryTable[id].second = true;
            }
        }
        cout << '\n';
    }
}
