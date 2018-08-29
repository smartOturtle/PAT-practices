#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

struct Record
{
    string id;
    int time;
    bool isIn;
    bool operator<(const Record& rhs)const{return time < rhs.time;}
};
void Filter(vector<Record>& records)
{
    sort(records.begin(), records.end());
    vector<Record> matched;
    unordered_map<string, Record> match;
    for (auto && record : records)
    {
        if (record.isIn)match[record.id] = record;
        else if(match.find(record.id)!=match.end())
        {
            matched.push_back(match[record.id]);
            matched.push_back(record);
            match.erase(record.id);
        }
    }
    sort(matched.begin(), matched.end());
    swap(records, matched);
}
int GetTime()
{
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    return (hh * 60 + mm) * 60 + ss;
}
int main(int argc, char* argv[])
{
    int recordSize, querySize;
    cin >> recordSize >> querySize;
    vector<Record> records(recordSize);
    for (int i = 0; i < recordSize; ++i)
    {
        string s;
        string isIn;
        cin >> s;
        int time = GetTime();
        cin >> isIn;
        records[i] = { s,time,isIn == "in" };
    }
    Filter(records);
    unordered_map<string, int> parkingTime;
    unordered_map<string,Record> parkingCars;
    auto iter = records.begin();
    auto processRecord=[&](int queryTime=INT32_MAX)
    {
        for (; iter!=records.end()&& iter->time <= queryTime; ++iter)
        {
            auto& record = *iter;
            if (record.isIn)parkingCars[record.id] = record;
            else
            {
                parkingTime[record.id] += record.time - parkingCars[record.id].time;
                parkingCars.erase(record.id);
            }
        }
    };
    for (int i = 0; i < querySize; ++i)
    {
        processRecord(GetTime());
        cout << parkingCars.size() << '\n';
    }
    if (iter != records.end())processRecord();
    vector<string> cars;
    int longestTime = -1;
    for (auto && idTime : parkingTime)
    {
        if (longestTime < idTime.second)
        {
            longestTime = idTime.second;
            cars.assign({ idTime.first });
        }
        else if(longestTime==idTime.second){ cars.push_back(idTime.first); }
    }
    sort(cars.begin(), cars.end());
    for (auto& id : cars)cout << id << " ";
    int hh = longestTime / 3600, mm = longestTime / 60 % 60, ss = longestTime % 60;
    printf("%02d:%02d:%02d", hh, mm, ss);
}
