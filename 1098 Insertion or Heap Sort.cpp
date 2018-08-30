#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
template<typename Iter>
void InsertionSort(Iter first,Iter last)
{
    for(auto i=first;i!=last;++i)
    {
        auto temp = *i;
        auto j = i;
        for (; j != first && *(j - 1) > temp; --j)*j = *(j - 1);
        *j = temp;
    }
}

int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    vector<int> pre(size);
    auto after = pre;
    for (auto& value : pre)cin >> value;
    for (auto& value : after)cin >> value;
    auto pos = is_sorted_until(after.begin(), after.end());
    if(equal(pos,after.end(),pre.begin()+(pos-after.begin()),pre.end()))
    {
        InsertionSort(after.begin(), pos + 1);
        cout << "Insertion Sort\n";
    }
    else
    {
        pop_heap(after.begin(), is_heap_until(after.begin(), after.end()));
        cout << "Heap Sort\n";
    }
    cout << after.front();
    for (int i = 1; i < after.size(); ++i)
    {
        cout << " " << after[i];
    }
}

