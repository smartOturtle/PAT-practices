#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) :value(value) {}
};
template<typename Iter>
Node* BuildTree(Iter postFirst, Iter postLast, Iter inFirst, Iter inlast)
{
    if (postFirst == postLast)return nullptr;
    auto inpos = find( inFirst, inlast, *(--postLast));
    auto node = new Node(*postLast);
    auto leftChildSize = inpos - inFirst;
    node->left = BuildTree(postFirst, postFirst + leftChildSize, inFirst, inpos);
    node->right = BuildTree(postFirst + leftChildSize, postLast, inpos + 1, inlast);
    return node;
}
void ZigzagTravelsal(Node* n)
{
    deque<Node*> q;
    q.push_back(n);
    string str=to_string(n->value);
    for (int i = 0; !q.empty(); i++)
    {
        deque<Node*> temp;
        while (!q.empty())
        {
            if (q.front()->left)temp.push_back(q.front()->left);
            if (q.front()->right)temp.push_back(q.front()->right);
            q.pop_front();
        }
        swap(temp, q);
        if (i % 2)for_each(q.rbegin(), q.rend(), [&str](Node* n) { str += ' ' + to_string(n->value); });
        else { for_each(q.begin(), q.end(), [&str](Node* n) { str += ' ' + to_string(n->value); }); }
    }
    cout << str;
}
int main()
{
    int nodeSize;
    cin >> nodeSize;
    vector<int> inorder(nodeSize);
    vector<int> postorder(nodeSize);
    for (auto& value : inorder)cin >> value;
    for (auto& value : postorder)cin >> value;
    ZigzagTravelsal(BuildTree(postorder.begin(), postorder.end(), inorder.begin(), inorder.end()));
}
