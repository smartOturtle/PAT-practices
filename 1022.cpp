#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
enum Type
{
	Title=1,Author,Keyword,Publisher,Year
};
string ReadLine()
{
	char c;
	string s;
	while ((c= getchar())!='\n')
	{
		s.push_back(c);
	}
	return s;
}
vector<string> Split(const string& s, const char divChar)
{
	string part;
	vector<string> strings;
	for (auto c : s)
	{
		if (c == divChar)
		{
			strings.push_back(part);
			part.clear();
		}
		else part.push_back(c);
	}
	strings.push_back(part);
	return strings;
}
int main()
{
	int bookSize= stoi(ReadLine());
	unordered_map < int, unordered_map<string, set<int>>> queryTables;
	for (int i = 0; i < bookSize; ++i)
	{
		int id=stoi(ReadLine());
		string title = ReadLine();
		queryTables[Title][title].insert(id);
		string author = ReadLine();
		queryTables[Author][author].insert(id);
		auto keywords = Split(ReadLine(),' ');
		for (auto && keyword : keywords)
		{
			queryTables[Keyword][keyword].insert(id);
		}
		auto publisher = ReadLine();
		queryTables[Publisher][publisher].insert(id);
		string year=ReadLine();
		queryTables[Year][year].insert(id);
	}
	int querySize = stoi(ReadLine());
	for (int i = 0; i < querySize; ++i)
	{
		string query=ReadLine();
		cout << query << '\n';
		auto pos = queryTables[query[0] - '0'].find(query.substr(3));
		if (pos == queryTables[query[0] - '0'].end())cout << "Not Found\n";
		else for (auto id : pos->second)printf("%07d\n",id);
	}
}
