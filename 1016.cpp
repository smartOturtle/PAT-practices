#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Record
{
    string name;
    int day;
    int hour;
    int min;
    bool isOnline;
    Record(){}
    Record(string name,int d,int h,int m,bool tag):
    name(name),day(d),hour(h),min(m),isOnline(tag)
    {}
    void Print()const { printf("%02d:%02d:%02d ", day, hour, min); }
    bool operator<(const Record& rhs)const
    {
        return make_tuple(day, hour, min) < make_tuple(rhs.day, rhs.hour, rhs.min);
    }
};
vector<double> eachHourRate(24);
int CountTotalTime(Record start,Record end)
{
    auto base=[](Record record){return (record.day * 24 + record.hour) * 60 + record.min;};
    return base(end) - base(start);
}
double CountCost(Record start,Record end)
{
    auto base=[](Record record)
    {
        double cost = 0;
        for (auto hourRate : eachHourRate)cost += (hourRate * 60);
        cost *= record.day;
        for (int i = 0; i < record.hour; ++i)cost += 60 * eachHourRate[i];
        return cost + eachHourRate[record.hour] * record.min;
    };
    return (base(end) - base(start))/100;
}
int main(int argc, char* argv[])
{
    for (auto& rate : eachHourRate)cin >> rate;
    int recordSize;
    cin >> recordSize;
    int month;
    vector<Record> records;
    for (int i = 0; i < recordSize; ++i)
    {
        string name,tag;
        int d, h, m;
        cin >> name;
        scanf("%d:%d:%d:%d", &month, &d, &h, &m);
        cin >> tag;
        records.emplace_back(name, d, h, m, tag == "on-line");
    }
    unordered_map<string, Record> match;
    map<string, vector<pair<Record, Record>>> users;
    sort(records.begin(), records.end());
    for (auto record : records)
    {
        if (record.isOnline)match[record.name] = record;
        else if(match.find(record.name)!=match.end())
        {
            users[record.name].emplace_back(match[record.name], record);
            match.erase(record.name);
        }
    }
    for (auto user : users)
    {
        printf("%s %02d\n", user.first.c_str(), month);
        double totalAmount = 0;
        for (auto pairRecord : user.second)
        {
            pairRecord.first.Print();
            pairRecord.second.Print();
            auto cost = CountCost(pairRecord.first, pairRecord.second);
            printf("%d $%.2lf\n", CountTotalTime(pairRecord.first, pairRecord.second),cost);
            totalAmount += cost;
        }
        printf("Total amount: $%.2lf\n", totalAmount);
    }
}
