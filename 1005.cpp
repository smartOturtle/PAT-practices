#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
  string s;
  cin >> s;
  int result=0;
  for (auto && value : s)
    result += value-'0';
  string spell[]{"zero","one","two","three","four","five","six","seven","eight","nine"};
  int i;
  for (i = 1; result / static_cast<int>(pow(10, i)); ++i){}
  for (i--; i >0; --i)
  {
    cout << spell[result / static_cast<int>(pow(10, i))]<<" ";
    result %= static_cast<int>(pow(10, i));
  }
  cout << spell[result];
}
