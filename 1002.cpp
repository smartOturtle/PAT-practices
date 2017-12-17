#include <iostream>
#include <cmath>
#include <map>
using namespace std;
using Poly = map<int, float>;
Poly add(Poly& poly1, Poly& poly2)
{
  Poly result;
  for (auto && value : poly1)
  {
    auto pos= poly2.find(value.first);
    if (pos == poly2.end())result.insert(value);
    else
    {
      auto coe = value.second + pos->second;
      if(coe!=0)result.insert({ value.first, coe});
      poly2.erase(pos);
    }
  }
  for (auto && value : poly2)
  {
    result.insert(value);
  }
  return result;
}
void Input(Poly& m)
{
  int size;
  cin >> size;
  for (int i = 0; i < size; ++i)
  {
    int exp;
    float coe;
    cin >> exp >> coe;
    m.insert({ exp,coe });
  }
}
int main()
{
  Poly poly1; 
  Poly poly2;
  Input(poly1);
  Input(poly2);
  auto result= add(poly1,poly2);
  //if (result.empty())cout << "1 0";
  //else
  {
    cout << result.size();
    for (auto i =result.rbegin(); i != result.rend(); ++i)
    {
      cout << " " << i->first;
      printf(" %.1f", i->second);
    }
  }
}
