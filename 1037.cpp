#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(int argc, char* argv[])
{
	long long couponSize;
	cin >> couponSize;
	vector<long long> positiveCoupons;
	vector<long long> negativeCoupons;
	for (auto i = 0; i < couponSize; ++i)
	{
		long long value;
		cin >> value;
		if (value > 0)positiveCoupons.push_back(value);
		else negativeCoupons.push_back(value);
	}
	long long productSize;
	cin >> productSize;
	vector<long long> positiveProducts;
	vector<long long> negativeProducts;
	for (auto i = 0; i < productSize; ++i)
	{
		long long value;
		cin >> value;
		if (value > 0)positiveProducts.push_back(value);
		else negativeProducts.push_back(value);
	}
	sort(positiveCoupons.begin(), positiveCoupons.end());
	sort(positiveProducts.begin(), positiveProducts.end());
	sort(negativeCoupons.begin(), negativeCoupons.end(), greater<long long>());
	sort(negativeProducts.begin(), negativeProducts.end(), greater<long long>());
	long long totalMoney = 0;
	auto i = positiveProducts.rbegin(),j = positiveCoupons.rbegin();
	while (i!=positiveProducts.rend()&&j!=positiveCoupons.rend())
	{
		totalMoney += (*i)*(*j);
		++i, ++j;
	}
	i = negativeProducts.rbegin(), j = negativeCoupons.rbegin();
	while (i != negativeProducts.rend() &&j != negativeCoupons.rend())
	{
		totalMoney += (*i)*(*j);
		++i, ++j;
	}
	cout << totalMoney;
}
