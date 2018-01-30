#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Station
{
	double dist;
	double price;
	Station(){}
	Station(double dist,double price):dist(dist),price(price){}
};
int main(int argc, char* argv[])
{
	double capacity, distance, unit ;
	int  stationSize;
	cin >> capacity >> distance >> unit >> stationSize;
	vector<Station> stations(stationSize);
	for (int i = 0; i < stationSize; ++i)
	{
		scanf("%lf %lf", &stations[i].price, &stations[i].dist);
	}
	sort(stations.begin(), stations.end(), 
		[](const Station&lhs, const Station&rhs) { return lhs.dist < rhs.dist; });
	double currentGas = 0,currentPos=0;
	double totalCost=0;
	stations.push_back({ distance, 0 });//sentry or guard
	for (int i = 0; i < stations.size(); ++i)
	{
		auto reachFarest = currentGas * unit + currentPos;
		if(reachFarest<stations[i].dist||reachFarest>=distance)
		{
			currentPos = min(reachFarest,distance);
			break;
		}
		currentGas -= (stations[i].dist - currentPos) / unit;
		currentPos = stations[i].dist;
		Station cheaper=stations[i];
		for (auto j=i+1; j<stations.size()&& stations[j].dist<=capacity*unit + currentPos; ++j)
		{
			if (stations[j].price < cheaper.price)
			{
				cheaper = stations[j];
				break;
			}
		}
		if(cheaper.price<stations[i].price)
		{
			auto need = max(0.0, (cheaper.dist - reachFarest) / unit);
			totalCost += (need*stations[i].price);
			currentGas += need;
		}
		else
		{
			totalCost += (capacity - currentGas)*stations[i].price;
			currentGas = capacity;
		}
	}
	if(abs(currentPos-distance)<=1e-8) {printf("%.2lf", totalCost);}
	else { printf("The maximum travel distance = %.2lf", currentPos); }
}
