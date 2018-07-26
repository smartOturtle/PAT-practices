#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
    string a;
    cin >> a;
    auto b = a;
    bool carry = false;
    for (int i = a.size()-1; i >=0; --i)
    {
        int c = (a[i] - '0')*2+carry;
        if (c >= 10)
        {
            carry = true;
            c %= 10;
        }
        else { carry = false; }
        a[i] = c + '0';
    }
    if (carry)a.insert(a.begin(), '1');
    if (is_permutation(a.begin(), a.end(), b.begin(), b.end()))cout << "Yes";
    else { cout << "No"; }
    cout << '\n' << a;
}
