#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v[a].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
