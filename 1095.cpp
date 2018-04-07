#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
int ToSecond(int hh, int mm, int ss)
{
    return (hh * 60 + mm) * 60 + ss;
}
enum Status
{
    In, Out
};

struct Record
{
    string id;
    int time;
    Status status;
    Record(string id, int duration, Status status) :
        id(id), time(duration), status(status)
    {
    }
    bool operator<(const Record& record)const
    {
        return time < record.time;
    }
    Record() {}
};
int main(int argc, char* argv[])
{
    int recordSize, querySize;
    cin >> recordSize >> querySize;
    vector<Record> records;
    for (int i = 0; i < recordSize; ++i)
    {
        string id, status;
        cin >> id;
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> status;
        if (status == "in")records.emplace_back(id, ToSecond(hh, mm, ss), In);
        else records.emplace_back(id, ToSecond(hh, mm, ss), Out);
    }
    sort(records.begin(), records.end());

    unordered_map<string, Record> validCheck;
    vector<Record> validRecords;
    for (auto && record : records)
    {
        if (record.status == In)validCheck[record.id] = record;
        else
        {
            if (validCheck.find(record.id) != validCheck.end())
            {
                validRecords.push_back(validCheck[record.id]);
                validRecords.push_back(record);
                validCheck.erase(record.id);
            }
        }
    }
    sort(validRecords.begin(), validRecords.end());
    vector<int> queryTimes;
    for (int i = 0; i < querySize; ++i)
    {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        queryTimes.push_back(ToSecond(hh, mm, ss));
    }
    unordered_map<string, int> inTimeRecords;
    unordered_map<string, int> durationRecords;

    int i = 0;
    for (auto && record : validRecords)
    {
        while (i<queryTimes.size() && record.time>queryTimes[i])
        {
            cout << inTimeRecords.size() << '\n';
            i++;
        }
        if (record.status == In)inTimeRecords[record.id] = record.time;
        else
        {
            durationRecords[record.id] += (record.time - inTimeRecords[record.id]);
            inTimeRecords.erase(record.id);
        }
    }
    for (; i < queryTimes.size(); ++i)cout << inTimeRecords.size() << '\n';

    vector<string> maxDurationIds;
    int maxDuration = -1;
    for (auto && record : durationRecords)
    {
        if (record.second == maxDuration)maxDurationIds.push_back(record.first);
        else if (record.second>maxDuration)
        {
            maxDurationIds.assign({ record.first });
            maxDuration = record.second;
        }
    }
    sort(maxDurationIds.begin(), maxDurationIds.end());
    for (auto && id : maxDurationIds)
    {
        cout << id << " ";
    }
    printf("%02d:%02d:%02d", maxDuration / 3600, maxDuration % 3600 / 60, maxDuration % 60);
}
