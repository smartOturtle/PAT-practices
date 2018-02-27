#include<iostream>
using namespace std;
int NextFactor(int n, int begin)
{
	for (int i = begin; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return i;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	cout << n << '=';
	int factor = NextFactor(n,2);
	int i = 0;
	while (true)
	{
		if (factor == 0)
		{
			cout<<n;
			break;
		}
		++i;
		n /= factor;
		int nextFactor = NextFactor(n, factor);
		if(nextFactor!=factor)
		{
			cout << factor;
			if (n == factor)
			{
				cout << '^' << i + 1;
				break;
			}
			if (i > 1)cout << '^' << i;
			i = 0;
			cout << '*';
			factor = nextFactor;
		}
	}
}
