#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
bool IsPrime(int num)
{
	if (num == 1)return false;
	if (num == 2)return true;
	if (num % 2 == 0)return false;
	for (int i = 3; i < sqrt(num)+1; i+=2)
	{
		if (num%i == 0)return false;
	}
	return true;
}
int ToDecimal(const string& s,int radix)
{
	int result = 0;
	for (auto && c : s)
	{
		result = result * radix + c - '0';
	}
	return result;
}
int ReverseWithRadix(int num,int radix)
{
	string s;
	while(num!=0)
	{
		s.push_back(num%radix + '0');
		num /= radix;
	}
	return ToDecimal(s,radix);
}
int main()
{
	int num;
	int radix;
	while (true)
	{
		cin >> num;
		if(num<0)break;
		cin >> radix;
		auto reverseResult = ReverseWithRadix(num, radix);
		if (IsPrime(num)&&IsPrime(reverseResult))cout << "Yes";
		else { cout << "No"; }
		cout << '\n';
	}
}
