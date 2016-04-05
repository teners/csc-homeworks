#include <iostream>
int main()
{
	std::ios::sync_with_stdio(0);
	long long n, a, b, c, x, y, z;
	std::cin >> n;
	long long s = 4 * n + 3;
	for (a = 1; a * a * a <= n; a++)
		if (n % a == 0)
		{
			for (b = a; a * b * b <= n; b++)
			{
				if (n % (a * b) == 0)
				{
					c = n / (a * b);
					if (s > 2 * (a * b + a * c + b * c))
					{
						s = 2 * (a * b + a * c + b * c);
						x = a;
						y = b;
						z = c;
					}
				}
			}
		}
	std::cout << s << " " << x << " " << y << " " << z << "\n";
	return 0;
}
