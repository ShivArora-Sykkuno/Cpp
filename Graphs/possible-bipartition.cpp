#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[], vector<int> &col, int start)
{
    if (col[start] == -1)
        col[start] = 1;
    for (auto &i : adj[start])
    {
        if (col[i] == -1)
        {
            col[i] = 1 - col[start];
            if (!dfs(adj, col, i))
                return false;
        }
        else if (col[i] == col[start])
            return false;
    }

    return true;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    n = n + 1;
    vector<int> adj[n];

    for (auto &i : dislikes)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<int> col(n, -1);
    for (int i = 1; i < n; i++)
    {

        if (col[i] == -1 && !dfs(adj, col, i))
        {
            return false;
        }
    }
    return true;
}