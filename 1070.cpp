#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <functional>
using namespace std;
int main(int argc, char* argv[])
{
	int kindSize, maxWeight;
	cin >> kindSize >> maxWeight;
	using WeightValue = pair<float, float>;
	vector<WeightValue> cakes(kindSize);
	for (int i = 0; i < kindSize; ++i)
	{
		cin >> cakes[i].first;
	}
	for (int i = 0; i < kindSize; ++i)
	{
		cin >> cakes[i].second;
	}
	sort(cakes.begin(), cakes.end(),
		[](const WeightValue& lhs, const WeightValue& rhs) 
		{ return(lhs.second / lhs.first) > (rhs.second / rhs.first); });
	float sum = 0;
	for (int i = 0; i < cakes.size()&&maxWeight!=0; ++i)
	{
		if(maxWeight>=cakes[i].first)
		{
			maxWeight -= cakes[i].first;
			sum += cakes[i].second;
		}
		else
		{
			sum += maxWeight / cakes[i].first*cakes[i].second;
			maxWeight = 0;
		}
	}
	printf("%.2f", sum);
}
