#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        int v[n];
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &v[i]);
            if (__builtin_popcount(v[i]) % 2 == 0)
                even++;
        }
        odd = n - even;
        for (int i = 0; i < q; i++)
        {
            int p;
            scanf("%d", &p);
            int Even = even, Odd = odd;
            if (((__builtin_popcount(p)) & 1))
                swap(Odd, Even);
            printf("%d %d \n", Even, Odd);
        }
    }
}