#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;

int main(int argc, char* argv[])
{
	string needType;
	string actual;
	cin >> needType >> actual;
	for (auto& value : needType)
	{
		value = toupper(value);
	}
	for (auto& value : actual)
	{
		value = toupper(value);
	}
	unordered_map<char, bool> hasOutput;
	for (auto value : needType)
	{
		if (!hasOutput[value]&&actual.find(value)==-1)
		{
			cout << value;
			hasOutput[value] = true;
		}
	}
}
