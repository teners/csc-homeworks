#include <iostream>
int main()
{
	std::ios::sync_with_stdio(0);
	bool all[15000] = {};
	int n = 0, sum = 15000;
	std:: cin >> n;
	for (int i = 0; i < n; ++i)
    {
    	int t;
    	std:: cin >> t;
        if (all[t-1] == 0)
        {
    		all[t-1] = 1;
        	sum--;
        }
    }
	std::cout << sum;
	return 0;
}
