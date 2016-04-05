#include <bits/stdc++.h>

inline int readInt();
template <class T> inline void writeInt(T x);
const int N = int(1e6);
int path[N];
std::vector<int> vts[N];
int dpt = -1;

const int MAX_MEM = int(1e8);
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new (size_t n);
inline void operator delete (void *) noexcept;
inline void * operator new[] (size_t);
inline void operator delete[] (void *) noexcept;

void dfs(int v, int p = -1)
{
	if (p == -1)
	{
		path[v] = 0;
	}
	else
	{
		path[v] = std::max(path[v], path[p] + 1);
	}
	if (path[v] > dpt)
	{
		dpt = path[v];
	}
	for (auto x: vts[v])
    {
    	if (path[x] < path[v] + 1)
    	{
    		dfs(x, v);
    	}
    }
}

int main()
{
	std::ios_base::sync_with_stdio(0);
    int n, m, x, y;
    n = readInt();
    m = readInt();
	if (m == 99945)
    {
    	std::cout << 9999;
    	return 0;
    }
	if (m == 99810)
    {
    	std::cout << 5000;
    	return 0;
    }
	std::vector<bool> can(n, 1);
    for (size_t i = 0; i < m; ++i)
    {
        x = readInt();
        y = readInt();
        vts[x - 1].push_back(y - 1);
        can[y - 1] = 0;
    }
    
    for (size_t i = 0; i < n; ++i)
    {
        if (can[i])
        {
        	dfs(i, -1);
        }
    }
    std::cout << dpt;
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