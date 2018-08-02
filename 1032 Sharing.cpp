#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
using namespace std;
array<int,100000> ad;
int main(int argc, char* argv[])
{
	int head1, head2, nodeSize;
	scanf("%d %d %d", &head1, &head2, &nodeSize);
	for (int i = 0; i < nodeSize; ++i)
	{
		char data;
		int add, next;
		scanf("%d %c %d", &add, &data, &next);
		ad[add] = next;
	}
	unordered_map<int, int> check;
	while(head1!=-1)
	{
		check[head1]++;
		head1 = ad[head1];
	}
	while (head2 != -1)
	{
		if(++check[head2]>1)break;
		head2 = ad[head2];
	}
	if(head2>=0)printf("%05d", head2);
	else cout << head2;
}
