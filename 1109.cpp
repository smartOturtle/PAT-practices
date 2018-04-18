#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <functional>
using namespace std;
using Person = pair<int, string>;
vector<Person> people;
int main(int argc, char* argv[])
{
    //each row has N/k, there are extra people in last row
    //rear row no shorter than
    //i th row must >= i-1 th row
    //tallest one in the middle as idx rowSize/2
    //middle out from left to right
    int peopleSize, rowSize;
    cin >> peopleSize >> rowSize;
    for (int i = 0; i < peopleSize; ++i)
    {
        Person p;
        cin >> p.second >> p.first;
        people.push_back(p);
    }
    sort(people.begin(), people.end(),[](const Person& lhs, const Person& rhs)
    {
        if (lhs.first == rhs.first)return lhs.second < rhs.second;
        return lhs.first > rhs.first;
    });

    int rowPeopleSize = peopleSize / rowSize;
    int lastRowPeopleSize = peopleSize - (rowSize - 1)*rowPeopleSize;
    vector<vector<string>> matrix(rowSize-1,vector<string>(rowPeopleSize));
    matrix.push_back(vector<string>(lastRowPeopleSize));
    reverse(matrix.begin(), matrix.end());
    int peopleIdx = 0;
    matrix.front()[lastRowPeopleSize / 2] = people[peopleIdx++].second;
    for (int i = 1; lastRowPeopleSize / 2 - i >= 0; ++i)
    {
        matrix.front()[lastRowPeopleSize / 2 - i] = people[peopleIdx++].second;
        if (lastRowPeopleSize / 2 + i<lastRowPeopleSize)
            matrix.front()[lastRowPeopleSize / 2 + i] = people[peopleIdx++].second;
    }
    for (int i = 1; i < matrix.size(); ++i)
    {
        matrix[i][rowPeopleSize / 2] = people[peopleIdx++].second;
        for (int j = 1; rowPeopleSize / 2 - j >= 0; ++j)
        {
            matrix[i][rowPeopleSize / 2 - j] = people[peopleIdx++].second;
            if (rowPeopleSize / 2 + j<rowPeopleSize)
                matrix[i][rowPeopleSize / 2 + j] = people[peopleIdx++].second;
        }
    }
    for (auto && names : matrix)
    {
        cout << names.front();
        for (int i = 1; i < names.size(); ++i)
        {
            cout << " " << names[i];
        }
        cout << '\n';
    }
}
