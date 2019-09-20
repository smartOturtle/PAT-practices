#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  int c = a + b;
  if(c<0)
  {
    cout << "-";
    c = -c;
  }
  int k = 1000;
  int i;
  for (i = 1;c/int(pow(k, i)) ; ++i){ }
  //同步测试
  for (int j = i - 1; j >=0; --j)
  {
    int head = c / pow(k, j);
    if(j!=i-1)printf("%03d", head);
    else cout << head;
    if(j>0)cout<< ",";
    c -= head*pow(k, j);
  }
}
