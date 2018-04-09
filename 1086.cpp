#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
vector<int> preorder;
vector<int> inorder;

struct Node
{
    int data;
    Node* left=nullptr;
    Node* right = nullptr;
    explicit Node(int data):data(data)
    {
        
    }
};
Node* BuildTree(int preIdx,int inBegin,int inEnd)
{
    if (preIdx >= preorder.size() || inBegin >= inEnd)return nullptr;
    int inPos = inBegin;
    for (; inPos < inEnd; ++inPos)
    {
        if(preorder[preIdx]==inorder[inPos])break;
    }
    auto n = new Node(preorder[preIdx]);
    n->left = BuildTree(preIdx + 1, inBegin,inPos );
    n->right = BuildTree(preIdx + (inPos - inBegin) + 1, inPos+1,inEnd);
    return n;
}
string s;
void Travelsal(Node* n)
{
    if(n==nullptr)return;
    Travelsal(n->left);
    Travelsal(n->right);
    s += to_string(n->data);
    s.push_back(' ');
}
int main(int argc, char* argv[])
{
    int nodeSize;
    cin >> nodeSize;
    string instruction;
    stack<int> stack;
    for (int i = 0; i < 2*nodeSize; ++i)
    {
        cin >> instruction;
        if(instruction=="Push")
        {
            int value;
            cin >> value;
            stack.push(value);
            preorder.push_back(value);
        }
        else
        {
            inorder.push_back(stack.top());
            stack.pop();
        }
    }
    Travelsal(BuildTree(0, 0, inorder.size()));
    if(!s.empty())s.pop_back();
    cout << s;
}
