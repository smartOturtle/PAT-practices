#include<iostream>
#include <string>
#include <map>
#include <array>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
array<double, 24> timeRates;
int month=0;
enum Describe{ online , offline};
unordered_map<string, Describe> describes
{{"on-line",online},{"off-line",offline}};
struct Record
{
	int duration;//always count from 0:0:0
	Describe describe;
	bool operator< (const Record& one)const
	{
		return duration < one.duration;
	}
	int Day()const { return duration / (24*60); }
	int Hour()const { return duration % (24*60) / 60; }
	int Minute()const { return duration % 60; }
	double Cost()const
	{
		double cost = 0;
		for (auto && timeRate : timeRates)
		{
			cost += timeRate * 60;
		}
		cost *= Day();
		for (int i = 0; i < Hour(); ++i)
		{
			cost += timeRates[i]*60;
		}
		cost += timeRates[Hour()] * Minute();
		return cost;
	}
	Record(int duration,string describe)
	:duration(duration),describe(describes[describe])
	{}
};
int ToDuration(const string& chrono)
{
	if (month == 0)month = stoi(chrono.substr(0, 2));
	int duration = stoi(chrono.substr(3, 2))*24;
	duration += stoi(chrono.substr(6, 2));
	duration *= 60;
	duration += stoi(chrono.substr(9, 2));
	return duration;
}          
double GetCostAndPrint(const pair<Record,Record>& pairRecord)
{
	auto& onTime = pairRecord.first;
	auto& offTime = pairRecord.second;
	printf("%02d:%02d:%02d ", onTime.Day(), onTime.Hour(), onTime.Minute());
	printf("%02d:%02d:%02d ", offTime.Day(), offTime.Hour(), offTime.Minute());
	auto cost = offTime.Cost() - onTime.Cost();
	printf("%d $%.2lf\n", offTime.duration - onTime.duration, cost);
	return cost;
}
int main()
{
	for (auto && rate : timeRates)
	{
		cin >> rate;
		rate /= 100;
	}
	int size;
	cin >> size;
	map<string, set<Record>> records;
	for (int i = 0; i < size; ++i)
	{
		string id, time, describe;
		cin >> id >> time >> describe;
		records[id].emplace(ToDuration(time), describe);
	}
	map<string, vector<pair<Record, Record>>> valid;
	for (auto && record : records)
	{
		const Record* onRecord=nullptr ;
		for (auto && time : record.second)
		{
			if(time.describe==offline&&onRecord!=nullptr)
			{
				valid[record.first].push_back({ *onRecord,time });
				onRecord = nullptr;
			}
			else if(time.describe==online){ onRecord = &time; }
		}
	}
	for (auto && user : valid)
	{
		cout << user.first;
		printf(" %02d\n", month);
		double totalCost = 0;
		for (auto && pairRecord : user.second)
		{
			totalCost += GetCostAndPrint(pairRecord);
		}
		printf("Total amount: $%.2lf\n", totalCost);
	}
}
