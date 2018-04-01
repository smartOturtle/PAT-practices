#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
using NumType = long long;
NumType GCD(NumType lhs,NumType rhs)
{
    if (rhs == 0)return lhs;
    return GCD(rhs, lhs%rhs);
}
using Ratio = pair<NumType, NumType>;
void Reduce(Ratio& ratio)
{
    auto gcd = GCD(ratio.first, ratio.second);
    if(gcd!=0)
    {
        ratio.first /= gcd;
        ratio.second /= gcd;
    }
}
void Print(Ratio ratio)
{
    if (ratio.second == 0)cout << "Inf";
    else
    {
        Reduce(ratio);
        bool isNegative = (ratio.first < 0 || ratio.second<0);
        ratio = { abs(ratio.first),abs(ratio.second) };
        auto intPart = ratio.first / ratio.second;
        ratio.first %= ratio.second;
        if (isNegative)cout << "(-";
        if (intPart != 0)
        {
            cout << intPart;
            if (ratio.first != 0)cout << " " << ratio.first << '/' << ratio.second;
        }
        else
        {
            if (ratio.first != 0)cout << ratio.first << '/' << ratio.second;
            else { cout << 0; }
        }
        if (isNegative)cout << ")";
    }
}
void Operation(Ratio lhs, Ratio rhs,char c,function<Ratio(Ratio,Ratio)> f)
{
    Print(lhs);
    printf(" %c ",c);
    Print(rhs);
    cout << " = ";
    Print(f(lhs, rhs));
    cout << '\n';
}
int main(int argc, char* argv[])
{
    Ratio lhs, rhs;
    scanf("%lld/%lld", &lhs.first, &lhs.second);
    scanf("%lld/%lld", &rhs.first, &rhs.second);
    Operation(lhs, rhs, '+', [](Ratio lhs, Ratio rhs) { return Ratio{ lhs.first*rhs.second + rhs.first*lhs.second,lhs.second*rhs.second }; });
    Operation(lhs, rhs, '-', [](Ratio lhs, Ratio rhs) { return Ratio{ lhs.first*rhs.second - rhs.first*lhs.second,lhs.second*rhs.second }; });
    Operation(lhs, rhs, '*', [](Ratio lhs, Ratio rhs) { return Ratio{ lhs.first * rhs.first,lhs.second * rhs.second }; });
    Operation(lhs, rhs, '/', [](Ratio lhs, Ratio rhs) { return Ratio{ lhs.first * rhs.second,lhs.second * rhs.first }; });
}
