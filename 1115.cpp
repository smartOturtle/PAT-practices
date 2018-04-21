#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <sstream>
using namespace std;

struct Node
{
    int value;
    Node* left=nullptr;
    Node* right=nullptr;
    explicit Node(int value):value(value){}
};

struct Tree
{
    Node* root = nullptr;
    void Insert(int value)
    {
        Insert(root, value);
    }
    void Insert(Node*& n,int value)
    {
        if (n == nullptr)n = new Node(value);
        else
        {
            if (value <= n->value)Insert(n->left, value);
            else { Insert(n->right, value); }
        }
    }
};
struct ResultByLayer
{
    int maxLayer;
    vector<int> result;
    bool operator()(int layer)const { return maxLayer == layer || maxLayer - 1 == layer; }
    explicit ResultByLayer(int maxLayer) :maxLayer(maxLayer) {}
};
int LevelOrderTravelsal(Node* root,ResultByLayer& resultByLayer)
{
    int layer = 0, last = 1;
    queue<Node*> q;
    q.push(root);
    for (int i = 1; !q.empty(); ++i)
    {
        if (q.front()->left != nullptr)q.push(q.front()->left);
        if (q.front()->right != nullptr)q.push(q.front()->right);
        q.pop();
        if (i == last)
        {
            layer++;
            last = q.size();
            i = 0;
            if (resultByLayer(layer+1))resultByLayer.result.push_back(last);
        }
    }
    return layer;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    Tree tree;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        tree.Insert(value);
    }
    ResultByLayer result(-1);
    int maxLayer = LevelOrderTravelsal(tree.root, result);
    result = ResultByLayer(maxLayer);
    LevelOrderTravelsal(tree.root, result);
    if (result.result.empty())printf("1 + 0 = 1");
    else printf("%d + %d = %d", result.result[1], result.result[0], result.result[1] + result.result[0]);
}

