#include <vector>
#include <algorithm>
#include <iostream>
int main()
{
	std::ios::sync_with_stdio(0);
	int n, m, t; 
    std::cin >> n >> m;
    std::vector <int> s(n);
    for (auto i = s.begin(); i != s.end(); ++i)
        std::cin >> *i;
    std::sort(s.begin(), s.end());
    for (int i = 0; i < m; ++i)
    {
        std::cin >> t;
        std::cout << (std::binary_search(s.begin(), s.end(), t) ? "YES\n" : "NO\n");
    }
    return 0;
}
