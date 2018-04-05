#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <array>
#include <functional>
using namespace std;
int M, N, sliceSize, threshold;
int area[60][1286][128] = {};
using Coordinate = array<int, 3>;
bool TestAndSet(const Coordinate& coord,queue<Coordinate>& q)
{
    if (coord[0] < sliceSize&&
        coord[0] >= 0 &&
        coord[1] < M&&
        coord[1] >= 0 &&
        coord[2] < N&&
        coord[2] >= 0 &&
        area[coord[0]][coord[1]][coord[2]])
    {
        area[coord[0]][coord[1]][coord[2]] = 0;
        q.push(coord);
        return true;
    }
    return false;
}
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int main(int argc, char* argv[])
{
    cin >> M >> N >> sliceSize >> threshold;
    int totalVolume = 0;

    for (int i = 0; i < sliceSize; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < N; ++k)
                cin >> area[i][j][k];

    queue<Coordinate> q;
    for (int x = 0; x < sliceSize; ++x)
        for (int y = 0; y < M; ++y)
            for (int z = 0; z < N; ++z)
                if(TestAndSet({x,y,z},q))
                {
                    int currentVolume=0;
                    while (!q.empty())
                    {
                        for (int i = 0; i < 6; ++i)
                            TestAndSet({ q.front()[0] + dx[i],q.front()[1] + dy[i],q.front()[2] + dz[i] }, q);
                        q.pop();
                        currentVolume++;
                    }
                    if (currentVolume >= threshold)totalVolume += currentVolume;
                }
    cout << totalVolume;
}

