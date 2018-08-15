#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    Node* left=nullptr;
    Node* right=nullptr;
    int value;
    explicit Node(int value):value(value){}
};

struct Tree
{
    Node* root = nullptr;
    void Insert(int value,Node*& n)
    {
        if(n==nullptr)
        {
            n = new Node(value);
            return;
        }
        if (n->value > value)Insert(value, n->left);
        else { Insert(value, n->right); }
    }
    void Insert(int value) { Insert(value, root); }
};
vector<int> travelsal;
void Travelsal(Node* n,int type)
{
    if (n)
    {
        if (type == 0)travelsal.push_back(n->value);
        Travelsal(n->left, type);
        Travelsal(n->right, type);
        if (type == 1)travelsal.push_back(n->value);
    }
}
void Swap(Node* n)
{
    if(n==nullptr)return;
    swap(n->left, n->right);
    Swap(n->left);
    Swap(n->right);
}
int main(int argc, char* argv[])
{
    Tree tree;
    int size;
    cin >> size;
    vector<int> compared;
    for (int i = 0; i < size; ++i)
    {
        int value;
        cin >> value;
        compared.push_back(value);
        tree.Insert(value);
    }
    Travelsal(tree.root, 0);
    if(travelsal!=compared)
    {
        Swap(tree.root);
        travelsal.clear();
        Travelsal(tree.root, 0);
    }
    if (travelsal != compared)cout << "NO";
    else
    {
        travelsal.clear();
        Travelsal(tree.root, 1);
        cout << "YES\n";
        cout << travelsal.front();
        for (int i = 1; i < travelsal.size(); ++i)
        {
            cout << " " << travelsal[i];
        }
    }
}
