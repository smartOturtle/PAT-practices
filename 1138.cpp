#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;
vector<int> preorder;
vector<int> inorder;
template<typename Iter>
void FindFirstLeaf(int preIdx, Iter inBegin, Iter inEnd)
{
    static bool hasFind = false;
    if(hasFind)return;
    if (inEnd - inBegin == 1)
    {
        cout << *inBegin;
        hasFind = true;
        return;
    }
    Iter inPos = find(inBegin, inEnd, preorder[preIdx]);
    if (inPos == inEnd)return;
    FindFirstLeaf(preIdx + 1, inBegin, inPos);
    FindFirstLeaf(preIdx + (inPos-inBegin)+1, inPos + 1, inEnd);
}
int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    preorder.resize(size);
    inorder.resize(size);
    for (auto && value : preorder)cin >> value;
    for (auto && value : inorder)cin >> value;
    FindFirstLeaf(0, inorder.begin(), inorder.end());
}
