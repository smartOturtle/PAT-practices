#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
//找规律
int main(int argc, char* argv[])
{
    int size;
    cin >> size;
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        double value;
        cin >> value;
        sum += value * (size - i)*(i + 1);
    }
    printf("%.2lf", sum);
}
