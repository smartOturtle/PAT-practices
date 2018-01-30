#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
template<typename RandIter>
RandIter FindKthSmallest(RandIter lBegin,RandIter lEnd,RandIter rBegin,RandIter rEnd,int k)
{
	static_assert(
		is_same<typename  iterator_traits<RandIter>::iterator_category, 
		random_access_iterator_tag>::value,
		"random access iterator only");
	if (lBegin == lEnd)return rBegin + (k - 1);
	if (rBegin == rEnd)return lBegin + (k - 1);
	if (k == 1){ return *lBegin< *rBegin ? lBegin : rBegin; }
	int lhsIdx = 1.0*(lEnd - lBegin) / (lEnd - lBegin + (rEnd - rBegin))*(k - 1);
	int rhsIdx = k - 2 - lhsIdx;
	if (*(lBegin + lhsIdx) == *(rBegin + rhsIdx)){ return lBegin + lhsIdx; }
	if (*(lBegin + lhsIdx) > *(rBegin + rhsIdx))
	{
		return FindKthSmallest(lBegin, lBegin + lhsIdx+1, rBegin + rhsIdx+1 , rEnd, k - (rhsIdx + 1));
	}
	//if (*(lBegin + lhsIdx) < *(rBegin + rhsIdx))
	return FindKthSmallest(lBegin + lhsIdx + 1, lEnd, rBegin, rBegin + rhsIdx + 1, k - (lhsIdx + 1));
}
template<typename C>
C Input()
{
	int size;
	cin >> size;
	C seq(size);
	for (int i = 0; i < size; ++i) {scanf("%d", &seq[i]);}
	return seq;
}
int main(int argc, char* argv[])
{
	auto a = Input<vector<int>>();
	auto b = Input<vector<int>>();
	cout << *FindKthSmallest(a.begin(), a.end(), b.begin(), b.end(), (a.size()+b.size()+1)/2);
}
