#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<int, const char> toCardType
{{0,'S'},{ 1,'H' },{ 2,'C' },{ 3,'D' },{ 4,'J' }, };
int main(int argc, char* argv[])
{
	int repeatTimes;
	cin >> repeatTimes;
	vector<int> cards;
	vector<int> shuffleSeq(54);
	for (int i = 0; i < 54; ++i)
	{
		cards.push_back(i);
		cin >> shuffleSeq[i];
	}
	for (int i = 0; i < repeatTimes; ++i)
	{
		vector<int> after(54);
		for (int j = 0; j < shuffleSeq.size(); ++j)
		{
			after[shuffleSeq[j]-1] = cards[j];
		}
		cards = move(after);
	}
	cout << toCardType[cards.front() / 13] << cards[0] % 13 + 1 ;
	for (int i = 1; i < cards.size(); ++i)
	{
		cout << " " << toCardType[cards[i]/ 13] << cards[i] % 13 + 1 ;
	}
}
