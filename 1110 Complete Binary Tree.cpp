#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
    int nodeSize;
    cin >> nodeSize;
    vector<pair<int, int>> tree(nodeSize, { -1,-1 });
    vector<bool> appeared(nodeSize);
    for (int i = 0; i < nodeSize; ++i)
    {
        string lhs, rhs;
        cin >> lhs >> rhs;
        if (isdigit(lhs.front()))appeared[tree[i].first = stoi(lhs)]=true;
        if (isdigit(rhs.front()))appeared[tree[i].second = stoi(rhs)]=true;
    }
    auto root = find(appeared.begin(), appeared.end(), false) - appeared.begin();
    queue<int> q;
    q.push(root);
    bool isComplete = true;
    int firstNoChildNode = -1;
    while (!q.empty())
    {
        if (tree[q.front()].first != -1)
        {
            if(firstNoChildNode!=-1)
            {
                isComplete = false;
                break;
            }
            q.push(tree[q.front()].first);
            if (tree[q.front()].second != -1)q.push(tree[q.front()].second);
        }
        else if (tree[q.front()].second != -1)
        {
            isComplete = false;
            break;
        }
        else { firstNoChildNode = q.front(); }
        if (q.size() == 1&&isComplete)cout << "YES " << q.front();
        q.pop();
    }
    if(!isComplete)cout <<"NO " << root;
}


