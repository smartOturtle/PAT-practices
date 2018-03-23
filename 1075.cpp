#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int userSize, problemSize, submissionSize;
struct User
{
	enum Status
	{
		NotSubmitted = -2, NotPassed = -1
	};
	bool hasPassed;
	vector<int> partialScores;
	int totalScore;
	int perfectAnswerSize;
	User() :
		hasPassed(false), partialScores(problemSize, NotSubmitted), totalScore(0), perfectAnswerSize(0)
	{
	}
	void Update(int score, int problemIdx, int perfectScore)
	{
		if (score >= 0)hasPassed = true;
		if (partialScores[problemIdx]<score)
		{
			if (partialScores[problemIdx] > 0)totalScore+=(score- partialScores[problemIdx]);
			else if(score>0){ totalScore += score; }
			partialScores[problemIdx] = score;
			if (score == perfectScore)perfectAnswerSize++;
		}
	}
	void Print()
	{
		printf("%d", totalScore);
		for (auto partialScore : partialScores)
		{
			cout << " ";
			switch (partialScore)
			{
			case NotSubmitted:
				cout << '-';
				break;
			case NotPassed:
				cout << 0;
				break;
			default:
				cout << partialScore;
			}
		}
		cout << '\n';
	}
};
using idUserIter = unordered_map<int, User>::iterator;
bool Cmp(idUserIter lhs, idUserIter rhs)
{
	if (lhs->second.totalScore == rhs->second.totalScore)
	{
		if (lhs->second.perfectAnswerSize == rhs->second.perfectAnswerSize)
		{
			return lhs->first < rhs->first;
		}
		return lhs->second.perfectAnswerSize > rhs->second.perfectAnswerSize;
	}
	return lhs->second.totalScore > rhs->second.totalScore;
}
int main()
{
	cin >> userSize >> problemSize >> submissionSize;
	vector<int> perfectScores(problemSize);
	for (int i = 0; i < problemSize; ++i)
	{
		cin >> perfectScores[i];
	}
	unordered_map<int, User> users;
	for (int i = 0; i < submissionSize; ++i)
	{
		int id, problemId, score;
		scanf("%d %d %d", &id, &problemId, &score);
		users[id].Update(score, problemId - 1, perfectScores[problemId - 1]);
	}
	vector<idUserIter> sortedIters;
	for (auto iter = users.begin(); iter != users.end(); ++iter)
	{
		if(iter->second.hasPassed)sortedIters.push_back(iter);
	}
	sort(sortedIters.begin(), sortedIters.end(), Cmp);
	int rank = 1, preScore = -1, sameScoreSize = 0;
	for (auto iter : sortedIters)
	{
		if (preScore != iter->second.totalScore)
		{
			rank += sameScoreSize;
			sameScoreSize = 1;
			preScore = iter->second.totalScore;
		}
		else { sameScoreSize++; }
		printf("%d %05d ", rank, iter->first);
		iter->second.Print();
	}
}
