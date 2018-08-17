#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char* argv[])
{
    int capacity, seqLength, caseSize;
    cin >> capacity >> seqLength >> caseSize;
    for (int i = 0; i < caseSize; ++i)
    {
        stack<int> s;
        int nextValue=1;
        bool isTrue = true;
        for (int j = 0; j < seqLength; ++j)
        {
            int popValue;
            cin >> popValue;
            while (popValue>=nextValue)
            {
                s.push(nextValue++);
                if (s.size() > capacity)isTrue = false;
            }
            if (s.top() != popValue)isTrue = false;
            else { s.pop(); }
        }
        if (isTrue)cout << "YES\n";
        else cout << "NO\n";
    }
}
