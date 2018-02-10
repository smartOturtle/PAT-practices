#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	int size;
	cin >> size;
	vector<int> numbers(size);
	unordered_map<int, int> numTimes;
	for (int i = 0; i < size; ++i)
	{
		cin >> numbers[i];
		numTimes[numbers[i]]++;
	}
	for (auto number : numbers)
	{
		if(numTimes[number]==1)
		{
			cout << number;
			return 0;
		}
	}
	cout << "None";
}
