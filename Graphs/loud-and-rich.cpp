#include <bits/stdc++.h>
using namespace std;

vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{
    unordered_map<int, vector<int>> richerMap;
    vector<int> res = vector<int>(quiet.size(), -1);
    for (auto v : richer)
        richerMap[v[1]].push_back(v[0]);
    for (int i = 0; i < quiet.size(); i++)
        dfs(i, quiet, richerMap, res);
    return res;
}

int dfs(int i, vector<int> &quiet, unordered_map<int, vector<int>> &richerMap, vector<int> &res)
{
    if (res[i] >= 0)
        return res[i];
    res[i] = i;
    for (int j : richerMap[i])
        if (quiet[res[i]] > quiet[dfs(j, quiet, richerMap, res)])
            res[i] = res[j];
    return res[i];
}