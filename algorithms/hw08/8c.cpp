#include <bits/stdc++.h>

inline int readInt();
template <class T> inline void writeInt(T x);
const int N = int(1e6);
bool marked[N];
std::vector<int> vts[N];
const int MAX_MEM = int(1e8);
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new (size_t n);
inline void operator delete (void *) noexcept;
inline void * operator new[] (size_t);
inline void operator delete[] (void *) noexcept;
void dfs(int v)
{
    if (marked[v])
    {
        return;
    }
    marked[v] = true;
    for (auto x: vts[v])
    {
        dfs(x);
    }
}

int main()
{
    int cc = 0;
    int n, m;
    n = readInt();
    m = readInt();
    for (size_t i = 0; i < m; ++i)
    {
        int x = readInt() - 1;
        int y = readInt() - 1;
        vts[x].push_back(y);
        vts[y].push_back(x);
    }
    for (size_t i = 0; i < n; ++i)
    {
        if (!marked[i])
        {
            ++cc;
            if (cc > 1)
            {
                break;
            }
            dfs(i);
        }
    }
    std::cout << (cc == 1 ? "YES" : "NO");
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