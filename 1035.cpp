#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
	unordered_map<char, char> mapping{{ '1','@' },{ '0','%' } ,{ 'l','L' },{ 'O','o' } };
	int size;
	cin >> size;
	vector<pair<string,string>> users(size);
	vector<pair<string, string>*> modifiedUsers;
	for (auto& user:users)
	{
		cin >> user.first>>user.second;
		bool isModified = false;
		for (auto& c : user.second)
		{
			if (mapping.find(c) != mapping.end())
			{
				c = mapping[c];
				isModified = true;
			}
		}
		if (isModified) { modifiedUsers.push_back(&user); }
	}
	if(!modifiedUsers.empty())
	{
		cout << modifiedUsers.size() << '\n';
		for (auto && modifiedUser : modifiedUsers)
		{
			cout << modifiedUser->first << ' ' << modifiedUser->second<<'\n';
		}
	}
	else	if(size==1){ printf("There is 1 account and no account is modified"); }
	else { printf("There are %d accounts and no account is modified", size); }
}
