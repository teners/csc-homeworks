#include <iostream>
int main()
{
	std::ios::sync_with_stdio(0);
	unsigned long long a[1001] = {};
	a[0] = a[1] = 1;
	unsigned int n = 0, m = 0;
	std::cin >> n >> m;
	if (!n || n == 1) 
	{
		std::cout << a[n] % m;
    	return 0;
    }
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			a[i] = (a[i] + (((a[j] % m) * (a[i - j - 1] % m)) % m)) % m;
		}
	}
	std::cout << a[n];
	return 0;
}
