#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include<functional>
#include<string>
using namespace std;
int main()
{
	int forwardSize,skipNum,firstIdx;
	cin>>forwardSize>>skipNum>>firstIdx;
	for(auto i=1;i<min(firstIdx,forwardSize+1);++i)
	{
		string s;
		cin>>s;
	}
	unordered_map<string,bool> hasGot;
	auto winnerIdx=firstIdx;
	for(auto i=firstIdx;i<=forwardSize;++i)
	{
		string s;
		cin>>s;
		if((winnerIdx-firstIdx)%skipNum==0)
		{
			if(!hasGot[s])
			{
				cout<<s<<'\n';
				hasGot[s]=true;
			}
			else winnerIdx--;
		}
		winnerIdx++;
	}
	if(all_of(hasGot.begin(),hasGot.end(),[](const pair<const string,bool>& p){return !p.second;}))cout<<"Keep going...";
}

