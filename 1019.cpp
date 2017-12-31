#include <iostream>
#include <string>
#include <deque>
using namespace std;
bool IsPalindromic(const deque<int>& s)
{
	int middle = s.size() / 2,offset=0;
	if (s.size() % 2 == 0)offset = 1;
	for (int i = 0; middle + i <s.size(); ++i)
	{
		if (s[middle - i-offset] != s[middle+ i]) { return false; }
	}
	return true;
}
int main()
{
	int num;
	int radix;
	cin >> num >> radix;
	deque<int> result;
	while (num)
	{
		result.push_front(num%radix);
		num /= radix;
	}
	if(IsPalindromic(result)) cout<<"Yes";
  	else cout<<"No";
	cout << "\n";
	cout << result.front();
	for (int i = 1; i < result.size(); ++i)
	{
		cout <<" "<< result[i];
	}
}
