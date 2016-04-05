#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

long long n, k;
std::map <long long, long long> d;

long long go(long long n)
{
    if (d.count(n))
    {
        return d[n];
    }
    if (n <= k)
    {
        d[n] = 1;
    }
    else
    {
        d[n] = go(n / 2) + go((n + 1) / 2);
    }
    return d[n];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> n >> k;
    std::cout << go(n);
    return 0;
}
