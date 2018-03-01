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
	string s{"0."};
	int cnt = 0;
	auto iter= find_if(num.begin(), num.end(), [](char c) { return c != '0'&&c != '.'; });
	for(;iter!=num.end();++iter)
	{
		if(*iter=='.')continue;
		s.push_back(*iter);
		if(++cnt>=digitSize)break;
	}
	if(digitSize>cnt)s += string(digitSize - cnt, '0');
	s += "*10^" + to_string(Magnititudes(num));
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
