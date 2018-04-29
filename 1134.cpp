#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

int main(int argc, char* argv[])
{
    int vertexSize, edgeSize;
    cin >> vertexSize >> edgeSize;
    vector<pair<int, int>> edges;
    for (int i = 0; i < edgeSize; ++i)
    {
        int from, to;
        cin >> from >> to;
        edges.push_back({ from,to });
    }
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        unordered_set<int> vertices;
        int setVertexSize;
        cin >> setVertexSize;
        for (int j = 0; j < setVertexSize; ++j)
        {
            int id;
            cin >> id;
            vertices.insert(id);
        }
        int cnt = 0;
        for (auto && edge : edges)
        {
            if (vertices.find(edge.first) != vertices.end() ||
                vertices.find(edge.second) != vertices.end())cnt++;
        }
        if (cnt == edgeSize)cout << "Yes\n";
        else { cout << "No\n"; }
    }
}

