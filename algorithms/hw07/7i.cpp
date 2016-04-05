#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <random>

std::string s;
std::stack<char, std::vector<char>> op;
std::stack<int, std::vector<int>> st;

bool isOp(char c)
{
    return (c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/');
}

int get(char c)
{
    if (c == '(')
    {    
    	return -1;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return 2;
}

void make()
{
    int y = st.top();
    st.pop();
    int x = st.top();
    st.pop();
    char o = op.top();
    op.pop();
    if (o == '-')
    {
        st.emplace(x - y);
    }
    if (o == '+')
    {
        st.emplace(x + y);
    }
    if (o == '*')
	{
        st.emplace(x * y);
	}
    if (o == '/')
    {
        st.emplace(x / y);
    }
}

int main()
{
    std::cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isOp(s[i]))
        {
            if (s[i] == '(')
            {
                op.emplace(s[i]);
                continue;
            }
            if (s[i] == ')')
            {
                while (op.top() != '(')
                {    
                	make();
                }
                op.pop();
                continue;
            }
            while (op.size() > 0 && get(op.top()) >= get(s[i]))
            {    
            	make();
            }
            op.emplace(s[i]);
        }
        else
        {
            int x = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {    
            	x = 10 * x + (s[i] - '0'); 
            	++i;
            }
            --i;
            st.emplace(x);
        }
    }
    while (op.size() > 0)
    {    
    	make();
    }
	
	std::cout << st.top();
    return 0;
}