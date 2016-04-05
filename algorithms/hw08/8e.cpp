#include <bits/stdc++.h>

/** Begin fast allocation */
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new (size_t n)
{
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *)res;
}
inline void operator delete (void *) {}
inline void * operator new[] (size_t) { assert(0); }
inline void operator delete[] (void *) { assert(0); }
/** End fast allocation */

template <class T>
inline void writeInt(T x);
inline int readInt();

const int N = int(1e3) + 1;
bool g[N][N];

int main()
{
    int n = readInt();
    int m = readInt();
    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        int x = readInt() - 1;
        int y = readInt() - 1;
        g[x][y] = g[y][x] = true;
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
        {
            if (!g[i][j])
            {
                continue;
            }
            for (size_t k = j + 1; k < n; ++k)
            {
                if (g[i][k] && g[j][k])
                {
                    ++count;
                }
            }
        }
    }
    std::cout << count;
    return 0;
}

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