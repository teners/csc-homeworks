#include <iostream>
 
int main()
{
	int n, k, ans;
    std::ios::sync_with_stdio(0);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        ans = (ans + k) % i;
    std::cout << ans + 1;
}