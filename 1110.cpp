#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <queue>
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<pair<int, int>> nodes(n,{-1,-1});
    vector<bool> appeared(n);
    for (int i = 0; i < n; ++i)
    {
        string left,right;
        cin >> left >> right;
        if (isdigit(left.front()))appeared[nodes[i].first = stoi(left)]=true;
        if (isdigit(right.front()))appeared[nodes[i].second = stoi(right)]=true;
    }
    auto root = find(appeared.begin(), appeared.end(), false) - appeared.begin();
    queue<int> q;
    q.push(root);
    bool isCompleteBTree=true;
    int lastNodeIdx = -1;
    while (!q.empty())
    {
        if (nodes[q.front()].first != -1)
        {
            q.push(nodes[q.front()].first);
            if (nodes[q.front()].second != -1) q.push(nodes[q.front()].second);
            else { lastNodeIdx = q.back(); }
        }
        else
        {
            if(nodes[q.front()].second!=-1)
            {
                isCompleteBTree = false;
                break;
            }
            lastNodeIdx = q.back();
        }
        if (lastNodeIdx != -1 && lastNodeIdx != q.back())
        {
            isCompleteBTree = false;
            break;
        }
        q.pop();
    }
    if (isCompleteBTree)cout << "YES " << lastNodeIdx;
    else { cout << "NO " << root; }
}

