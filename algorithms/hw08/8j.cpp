#include <bits/stdc++.h>

std::vector <std::vector <int>> g, gr;
std::vector <int> used, ord;
std::vector <std::pair <int, int>> e, res;
int n, m, a, b, s;

void dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i)
    {
        if (used[g[v][i]] == 0)
        {
            dfs(g[v][i]);
        }
    }
    ord.push_back(v);
    return;
}

void dfs2(int v)
{
    used[v] = s;
    for (int i = 0; i < gr[v].size(); ++i)
    {
        if (used[gr[v][i]] == 0)
        {
            dfs2(gr[v][i]);
        }
    }
    return;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin >> n >> m;
    g.resize(n);
    gr.resize(n);
    used.assign(n, 0);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b;
        if (a != b)
        {
            --a, --b;
            g[a].push_back(b);
            gr[b].push_back(a);
            e.push_back(std::make_pair(a, b));
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (used[i] == 0)
        {
            dfs(i);
        }
    }
    used.clear();
    used.assign(n, 0);
    s = 0;
    for (int i = ord.size() - 1; i >= 0; --i)
    {
        if (used[ord[i]] == 0)
        {
            ++s;
            dfs2(ord[i]);
        }
    }
    for (int i = 0; i < e.size(); ++i)
    {
        a = used[e[i].first];
        b = used[e[i].second];
        if (a != b)
            res.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
    }
    sort(res.begin(), res.end());
    std::cout << unique(res.begin(), res.end()) - res.begin();
    return 0;
}
