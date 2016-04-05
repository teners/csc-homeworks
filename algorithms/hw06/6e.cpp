#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <string>
#include <cstring>

int main()
{
    std::ios::sync_with_stdio(0);
    std::string s1, s2;
    bool d[2][10010];
    d[0][0] = 1;
    std::cin >> s1 >> s2;
    s1 = '#' + s1;
    s2 = '#' + s2;
    int l1 = s1.length();
    int l2 = s2.length();
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                d[1][j] = d[0][j - 1];
            }
            else if (s1[i - 1] == '*')
            {
                d[1][j] = d[0][j - 1] || d[1][j - 1] || d[0][j];
            }
        }
        for (int j = 0; j <= l2; ++j)
        {
            d[0][j] = d[1][j];
            d[1][j] = 0;
        }
    }
    if (d[0][l2])
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
