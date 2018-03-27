#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;
struct Applicant
{
	int id;
	int totalScore;
	pair<int, int> geGi;
	vector<int> choices;
	Applicant(int id,pair<int,int> geGi,int choiceSize):
	id(id),geGi(geGi),choices(choiceSize)
	{
		totalScore = (geGi.first + geGi.second)/2;
	}
	bool operator>(const Applicant& applicant )const
	{
		if (totalScore == applicant.totalScore)
			return geGi > applicant.geGi;
		return totalScore > applicant.totalScore;
	}
	bool operator==(const Applicant& applicant)const
	{
		return totalScore == applicant.totalScore&&
			geGi == applicant.geGi;
	}
};
int main(int argc, char* argv[])
{
	int applicantSize, schoolSize, choiceSize;
	cin >> applicantSize >> schoolSize >> choiceSize;
	vector<vector<int>> schools(schoolSize);
	vector<int> schoolQuotas;
	for (int i = 0; i < schoolSize; ++i)
	{
		int quota;
		cin >> quota;
		schoolQuotas.push_back(quota);
	}
	vector<Applicant> applicants;
	for (int i = 0; i < applicantSize; ++i)
	{
		pair<int, int> geGi;
		cin >> geGi.first >> geGi.second;
		Applicant applicant(i,geGi,choiceSize);
		for (int j = 0; j < choiceSize; ++j)
		{
			cin >> applicant.choices[j];
		}
		applicants.emplace_back(move(applicant));
	}

	sort(applicants.begin(), applicants.end(), greater<Applicant>());
	vector<vector<Applicant*>> rankList{{&applicants.front()}};
	for (int i = 1; i < applicants.size(); ++i)
	{
		if (applicants[i] == *rankList.back().back())
		{
			rankList.back().push_back(&applicants[i]);
		}
		else
		{
			rankList.push_back({ &applicants[i] });
		}
	}

	for (auto && sameRankGroup : rankList)
	{
		const auto needQuery = 1, notAvailable = 2, avaiable = 3;
		vector<int> schoolStatus(schoolSize, needQuery);
		for (auto applicantPtr : sameRankGroup)
		{
			for (auto choice : applicantPtr->choices)
			{
				if (schoolStatus[choice] == needQuery)
				{
					if (schools[choice].size()<schoolQuotas[choice])
					{
						schools[choice].push_back(applicantPtr->id);
						schoolStatus[choice] = avaiable;
						break;
					}
					schoolStatus[choice] = notAvailable;
				}
				else if (schoolStatus[choice] == avaiable)
				{
					schools[choice].push_back(applicantPtr->id);
					break;
				}
			}
		}
	}

	for (auto && school : schools)
	{
		string s;
		sort(school.begin(), school.end());
		for (auto admittedApplicantId : school)
		{
			s += to_string(admittedApplicantId);
			s.push_back(' ');
		}
		if(!s.empty())s.pop_back();
		cout <<s<< '\n';
	}
}
