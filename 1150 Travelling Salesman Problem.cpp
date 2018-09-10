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
#include <tuple>
#include <numeric>
using namespace std;
#define FOR(idxName,start,end,step) for(auto idxName=start;idxName<end;idxName+=step)
#define FORI(idxName,end) for(auto idxName=0;idxName<end;idxName++)
#define FORR(idxName,start) for(auto idxName=start;idxName>=0;idxName--)
#define CONT_RANGE(c) c.begin(),c.end()
#define RANGE(first,advanceSize) first,first+advanceSize 
template<typename C, typename T>
bool IsIn(const T& key, const C& c) { return c.find(key) != c.end(); }
typedef vector<int> VecInt;

int main(int argc, char* argv[])
{
    int vertexSize, edgeSize;
    cin >> vertexSize >> edgeSize;
    vector<VecInt> graph(vertexSize,VecInt(vertexSize,0xffffff));
    FORI(i,edgeSize)
    {
        int lhs, rhs,dist;
        cin >> lhs >> rhs>>dist;
        lhs--, rhs--;
        graph[lhs][rhs] = dist;
        graph[rhs][lhs] = dist;
    }
    int k;
    cin >> k;
    int shortest = -1;
    int minDist = 0xffffff;
    FORI(i,k)
    {
        int length;
        cin >> length;
        vector<int> cycle;
        vector<int> visited(vertexSize);
        FORI(j,length)
        {
            int idx;
            cin >> idx;
            cycle.push_back(idx - 1);
            visited[idx - 1] += 1;
        }
        int totalDist = 0;
        accumulate(cycle.begin() + 1, cycle.end(), cycle.front(), [&](int pre, int now) { totalDist += graph[pre][now]; return now; });
        printf("Path %d: %s ", i + 1, totalDist >= 0xffffff ? "NA" : to_string(totalDist).c_str());
        if (totalDist<0xffffff&&cycle.front()==cycle.back()&&all_of(CONT_RANGE(visited), [](int times) { return times >= 1; }))
        {
            if (cycle.size()==vertexSize+1)
            {
                cout << "(TS simple cycle)\n";
            }
            else cout << "(TS cycle)\n";
            if (totalDist < minDist)tie(shortest, minDist) = make_tuple(i + 1, totalDist);
        }
        else { cout << "(Not a TS cycle)\n"; }
    }
    printf("Shortest Dist(%d) = %d", shortest, minDist);
}

