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

struct Node
{
    bool isBlack=true;
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int data,bool isBlack):data(data),isBlack(isBlack){}
};
void Insert(Node*& n,int value)
{
    if(n==nullptr)
    {
        if (value < 0)n = new Node(-value, false);
        else { n = new Node(value, true); }
        return;
    }
    if (abs(value) > n->data) { Insert(n->right, value); }
    else { Insert(n->left, value); }
}
int pathToLeafBlackSize = 0;
bool DFS(Node* n, bool isParentBlack, int blackSize)
{
    if (n == nullptr)
    {
        if (pathToLeafBlackSize == 0)
        {
            pathToLeafBlackSize = blackSize;
            return true;
        }
        return blackSize == pathToLeafBlackSize;
    }
    if (n->isBlack)blackSize++;
    if (!isParentBlack)if (!n->isBlack)return false;
    return DFS(n->left, n->isBlack, blackSize) && DFS(n->right, n->isBlack, blackSize);
}
int main(int argc, char* argv[])
{
    int caseSize;
    cin >> caseSize;
    for (int i = 0; i < caseSize; ++i)
    {
        int nodeSize;
        cin >> nodeSize;
        Node* n = nullptr;
        for (int j = 0; j < nodeSize; ++j)
        {
            int value;
            cin >> value;
            Insert(n, value);
        }
        if (n->isBlack)
        {
            if (DFS(n, true, 0))cout << "Yes\n";
            else { cout << "No\n"; }
            pathToLeafBlackSize = 0;
        }
        else { cout << "No\n"; }
    }
}
