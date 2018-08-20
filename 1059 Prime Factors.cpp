#include <cmath>
#include<iostream>
using namespace std;
int NextFactor(int n, int begin)
{
    for (int i = begin; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return n;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    cout << n << '=';
    int factor = NextFactor(n, 2);
    int i = 1;
    while (true)
    {
        n /= factor;
        if (n == 1)break;
        int nextFactor = NextFactor(n, factor);
        if (nextFactor != factor)
        {
            cout << factor;
            if (i > 1)cout << '^' << i;
            i = 1;
            cout << '*';
            factor = nextFactor;
        }
        else { ++i; }
    }
    cout << factor;
    if (i > 1)cout << '^' << i;
}
