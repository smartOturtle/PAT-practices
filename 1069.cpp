#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <functional>
using namespace std;
void Calculate(string& s)
{
	sort(s.begin(), s.end());
	auto minNum = stoi(s);
	reverse(s.begin(), s.end());
	auto maxNum = stoi(s);
	char cStr[5];
	sprintf(cStr, "%04d", maxNum - minNum);
	s = cStr;
	printf("%04d - %04d = %s\n", maxNum, minNum, s.data());
}
int main(int argc, char* argv[])
{
	int num;
	cin >> num;
	char cStr[5];
	sprintf(cStr, "%04d", num);
	string s = cStr;
	Calculate(s);
	while (s!="0000" && s!="6174")Calculate(s);
}
