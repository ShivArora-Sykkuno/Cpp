#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int hei = 1;
    string str;
    cin >> n >> str;
    if (str[0] == '0' || str[1] == '0' || str[n] == '0')
    {
        cout << "No" << endl;
        return;
    }
    vector<int> v1;
    v1.push_back(0);
    for (int i = 2; i < str.size() - 1; i++)
    {
        if (str[i] == '0')
            v1.push_back(i);
        else
        {
            v1.push_back(hei);
            hei = i;
        }
    }

    v1.push_back(hei);
    cout << "Yes" << endl;
    for (auto x : v1)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}