#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int address;
	int data;
	int next;
	bool operator<(const Node& node)const
	{
		return data < node.data;
	}
};

int main(int argc, char* argv[])
{
	int size,head;
	cin >> size >> head;
	vector<Node> nodes(100000);
	for (int i = 0; i < size; ++i)
	{
		int address;
		scanf("%d", &address);
		nodes[address].address = address;
		scanf("%d %d",&nodes[address].data,&nodes[address].next);
	}
	vector<Node> linkedList;
	while (head!=-1)
	{
		linkedList.push_back(nodes[head]);
		head = nodes[head].next;
	}
	if(!linkedList.empty())
	{
		sort(linkedList.begin(), linkedList.end());
		printf("%d %05d\n", linkedList.size(), linkedList[0].address);
		for (int i = 0; i < linkedList.size() - 1; ++i)
		{
			printf("%05d %d %05d\n", linkedList[i].address, linkedList[i].data, linkedList[i + 1].address);
		}
		printf("%05d %d -1", linkedList[linkedList.size() - 1].address, linkedList[linkedList.size() - 1].data);
	}
	else
	{
		printf("0 -1\n");
	}
}
