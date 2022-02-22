#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if ((n & (n - 1)) == 0)
            cout << "-1" << endl;
        else
        {
            int res = 0;
            for (int i = 1; i <= n; i = (i << 1))
            {
                res += (n - i) / (2 * i) * i;
            }
            for (int i = 2; i < n; i = i << 1)
            {
                res += i;
            }
            cout << res << endl;
        }
    }

    return 0;
}
