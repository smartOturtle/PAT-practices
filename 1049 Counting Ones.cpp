#include <iostream>
#include <algorithm>
using namespace std;
int Magnitude(int num)
{
    for (int i = 0; ; ++i)
    {
        num /= 10;
        if (num == 0)return pow(10, i);
    }
}
int OneSize(int num)
{
    if (num == 0)return 0;
    if (num < 10)return 1;
    int magnitude = Magnitude(num);
    return
        OneSize(num % magnitude) +//尾数部分1的个数
        num / magnitude * OneSize(magnitude - 1) +//有这位数个小于magnitude的数需要计算
        min(magnitude, num - magnitude + 1);//前面有一个1会增加尾数个1，若该位大于1也只会增加magnitude个1
}
int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    cout << OneSize(N);
}
