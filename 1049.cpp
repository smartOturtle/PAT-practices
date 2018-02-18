#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;
int Magnitude(int num)
{
	for (int i = 0; ; ++i)
	{
		num /= 10;
		if (num == 0)return pow(10,i);
	}
}
int OneSize(int num)
{
	if (num == 0)return 0;
	if (num < 10)return 1;
	int magnitude = Magnitude(num);
	return 
		OneSize(num % magnitude) + 
		num / magnitude * OneSize(magnitude - 1) +
		min(magnitude, num - magnitude + 1);
}
int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << OneSize(N);
}
