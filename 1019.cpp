#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
    int num;
    int radix;
    cin >> num >> radix;
    deque<int> s;
    while (num)
    {
        s.push_front(num%radix);
        num /= radix;
    }
    if (mismatch(s.begin(), s.end(), s.rbegin(), s.rend()).first == s.end()) cout << "Yes\n";
    else cout << "No\n";
    if(!s.empty())
    {
        cout << s.front();
        for (int i = 1; i < s.size(); ++i)cout << " " << s[i];
    }
    else cout << 0;
}
