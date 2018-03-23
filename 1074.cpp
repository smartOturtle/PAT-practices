#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	int data;
	int next = -1;
	Node(){}
	Node(int data,int next):data(data),next(next)
	{
		
	}
};
vector<Node> nodes(100000);
int Reverse(int begin,int size,int k)
{
	if (size < k)return begin;
	int oldHead = begin, newHead = -1;
	for (int i = 0; i < k; ++i)
	{
		int temp = nodes[oldHead].next;
		nodes[oldHead].next = newHead;
		newHead = oldHead;
		oldHead = temp;
	}
	nodes[begin].next = Reverse(oldHead, size - k, k);
	return newHead;
}
void PrintAddress(int address)
{
	if (address >= 0)printf("%05d", address);
	else { cout << address; }
}
int main()
{
	int head, nodeSize, k;
	cin >> head >> nodeSize >> k;
	for (int i = 0; i < nodeSize; ++i)
	{
		int address, data, next;
		cin >> address >> data >> next;
		nodes[address] = { data,next };
	}
	int size=0;
	for (int i = head; i !=-1; i=nodes[i].next,size++){}
	head = Reverse(head, size, k);
	for (int i = head; i != -1; i = nodes[i].next)
	{
		PrintAddress(i);
		cout <<" "<< nodes[i].data<<" ";
		PrintAddress(nodes[i].next);
		cout << '\n';
	}
}
