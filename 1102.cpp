#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
//There are two simple ways
//First method,we can just reverse the travelsal sequence
//like first visit right rather left
//Second method ,Construct a Type which just reverse the left and the right
//postion in the struct
//this is only makes sense in standard layout object or called plain old data
//if you want to know more about POD,please refer cppreference.com
struct Node
{
    int value;
    int left=-1;
    int right=-1;
};

struct ReverseNode
{
    int value;
    int right = -1;
    int left = -1;
};
vector<Node> nodes;
vector<ReverseNode*> reverseNodes;
string inorder;
void Travelsal(int idx)
{
    if(idx==-1)return;
    Travelsal(nodes[idx].right);
    inorder += (to_string(nodes[idx].value) + " ");
    Travelsal(nodes[idx].left);
}
int main(int argc, char* argv[])
{
    int nodeSize;
    cin >> nodeSize;
    vector<int> appeared(nodeSize);
    nodes.resize(nodeSize);
    for (int i = 0; i < nodeSize; ++i)
    {
        string left,right;
        cin >> left>>right;
        if (left.front() != '-')appeared[nodes[i].left = stoi(left)]=1;
        if (right.front() != '-')appeared[nodes[i].right = stoi(right)]=1;
        nodes[i].value = i;
    }
    auto rootIdx = find(appeared.begin(), appeared.end(), 0)-appeared.begin();
    for (auto& node : nodes)
    {
        reverseNodes.push_back(reinterpret_cast<ReverseNode*>(&node));
    }
    Travelsal(rootIdx);
    queue<ReverseNode*> q;
    q.push(reverseNodes[rootIdx]);
    string levelOrder;
    while (!q.empty())
    {
        if (q.front()->left != -1)q.push(reverseNodes[q.front()->left]);
        if (q.front()->right != -1)q.push(reverseNodes[q.front()->right]);
        levelOrder += (to_string(q.front()->value) + " ");
        q.pop();
    }
    levelOrder.pop_back();
    inorder.pop_back();
    cout << levelOrder << '\n' << inorder;
}
