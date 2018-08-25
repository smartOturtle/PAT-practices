#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int value;
    int next=-1;
};
vector<Node> mem(100000);
int ReverseLinkedList(int head,int k,int size)
{
    if (size < k)return head;
    int newHead = -1, oldHead = head;
    for (int i = 0; i < k; ++i)
    {
        int temp = mem[oldHead].next;
        mem[oldHead].next = newHead;
        newHead = oldHead;
        oldHead = temp;
    }
    mem[head].next = ReverseLinkedList(oldHead, k, size - k);
    return newHead;
}
int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int head, nodeSize, k;
    cin >> head >> nodeSize >> k;
    for (int i = 0; i < nodeSize; ++i)
    {
        int address;
        cin >> address;
        cin >> mem[address].value >> mem[address].next;
    }
    nodeSize = 0;
    for (int iter=head; iter != -1; iter = mem[iter].next, ++nodeSize){}
    head= ReverseLinkedList(head, k, nodeSize);
    while (head!=-1)
    {
        printf("%05d %d ", head, mem[head].value);
        if (mem[head].next == -1)printf("-1\n");
        else { printf("%05d\n", mem[head].next); }
        head = mem[head].next;
    }
}

