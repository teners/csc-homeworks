#include <bits/stdc++.h>

const int N = int(1e6);
int to[N], next[N], cur[N], dist[N], prev[N], w[N];
int n, m, s, sres, fst, snd;
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
	std::cin >> fst >> snd;
	--fst, --snd;

	std::fill(cur, cur + n, -1);

	for (int i = 0; i < m; ++i)
	{
	    int a, b, c;
		std::cin >> a >> b >> c;
		--a, --b;
		add(a, b, c);
		add(b, a, c);
	}

    bfs(fst);

    std::cout << dist[snd];

	return 0;
}
