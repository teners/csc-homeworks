#include <iostream>
#include <vector>
int main() 
{
	std::ios::sync_with_stdio(0);
	int n;
	std::cin >> n;
	//std::vector<std::string> v(n);
	//std::vector<int> next(n), prev(n);
	std::string v[n];
	int next[n], prev[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin >> v[i];
		next[i] = (i + 1) % n;
		prev[i] = (i + n - 1) % n;
	}
	for (int i = 0; i < n - 3; ++i)
	{
		int temp;
		std::cin >> temp;
		--temp;
		std::cout << v[prev[temp]] << " " << v[next[temp]] << "\n";
		prev[next[temp]] = prev[temp];
  		next[prev[temp]] = next[temp];
	}
	return 0;	
}