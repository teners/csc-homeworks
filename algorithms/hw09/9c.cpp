#include <bits/stdc++.h>

const int N = 100001;
std::vector<int> used(N, 0);
std::vector<std::vector<int>> res;
int t, tin[N], fup[N], c, rem[2 * N], to[2 * N], next[2 * N];
int sz, curr[N], prev[N];

void dfs(int v, int p = -1)
{
	used[v] = c;
	tin[v] = fup[v] = ++t;
	for (int i = curr[v]; i != -1; i = next[i])
    {
        if (to[i] != p)
        {
        	if (used[to[i]] != c)
        	{
        		dfs(to[i], v);
        		fup[v] = std::min(fup[v], fup[to[i]]);
        		if (fup[to[i]] > tin[v])
        		{
        			rem[i] = rem[i ^ 1] = true;
        		}
        	}
        	else
        	{
        		fup[v] = std::min(fup[v], tin[to[i]]);
        	}
        }
    }
}

void dfs2(int v)
{
    res[c - 1].push_back(v + 1);
    used[v] = c;
    for (int i = curr[v]; i != -1; i = next[i])
    {
        if (used[to[i]] != c && rem[i] == false)
        {
            dfs2(to[i]);
        }
    }

}

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n, m;
	res.resize(N);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
    {
        curr[i] = -1;
    }
	for (int i = 0; i < m; ++i)
	{
		int s, t;
		std::cin >> s >> t;
		--s, --t;
		to[sz] = t;
		next[sz] = curr[s];
		curr[s] = sz++;
		to[sz] = s;
		next[sz] = curr[t];
		curr[t] = sz++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
		    ++c;
			dfs(i);
		}
	}
	for (int i = 0; i < n; ++i)
    {
        used[i] = 0;
    }
    c = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            ++c;
            dfs2(i);
            sort(res[c - 1].begin(), res[c - 1].end());
        }
    }
	std::cout << c << "\n";
	for (int i = 0; i < n; ++i)
    {
        if (!prev[used[i] - 1])
        {
            for (int j = 0; j < res[used[i] - 1].size(); ++j)
            {
                std::cout << res[used[i] - 1][j] << " ";
            }
            std::cout << "\n";
            prev[used[i] - 1] = true;
        }
    }
	return 0;
}
