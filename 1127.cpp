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
#include <deque>
#include <queue>
using namespace std;
vector<int> inorder;
vector<int> postorder;

struct Node
{
    int data;
    Node* left=nullptr;
    Node* right=nullptr;
    explicit Node(int data):data(data){}
};
template<typename Iter>
Node* BuildTree(Iter postBegin,Iter postEnd,Iter inBegin,Iter inEnd)
{
    Node* n = nullptr;
    if (postEnd==postBegin)return n;
    auto inPos = find(inBegin, inEnd, *(--postEnd));
    if(inPos!=inEnd)
    {
        n = new Node(*inPos);
        n->left = BuildTree(postBegin, postBegin + (inPos - inBegin), inBegin, inPos);
        n->right = BuildTree(postEnd -(inEnd-inPos-1) , postEnd, inPos + 1, inEnd);
    }
    return n;
}
void ZigzagTravelsal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    auto layerSize = 1;
    vector<vector<int>> seqs;
    vector<int> temp;
    for (int i = 1;!q.empty(); ++i)
    {
        if (q.front()->left)q.push(q.front()->left);
        if (q.front()->right)q.push(q.front()->right);
        temp.push_back(q.front()->data);
        q.pop();
        if(i==layerSize)
        {
            seqs.push_back(temp);
            temp.clear();
            layerSize = q.size();
            i = 0;
        }
    }
    cout << seqs.front().front();
    for (int i = 1; i < seqs.size(); ++i)
    {
        if (i % 2 == 0)reverse(seqs[i].begin(), seqs[i].end());
        for (auto value : seqs[i])
        {
            cout << " " << value;
        }
    }
}
int main(int argc, char* argv[])
{
    int numSize;
    cin >> numSize;
    inorder.resize(numSize);
    postorder.resize(numSize);
    for (auto&& value : inorder)cin >> value;
    for (auto&& value : postorder)cin >> value;
    auto root= BuildTree(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
    ZigzagTravelsal(root);
}

