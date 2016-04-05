#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0);
    int n, l, r;
    std::cin >> n;
    std::vector <int> s(n);
    for (auto i = 0; i < n; ++i)
        std::cin >> s[i];
    std::sort(s.begin(), s.end());
    std::cin >> n;
    while (n--) {
        std::cin >> l >> r;
        int t = std::upper_bound(s.begin(), s.end(), r) - 
        		std::lower_bound(s.begin(), s.end(), l);
        std::cout << t << " ";
    }
    return 0;
}
