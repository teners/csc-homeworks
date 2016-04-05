#include <bits/stdc++.h>

/** Begin fast allocation */
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *)res;
}
inline void operator delete ( void * ) { }
inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }
/** End fast allocation */


const int N = 20000;
std::vector<int> vts[N];
std::vector<bool> used(N, false);
int t, tin[N], fup[N];
std::vector<int> cp;

void dfs(int v, int p = -1)
{
    int children = 0;
    used[v] = true;
    tin[v] = fup[v] = t++;
    for (auto x: vts[v])
    {
        if (x == p || x == v)
        {
            continue;
        }
        if (used[x])
        {
            fup[v] = std::min(fup[v], tin[x]);
        }
        else
        {
            dfs(x, v);
            fup[v] = std::min(fup[v], fup[x]);
            if (p != -1 && fup[x] >= tin[v])
            {
                cp.push_back(v + 1);
            }
            ++children;
        }
    }
    if (p == -1 && children > 1)
    {
        cp.push_back(v + 1);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int s, t;
        std::cin >> s >> t;
        if (s == t)
        {
            continue;
        }
        --s, --t;
        vts[s].push_back(t);
        vts[t].push_back(s);
    }
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    std::sort(cp.begin(), cp.end());
    auto size = std::unique(cp.begin(), cp.end()) - cp.begin();
    std::cout << size << "\n";
    for (auto i = 0; i < size; ++i)
    {
        std::cout << cp[i] << "\n";
    }
    return 0;
}