#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	using ui = unsigned;
	using ull = unsigned long long;
	std::ios::sync_with_stdio(0);
	ui n, x, y, a0, m, z, b0;
	int t;
	std::cin >> n >> x >> y >>a0;
	std::cin >> m >> z >> t >> b0;
	if (!m)
	{
		std::cout << 0 << "\n";
		return 0;
	}
	std::vector<ull> s(n);
	s[0] = a0;
	for (ui i = 1; i < n; ++i)
    {
    	a0 = x * a0 + y;
    	a0 <<= 16;
    	a0 >>= 16;
    	s[i] = s[i-1] + a0;
    }
	
	std::vector<ui> c(m * 2);
	c[0] = b0 % n;
	for (ui i = 1; i < m * 2; ++i)
    {
    	b0 = z * b0 + t;
    	b0 <<= 2;
    	b0 >>= 2;
    	c[i] = b0 % n;
    }
   	long long sum = 0;
   	for (int i = 0; i < m; ++i)
   	{
   		x = std::max(c[i*2], c[i*2+1]);
   		y = std::min(c[i*2], c[i*2+1]);
   		sum += s[x] - (!y ? 0 : s[std::min(c[i*2], c[i*2+1]) - 1]);
   	}
   	std::cout << sum << "\n";
	return 0;
}
