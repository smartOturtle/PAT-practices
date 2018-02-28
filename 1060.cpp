#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
int Magnititudes(const string& num)
{
	auto dotPos = find(num.begin(),num.end(),'.');
	auto firstNotZeroPos = find_if(num.begin(), num.end(), [](char c) { return c != '0'&&c!='.'; });
	if (firstNotZeroPos==num.end()) return 0;
	if (firstNotZeroPos < dotPos) return dotPos - firstNotZeroPos;
	return dotPos - firstNotZeroPos + 1;
}
string ToScientificNotation(const string& num, int digitSize)
{
	string s;
	s += "0.";
	int magnititudes = Magnititudes(num);
	int cnt = 0;
	int begin = num.find_first_not_of('0');
	if(magnititudes<0)begin = -magnititudes + begin+1;
	for (int i = begin;; i++)
	{
		if (i >= num.size())s.push_back('0');
		else
		{
			if (num[i] == '.')continue;
			s.push_back(num[i]);
		}
		if (++cnt == digitSize)break;
	}
	s.push_back('*');
	s += "10^" + to_string(magnititudes);
	return s;
}
int main(int argc, char *argv[])
{
	int digitSize;
	string a, b;
	cin >> digitSize >> a >> b;
	a = ToScientificNotation(a, digitSize);
	b = ToScientificNotation(b, digitSize);
	if (a == b)cout << "YES " << a;
	else cout << "NO " << a << " " << b;
}
