#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

const int MAXN = 110;
const int INF = 1e9;
 
int n, m;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];
 
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> m >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> a[i][j];
    for (int i = 0; i < MAXN; ++i)
        dp[i][0] = INF, dp[0][i] = INF;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (i == 1 && j == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = std::min(dp[i - 1][j] + abs(a[i][j] - a[i - 1][j]), dp[i][j - 1] + abs(a[i][j] - a[i][j - 1]));
    std::cout << dp[n][m];
}