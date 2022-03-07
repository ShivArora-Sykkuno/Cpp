#include <bits/stdc++.h>
using namespace std;

string graph[10009];

int n, m;

int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, 1, -1};

bool not_island(int x, int y)
{
    return x < 0 || y < 0 || x >= n || y >= m || graph[x][y] == '0' || graph[x][y] == '#';
}

void DFS(int x, int y)
{
    if (not_island(x, y))
        return;
    graph[x][y] = '0';
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x, ny = dy[i] + y;
        DFS(nx, ny);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> graph[i];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if ((i * j == 0 || i == n - 1 || j == m - 1) && graph[i][j] == '.')
                    DFS(i, j);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (graph[i][j] == '.')
                {
                    res++;
                    DFS(i, j);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}