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
#include <list>
using namespace std;
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
        for (auto && value : heap)cin >> value;
        if (is_heap(heap.begin(), heap.end())) { cout << "Max Heap"; }
        else if (is_heap(heap.begin(), heap.end(), greater<int>())) { cout << "Min Heap"; }
        else { cout << "Not Heap"; }
        cout << '\n';
        Travelsal(0, heap);
        cout << '\n';
    }
}
