#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	string s;
	getline(cin, s);
	int n2 = max(static_cast<int>(ceil((s.size() + 2) / 3.0)),3);
	if ((s.size() - n2) % 2 != 0)n2++;
	int k = (s.size() - n2) / 2;
	string space(n2 - 2, ' ');
	for (int i = 0; i < k; ++i)
	{
		cout << s[i] << space << s[s.size() - 1 - i]<<'\n';
	}
	cout << s.substr(k, n2);
}
