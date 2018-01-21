#include <iostream>
#include <string>
using namespace std;
const char radix[]{ "0123456789ABC" };
string s{ '#' };
void Transform(int num)
{
	s.push_back(radix[num / 13]);
	s.push_back(radix[num % 13]);
}
int main()
{
	int R, G, B;
	cin >> R >> G >> B;
	Transform(R);
	Transform(G);
	Transform(B);
	cout << s;
}
