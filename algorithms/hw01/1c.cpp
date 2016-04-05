#include <cstdio>
int main()
{
	long long n = 0, k = 1, s = 0;
	scanf("%lld", &n);
	while (k * k <= n)
    {
    	s += n / (k * k);
    	++k;
    }
	printf("%lld\n", s);
	return 0;
}
