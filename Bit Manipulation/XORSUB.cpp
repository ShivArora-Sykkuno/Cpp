#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1010][1030];

int solve(int i, int k, int curr, vector<int> &a)
{
    if (i < 0)
        return curr ^ k;
    if (dp[i][curr] != -1)
        return dp[i][curr];
    int x = solve(i - 1, k, curr ^ a[i], a);
    int y = solve(i - 1, k, curr, a);

    return dp[i][curr] = max(x, y);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        memset(dp, -1, sizeof(dp));
        cout << solve(n - 1, k, 0, a) << '\n';
    }

    return 0;
}