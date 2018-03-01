#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
const unordered_map<char, string> WeekDays
{{ 'A',"MON" },{ 'B',"TUE" },{ 'C',"WED" },{ 'D',"THU" },{ 'E',"FRI" },{ 'F',"SAT" },{ 'G',"SUN" }, };
int ToHour(char c)
{
	if (isdigit(c))return c - '0';
	return c - 'A' + 10;
}
int main(int argc, char *argv[])
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	bool isFirstCommon = true;
	for (int i = 0; i < min(a.size(),b.size()); ++i)
	{
		if (a[i] == b[i])
		{
			if(isFirstCommon)
			{
				if(a[i]>='A'&&a[i]<='G')
				{
					cout << WeekDays.at(a[i]) << " ";
					isFirstCommon = false;
				}
			}
			else
			{
				if(isdigit(a[i])||(a[i] >= 'A'&&a[i] <= 'N'))
				{
					printf("%02d", ToHour(a[i]));
					break;
				}
			}
		}
	}
	for (int i = 0; i < min(c.size(), d.size()); ++i)
	{
		if (c[i] == d[i]&&isalpha(c[i]))
		{
			printf(":%02d", i);
			break;
		}
	}
}
