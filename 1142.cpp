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
using namespace std;

int main(int argc, char* argv[])
{
    int Nv, Ne;
    cin >> Nv >> Ne;
    vector<unordered_set<int>> gragh(Nv+1);
    for (int i = 0; i < Ne; ++i)
    {
        int from, to;
        cin >> from >> to;
        gragh[from].insert(to);
        gragh[to].insert(from);
    }
    int querySize;
    cin >> querySize;
    for (int i = 0; i < querySize; ++i)
    {
        int setSize;
        cin >> setSize;
        vector<int> vertices(setSize);
        for (auto && vertex : vertices)cin >> vertex;
        auto possible=gragh[vertices.front()];
        for (int j = 0; j < vertices.size(); ++j)
        {
            for(auto iter=possible.begin();iter!=possible.end();)
            {
                if (gragh[vertices[j]].find(*iter) == gragh[vertices[j]].end()) { iter = possible.erase(iter); }
                else { ++iter; }
            }
            for (int k = j+1; k < vertices.size(); ++k)
            {
                if(gragh[vertices[k]].find(vertices[j])== gragh[vertices[k]].end())
                {
                    cout << "Not a Clique";
                    goto out;
                }
            }
        }
        if (!possible.empty())cout << "Not Maximal";
        else { cout << "Yes"; }
    out:cout << '\n';
    }
}

