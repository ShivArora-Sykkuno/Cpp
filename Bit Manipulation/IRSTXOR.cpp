#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll c, d = 1, i, a = 0, b = 0;
        cin >> c;
        while (d <= c)
            d = (d << 1);
        for (i = 30; i >= 0; i--)
        {
            if ((1 & (c >> i)))
            {
                a = (a | (1 << i));
                break;
            }
        }
        for (i = i - 1; i >= 0; i--)
        {
            if ((1 & (c >> i)) == 0)
                a = (a | (1 << i));
            b = (b | (1 << i));
        }
        cout << a * b;
        cout << "\n";
    }
    return 0;
}