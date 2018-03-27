#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
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
	NumType gcd = GCD(ratio.first, ratio.second);
	if(gcd!=0&&gcd!=1)
	{
		ratio.first /= gcd;
		ratio.second /= gcd;
	}
}
Ratio Add(Ratio lhs,Ratio rhs)
{
	NumType lcm = lhs.second*rhs.second / GCD(lhs.second, rhs.second);
	lhs.first *= lcm / lhs.second;
	rhs.first *= lcm / rhs.second;
	return Ratio(lhs.first + rhs.first, lcm);
}
void Print(Ratio ratio)
{
	Reduce(ratio);
	NumType intPart = ratio.first / ratio.second;
	ratio.first %= ratio.second;
	if (intPart != 0) cout << intPart;
	if(ratio.first!=0)
	{
		if(intPart!=0)cout<<' ';
		cout << ratio.first << '/' << ratio.second;
	}
	else if (intPart == 0) { cout << 0; }
}
int main(int argc, char* argv[])
{
	NumType size;
	cin >> size;
	vector<Ratio> ratios;
	for (NumType i = 0; i < size; ++i)
	{
		Ratio ratio;
		scanf("%lld/%lld", &ratio.first, &ratio.second);
		Reduce(ratio);
		ratios.push_back(ratio);
	}
	Ratio ratio = ratios.front();
	for (NumType i = 1; i < ratios.size(); ++i)
	{
		ratio = Add(ratio, ratios[i]);
	}
	Print(ratio);
}
