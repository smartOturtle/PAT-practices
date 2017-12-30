#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;
vector<list<int>> gragh;
vector < bool > collected;
int maxHeight = 0;
vector<int> temp;
void DFS(int idx, int height)
{
  if(height>maxHeight)
  {
    temp.assign({ idx });
    maxHeight = height;
  }
  else if (height == maxHeight)temp.push_back(idx);
  collected[idx] = true;
  for (auto && value : gragh[idx])
  {
    if (!collected[value])DFS(value, height + 1);
  }
}
int main()
{
  int n;
  cin >> n;
  gragh.resize(n);
  for (int i = 0; i < n - 1; ++i)
  {
    int one, other;
    cin >> one >> other;
    gragh[one - 1].push_back(other - 1);
    gragh[other - 1].push_back(one - 1);
  }
  collected.resize(gragh.size());
  int cnt = 0;
  set<int> roots;
  for (int i = 0; i < gragh.size(); ++i)
  {
    if(!collected[i])
    {
      DFS(i, 1);
      if(i==0)
      {
        for (auto && value : temp)
          roots.insert(value);
      }
      cnt++;
    }
  }
  if (cnt != 1)printf("Error: %d components", cnt);
  else
  {
    temp.clear();
    maxHeight = 0;
    collected.assign(gragh.size(), false);
    DFS(*roots.begin(), 1);
    for (auto && value : temp)
      roots.insert(value);
    for (auto && value : roots)
      cout << value+1 << '\n';
  }
}
