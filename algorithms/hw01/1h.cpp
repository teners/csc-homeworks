#include <iostream>
using namespace std;
 
int a[41] = {};
void part(int n, int k, int i)
{
	if (n < 0) return; 
	if (!n)
    {
    	int j;
    	for (int j = 0; j < i; ++j)
        	std::cout << *(a + j) << " ";
      	cout << "\n";
    }
	else
	if (k - 1 > 0)
    	part(n, k - 1, i);
    if (n - k >= 0)
    {
    	*(a + i) = k;
    	part(n - k, k, i + 1);
    }
    return;
}
 
int main()
{
	int n = 0;
	std::ios::sync_with_stdio(0);
	std::cin >> n;
	part(n, n, 0);
	return 0;
}
