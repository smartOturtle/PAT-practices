#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;
int main()
{
	string s;
	cin >> s;
	unordered_map<int, int> check;
	list<int> l{0};
	for (auto c : s)
	{
		int digit = c - '0';
		++check[digit];
	}
	for(auto i=s.rbegin();i!=s.rend();++i)
	{
		int digit = (*i - '0') * 2;
		l.front() += digit % 10;
		l.push_front(digit / 10);
	}
	if (l.front() == 0)l.pop_front();
	if (s.size() != l.size())cout << "No\n";
	else
	{
		for (auto value : l)
		{
			check[value]--;
		}
		auto right= all_of(check.begin(), check.end(), [](const pair<int, int>& a) { return a.second == 0; });
		if (right)cout << "Yes\n";
		else cout << "No\n";
	}
	for (auto value : l)
	{
		cout << value;
	}
}
