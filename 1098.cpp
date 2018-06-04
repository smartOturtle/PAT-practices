#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;
template<typename Iter>
void InsertSort(Iter first, Iter last)
{
    for (auto i = next(first); i != last; ++i)
    {
        auto value = *i;
        auto j = i;
        for (; j != first && *prev(j) > value; --j)
            *j = *prev(j);
        *j = value;
    }
}
template<typename Iter1,typename Iter2>
bool IsInsertSort(Iter1 first, Iter1 last, Iter2 initFirst, Iter2 initLast)
{
    auto sortedEnd = is_sorted_until(first, last);
    if (mismatch(sortedEnd, last, next(initFirst, distance(first, sortedEnd)), initLast).first == last)return true;
    return false;
}
int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    list<int> init(size);
    vector<int> after(size);
    for (auto& value : init)cin >> value;
    for (auto& value : after)cin >> value;
    if (IsInsertSort(after.begin(), after.end(), init.begin(), init.end()))
    {
        InsertSort(after.begin(), ++is_sorted_until(after.begin(), after.end()));
        cout << "Insertion Sort\n";
    }
    else
    {
        pop_heap(after.begin(), is_heap_until(after.begin(), after.end()));
        cout << "Heap Sort\n";
    }
    cout << after.front();
    for (int i = 1; i < after.size(); ++i)cout << " " << after[i];
}
