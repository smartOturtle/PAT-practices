#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;
vector<int> preorder;
vector<int> postorder;
struct Node
{
    int data;
    Node* left=nullptr;
    Node* right=nullptr;
    explicit  Node(int data):data(data){}
};
int preIdx = 0;
bool isUnique = true;
template<typename Iter>
Iter BuildTree(Iter postBegin,Iter postEnd,Node*& n)
{
    if (preIdx >= preorder.size())return postEnd;
    auto postIter = find(postBegin, postEnd, preorder[preIdx]);
    if (postIter != postEnd)
    {
        preIdx++;
        n = new Node(*postIter);
        auto leftPostEnd = BuildTree(postBegin, postIter, n->left);
        BuildTree(leftPostEnd, postIter, n->right);
        if (++leftPostEnd == postIter)isUnique = false;
    }
    return postIter;
}
string s;
void Travelsal(Node* n)
{
    if(n==nullptr)return;
    Travelsal(n->left);
    s += to_string(n->data) + " ";
    Travelsal(n->right);
}
int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    preorder.resize(size);
    postorder.resize(size);
    for_each(preorder.begin(), preorder.end(), [](int& value) { cin >> value; });
    for_each(postorder.begin(), postorder.end(), [](int& value) { cin >> value; });
    Node* root;
    BuildTree(postorder.begin(), postorder.end(),root);
    if (isUnique)cout << "Yes\n";
    else { cout << "No\n"; }
    Travelsal(root);
    if (!s.empty())s.pop_back();
    cout << s<<'\n';
}
