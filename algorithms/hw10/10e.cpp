#include <bits/stdc++.h>

const int N = int(1e6);
int to[N], next[N], cur[N], dist[N], prev[N], q[N], w[N], res[N];
int n, m, s, sres;
std::set <std::pair <int, int>> t;

void add(int a, int b, int c)
{
	to[s] = b;
	next[s] = cur[a];
	w[s] = c;
	cur[a] = s++;
}

void bfs(int start)
{
	std::fill(dist, dist + n, -1);
	dist[start] = 0;
	prev[start] = -1;
	t.insert(std::make_pair(0, start));
	while (t.size())
	{
		int v = (*t.begin()).second;
		t.erase(*t.begin());
		for (int i = cur[v]; i != -1; i = next[i])
		{
			if (dist[to[i]] == -1 || dist[to[i]] > dist[v] + w[i])
			{
			    t.erase(std::make_pair(dist[to[i]], to[i]));
				dist[to[i]] = dist[v] + w[i];
				prev[to[i]] = v;
				t.insert(std::make_pair(dist[to[i]], to[i]));
			}
		}
	}
}

int main()
{

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n >> m;

	std::fill(cur, cur + n, -1);

	for (int i = 0; i < n; ++i)
    {
        std::cin >> q[i];
    }

	for (int i = 0; i < m; ++i)
	{
	    int a, b, c;
		std::cin >> a >> b;
		--a, --b;
		c = (q[a] == q[b] ? 0 : 1);
		add(a, b, c);
		add(b, a, c);
	}

    bfs(0);

	if (dist[n - 1] == -1)
    {
        std::cout << "impossible";
    }
    else
    {
        for (int i = n - 1; i != -1; i = prev[i])
        {
            res[sres++] = i;
        }

        std::cout << dist[n - 1] << " " << sres << std::endl;

        for (int i = sres - 1; i >= 0; --i)
        {
            std::cout << res[i] + 1 << " ";
        }
    }

	return 0;
}
