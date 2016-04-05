#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

int n, m;
int d[51][51];

int go(int x, int y)
{
    if (x >= n || y >= m)
        return 0;
    if (d[x][y] != 0)
        return d[x][y];
    d[x][y] = go(x + 2, y + 1) + go(x + 1, y + 2);
    return d[x][y];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> n >> m;
    if ((n + m - 2) % 3 != 0)
    {
        std::cout << 0;
        return 0;
    }
    d[n - 1][m - 1] = 1;
    std::cout << go(0, 0);
    return 0;
}
