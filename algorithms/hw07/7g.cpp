/*#include <iostream>
#include <stack>

int main()
{
    std::string s;
    std::stack<char> st;
    std::cin >> s;
    int l = 0, r = 0, x = -1, y = -1;
    auto clear = [&st](){while (!st.empty()) st.pop();};
    for (auto j = 0; j < s.size(); ++j)
    {
        auto i = s[j];
        if (i == '(' || i == '[' || i == '{')
        {
            st.emplace(i);
            ++r;
        }
        else
        if (i == ')' && !st.empty() && st.top() == '(')
        {
            st.pop();
            ++r;
        }
        else
        if (i == ']' && !st.empty() && st.top() == '[')
        {
            st.pop();
            ++r;
        }
        else
        if (i == '}' && !st.empty() && st.top() == '{')
        {
            st.pop();
            ++r;
        }
        else
        {
            //l += st.size();
            //r -= st.size();
            if (y - x < r - l)
            {
                y = r;
                x = l;
            }
            clear();
            l = r = j + 1;
        }
    }
    l += st.size();
    if (y - x < r - l)
    {
        y = r;
        x = l;
    }
    if (x == y)
        std::cout << "";
    else
        std::cout << s.substr(x, y);
    return 0;
}
*/

#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int k, x;
    std::cin >> k;
    std::string s;
    std::cin >> s;
    x = s.size();
    std::stack<char, std::vector<char>> st;
    st.emplace(s[0]);
    for (int i = 1, j = 1; i < x; ++i)
    {
        if (st.size() + x - i == k)
        {
            x = st.size();
            std::vector<char> v(x);
            for (int i = x - 1; i >= 0; --i)
            {
                v[i] = st.top();
                st.pop();
            }
            for (auto i : v)
            {
                std::cout << i;
            }
            std::cout << s.substr(i, s.size() - 1);
            return 0;
        }
        if (st.top() < s[i])
        {
            while (st.size() && st.top() < s[i] && st.size() + x - i > k)
            {
                st.pop();
                --j;
            }
            st.emplace(s[i]);
            ++j;
        }
        else if (j < k)
        {
            st.emplace(s[i]);
            ++j;
        }
    }
    x = st.size();
    std::vector<char> v(x);
    for (int i = x - 1; i >= 0; --i)
    {
        v[i] = st.top();
        st.pop();
    }
    for (auto i : v)
        std::cout << i;
}