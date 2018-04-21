#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <sstream>
using namespace std;

struct Person
{
    //if rootIdx <0 itself is a root and the abs of rootIdx is the size of the group
    int rootIdx=-1;
    int m_estate=0;
    int area=0;
    Person& operator +=(const Person& person)
    {
        rootIdx += person.rootIdx;
        m_estate += person.m_estate;
        area += person.area;
        return *this;
    }
    double AverageEstate()const { return m_estate / (-1.0*rootIdx); }
    double AverageArea()const { return area / (-1.0*rootIdx); }
};
unordered_map<int,Person> people;
int Find(int idx)
{
    if (people[idx].rootIdx < 0)return idx;
    return people[idx].rootIdx = Find(people[idx].rootIdx);
}
void Union(int lhs,int rhs)
{
    auto lhsRoot = Find(lhs);
    auto rhsRoot = Find(rhs);
    if(lhsRoot==rhsRoot)return;
    if (lhsRoot < rhsRoot)swap(lhsRoot, rhsRoot);
    people[rhsRoot] += people[lhsRoot];
    people[lhsRoot].rootIdx = rhsRoot;
}
int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    stringstream ss;
    for (int i = 0; i < n; ++i)
    {
        int id, fatherId, motherId, childrenSize;
        cin >> id >> fatherId >> motherId >> childrenSize;
        vector<int> children(childrenSize);
        for (int j = 0; j < childrenSize; ++j)
        {
            cin >> children[j];
        }
        int m_estate, area;
        cin >> m_estate >> area;
        people[id].m_estate = m_estate;
        people[id].area = area;
        ss << id <<" "<< fatherId << " " << motherId << " " << childrenSize << " ";
        for (auto child : children)
        {
            ss << child << " ";
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int id, fatherId, motherId, childrenSize;
        ss >> id >> fatherId >> motherId >> childrenSize;
        if (fatherId != -1)Union(id, fatherId);
        if (motherId != -1)Union(id, motherId);
        for (int j = 0; j < childrenSize; ++j)
        {
            int childId;
            ss >>childId;
            Union(id, childId);
        }
    }
    vector<pair<int,Person>> families;
    for (auto && pair : people)
    {
        if (pair.second.rootIdx < 0)families.push_back(pair);
    }
    sort(families.begin(), families.end(),[](pair<int,Person> lhs, pair<int, Person> rhs)
    {
        if (abs(lhs.second.AverageArea() - rhs.second.AverageArea()) < 1E-5)return lhs.first < rhs.first;
        return lhs.second.AverageArea() > rhs.second.AverageArea();
    });
    cout << families.size()<<"\n";
    for (auto && family : families)
    {
        printf("%04d %d ", family.first, -family.second.rootIdx);
        printf("%.3lf %.3lf\n", family.second.AverageEstate(), family.second.AverageArea());
    }
}
