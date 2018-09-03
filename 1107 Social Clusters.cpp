#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include<functional>
using namespace std;
vector<int> people;
int Find(int idx)
{
	if(people[idx]<0)return idx;
	return people[idx]=Find(people[idx]);
}
void Union(int lhs,int rhs)
{
	auto lhsRoot=Find(lhs);
	auto rhsRoot=Find(rhs);
	if(lhsRoot==rhsRoot) return;
	if(people[lhsRoot]<people[rhs])swap(lhsRoot,rhsRoot);
	people[rhsRoot]+=people[lhsRoot];
	people[lhsRoot]=rhsRoot;
}
int main()
{
	int peopleSize;
	cin>>peopleSize;
	people.resize(peopleSize,-1);
	unordered_map<int,vector<int>> hobbyGroup;
	for(auto i=0;i<peopleSize;++i)
	{
		int hobbySize;
		scanf("%d:",&hobbySize);
		for(auto j=0;j<hobbySize;++j)
		{
			int id;
			cin>>id;
			hobbyGroup[id].push_back(i);
		}
	}
	for(auto iter=hobbyGroup.begin();iter!=hobbyGroup.end();++iter)
	{
		auto& group=iter->second;
		if(!group.empty())
		{
			int first=group.front();
			for(int i=1;i<group.size();i++)
			{
				Union(first,group[i]);
			}
		}
	}
	vector<int> clusters;
	for_each(people.begin(),people.end(),[&clusters](int value){if(value<0)clusters.push_back(-value);});
	sort(clusters.begin(),clusters.end(),greater<int>());
	cout<<clusters.size()<<'\n';
	if(clusters.size())
	{
		cout<<clusters.front();
		for(int i=1;i<clusters.size();++i)cout<<" "<<clusters[i];
	}
	return 0;
}

