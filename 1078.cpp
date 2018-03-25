#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
bool IsPrime(int num)
{
	if (num == 2)return true;
	if (num == 1 || num % 2 == 0)return false;
	for (int i = 3; i <= sqrt(num); i+=2)
	{
		if (num%i == 0)return false;
	}
	return true;
}
int MinimumPrime(int num)
{
	for (; !IsPrime(num); ++num){}
	return num;
}
constexpr int emptySpace = -1;
vector<int> mem;
int Insert(int num)
{
	for (int i = 0; i < mem.capacity(); ++i)
	{
		int idx = (num + i * i) % mem.size();
		if (mem[idx] == emptySpace)
		{
			mem[idx] = num;
			return idx;
		}
	}
	return -1;
}
int main(int argc, char* argv[])
{
	int maxCapacity, numSize;
	cin >> maxCapacity >> numSize;
	mem.resize(MinimumPrime(maxCapacity), emptySpace);
	string s;
	for (int i = 0; i < numSize; ++i)
	{
		int num;
		cin >> num;
		int pos = Insert(num);
		if (pos != -1)s += to_string(pos);
		else { s .push_back('-'); }
		s.push_back(' ');
	}
	s.pop_back();
	cout << s;
}
