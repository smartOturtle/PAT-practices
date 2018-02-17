#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char* argv[])
{
	int N;
	cin >> N;
	vector<int> eachDist(N);
	vector<int> dis(N);//the distance is based on #1 to the other
	int sum=0;
	for (int i = 0; i < N-1; ++i)
	{
		scanf("%d", &eachDist[i]);
		sum += eachDist[i];
		dis[i+1] = sum;
	}
	scanf("%d", &eachDist[N-1]);
	sum += eachDist[N-1];
	int querySize;
	cin >> querySize;
	for (int i = 0; i < querySize; ++i)
	{
		int begin, end;
		scanf("%d %d", &begin, &end);
		begin--, end--;
		if (begin > end)swap(begin, end);
		cout << min(dis[end]-dis[begin], sum-(dis[end] - dis[begin])) << '\n';
	}
}
