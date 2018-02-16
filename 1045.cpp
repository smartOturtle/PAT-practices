#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[])
{
	int colorSize,lhsSize;
	cin >>colorSize>> lhsSize;
	vector<int> lhs(lhsSize);
	for (int i = 0; i < lhsSize; ++i)
	{
		cin >> lhs[i];
	}
	int rhsSize;
	cin >> rhsSize;
	vector<int> rhs(rhsSize);
	for (int i = 0; i < rhsSize; ++i)
	{
		cin >> rhs[i];
	}
	vector<vector<int>> lcs(lhs.size()+1,vector<int>(rhs.size()+1));
	for (int i = 1; i <= lhs.size(); ++i)
	{
		for (int j = 1; j <= rhs.size(); ++j)
		{
			lcs[i][j] = max({ lcs[i - 1][j], lcs[i][j - 1], lcs[i - 1][j - 1] });
			if (lhs[i-1] == rhs[j-1])lcs[i][j]++;
		}
	}
	cout << lcs[lhs.size()][rhs.size()];
}
