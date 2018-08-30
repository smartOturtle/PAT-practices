#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct Node
{
    int address;
    int value;
    int next=-1;
};
vector<Node> mem(100000);
void Print(const vector<Node>& nodes)
{
    if(nodes.empty())return;
    for (int i = 0; i < nodes.size()-1; ++i)
    {
        printf("%05d %d %05d\n", nodes[i].address, nodes[i].value, nodes[i + 1].address);
    }
    printf("%05d %d -1\n", nodes.back().address, nodes.back().value);

}
int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int head, nodeSize;
    cin >> head >> nodeSize;
    for (int i = 0; i < nodeSize; ++i)
    {
        int address, value, next;
        cin >> address >> value >> next;
        mem[address] = { address,value,next };
    }
    vector<Node> nodes;
    unordered_set<int> existedValues;
    vector<Node> removed;
    for (auto i = head; i !=-1; i=mem[i].next)
    {
        int absValue = abs(mem[i].value);
        if (existedValues.find(absValue) != existedValues.end()) { removed.push_back(mem[i]); }
        else
        {
            existedValues.insert(absValue);
            nodes.push_back(mem[i]);
        }
    }
    Print(nodes);
    Print(removed);
}
