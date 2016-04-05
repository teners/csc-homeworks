#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
int main() {
	std::ios::sync_with_stdio(0);
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector <int> v(n);
    ll r = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        r += (ll)(v[i]);
    }
    r /= (ll)(m);
    ll l = 0, sum = 0;
	if (!r) {
		std::cout << 0;
		return 0;
	}
    while (l < r - 1) {
        ll mid = (l + r + 1) >> 1;
		sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += v[i] / mid;
            if (sum >= m) {
				l = mid;
                break;
			}
        }
        if (sum < m) 
            r = mid;
	}
	sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i] / r;
        if (sum >= m) {
			std::cout << r;
            return 0;
		}
	}
	std::cout << l;
    return 0;
}
