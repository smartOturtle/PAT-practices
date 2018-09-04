#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include<functional>
#include<string>
#include<numeric>
using namespace std;
int main()
{
	int size;
	cin>>size;
	vector<int> segments(size);
	for(int i=0;i<size;++i)cin>>segments[i];
	sort(segments.begin(),segments.end());
	cout<< accumulate(segments.begin()+1,segments.end(),segments.front(),[](int lhs,int rhs){return (lhs+rhs)/2;});
}
