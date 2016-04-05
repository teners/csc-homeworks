#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

const int MINF = INT_MIN;

int main()
{
	std::ios::sync_with_stdio(0);
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	std::vector<long long> x(n, MINF);
	for (int i = 0; i < n; ++i)
	{
		char t;
		std::cin >> t;
		if (t == '.')
			p[i] = 0;
		if (t == '\"')
			p[i] = 1;
		if (t == 'w')
			p[i] = MINF;
	}
	//if (n != 1)
	//	p[0] = -1;
	x[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		x[i] = std::max(x[i], x[i-1]);
		if (i > 2)
			x[i] = std::max(x[i], x[i-3]);
		if (i > 4)
			x[i] = std::max(x[i], x[i-5]);
		x[i] += p[i];
	}
	std::cout << (x[n - 1] < 0 ? -1 : x[n - 1]);
	return 0;
}