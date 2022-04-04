#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{

public:
    int presum[500][500] = {0}, sqsum[500][500] = {0};
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = n ? matrix[0].size() : 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                presum[i][j] = matrix[i - 1][j - 1];
                if (j > 1)
                    presum[i][j] += presum[i][j - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                sqsum[i][j] = presum[i][j];
                if (i > 1)
                    sqsum[i][j] += sqsum[i - 1][j];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2)
    {
        return sqsum[r2 + 1][c2 + 1] + sqsum[r1][c1] - sqsum[r2 + 1][c1] - sqsum[r1][c2 + 1];
    }
};