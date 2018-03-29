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
	int N, p;
	cin >> N >> p;
	vector<long long> seq(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> seq[i];
	}
	sort(seq.begin(), seq.end());
	int maxLength = 0;
	for (int i = 0; i < seq.size(); ++i)
	{
		auto pos = upper_bound(seq.begin() + i, seq.end(), seq[i] * p);
		maxLength = max<int>(maxLength, pos - (seq.begin() + i));
	}
	cout << maxLength;
}
