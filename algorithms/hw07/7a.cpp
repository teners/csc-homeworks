#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <map>

int main() {
	std::ios::sync_with_stdio(0);
	std::queue<std::pair<int, int>> q;
	std::map<int, std::queue<int>> i;
	int n, type, time, item, now;
	std::cin >> n;
	while (n--)
	{
		std::cin >> type >> time >> item;
		if (type == 1)
		{
			i[item].emplace(time);
		}
		else 
		{
			q.emplace(std::make_pair(time, item));
		}
		now = time;
		while (!q.empty() && !i[q.front().second].empty())
		{
			std::cout << now - q.front().first << " ";
			i[q.front().second].pop();
			q.pop();
		}
	}
	while (!q.empty())
	{
		std::cout << "-1 ";
		q.pop();
	}
	return 0;
}