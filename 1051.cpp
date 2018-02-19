#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(int argc, char* argv[])
{
	int capacity, seqLength,seqSize;
	cin >> capacity >> seqLength>>seqSize;
	for (int i = 0; i < seqSize; ++i)
	{
		stack<int> stack;
		int current = 1;
		bool isRight = true;
		for (int j = 0; j < seqLength; ++j)
		{
			int pop ;
			cin >> pop;
			while (pop>=current)
			{
				stack.push(current++);
			}
			if (stack.size()>capacity|| pop != stack.top())
			{
				isRight = false;
			}
			stack.pop();
		}
		if (isRight)cout << "YES\n";
		else cout << "NO\n";
	}
}
