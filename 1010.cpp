#include <iostream>  
#include <string>
#include<cctype>  
#include <algorithm>
using namespace std;

long long CharToLlong(char c)
{
  if (isdigit(c)) return c - '0';
  else return c - 'a' + 10;
}
long long ToDecimal(const string& s, long long radix)
{
  long long result = 0;
  for (auto c : s)
  {
    result *= radix;
    result += CharToLlong(c);
  }
  return result;
}
int main()
{
  string n1, n2;
  long long tag, radix;
  cin >> n1 >> n2 >> tag >> radix;
  if (radix<2) cout << "Impossible";
  if (tag == 2) swap(n1, n2);
  long long num1 = ToDecimal(n1,radix), num2 = 0;
  long long left = CharToLlong(*max_element(n2.begin(), n2.end()))+1;
  long long right = num1 + 1;
  while (left <= right)
  {
    auto mid = (left + right) / 2;
    num2 = ToDecimal(n2, mid);
    if (num2 == num1)
    {
      cout << mid;
      return 0;
    }
    if (num2>num1 || num2<0)right = mid - 1;    
    else  left = mid + 1;
  }

  cout << "Impossible";
}
