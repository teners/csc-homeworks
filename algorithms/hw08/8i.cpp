#include <bits/stdc++.h>

inline int readInt();
template <class T> inline void writeInt(T x);
const int N = int(1e6);
int marked[N], cs = -1, ce = -1;
std::vector<int> vts[N];
std::vector<int> p(N, -1);

const int MAX_MEM = int(1e8);
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new (size_t n);
inline void operator delete (void *) noexcept;
inline void * operator new[] (size_t);
inline void operator delete[] (void *) noexcept;

bool dfs(int v)
{
	marked[v] = 1;
    for (auto x: vts[v])
    {
    	if (!marked[x])
    	{
    		p[x] = v;
	        if (dfs(x))
	        {	
	        	return true;
	        }
    	}
    	else
    	if (marked[x] == 1)
    	{
    		ce = v;
    		cs = x;
    		return true;
    	}
    }
    marked[v] = 2;
    return false;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
    	marked[i] = 0;
    }
    for (size_t i = 0; i < m; ++i)
    {
    	int x, y;
        std::cin >> x >> y;
        vts[x - 1].push_back(y - 1);
    }
    for (size_t i = 0; i < n; ++i)
    {
        if (!marked[i] && dfs(i))
        {
        	break;
        }
    }
    
    if (cs == -1)
    {
    	std::cout << "NO";
    }
    else
    {
    	std::vector<int> t;
    	std::cout << "YES\n";
    	for (int i = ce; i != cs; i = p[i])
    	{
    		t.emplace_back(i);
    	}
    	t.emplace_back(cs);
    	for (auto i = t.rbegin(); i != t.rend(); ++i)
    	{
    		std::cout << *i + 1 << " ";
    	}
    }
    return 0;
}

/** Begin fast allocation */
inline void * operator new (size_t n)
{
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *)res;
}
inline void operator delete (void *) noexcept {}
inline void * operator new[] (size_t) { assert(0); }
inline void operator delete[] (void *) noexcept { assert(0); }
/** End fast allocation */

inline int readInt()
{
    int s = 0, c = getchar(), x = 0;
    if (c == '-')
    {
        s = 1;
        c = getchar();
    }
    while ('0' <= c && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return s ? -x : x;
}

template <class T>
inline void writeInt(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    char s[24];
    int n = 0;
    while (x || !n)
    {
        s[n++] = '0' + x % 10;
        x /= 10;
    }
    while (n--)
    {
        putchar(s[n]);
    }
}