include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1e5 + 1;
int a[MAX_N];
int n, k;

int main() 
{
	std::ios::sync_with_stdio(0);
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
	}
	int l = 0, r = a[n-1];
	int m, count, cur, ans;
	while (l < r)
	{
		m = (l + r + 1) >> 1;
		count = 1;
		cur = a[0];
		for (int i = 1; i < n; ++i)
		{
			if (!((a[i] - cur) < m)) {
				cur = a[i];
				count++; }
		}
		if (count >= k)
		{
			l = m;
			if (count >= k)
				ans = m;
		}
		else 
			r = m - 1;
	}
	std::cout << ans;
	return 0;
}
