#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int address;
    int data;
    int next=-1;
    Node() = default;
    Node(int address,int data,int next):address(address),data(data),next(next){}
};
vector<Node> nodes(100000);
int main(int argc, char* argv[])
{
    int head, nodeSize, K;
    cin >> head >> nodeSize >> K;
    for (int i = 0; i < nodeSize; ++i)
    {
        int address, data, next;
        cin >> address >> data >> next;
        nodes[address] = { address,data,next };
    }
    vector<Node> validNodes;
    for (auto i = head; i != -1; i = nodes[i].next)validNodes.push_back(nodes[i]);
    auto negaEnd= stable_partition(validNodes.begin(), validNodes.end(), [](Node n) { return n.data < 0; });
    stable_partition(negaEnd, validNodes.end(), [K](Node n) { return n.data <= K; });
    for (int i = 0; i < validNodes.size()-1; ++i)
    {
        printf("%05d %d %05d\n", validNodes[i].address, validNodes[i].data, validNodes[i + 1].address);
    }
    printf("%05d %d -1\n", validNodes.back().address, validNodes.back().data);
}
