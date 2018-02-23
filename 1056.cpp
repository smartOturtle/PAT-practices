#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[])
{
	int mouseSize, groupCapacity;
	cin >> mouseSize >> groupCapacity;
	vector<int> mice(mouseSize);
	for (int i = 0; i < mouseSize; ++i)
	{
		cin >> mice[i];
	}
	vector<int> order(mouseSize);
	for (int i = 0; i < mouseSize; ++i)
	{
		cin >> order[i];
	}
	auto cmp = [&mice](int lhsIdx, int rhsIdx) { return mice[lhsIdx] < mice[rhsIdx]; };
	while (true)
	{
		vector<int> tmp;
		int groupSize = (order.size() - 1) / groupCapacity + 1;
		for (size_t i = 0; i < groupSize; ++i)
		{
			auto begin = order.begin() + i * groupCapacity;
			auto end = order.begin() + min((i + 1) * groupCapacity, order.size());
			auto maxElementIdx = *max_element(begin,end, cmp);
			tmp.push_back(maxElementIdx);
			for(auto iter=begin;iter!=end;++iter)
			{
				if (*iter != maxElementIdx)mice[*iter] = groupSize+1;
			}
		}
		if (tmp.size() == 1)
		{
			mice[order.front()] = 1;
			break;
		}
		swap(tmp, order);
	}
	cout << mice[0];
	for (int i = 1; i < mice.size(); ++i)
	{
		cout << " " << mice[i];
	}
}
