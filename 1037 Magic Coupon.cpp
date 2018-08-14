#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
int main(int argc, char* argv[])
{
    int64_t couponSize;
    cin >> couponSize;
    vector<int64_t> coupons(couponSize);
    for (auto& coupon : coupons)cin >> coupon;
    int64_t productSize;
    cin >> productSize;
    vector<int64_t> products(productSize);
    for (auto&product : products)cin >> product;
    auto negaBegin= partition(coupons.begin(), coupons.end(), [](int64_t n) { return n > 0; });
    auto bonusBegin= partition(products.begin(), products.end(), [](int64_t n) { return n > 0; });
    sort(coupons.begin(), negaBegin,greater<int64_t>());
    sort(negaBegin, coupons.end());
    sort(products.begin(), bonusBegin,greater<int64_t>());
    sort(bonusBegin, products.end());
    int64_t totalMoney=0;
    for(auto i=coupons.begin(),j=products.begin();i!=negaBegin&&j!=bonusBegin;++i,++j)
    {
        totalMoney += *i**j;
    }
    for (auto i = negaBegin, j = bonusBegin; i != coupons.end() && j != products.end(); ++i, ++j)
    {
        totalMoney += *i**j;
    }
    cout << totalMoney;
}
