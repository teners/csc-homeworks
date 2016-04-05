#include <iostream>
#include <algorithm>
#include <vector>

int n, a, b;
unsigned int cur = 0;

unsigned int nextRand24()
{
    cur = cur * a + b;
    return cur >> 8;
}

unsigned int nextRand32()
{
    unsigned int a = nextRand24(), b = nextRand24();
    return (a << 8) ^ b;
}

long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}


int main()
{
    std::cin >> n >> a >> b;
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += nextRand32();
    }
    long long k = gcd(sum, n);
    std::cout << sum / k << "/" << n / k;
}
