#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(0);
	std::stack<int, std::vector<int>> s;
	std::string t;
	while(std::cin >> t)
	{
		if (t == "+")
		{
			int x = s.top();
			s.pop();
			x += s.top();
			s.pop();
			s.emplace(x);
		}
		else
		if (t == "-")
		{
			int x = s.top();
			s.pop();
			x = s.top() - x;
			s.pop();
			s.emplace(x);
		}
		else
		if (t == "*")
		{
			int x = s.top();
			s.pop();
			x *= s.top();
			s.pop();
			s.emplace(x);
		}
		else
		{
			s.emplace(std::stoi(t));
		}
	}
	std::cout << s.top();
	s.pop();
	return 0;
}