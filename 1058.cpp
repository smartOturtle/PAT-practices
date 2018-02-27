#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <array>
using namespace std;

struct Currency
{
	long long knut;
	int Galleon() { return knut / 29 / 17; }
	int Sickle() { return knut / 29 % 17; }
	int Knut() { return knut % 29; }
	explicit Currency(long long knut = 0) :knut(knut) {}
	Currency operator +(const Currency& currency)const
	{
		return Currency(knut + currency.knut);
	}
	Currency(int galleon, int sickle, int knut)
		:knut(static_cast<long long>(galleon * 17 + sickle) * 29 + knut)
	{

	}
};
int main(int argc, char* argv[])
{
	int g, s, k;
	scanf("%d.%d.%d", &g, &s, &k);
	Currency a(g, s, k);
	scanf("%d.%d.%d", &g, &s, &k);
	Currency b(g, s, k);
	auto c = a + b;
	printf("%d.%d.%d", c.Galleon(), c.Sickle(), c.Knut());
}
