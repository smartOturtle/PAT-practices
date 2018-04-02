#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename Iter, typename Comparator = less<typename Iter::value_type>>
void InsertionSort(Iter begin,Iter end,Comparator cmp=Comparator())
{
    for (auto i = begin; i != end; ++i)
    {
        auto insert = *i;
        auto j = i;
        for (; j !=begin&&cmp(insert,*(j-1)); --j)
        {
            (*j) = *(j-1);
        }
        *j = insert;
    }
}
template<typename Iter,typename Comparator=less<typename Iter::value_type>>
void InplaceMerge(Iter begin,Iter middle,Iter end,Iter auxBegin,Iter auxEnd, Comparator cmp = Comparator())
{
    using T = typename Iter::value_type;
    auto auxIter = auxBegin, lhsIter = begin, rhsIter = middle;
    while (lhsIter!=middle&&rhsIter!=end)
    {
        if(cmp(*lhsIter, *rhsIter)) (*auxIter++) = (*lhsIter++);
        else (*auxIter++) = (*rhsIter++);
    }
    copy(lhsIter, middle, auxIter);
    copy(rhsIter, end, auxIter);
    copy(auxBegin, auxEnd, begin);
}
template<typename Iter>
void MergeSort(Iter begin,Iter end)
{
    vector<typename Iter::value_type> aux(begin, end);
    function<void(Iter,Iter,Iter,Iter)> sortImpl=[&sortImpl](Iter begin,Iter end,Iter auxBegin,Iter auxEnd)
    {
        if(end-begin<2)return;
        auto middle = begin + (end - begin) / 2;
        sortImpl(begin, middle,auxBegin,auxBegin+ (end - begin) / 2);
        sortImpl(middle, end, auxBegin + (end - begin) / 2,auxEnd);
        InplaceMerge(begin, middle, end, auxBegin,auxEnd);
    };
    sortImpl(begin, end, aux.begin(), aux.end());
}
template<typename Iter>
void MergeSort(Iter begin,Iter end,size_t sortedLength,size_t endLength)
{
    vector<typename Iter::value_type> aux(begin, end);
    for (size_t length = sortedLength; length < min(endLength,aux.size()); length*=2)
    {
        for (int i = 0; i < aux.size()-length; i+=length*2)
        {
            InplaceMerge(begin + i, begin + i + length, begin + min(aux.size(), i + 2 * length),
                aux.begin() + i, aux.begin() + min(aux.size(), i + 2 * length));
        }
    }
}
template<class InputIt1, class InputIt2>
bool Equal(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2)
{
    if (distance(first1, last1) != distance(first2, last2))
        return false;
    for (; first1 != last1, first2 != last2; ++first1, ++first2)
    {
        if (!(*first1 == *first2))
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    vector<int> before(N);
    vector<int> after(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> before[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> after[i];
    }
    auto pos = is_sorted_until(after.begin(), after.end());
    if(Equal(pos, after.end(), before.begin() + (pos - after.begin()), before.end()))
    {
        InsertionSort(after.begin(), pos+1);
        cout << "Insertion Sort\n";
    }
    else
    {
        for (int length = 2; length < after.size(); length*=2)
        {
            for (int i = length; i < after.size(); i+=length*2)
            {
                if (after[i] < after[i - 1])
                {
                    MergeSort(after.begin(), after.end(), length, length * 2);
                    goto out;
                }
            }
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
