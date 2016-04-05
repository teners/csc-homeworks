#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

const int MAXM = 300001;
const int MAXN = 200;

int main()
{
	std::ios::sync_with_stdio(0);
	std::vector<int> a(MAXN, 0);
	std::vector<int> d(MAXM, 0);
    for (int i = 1; i < MAXN; ++i)
    {
        a[i] = a[i - 1] + i;
    }
    for (int i = 1; i < MAXN; ++i)
    {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < MAXM; ++i)
    {
        d[i] = i;
    }
    for (int i = 2; i < MAXN; ++i)
    {
        for (int j = a[i]; j < MAXM; ++j)
        {
            d[j] = std::min(d[j], d[j - a[i]] + 1);
        }
    }
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        std::cin >> n;
        std::cout << d[n] << std::endl;
    }
    return 0;
}
