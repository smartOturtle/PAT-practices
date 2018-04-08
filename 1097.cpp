#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    string address;
    int data;
    string next="-1";
};
void PrintList(vector<Node*>& nodes)
{
    if(!nodes.empty())
    {
        for (int i = 0; i < nodes.size() - 1; ++i)
        {
            cout << nodes[i]->address << " " << nodes[i]->data << " " << nodes[i + 1]->address << "\n";
        }
        cout << nodes.back()->address << " " << nodes.back()->data << " " << -1 << "\n";
    }
}
int main(int argc, char* argv[])
{
    string head;
    int nodeSize;
    cin >> head >> nodeSize;
    unordered_map<string, Node> mem;
    for (int i = 0; i < nodeSize; ++i)
    {
        string address;
        cin >> address;
        mem[address].address = address;
        cin >> mem[address].data>>mem[address].next;
    }
    vector<Node*> nodes;
    for (string i = head; i !="-1"; i=mem[i].next)
    {
        nodes.push_back(&mem[i]);
    }
    unordered_map<int, bool> existValues;
    vector<Node*> remainNodes;
    vector<Node*> removedNodes;
    for (auto && nodePtr : nodes)
    {
        if (existValues[abs(nodePtr->data)])removedNodes.push_back(nodePtr);
        else
        {
            remainNodes.push_back(nodePtr);
            existValues[abs(nodePtr->data)] = true;
        }
    }
    
    PrintList(remainNodes);
    PrintList(removedNodes);
}
