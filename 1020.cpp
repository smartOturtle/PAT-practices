#include<iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
  int data;
  int left;
  int right;
  explicit Node(int data_):data(data_),left(-1),right(-1){}
};
using Section = pair<int, int>;
struct PartitonPoint
{
  int idx;
  Section left{-1,-1};
  Section right{ -1,-1 };

  explicit PartitonPoint(int idx, Section left = { -1,-1 }, Section right = { -1,-1 }) :
    idx(idx), left(left), right(right)
  {
  }
};
vector<int> postorder;
vector<Node> inorder;
int FindInorderIdx(int value)
{
  for (int i = 0; i < inorder.size(); ++i)
    if (inorder[i].data == value)return i;
  return -1;
}
void Traversal(int root)
{
  cout << inorder[root].data;
  queue<int> q;
  if(inorder[root].left!=-1)q.push(inorder[root].left);
  if (inorder[root].right != -1)q.push(inorder[root].right);
  while (!q.empty())
  {
    cout <<" "<< inorder[q.front()].data;
    if (inorder[q.front()].left != -1)q.push(inorder[q.front()].left);
    if (inorder[q.front()].right != -1)q.push(inorder[q.front()].right);
    q.pop();
  }
}
int main()
{
  int size;
  cin >> size;
  postorder.resize(size);
  for (int i = 0; i < size; ++i)
    cin >> postorder[i];
  for (int i = 0; i < size; ++i)
  {
    int data;
    cin >> data;
    inorder.emplace_back(data);
  }
  stack<PartitonPoint> points;
  auto rootIdx = FindInorderIdx(postorder.back());
  postorder.pop_back();
  points.push(PartitonPoint{ rootIdx,{ 0,rootIdx },{ rootIdx + 1,size } });
  while (!postorder.empty())
  {
    auto idx = FindInorderIdx(postorder.back());
    Section section;
    bool isRight;
    while (true)
    {
      if (idx > points.top().idx)
      {
        section = points.top().right;
        isRight = true;
      }
      else
      {
        section = points.top().left;
        isRight = false;
      }
      if (idx >= section.first&&idx<section.second)break;
      points.pop();
    }
    if (isRight) { inorder[points.top().idx].right = idx; }
    else inorder[points.top().idx].left = idx;
    points.push(PartitonPoint{ idx,{section.first,idx},{idx + 1,section.second} });
    postorder.pop_back();
  }
  Traversal(rootIdx);
}
