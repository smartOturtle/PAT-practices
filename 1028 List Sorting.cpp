#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct Record
{
    string id;
    string name;
    int score;
    bool CmpWithType(const Record& rhs,int type)const
    {
        if (type == 1)return id < rhs.id;
        if (type == 2)
        {
            if (name == rhs.name)return id < rhs.id;
            return name < rhs.name;
        }
        if (score == rhs.score)return id < rhs.id;
        return score < rhs.score;
    }
};
int main(int argc, char* argv[])
{
    using namespace std::placeholders;
    istream::sync_with_stdio(false);
    int size, sortType;
    cin >> size >> sortType;
    vector<Record> records(size);
    for(auto& record:records)cin >> record.id>>record.name>>record.score;
    sort(records.begin(), records.end(), bind(&Record::CmpWithType,_1,_2,sortType));
    for (auto& record : records)cout << record.id <<" "<< record.name<<" " << record.score<<'\n';
}
