#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;
int main(int argc, char* argv[])
{
	char c=getchar();
	string word;
	unordered_map<string, int> counter;
	while (c!='\n')
	{
		char next = getchar();
		if (isalnum(c))word.push_back(tolower(c));
		if(!isalnum(next)&&!word.empty())
		{
			counter[word]++;
			word.clear();
		}
		c = next;
	}
	if(!word.empty())counter[word]++;
	auto& maxWord= *max_element(counter.begin(), counter.end(),
		[](const pair<string,int>& lhs, const pair<string, int>& rhs)
	{
		if (lhs.second == rhs.second)return lhs.first > rhs.first;
		return lhs.second < rhs.second;
	});
	cout << maxWord.first << " " << maxWord.second;
}
