#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main() {
	unsigned const mod = (1 << 30) - 1;
	std::ios::sync_with_stdio(0);
	int n, k;
	std::cin >> n >> k;
	std::deque<int> d;
	while(n--)
	{
		int x;
		std::cin >> x;
		d.emplace_back(x);
	}
	while(k--)
	{
		unsigned x = d.front(), y = d.back();
		if (x < y)
		{
			d.pop_front();
			d.emplace_back((x + y) & mod);
		}
		else
		{
			d.pop_back();
			d.emplace_front((y - x) & mod);
		}
	}
	for (auto i : d)
		std::cout << i << " ";
	return 0;
}