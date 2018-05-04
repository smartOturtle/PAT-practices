#include <iostream>
#include <cmath>
#include <map>
using namespace std;
using Poly = map<int, float>;
void Reduce(Poly& poly)
{
    for (auto i = poly.begin(); i !=poly.end();)
    {
        if (i->second == 0)i = poly.erase(i);
        else { ++i; }
    }
}
Poly operator+(const Poly& lhs,const Poly& rhs)
{
    Poly result=rhs;
    for (auto && value : lhs)result[value.first] += value.second;
    Reduce(result);
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
  cout << result.size();
  for (auto i =result.rbegin(); i != result.rend(); ++i)
    {
      cout << " " << i->first;
      printf(" %.1f", i->second);
    }  
}
