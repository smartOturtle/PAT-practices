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
#include <queue>
using namespace std;
bool IsConnected(vector<vector<int>>& gragh)
{
    deque<bool> visited(gragh.size());
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        for (int i = 0; i < gragh[q.front()].size(); ++i)
        {
            if (!visited[i] && gragh[q.front()][i])q.push(i);
        }
        visited[q.front()] = true;
        q.pop();
    }
    return all_of(visited.begin(), visited.end(), [](bool visited) { return visited; });
}
int main(int argc, char* argv[])
{
    int vertexSize, edgeSize;
    cin >> vertexSize >> edgeSize;
    vector<vector<int>> gragh(vertexSize,vector<int>(vertexSize));
    for (int i = 0; i < edgeSize; ++i)
    {
        int from, to;
        cin >> from >> to;
        gragh[from-1][to-1] = gragh[to-1][from-1] = 1;
    }
    vector<int> vertexDegrees(vertexSize);
    bool isConnected = IsConnected(gragh);
    for (int i = 0; i < gragh.size(); ++i)
    {
        vertexDegrees[i]= count(gragh[i].begin(), gragh[i].end(), 1);
    }
    int oddDegreeVertexSize = vertexDegrees.front()%2;
    cout << vertexDegrees.front();
    for (int i = 1; i < vertexSize; ++i)
    {
        cout <<" "<< vertexDegrees[i];
        if (vertexDegrees[i] % 2)oddDegreeVertexSize++;
    }
    cout << '\n';
    if(isConnected)
    {
        if (oddDegreeVertexSize == 0)cout << "Eulerian";
        else if (oddDegreeVertexSize == 2)cout << "Semi-Eulerian";
        else cout << "Non-Eulerian";
    }
    else { cout << "Non-Eulerian"; }
}
