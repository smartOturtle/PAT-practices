#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> nDayMiles(n);
    for (int i = 0; i < nDayMiles.size(); ++i)
    {
        cin >> nDayMiles[i];
    }
    sort(nDayMiles.begin(), nDayMiles.end(),greater<int>());
    for (int i = 0; i < nDayMiles.size(); ++i)
    {
        if(nDayMiles[i]<=i+1)
        {
            cout << i;
            return 0;
        }
    }
    cout << n;
}
