#include <bits/stdc++.h>

std::vector <std::vector <int>> g;
std::vector <int> used;
int n, m, a, b, s;

void dfs(int v)
{
    used[v] = s;
    for (int i = 0; i < g[v].size(); ++i)
    {
        if (used[g[v][i]] == 0)
        {
            dfs(g[v][i]);
        }
    }
    return;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> n >> m;
    g.resize(n);
    used.assign(n, 0);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i)
    {
        if (used[i] == 0)
        {
            ++s;
            dfs(i);
        }
    }
    std::cout << s << "\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << used[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
