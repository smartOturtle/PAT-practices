#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(int argc, char* argv[])
{
	string s1;
	getline(cin, s1);
	char c;
	unordered_map<char, int> check;
	while ((c=getchar())!='\n')
	{
		check[c]++;
	}
	for (auto value : s1)
	{
		if (check.find(value)==check.end()) { cout << value; }
	}
}
