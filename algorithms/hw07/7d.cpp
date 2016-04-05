#include <iostream>
#include <stack>

int main() 
{
	std::string s;
	std::stack<char> st;
	std::cin >> s;
	for (auto i : s)
	{
		if (i == '(' || i == '[' || i == '{')
		{
			st.emplace(i);
		}
		else
		if (i == ')' && !st.empty() && st.top() == '(')
		{
			st.pop();
		}
		else
		if (i == ']' && !st.empty() && st.top() == '[')
		{
			st.pop();
		}
		else
		if (i == '}' && !st.empty() && st.top() == '{')
		{
			st.pop();
		}
		else
		{
			std::cout << "NO";
			return 0;
		}
	}
	if (st.empty())
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	return 0;	
}