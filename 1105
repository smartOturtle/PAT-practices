#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>
using namespace std;
int main(int argc, char* argv[])
{
    int N;
    cin >> N;
    vector<int> seq(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &seq[i]);
    }
    sort(seq.begin(), seq.end(),greater<int>());
    int n = sqrt(N);
    while (N%n != 0)n--;
    int m = N / n;
    vector<vector<int>> matrix(m, vector<int>(n));
    int leftBound = 0, rightBound = n-1;
    int downBound = 0, upBound = m-1;
    int idx = 0;
    while (idx<seq.size())
    {
        for (int i = leftBound; i <= rightBound;++i )
        {
            matrix[downBound][i] = seq[idx++];
        }
        if(idx>=seq.size())break;
        downBound++;
        for (int i = downBound; i <= upBound; ++i)
        {
            matrix[i][rightBound] = seq[idx++];
        }
        if (idx >= seq.size())break;
        rightBound--;
        for (int i = rightBound; i >= leftBound; --i)
        {
            matrix[upBound][i] = seq[idx++];
        }
        if (idx >= seq.size())break;
        upBound--;
        for (int i = upBound; i >= downBound; --i)
        {
            matrix[i][leftBound] = seq[idx++];
        }
        leftBound++;
    }
    for (auto && row : matrix)
    {
        printf("%d", row[0]);
        for (int i = 1; i < row.size(); ++i)
        {
            printf(" %d", row[i]);
        }
        printf("\n");
    }
}
