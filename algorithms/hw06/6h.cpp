#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <climits>

int main()
{
    std::ios::sync_with_stdio(0);
    int n, s = 0;
    std::cin >> n;
    int n_ = 1 << n;
    ++n;
    int v[n], g[n][n], d[n_][n], p[n_][n];
    --n;
    for (int i = 0; i < n_; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            p[i][j] = -1;
            d[i][j] = 2e9;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> g[i][j];
            d[1 << i][i] = 0;
        }
    }
    for (int i = 0; i < n_; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (d[i | (1 << k)][k] > d[i][j] + g[j][k] && ((i >> k) & 1) == 0)
                {
                    d[i | (1 << k)][k] = d[i][j] + g[j][k];
                    p[i | (1 << k)][k] = j;
                }
            }

        }
    }
    int k = 0;
    int mask = n_ - 1;
    for (int i = 0; i < n; ++i)
    {
        if (d[mask][i] < d[mask][k])
        {
            k = i;
        }
    }
    int sum = d[mask][k];
    while (k != -1)
    {
        v[s] = k + 1;
        s++;
        int k_ = p[mask][k];
        mask ^= (1 << k);
        k = k_;
    }
    std::cout << sum << std::endl;
    for (int i = s - 1; i >= 0; --i)
        std::cout << v[i] << ' ';
    return 0;
}
