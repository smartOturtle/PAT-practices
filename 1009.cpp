#include <iostream>
#include <map>
#include <cmath>
using namespace std;
using Poly = map<int, float>;
void Input(Poly& p)
{
  int cnt;
  cin >> cnt;
  for (int i = 0; i < cnt; ++i)
  {
    int exp;
    float coe;
    cin >> exp >> coe;
    p.insert({ exp,coe });
  }
}
constexpr  bool FloatEqual(float lhs, float rhs) { return abs(lhs - rhs) < 0.00001; }
Poly operator* (const Poly& lhs, const Poly& rhs)
{
  Poly result;
  for (auto && lhsItem : lhs)
  {
    for (auto&& rhsItem : rhs)
    {
      auto exp = lhsItem.first + rhsItem.first;
      auto coe = lhsItem.second * rhsItem.second;
      auto pos = result.find(exp);
      if (pos != result.end())
      {
        result[exp] += coe;
        if (FloatEqual(result[exp],0))result.erase(pos);
      }
      else  if(!FloatEqual(coe,0)){ result.insert({ exp,coe }); }
    }
  }
  return result;
}
int main()
{
  Poly p1, p2;
  Input(p1);
  Input(p2);
  auto result = p1 * p2;
  cout << result.size();
  for (auto i = result.rbegin(); i != result.rend(); ++i)
    printf(" %d %.1f", i->first, i->second);
}
