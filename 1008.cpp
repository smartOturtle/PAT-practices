#include<iostream>
using namespace std;
int main()
{  int cnt;
  cin >> cnt;
  int currentFloor = 0,totalTime=0;
  for (size_t i = 0; i < cnt; i++)
  {
    int floor;
    cin >> floor;
    if (currentFloor>floor)totalTime += (currentFloor - floor)*4;
    else totalTime += (floor-currentFloor) * 6;
    currentFloor = floor;
    totalTime += 5;
  }
  cout << totalTime;

}
