#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

struct AVLTree
{
    struct Node
    {
        int data;
        int height=1;
        Node* left=nullptr;
        Node* right=nullptr;
        explicit Node(int data):data(data){}
        Node* SingleLeftRotate()
        {
            auto parent = left;
            left = parent->right;
            parent->right = this;
            return parent;
        }
        Node* SingleRightRotate()
        {
            auto parent = right;
            right = parent->left;
            parent->left = this;
            return parent;
        }
        Node* LeftRightRotate()
        {
            left = left->SingleRightRotate();
            return SingleLeftRotate();
        }
        Node* RightLeftRotate()
        {
            right = right->SingleLeftRotate();
            return SingleRightRotate();
        }
        Node* Balance(int value)
        {
            height = max(GetHeight(left), GetHeight(right)) + 1;
            int balanceFactor = GetHeight(left) - GetHeight(right);
            auto n = this;
            if(abs(balanceFactor)>=2)
            {
                if(balanceFactor>0)
                {
                    if (value > left->data) { n = LeftRightRotate(); }
                    else { n = SingleLeftRotate(); }
                }
                else
                {
                    if (value > right->data) { n = SingleRightRotate(); }
                    else { n = RightLeftRotate(); }
                }
                UpdateHeight(n);
            }
            return n;
        }
        static int GetHeight(Node* n)
        {
            if (n == nullptr)return 0;
            return n->height;
        }
        static int UpdateHeight(Node* n)
        {
            if (n == nullptr)return 0;
            return n->height = max(UpdateHeight(n->left), UpdateHeight(n->right)) + 1;
        }
    };
    Node* root_=nullptr;
    
    void Insert(int value)
    {
        Insert(value, root_);
    }
    void Insert(int value,Node*& n)
    {
        if (n == nullptr)n = new Node(value);
        else
        {
            if (value < n->data)Insert(value, n->left);
            else { Insert(value, n->right); }
            n = n->Balance(value);
        }
    }
    bool LevelOrderTravelsal()const
    {
        queue<Node*> q;
        if (root_ != nullptr)q.push(root_);
        bool isCompleteBTree = true;
        Node* last = nullptr;
        string s;
        while (!q.empty())
        {
            if (q.front()->left)
            {
                q.push(q.front()->left);
                if (q.front()->right)q.push(q.front()->right);
                else if(last==nullptr)last = q.back();
            }
            else
            {
                if (q.front()->right)
                {
                    q.push(q.front()->right);
                    isCompleteBTree = false;
                }
                else { if(last==nullptr)last = q.back(); }
            }
            if (last != nullptr&&isCompleteBTree)isCompleteBTree = last == q.back();
            s += to_string(q.front()->data) + " ";
            q.pop();
        }
        if (!s.empty())s.pop_back();
        cout << s<<'\n';
        return isCompleteBTree;
    }
};

int main(int argc, char* argv[])
{
    AVLTree avlTree;
    int size;
    cin >> size;
    for (int i = 0; i < size; ++i)
    {
        int value;
        cin >> value;
        avlTree.Insert(value);
    }
    if (avlTree.LevelOrderTravelsal())cout << "YES";
    else { cout << "NO"; }
}
