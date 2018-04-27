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
#include <stack>
using namespace std;

struct Node
{
    string data;
    int left=-1;
    int right = -1;
    explicit  Node(string data):data(data){}
};
vector<Node> nodes;
int root;
void Travelsal(int idx)
{
    if(idx<0)return;
    bool hasParenthese = (idx!=root&&(nodes[idx].left>=0 || nodes[idx].right>=0));
    if (hasParenthese)cout << '(';
    Travelsal(nodes[idx].left);
    cout<<nodes[idx].data;
    Travelsal(nodes[idx].right);
    if (hasParenthese)cout << ')';
}
int main(int argc, char* argv[])
{
    int nodeSize;
    cin >> nodeSize;
    deque<bool> appeared(nodeSize);
    for (int i = 0; i < nodeSize; ++i)
    {
        string data;
        int left;
        int right;
        cin >> data >> left >> right;
        nodes.emplace_back(data);
        if (left > 0)appeared[nodes.back().left = left - 1]=true;
        if (right > 0)appeared[nodes.back().right = right - 1]=true;
    }
    root = find(appeared.begin(), appeared.end(), false) - appeared.begin();
    Travelsal(root);
}
