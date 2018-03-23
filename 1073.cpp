#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	if (s.front() == '-')cout << '-';
	string digits;
	for (int i = 1; i < s.find('E'); ++i)
	{
		if (isdigit(s[i]))digits.push_back(s[i]);
	}
	int exp = stoi(s.substr(s.find('E') + 1));
	if(exp<0)
	{
		cout << "0.";
		for (int i = exp; i < -1; ++i)
		{
			cout << 0;
		}
		cout << digits;
	}
	else
	{
		const auto integerSize = exp + 1;
		if (digits.size() <= integerSize)
		{
			cout << digits;
			for (int i = 0; i < integerSize-digits.size(); ++i)
			{
				cout << 0;
			}
		}
		else
		{
			cout << digits.substr(0, integerSize);
			cout << '.';
			cout << digits.substr(integerSize);
		}
	}
}
