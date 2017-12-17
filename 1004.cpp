#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
unordered_map<int, vector<int>> nodes;
void LevelOrderTraversal()
{
  queue<int> q;
  auto& root = nodes[01];
  if (root.empty())
  {
    cout << 1;
    return;
  }
  for (auto && child : root)
    q.push(child);
  int cnt = 0, last = root.size(), leafSize = 0;
  cout << 0;
  for (int i = 0; !q.empty(); q.pop())
  {
    auto& children = nodes[q.front()];
    if (children.empty())leafSize++;
    else
    {
      for (auto child : children)
        q.push(child);
      cnt += children.size();
    }
    if (++i == last)
    {
      last = cnt;
      cnt = 0;
      i = 0;
      cout << ' ' << leafSize;
      leafSize = 0;
    }
  }
}
void Input()
{
  int parentId, childrenSize;
  cin >> parentId >> childrenSize;
  if (nodes.find(parentId) == nodes.end())
    nodes.insert({ parentId,{} });
  for (int i = 0; i < childrenSize; ++i)
  {
    int id;
    cin >> id;
    if(nodes.find(id)==nodes.end())
      nodes.insert({ id,{} });
    nodes[parentId].push_back(id);
  }
}
int main()
{
  int totalSize, nonLeafSize;
  cin >> totalSize >> nonLeafSize;
  for (int i = 0; i < nonLeafSize; ++i) Input();
  LevelOrderTraversal();
}
