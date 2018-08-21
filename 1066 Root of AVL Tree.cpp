#include  <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;

struct Node
{
    int height = 1;
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* LeftRotate()
    {
        auto parent = left;
        left = parent->right;
        parent->right = this;
        return parent;
    }
    Node* RightRotate()
    {
        auto parent = right;
        right = parent->left;
        parent->left = this;
        return parent;
    }
    Node* LeftRightRotate()
    {
        left = left->RightRotate();
        return LeftRotate();
    }
    Node* RightLeftRotate()
    {
        right = right->LeftRotate();
        return RightRotate();
    }
};

struct Tree
{
    Node* root = nullptr;
    void Insert(Node*& n, int value)
    {
        if (n == nullptr)
        {
            n = new Node;
            n->value = value;
        }
        else
        {
            if (n->value > value)Insert(n->left, value);
            else { Insert(n->right, value); }
        }
        Balance(n, value);
    }
    void Insert(int value) { Insert(root, value); }
    int UpdateHeight(Node* n)
    {
        if (n == nullptr)return 0;
        return n->height = max(UpdateHeight(n->left), UpdateHeight(n->right)) + 1;
    }
    int GetHeight(Node* n)const
    {
        if (n == nullptr)return 0;
        return n->height;
    }
    void Balance(Node*& n, int value)
    {
        auto balanceFactor = GetHeight(n->left) - GetHeight(n->right);
        if (balanceFactor >= 2)
        {
            if (value > n->left->value)n = n->LeftRightRotate();
            else n = n->LeftRotate();
            UpdateHeight(n);
        }
        else if (balanceFactor <= -2)
        {
            if (value < n->right->value)n = n->RightLeftRotate();
            else n = n->RightRotate();
            UpdateHeight(n);
        }
        n->height = max(GetHeight(n->left), GetHeight(n->right)) + 1;
    }
};
int main(int argc, char* argv[])
{
    Tree tree;
    int size;
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        int num;
        cin >> num;
        tree.Insert(num);
    }
    cout << tree.root->value;
}
