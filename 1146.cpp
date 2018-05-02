#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
vector<list<int>> inDegree;
vector<list<int>> outDegree;
int main(int argc, char* argv[])
{
    int vertexSize, edgeSize;
    cin >> vertexSize >> edgeSize;
    inDegree.resize(vertexSize+1);
    outDegree.resize(vertexSize+1);
    for (int i = 0; i < edgeSize; ++i)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        outDegree[from].push_back(to);
        inDegree[to].push_back(from);
    }
    deque<bool> initValid(vertexSize + 1);
    for (int i = 1; i < inDegree.size(); ++i)
    {
        if (inDegree[i].empty())initValid[i] = true;
    }
    int querySize;
    cin >> querySize;
    vector<int> falseAnswersIdx;
    for (int i = 0; i < querySize; ++i)
    {
        auto valid = initValid;
        deque<bool> hasVisited(vertexSize+1);
        auto isTopo = true;
        for (int j = 0; j < vertexSize; ++j)
        {
            int idx;
            scanf("%d", &idx);
            if (!valid[idx])isTopo = false;
            else
            {
                vector<int> willValid;
                hasVisited[idx] = true;
                for (auto relateIdx : outDegree[idx])
                {
                    if (all_of(inDegree[relateIdx].begin(), inDegree[relateIdx].end(), 
                        [&hasVisited](int idx) { return hasVisited[idx]; }))
                        willValid.push_back(relateIdx);
                }
                for (auto value : willValid)valid[value] = true;
            }
        }
        if (!isTopo)falseAnswersIdx.push_back(i);
    }
    cout << falseAnswersIdx.front();
    for (int i = 1; i < falseAnswersIdx.size(); ++i)
    {
        printf(" %d", falseAnswersIdx[i]);
    }
}


