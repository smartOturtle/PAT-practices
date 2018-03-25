#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[])
{
	int size;
	cin >> size;
	getchar();
	vector<string> sentences;
	for (int i = 0; i < size; ++i)
	{
		string s;
		getline(cin, s);
		sentences.push_back(s);
	}
	string suffix;
	int reversedIdx = 1;
	while (sentences[0].size()>=reversedIdx)
	{
		char c = *(sentences[0].end()-reversedIdx);
		for (int i = 1; i < sentences.size(); ++i)
		{
			if (sentences[i].size() < reversedIdx || c != *(sentences[i].end() - reversedIdx))
				goto out;
		}
		reversedIdx++;
		suffix.push_back(c);
	}
	out:
	if (suffix.empty())cout << "nai";
	else
	{
		reverse(suffix.begin(), suffix.end());
		cout << suffix;
	}
}
