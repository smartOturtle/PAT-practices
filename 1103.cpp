#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;
deque<int> perfect;
deque<int> temp;
int num, factorSize, p;
void DFS(int factor,int num,int size)
{
    if (num == 0 && size == 0 )
    {
        if(accumulate(perfect.begin(),perfect.end(),0)<accumulate(temp.begin(), temp.end(),0)||
            perfect<temp)
        perfect = temp;
    }
    if(pow(factor,p)*size>num||num<=0||size<=0)return;
    temp.push_front(factor);
    DFS(factor, num - pow(factor, p), size - 1);
    temp.pop_front();
    DFS(factor +1, num, size);
}
int main(int argc, char* argv[])
{
    cin >> num >> factorSize >> p;
    DFS(1, num, factorSize);
    if (perfect.empty())cout << "Impossible";
    else
    {
        cout << num << " = ";
        cout << perfect.front() << "^" << p;
        for (int i = 1; i < perfect.size(); ++i)
        {
            cout<<" + "<<perfect[i] << "^" << p;
        }
    }
}
