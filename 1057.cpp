#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Stack
{
public:
	static constexpr int maxValue = 1e5;
	void Push(int value)
	{
		stack.push_back(value);
		Update(value, 1);
	}
	int Pop()
	{
		int top = stack.back();
		stack.pop_back();
		Update(top, -1);
		return top;
	}
	bool Empty() { return stack.empty(); }
	int PeekMedian()
	{
		int left = 1, right = maxValue, k = (stack.size()+1) / 2;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (RangeSum(mid) >= k)
				right = mid;
			else
				left = mid + 1;
		}
		//get the minimum left for left equals to k
		return left;
	}

private:
	vector<int> stack;
	array<int, 100001> bITree{};//bITree[i]=sum foreach [i-Lowbit(i)+1,i]
	int Lowbit(int value) { return value & -value; }
	void Update(int modifyPos, int value)
	{
		for (int i = modifyPos; i <= maxValue; i+=Lowbit(i))
		{
			bITree[i] += value;
		}	
	}
	int RangeSum(int value)
	{
		int sum = 0;
		for (; value >0; value-=Lowbit(value))
		{
			sum+= bITree[value];
		}
		return sum;
	}
};
int main(int argc, char* argv[])
{
	int size;
	cin >> size;
	Stack stack;
	using Instruction = array<char, 5>;
	for (int i = 0; i < size; ++i)
	{
		Instruction instruction;
		scanf("%4s", instruction.data());
		if (instruction == Instruction{ "Push" })
		{
			int value;
			scanf("%d", &value);
			stack.Push(value);
		}
		else if(instruction==Instruction{"Peek"})
		{
			char s[7];
			scanf("%s",s);
			if (stack.Empty())printf("Invalid\n");
			else	printf("%d\n", stack.PeekMedian());
		}
		else//pop
		{
			if (stack.Empty())printf("Invalid\n");
			else printf("%d\n", stack.Pop());
		}
	}
}
