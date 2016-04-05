#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <climits>

char opp(char c)
{
    switch (c)
    {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::string res[n + 10][n + 10];
    int d[n + 10][n + 10];
    for (int i = 0; i < n; ++i)
    {
        d[i][i] = 1;
        res[i][i] = "";
    }
    for (int j = 2; j <= n; ++j)
    {
        for (int i = 0; i <= n - j; ++i)
        {
            d[i][i + j - 1] = 1e9;
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                for (int k = i + 1; k < i + j; ++k)
                {
                    if (s[k] == opp(s[i]) &&
                        d[i + 1][k - 1] + d[k + 1][i + j - 1] <
                        d[i][i + j - 1])
                    {
                        d[i][i + j - 1] = d[i + 1][k - 1]
                                + d[k + 1][i + j - 1];
                        res[i][i + j - 1] = s[i] +
                            (i + 1 <= k - 1 ? res[i + 1][k - 1]
                             : "") + s[k] + (k <= i + j - 2
                             ? res[k + 1][i + j - 1] : "");
                    }
                }
            }
            for (int k = i; k < i + j - 1; ++k)
            {
                if (d[i][k] + d[k + 1][i + j - 1] < d[i][i + j - 1])
                {
                    d[i][i + j - 1] = d[i][k] + d[k + 1][i + j - 1];
                    res[i][i + j - 1] = res[i][k] +
                            res[k + 1][i + j - 1];
                }
            }
        }
    }
    std::cout << res[0][n - 1];
    return 0;
}
