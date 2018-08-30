#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

template<typename Iter>
void InsertSort(Iter first,Iter last)
{
    for(auto iter1=first;iter1!=last;++iter1)
    {
        auto temp = *iter1;
        auto iter2 = iter1;
        for (; iter2 != first && *prev(iter2) > temp; --iter2)*iter2=*prev(iter2);
        *iter2 = temp;
    }
}
template<typename Iter1,typename Iter2>
void Merge(Iter1 first,Iter1 middle,Iter1 last,Iter2 destFirst)
{
    auto left = first;
    auto right = middle;
    while (left!=middle&&right!=last)
    {
        if (*left < *right)*(destFirst++) = *(left++);
        else *(destFirst++) = *(right++);
    }
    copy(left, middle, destFirst);
    copy(right, last, destFirst);
}
template<typename Iter>
void MergeSort(Iter begin, Iter end, size_t sortedLength, size_t endLength)
{
    vector<typename Iter::value_type> aux(begin, end);
    for (size_t length = sortedLength; length < min(endLength, aux.size()); length *= 2)
    {
        for (int i = 0; i < aux.size() - length; i += length * 2)
        {
            Merge(begin + i, begin + i + length,begin + min(aux.size(), i + 2 * length),aux.begin() + i);
        }
        copy(aux.begin(), aux.end(), begin);
    }
}
int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    vector<int> before(N);
    vector<int> after(N);
    for (int i = 0; i < N; ++i)cin >> before[i];
    for (int i = 0; i < N; ++i)cin >> after[i];
    auto pos = is_sorted_until(after.begin(), after.end());
    if (equal(pos, after.end(), before.begin() + (pos - after.begin()), before.end()))
    {
        InsertSort(after.begin(), pos + 1);
        cout << "Insertion Sort\n";
    }
    else
    {
        for (int length = 2; length < after.size(); length *= 2)
            for (int i = length; i < after.size(); i += length * 2)
                if (after[i] < after[i - 1])
                {
                    MergeSort(after.begin(), after.end(), length, length * 2);
                    goto out;
                }
    out:
        cout << "Merge Sort\n";
    }
    cout << after.front();
    for (int i = 1; i < after.size(); ++i)
    {
        cout << " " << after[i];
    }
}
