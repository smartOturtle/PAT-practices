#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

int main(int argc, char* argv[])
{
    int vertexSize, edgeSize;
    cin >> vertexSize >> edgeSize;
    vector<vector<int>> gragh(vertexSize+1,vector<int>(vertexSize+1));
    for (int i = 0; i < edgeSize; ++i)
    {
        int from, to;
        cin >> from >> to;
        gragh[from][to] = gragh[to][from] = 1;
    }
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        int pathVertexSize;
        cin >> pathVertexSize;
        vector<int> path(pathVertexSize);
        unordered_set<int> hasVisited;
        bool isCycle=pathVertexSize==vertexSize+1;
        for (int j = 0; j < pathVertexSize; ++j)
        {
            cin >> path[j];
            if (j>0 )
            {
                if(gragh[path[j - 1]][path[j]] == 0||hasVisited.find(path[j])!=hasVisited.end())
                    isCycle = false;
                hasVisited.insert(path[j]);
            }
        }
        if (path.front() != path.back())isCycle = false;
        if (isCycle)cout << "YES\n";
        else { cout << "NO\n"; }
    }
}

