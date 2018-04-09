#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <map>
#include <algorithm>
using namespace std;
template<typename Iter>
void InsertionSort(Iter begin, Iter end)
{
    for (auto i = begin; i != end; ++i)
    {
        auto j = i;
        auto temp = *i;
        for (; j != begin && *(j - 1) > temp; --j)
            *j = *(j - 1);
        *j = temp;
    }
}
int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    vector<int> seq(N);
    vector<int> after(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> seq[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> after[i];
    }
    auto sortedEnd = is_sorted_until(after.begin(), after.end());
    bool isInsertionSort = true;
    for (auto i = sortedEnd - after.begin(); i<after.size(); ++i)
    {
        if (seq[i] != after[i])isInsertionSort = false;
    }
    if (isInsertionSort)
    {
        cout << "Insertion Sort\n";
        InsertionSort(after.begin(), sortedEnd + 1);
    }
    else
    {
        cout << "Heap Sort\n";
        pop_heap(after.begin(), is_heap_until(after.begin(), after.end()));
        //push_heap = swim
        //pop_heap = sink
    }   
    cout << after.front();
    for (int i = 1; i < after.size(); ++i)
    {
        cout << " " << after[i];
    }
}
