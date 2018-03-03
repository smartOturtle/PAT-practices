#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(int argc, char* argv[])
{
	int setSize;
	cin >> setSize;
	vector<unordered_set<int>> sets(setSize);
	for (int i = 0; i < setSize; ++i)
	{
		int numSize;
		cin >> numSize;
		for (int j = 0; j < numSize; ++j)
		{
			int num;
			scanf("%d", &num);
			sets[i].insert(num);
		}
	}
	int querySize;
	cin >> querySize;
	for (int i = 0; i < querySize; ++i)
	{
		pair<int, int>setPair;
		scanf("%d %d", &setPair.first, &setPair.second);
		auto& firstSet = sets[setPair.first - 1];
		auto& secondSet = sets[setPair.second - 1];
		int distinctNumCnt = firstSet.size()+secondSet.size();
		int similarNumCnt = 0;
		for (auto num : firstSet)
		{
			if (secondSet.find(num) != secondSet.end())
			{
				distinctNumCnt--;
				similarNumCnt++;
			}
		}
		printf("%.1lf%%\n", 100.0*similarNumCnt/distinctNumCnt);
	}
}
