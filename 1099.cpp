#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    int left=-1;
    int right=-1;
};
vector<Node> nodes;
vector<int> keys;
int keysIdx = 0;
void FixValue(int nodesIdx)
{
    if (nodes[nodesIdx].left != -1)FixValue(nodes[nodesIdx].left);
    nodes[nodesIdx].data = keys[keysIdx];
    keysIdx++;
    if(nodes[nodesIdx].right != -1)FixValue(nodes[nodesIdx].right);
}
void Travelsal(int rootIdx)
{
    queue<int> q;
    q.push(rootIdx);
    string s;
    while (!q.empty())
    {
        if (nodes[q.front()].left != -1)q.push(nodes[q.front()].left);
        if (nodes[q.front()].right != -1)q.push(nodes[q.front()].right);
        s += to_string(nodes[q.front()].data);
        s.push_back(' ');
        q.pop();
    }
    s.pop_back();
    cout << s;
}
int main(int argc, char* argv[])
{
    int nodeSize;
    cin >> nodeSize;
    nodes.resize(nodeSize);
    for (int i = 0; i < nodeSize; ++i)
    {
        cin >> nodes[i].left >> nodes[i].right;
    }
    keys.resize(nodeSize);
    for (int i = 0; i < keys.size(); ++i)
    {
        cin >> keys[i];
    }
    sort(keys.begin(), keys.end());
    FixValue(0);
    Travelsal(0);
}
