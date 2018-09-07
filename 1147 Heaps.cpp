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
template<typename Iter,typename Pred>
bool IsHeap(Iter first,Iter last,Pred cmp)
{
    int parent=0;
    for(int child=1;child<last-first;++child)
    {
        if(cmp(*(first+parent),*(first+child)))return false;
        if(child%2==0)parent++;
    }
    return true;
}
void Travelsal(int idx,vector<int>& heap)
{
    if(idx>=heap.size())return;
    Travelsal(2 * idx + 1, heap);
    Travelsal(2 * idx + 2, heap);
    if (idx == 0)printf("%d", heap[idx]);
    else { printf("%d ", heap[idx]); }
}
int main(int argc, char* argv[])
{
    int querySize, heapSize;
    cin >> querySize >> heapSize;
    for (int i = 0; i < querySize; ++i)
    {
        vector<int> heap(heapSize);
        for (int j = 0; j < heapSize; ++j)
        {
            cin >> heap[j];
        }
        if (IsHeap(heap.begin(), heap.end(),less<int>())) { cout << "Max Heap"; }
        else if (IsHeap(heap.begin(), heap.end(), greater<int>())) { cout << "Min Heap"; }
        else { cout << "Not Heap"; }
        cout << '\n';
        Travelsal(0, heap);
        cout << '\n';
    }
}
