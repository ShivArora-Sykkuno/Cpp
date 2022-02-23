#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int main()
    {
        int tt;
        cin >> tt;
        while (tt--)
        {
            int X, Y, i;
            cin >> X >> Y;
            int num = 1;

            while (num * num < X + Y)
                num++;

            if (num * num == X + Y)
            {

                int even_level_nodes, odd_level_nodes;
                even_level_nodes = 1;
                odd_level_nodes = num - 1;
                bool visited = false;

                while (even_level_nodes <= odd_level_nodes)
                {

                    int temp_y = 2 * even_level_nodes * odd_level_nodes;
                    if (temp_y == Y)
                    {
                        visited = true;
                        break;
                    }
                    even_level_nodes = even_level_nodes + 1;
                    odd_level_nodes = odd_level_nodes - 1;
                }

                if (visited == true)
                {
                    cout << "YES\n";
                    cout << num << "\n";
                    for (i = 1; i <= odd_level_nodes; i++)
                        cout << 1 << " " << i + 1 << "\n";
                    for (i = 1; i < even_level_nodes; i++)
                        cout << 2 << " " << odd_level_nodes + i + 1 << "\n";
                }

                else
                    cout << "NO\n";
            }

            else
                cout << "NO\n";
        }
    }
}