#include <bits/stdc++.h>

const int N = int(1e6);
int to[N], next[N], cur[N], dist[N], prev[N];
int n, m, s, start, st, en;

void add(int a, int b)
{
	to[s] = b;
	next[s] = cur[a];
	cur[a] = s++;
}

void bfs()
{
	std::fill(dist, dist + n, -1);
	prev[en++] = start;
	dist[start] = 0;
	while (st < en)
	{
		int v = prev[st++];
		for (int i = cur[v]; i != -1; i = next[i])
		{
			if (dist[to[i]] == -1)
			{
				dist[to[i]] = dist[v] + 1;
				prev[en++] = to[i];
			}
		}
	}
}

int main()
{

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n >> start >> m;
	--start;

	std::fill(cur, cur + n, -1);

	for (int i = 0; i < m; ++i)
	{
	    int a, b;
		std::cin >> a >> b;
		add(b - 1, a - 1);
	}

    bfs();

    for (int i = 0; i < n; ++i)
	{
		std::cout << dist[i] << " ";
	}

	return 0;
}
