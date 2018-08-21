#define  _CRT_SECURE_NO_WARNINGS
#include  <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;

struct Person
{
    string id;
    int virtue;
    int talent;
    bool operator>(Person rhs)const
    {
        if (talent + virtue == rhs.talent + rhs.virtue)
        {
            if(virtue==rhs.virtue)return id < rhs.id;
            return virtue > rhs.virtue;
        }
        return talent + virtue > rhs.talent + rhs.virtue;
    }
};

int main(int argc, char* argv[])
{
    iostream::sync_with_stdio(false);
    int personSize, lowerBound, higherLine;
    cin >> personSize >> lowerBound >> higherLine;
    vector<Person> sages;
    vector<Person> noblemen;
    vector<Person> foolmen;
    vector<Person> rest;
    for (int i = 0; i < personSize; ++i)
    {
        string id;
        int virture, talent;
        cin >> id >> virture >> talent;
        if (virture < lowerBound||talent < lowerBound)continue;
        if (virture >= higherLine)
        {
            if(talent >= higherLine)sages.push_back({ id,virture,talent });
            else noblemen.push_back({ id,virture,talent });
        }
        else if (virture >= talent)foolmen.push_back({ id,virture,talent });
        else rest.push_back({ id,virture,talent });
    }
    vector<vector<Person>*> assemble{&sages,&noblemen,&foolmen,&rest};
    cout << sages.size() + noblemen.size() + foolmen.size() + rest.size() << '\n';
    for (auto people : assemble)
    {
        sort(people->begin(), people->end(), greater<Person>());
        for (auto& person : *people)cout << person.id << " " << person.virtue << " " << person.talent << '\n';
    }
}
