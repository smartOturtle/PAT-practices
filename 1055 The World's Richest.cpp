#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Person
{
    string name;
    int age;
    int netWorth;
    bool operator>(const Person& rhs)const
    {
        if (netWorth == rhs.netWorth)
        {
            if (age == rhs.age)return name < rhs.name;
            return age < rhs.age;
        }
        return netWorth > rhs.netWorth;
    };
};
int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int personSize, querySize;
    cin >> personSize >> querySize;
    vector<vector<Person>> ageGroups(201);
    for (int i = 0; i < personSize; ++i)
    {
        string name;
        int age;
        int netWorth;
        cin >> name >> age >> netWorth;
        ageGroups[age].push_back({ name,age,netWorth });
    }
    for (auto& people : ageGroups)sort(people.begin(), people.end(), greater<Person>());
    for (int i = 0; i < querySize; ++i)
    {
        int outPutSize, minAge, maxAge;
        cin >> outPutSize >> minAge >> maxAge;
        using Iter = vector<Person>::iterator;
        vector<Iter> rangePeople;
        for (int age = minAge; age <= maxAge; ++age)
        {
            if (!ageGroups[age].empty())rangePeople.push_back(ageGroups[age].begin());
        }
        cout << "Case #" << i + 1 << ":\n";
        if (rangePeople.empty())cout << "None\n";
        else
        {
            auto cmp = [](Iter lhs, Iter rhs) { return *rhs > *lhs; };
            make_heap(rangePeople.begin(), rangePeople.end(), cmp);
            for (int j = 0; j < outPutSize && !rangePeople.empty(); ++j)
            {
                cout << rangePeople.front()->name << " "
                    << rangePeople.front()->age << " " << rangePeople.front()->netWorth << '\n';
                auto temp = rangePeople.front();
                pop_heap(rangePeople.begin(), rangePeople.end(), cmp);
                rangePeople.pop_back();
                if (next(temp) != ageGroups[temp->age].end())
                {
                    rangePeople.push_back(++temp);
                    push_heap(rangePeople.begin(), rangePeople.end(), cmp);
                }
            }
        }
    }
}

