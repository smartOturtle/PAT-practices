#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    istream::sync_with_stdio(false);
    int aSize;
    cin >> aSize;
    vector<int> a(aSize);
    for (auto && value : a)cin >> value;
    int bSize;
    cin >> bSize;
    auto aIter = a.begin();
    int cnt = 0;
    for (int i = 0; i < bSize; ++i)
    {
        int value;
        cin >> value;
        while (aIter!=a.end()&&*aIter<value)
        {
            cnt++;
            if (cnt == (aSize + bSize + 1) / 2)cout << *aIter;
            ++aIter;
        }
        cnt++;
        if (cnt == (aSize + bSize + 1) / 2)cout << value;
    }
    while (aIter != a.end())
    {
        cnt++;
        if (cnt == (aSize + bSize + 1) / 2)cout << *aIter;
        ++aIter;
    }
}
