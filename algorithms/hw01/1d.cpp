#include <iostream>
int main()
{
	std::ios::sync_with_stdio(false);
	int n = 0;
	std::cin >> n;
	int m[n];
	register int i = 0;
	while (i < n)
    {
    	std::cin >> *(m + i++);
    }
    while (n)
	{
    	std::cout << *(m + --n) << " ";
    }
	return 0;
}
