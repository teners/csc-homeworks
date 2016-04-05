#include <iostream>
#include <algorithm>
#include <vector>

const int MAXL = 1001;
const int MAXN = 10;

int s[MAXL + 10], t[MAXL + 10], n, m;
std::vector<int> ans(MAXL + 10, -1);
int sz, last;
short int dp[MAXN + 10][MAXL + 10];
short int data[4][MAXL + 10];
short int *f0 = data[0], *f1 = data[1], *p0 = data[2], *p1 = data[3];

void upd(short int &a, short int b) {
    a = std::max(a, b);
}

void solve(int sl, int sr, int tl, int tr);

void solveSlow(int sl, int sr, int tl, int tr)
{
    int sn = sr - sl;
    int tn = tr - tl;
    for (int i = 0; i < sn + 2; ++i)
        for (int j = 0; j < tn + 2; ++j)
            dp[i][j] = 0;
    for (int i = 0; i < sn + 1; ++i)
        for (int j = 0; j < tn + 1; ++j) {
            upd(dp[i + 1][j], dp[i][j]);
            upd(dp[i][j + 1], dp[i][j]);
            if (s[sl + i] == t[tl + j])
                upd(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    int i = sn, j = tn, last = sz;
    while (i && j)
        if (s[sl + i - 1] == t[tl + j - 1])
            ans[sz++] = s[sl + i - 1], --i, --j;
        else if (dp[i - 1][j] == dp[i][j])
            --i;
        else
            --j;
    std::reverse(ans.begin() + last, ans.begin() + sz);
}

void solveFast(int sl, int sr, int tl, int tr)
{
    int sn = sr - sl;
    int tn = tr - tl;
    for (int j = 0; j < tn + 1; ++j)
        f0[j] = 0;
    int m = sn / 2;
    for (int i = 0; i < sn + 1; ++i) {
        for (int j = 0; j < tn; ++j)
            if (f0[j + 1] < f0[j])
                f0[j + 1] = f0[j], p0[j + 1] = p0[j];
        if (i == m)
            for (int j = 0; j < tn + 1; ++j)
                p0[j] = j;
        for (int j = 0; j < tn + 1; ++j)
            f1[j] = f0[j], p1[j] = p0[j];
        for (int j = 0; j < tn; ++j)
            if (s[sl + i] == t[tl + j] && f1[j + 1] < f0[j] + 1)
                f1[j + 1] = f0[j] + 1, p1[j + 1] = p0[j];
        std::swap(f1, f0), std::swap(p0, p1);
    }
    int z = p0[tn];
    solve(sl, sl + m, tl, tl + z);
    solve(sl + m, sr, tl + z, tr);
}

void solve(int sl, int sr, int tl, int tr) {
    if (sr - sl <= MAXN)
        solveSlow(sl, sr, tl, tr);
    else
        solveFast(sl, sr, tl, tr);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin >> n;
    for (int i = 0; i < n; ++i)
       std::cin >> s[i];
    std::cin >> m;
    for (int i = 0; i < m; ++i)
       std::cin >> t[i];
    solve(0, n, 0, m);
    int x = 0;
    for (auto it = ans.begin(); it != ans.end(); ++it, ++x)
    {
    	if (*it == -1) 
    		break; 
    }
    std::cout << x;
    return 0;
}