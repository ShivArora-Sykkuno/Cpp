#include <bits/stdc++.h>
using namespace std;

int numSquares(int n)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int minm = INT_MAX;
        for (int j = 1; j <= sqrt(i); j++)
        {
            minm = min(minm, dp[i - j * j]);
        }
        dp[i] = 1 + minm;
    }
    return dp[n];
}