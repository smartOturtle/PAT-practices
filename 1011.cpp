#include<iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
  char results[]{ 'W','T','L' };
  vector<vector<double>> matchs(3, vector<double>(3));
  for (auto && match : matchs)
    for (auto && value : match)
      cin >> value;
  double profit = 1;
  for (auto && match : matchs)
  {
    auto maxOdd=max_element(match.begin(), match.end());
    cout << results[distance(match.begin(), maxOdd)]<<" ";
    profit *= *maxOdd;
  }
  profit = (profit*0.65 - 1) * 2;
  printf("%.2f", profit);
}
