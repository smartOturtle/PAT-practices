#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;
int Magnititudes(const string& num)
{
	if (num == "0")return 0;
	if (num.find("0.")!=string::npos)
	{
		int pos = num.substr(2).find_first_not_of('0');
		if (pos == string::npos)return 0;
		else return -pos;
	}
	else
	{
		int last = num.find('.');
		if (last == string::npos)last = num.size();
		return last - num.find_first_not_of('0');
	}
}
string ToScientificNotation(const string& num, int digitSize)
{
	string s;
	s += "0.";
	int magnititudes = Magnititudes(num);
	int cnt = 0;
	int begin = num.find_first_not_of('0');
	if(magnititudes<0)begin = -magnititudes + 2;
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
