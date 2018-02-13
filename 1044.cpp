#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <deque>
#include <functional>
using namespace std;

struct Segement
{
	int sum=INT32_MAX;
	int start=-1;
	int end=-1;
	explicit operator int() const{ return sum; }
	Segement(){}
	Segement(int sum,int start,int end):
	sum(sum),start(start),end(end)
	{ }
};
int main(int argc, char* argv[])
{
	int nodeSize,amount;
	cin >> nodeSize >> amount;
	vector<int> nodes(nodeSize);
	for (int i = 0; i < nodeSize; ++i)
	{
		cin >> nodes[i];
	}
	vector<pair<int, int>> exactStartEnd;
	vector<Segement> closest(1);
	int sum = 0;
	deque<int> chains;
	int start = 0,i=0;
	for (; i < nodeSize; ++i)
	{
		sum += nodes[i];
		chains.push_back(nodes[i]);
		if (sum>=amount)
		{
			while (sum-chains.front() >= amount)
			{
				sum -= chains.front();
				chains.pop_front();
				start++;
			}
			if (sum == amount)
			{
				exactStartEnd.emplace_back(start, i);
			}
			else if(sum<=closest.front().sum)
			{
				if (sum < closest.front().sum)closest.clear();
				closest.emplace_back(sum, start, i);
			}
		}
	}
	if (exactStartEnd.empty())
	{
		for (auto && segement : closest)
		{
			cout << segement.start + 1 << "-" << segement.end + 1 << '\n';
		}
	}
	else
	{
		for (auto && startEnd : exactStartEnd)
		{
			cout << startEnd.first+1 << "-" << startEnd.second+1<<'\n';
		}
	}
}

