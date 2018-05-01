#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    int left = -1;
    int right = -1;
};
vector<Node> nodes(20000);
unordered_map<int, bool> exist(20000);
void Insert(int root, int id)
{
    if(root==id)return;
    if (nodes[id].data < nodes[root].data)
    {
        if (nodes[root].left == -1) nodes[root].left = id;
        else Insert(nodes[root].left, id);
    }
    else
    {
        if (nodes[root].right == -1) nodes[root].right = id;
        else Insert(nodes[root].right, id);
    }
}
int LCA(int lhsValue, int rhsValue, int root)
{
    while (true)
    {
        if (lhsValue<nodes[root].data && rhsValue<nodes[root].data)root = nodes[root].left;
        else if (lhsValue > nodes[root].data && rhsValue > nodes[root].data)root = nodes[root].right;
        else return root;
    }
}
int root = 0;
int main(int argc, char* argv[])
{
    int querySize, nodeSize;
    cin >> querySize >> nodeSize;
    for (int i = 0; i<nodeSize; i++)
    {
        cin >> nodes[i].data;
        exist[nodes[i].data] = true;
        Insert(root, i);
    }
    for (int i = 0; i < querySize; ++i)
    {
        int lhsValue, rhsValue;
        cin >> lhsValue >> rhsValue;
        auto islhsExist = exist[lhsValue];
        auto isRhsExist = exist[rhsValue];
        if (islhsExist&&isRhsExist)
        {
            int lca = LCA(lhsValue,rhsValue,root);
            if (nodes[lca].data == rhsValue) { printf("%d is an ancestor of %d.\n", rhsValue, lhsValue); }
            else if (nodes[lca].data == lhsValue) { printf("%d is an ancestor of %d.\n", lhsValue, rhsValue); }
            else printf("LCA of %d and %d is %d.\n", lhsValue, rhsValue, nodes[lca].data);
        }
        else
        {
            if (!islhsExist && !isRhsExist)printf("ERROR: %d and %d are not found.\n", lhsValue, rhsValue);
            else
            {
                if (islhsExist)printf("ERROR: %d is not found.\n", rhsValue);
                else printf("ERROR: %d is not found.\n", lhsValue);
            }
        }
    }
}

