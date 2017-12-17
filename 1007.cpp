#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{  int cnt;
  cin >> cnt;
  vector<int> seq(cnt);
  bool allIsNegative = true;
  for (size_t i = 0; i < cnt; i++)
  {
    cin >> seq[i];
    if (seq[i] >= 0)allIsNegative = false;
  }
  if (allIsNegative)cout << 0 << " " << seq[0] << " " << seq[cnt - 1];  
  else
  {
    int maxSum{}, currentSum{};
    int maxSeqFirst{}, maxSeqLast{};
    int first = seq[0];
    for (int i = 0; i<cnt; i++)
    {
      currentSum += seq[i];
      if (currentSum > maxSum)
      {
        maxSum = currentSum;
        maxSeqFirst = first;
        maxSeqLast = seq[i];
      }
      else if (currentSum < 0)
      {
        currentSum = 0;
        first = seq[min(cnt - 1, i + 1)];
      }
    }
    cout << maxSum << " " << maxSeqFirst << " " << maxSeqLast;
  }
}
