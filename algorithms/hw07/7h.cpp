#include <iostream>
#include <stack>

int main() 
{
	std::string s;
	std::stack<char> st;
	int c = 0;
	std::cin >> s;
	for (auto i : s)
	{
		if (i == '(')
		{
			st.emplace(i);
		}
		else
		if (i == ')' && !st.empty() && st.top() == '(')
		{
			st.pop();
		}
		else
		{
			c++;
		}
	}
	std::cout << c + st.size();
	return 0;	
}