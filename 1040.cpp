#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int lo = 0, maxLen = 1;
string s;
void ExtendString(int left,int right)
{
	while (left>=0&&right<s.length()&&s[left]==s[right])
	{
		left--;
		right++;
	}
	//if loop has broke out,left and the right has been isub or iadd
	if (maxLen < right - left - 1)
	{
		lo = left + 1;
		maxLen = right - left - 1;
	}
}
int main(int argc, char* argv[])
{
	getline(cin, s);
	for (int i = 0; i < s.length()-1; ++i)
	{
		ExtendString(i, i);//odd
		ExtendString(i, i + 1);//even
	}
	cout << maxLen;
}
