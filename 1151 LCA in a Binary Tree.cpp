#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <tuple>
#include <numeric>
#include <cmath>
using namespace std;
#define FOR(idxName,start,end,step) for(int idxName=start;idxName<end;idxName+=step)
#define FORI(idxName,end) for(int idxName=0;idxName<end;idxName++)
#define FORR(idxName,start) for(int idxName=start;idxName>=0;idxName--)
#define CONT_RANGE(c) c.begin(),c.end()
#define RANGE(first,advanceSize) first,first+advanceSize 
template<typename C, typename T>
bool IsIn(const T& key, const C& c) { return c.find(key) != c.end(); }
typedef vector<int> VecInt;

struct Node
{
    int depth;
    int value;
    Node* left;
    Node* right;
    Node(int value,int depth):value(value),left(nullptr),right(nullptr),depth(depth){}
    Node(){}
    vector<Node*> biParents;
};
unordered_map<int, Node> nodes;
template<typename Iter>
Node* BuildTree(Iter preFirst,Iter preLast,Iter inFirst,Iter inLast,int depth)
{
    if (preFirst == preLast)return nullptr;
    auto inPos = find(inFirst, inLast, *preFirst);
    nodes[*preFirst] = Node(*preFirst, depth);
    auto n = &nodes[*preFirst];
    n->left = BuildTree(preFirst + 1, preFirst + 1 + (inPos - inFirst), inFirst, inPos,depth+1);
    n->right = BuildTree(preFirst + 1 + (inPos - inFirst),preLast, inPos + 1, inLast,depth+1);
    return n;
}
void DFS(Node* n)
{
    static deque<Node*> path;
    if(n==nullptr)return;
    path.push_front(n);
    for (int i = 1; i<path.size(); i *= 2)n->biParents.push_back(path[i]);
    DFS(n->left);
    DFS(n->right);
    path.pop_front();
}
int LCA(int lhs,int rhs)
{
    auto* shallow= &nodes[lhs];
    auto* deep = &nodes[rhs];
    if (shallow->depth > deep->depth)swap(shallow, deep);
    for(;deep->depth!=shallow->depth;deep=deep->biParents[floor(log2(deep->depth - shallow->depth))]){}
    if (deep->value == shallow->value)return shallow->value;
    while (deep->biParents[0]!= shallow->biParents[0])
    {
         FORR(i,deep->biParents.size()-1)
         {
             if (deep->biParents[i] != shallow->biParents[i])
             {
                 deep = deep->biParents[i];
                 shallow = shallow->biParents[i];
                 break;
             }
         }
    }
    return shallow->biParents[0]->value;
}
int main(int argc, char* argv[])
{
    int querySize, nodeSize;
    cin >> querySize >> nodeSize;
    VecInt inorder(nodeSize);
    VecInt preorder(nodeSize);
    for_each(CONT_RANGE(inorder), [](int& value) { cin >> value; });
    for_each(CONT_RANGE(preorder), [](int& value) { cin >> value; });
    auto root = BuildTree(CONT_RANGE(preorder), CONT_RANGE(inorder),1);
    DFS(root);
    FORI(i,querySize)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;
        if(!IsIn(lhs,nodes))
        {
            if (!IsIn(rhs, nodes)) { printf("ERROR: %d and %d are not found.", lhs, rhs); }
            else { printf("ERROR: %d is not found.", lhs); }
        }
        else if(!IsIn(rhs,nodes)){ printf("ERROR: %d is not found.", rhs); }
        else
        {
            auto lca = LCA(lhs, rhs);
            if (lca == lhs) { printf("%d is an ancestor of %d.", lca, rhs); }
            else if(lca==rhs){ printf("%d is an ancestor of %d.", lca, lhs); }
            else { printf("LCA of %d and %d is %d.", lhs, rhs, lca); }
        }
        cout << '\n';
    }
}
