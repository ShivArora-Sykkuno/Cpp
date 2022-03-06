#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        vector<int> v;
        if (x == 1 && y == 1)
        {
            if (bound >= 2)
            {
                v.push_back(2);
            }
            return v;
        }
        int x1 = 1, y1 = 1;
        set<int> ans;
        if (x == 1)
        {
            v.push_back(1);
        }
        else
        {
            while (bound - 1 >= x1)
            {
                v.push_back(x1);
                x1 = x1 * x;
            }
        }
        int n = v.size();
        if (y == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] + y1 <= bound)
                {
                    ans.insert(v[i] + y1);
                }
            }
        }
        else
        {
            while (bound > y1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (v[i] + y1 <= bound)
                    {
                        ans.insert(v[i] + y1);
                    }
                }
                y1 = y1 * y;
            }
        }
        v.clear();
        for (auto i : ans)
        {
            v.push_back(i);
        }
        return v;
    }
};