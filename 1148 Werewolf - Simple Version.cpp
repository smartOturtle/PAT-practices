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
#define IDXTYPE int
#define FOR(idxName,start,end,step) for(IDXTYPE idxName=start;idxName<end;idxName+=step)
#define FORI(idxName,end) for(IDXTYPE idxName=0;idxName<end;idxName++)
#define FORR(idxName,start) for(IDXTYPE idxName=start;idxName>=0;idxName--)
#define CONT_RANGE(c) c.begin(),c.end()
#define RANGE(first,advanceSize) first,first+advanceSize 
template<typename C, typename T>
bool IsIn(const T& key, const C& c) { return c.find(key) != c.end(); }
typedef vector<int> VecInt;
int main()
{
    int size;
    cin >> size;
    VecInt seq(size + 1);
    FOR(i, 1, seq.size(), 1)
    {
        cin >> seq[i];
    }
    FOR(i, 1, seq.size(), 1)
    {
        FOR(j, i + 1, seq.size(), 1)
        {
            VecInt liers;
            VecInt isWolf(seq.size());
            isWolf[i] = isWolf[j] = true;
            FOR(k, 1, seq.size(), 1)
            {
                auto idx = abs(seq[k]);
                if (isWolf[idx] != (seq[k]<0))liers.push_back(k);
            }
            if (liers.size() == 2 && (isWolf[liers[0]] + isWolf[liers[1]] == 1))
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
}
