#include <iostream>

int main()
{
	long long fib[92];
	fib[0] = fib[1] = 1;
	int n; 
	std::cin >> n;
	if (n == 0 || n == 1) {
		std::cout << 1;
		return 0;
	}
	for (int i = 2; i <= n; ++i)
		fib[i] = fib[i-1] + fib[i-2];
	std::cout << fib[n];
}
