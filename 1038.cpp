#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(int argc, char* argv[])
{
	int size;
	cin >> size;
	vector<string> strings(size);
	for (int i = 0; i < size; ++i)
	{
		cin >> strings[i];
	}
	sort(strings.begin(), strings.end(),[](const string& a, const string& b)
	{
		if (a.size() == b.size())return a < b;
		if(a.size()>b.size())
		{
			if (b == a.substr(0,b.size()))
			{
				if (a[b.size()] == b[0]){ return a + b < b + a; }
				return a[b.size()] < a[0];
			}
			else return a < b;
		}
		else
		{
			if (a == b.substr(0,a.size()))
			{
				if (b[a.size()] == b[0]){ return a+b < b+a; }
				return b[a.size()] > b[0];
			}
			else { return a < b; }
		}
		
	});
	string s;
	for (auto && str : strings)
	{
		s += str;
	}
	cout << s.substr(min(s.find_first_not_of('0'),s.size()-1));
}
