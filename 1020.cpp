#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
vector<int> postorder;
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
Node* BuildTree(int postIdx,int inBegin,int inEnd)
{
    if (postIdx <0 || inBegin >= inEnd)return nullptr;
    int inPos = inBegin;
    for (; inPos < inEnd; ++inPos)
    {
        if(postorder[postIdx]==inorder[inPos])break;
    }
    auto n = new Node(postorder[postIdx]);
    n->left = BuildTree(postIdx - (inEnd - inPos), inBegin, inPos);
    n->right = BuildTree(postIdx - 1,inPos + 1, inEnd);
    return n;
}
string s;
void Travelsal(Node* n)
{
    queue<Node*> q;
    q.push(n);
    while (!q.empty())
    {
        if (q.front()->left != nullptr)q.push(q.front()->left);
        if (q.front()->right != nullptr)q.push(q.front()->right);
        s += to_string(q.front()->data);
        s.push_back(' ');
        q.pop();
    }
}
int main(int argc, char* argv[])
{
    int nodeSize;
    cin >> nodeSize;
    postorder.resize(nodeSize);
    inorder.resize(nodeSize);
    for (int i = 0; i < nodeSize; ++i)
    {
        cin >> postorder[i];
    }
    for (int i = 0; i < nodeSize; ++i)
    {
        cin >> inorder[i];
    }
    Travelsal(BuildTree(postorder.size()-1, 0, inorder.size()));
    if(!s.empty())s.pop_back();
    cout << s;
}
