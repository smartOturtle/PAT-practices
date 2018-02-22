#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(int argc, char* argv[])
{
	int M, N;
	cin >> M >> N;
	unordered_map<int, int> colorFrequency;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int color;
			scanf("%d", &color);
			colorFrequency[color]++;
		}
	}
	cout<< max_element(colorFrequency.begin(), colorFrequency.end(),
		[](const pair<int, int> a, const pair<int, int> b) { return a.second < b.second; })->first;
}
