#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
	int size;
	cin >> size;
	vector<int> seq(size);
	for (int i = 0; i < seq.size(); ++i)
	{
		cin >> seq[i];
	}
	int cnt = 0;
	if (seq[0] != 0)
	{
		cnt--;
		for (int i = 0; seq[i] != i; )
		{
			cnt++;
			int tmp = seq[i];
			seq[i] = i;
			i = tmp;
		}
	}
	for (int i = 1; i < seq.size(); ++i)
	{
		if(seq[i]!=i)
		{
			cnt ++;
			for (int j = i; seq[j] != j; )
			{
				cnt++;
				int tmp = seq[j];
				seq[j] = j;
				j = tmp;
			}
		}
	}
	cout << cnt;
}
