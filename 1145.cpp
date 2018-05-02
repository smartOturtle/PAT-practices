#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
bool IsPrime(int num)
{
    if (num == 2)return true;
    if (num == 1 || num % 2 == 0)return false;
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num%i == 0)return false;
    }
    return true;
}
int NoLessPrime(int num)
{
    while (!IsPrime(num)) { ++num; }
    return num;
}
vector<int> buckets;
inline int Hash(int key) { return key % buckets.size(); }
bool Insert(int key)
{
    for (int i = 0; i <= buckets.size(); ++i)
    {
        int insertPos = Hash(Hash(key) + i * i);
        if (buckets[insertPos] == 0)
        {
            buckets[insertPos] = key;
            return true;
        }
    }
    return false;
}
int SearchTime(int key)
{
    for (int i = 0; i < buckets.size()+1; ++i)
    {
        int pos = Hash(Hash(key) + i * i);
        if (buckets[pos] == key || buckets[pos] == 0)return i + 1;
    }
    return buckets.size()+1;
}
int main(int argc, char* argv[])
{
    int tableSize, nums, findKeys;
    cin >> tableSize >> nums >> findKeys;
    buckets.resize(NoLessPrime(tableSize));
    for (int i = 0; i < nums; ++i)
    {
        int key;
        scanf("%d", &key);
        if (!Insert(key))printf("%d cannot be inserted.\n", key);
    }
    int totalSearchTime = 0;
    for (int i = 0; i < findKeys; ++i)
    {
        int key;
        cin >> key;
        totalSearchTime += SearchTime(key);
    }
    printf("%.1lf", 1.0*totalSearchTime / findKeys);
}

