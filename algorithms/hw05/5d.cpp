#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
 
const int MAXN = 110;
const int INF = 1e9;
const long long M = (1ll << 32);
 
std::map < long long, long long > data;
long long n;
 
long long f(long long n)
{
    if (data.count(n))
        return data[n];
    if (n <= 2)
        data[n] = 1;
    else if (n & 1)
        data[n] = (f(6 * n / 7) + f(2 * n / 3)) % M;
    else
        data[n] = (f(n - 1) + f(n - 3)) % M;
    return data[n];
}
 
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> n;
    std::cout << f(n) << "\n";
}