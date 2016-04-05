#include <bits/stdc++.h>

const int N = int(1e6);
int to[N], next[N], cur[N], dist[N], prev[N];
int n, m, s, start, e, sum;

void add(int a, int b)
{
	to[s] = b;
	next[s] = cur[a];
	cur[a] = s++;
}

void bfs(int s)
{
	start = 0;
	e = 0;
	std::fill(dist, dist + n, -1);
	prev[e++] = s;
	dist[s] = 0;
	while (start < e)
	{
		int v = prev[start++];
		for (int i = cur[v]; i != -1; i = next[i])
		{
			if (dist[to[i]] == -1)
			{
				dist[to[i]] = dist[v] + 1;
				prev[e++] = to[i];
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (dist[i] >= 0)
		{
			sum += dist[i];
		}
	}
}

int main()
{

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> n >> m;

	std::fill(cur, cur + n, -1);
	for (int i = 0; i < m; ++i)
	{
	    int a, b;
		std::cin >> a >> b;
		add(a - 1, b - 1);
		add(b - 1, a - 1);
	}

	for (int i = 0; i < n; ++i)
	{
		bfs(i);
	}

	std::cout << sum / 2;

	return 0;
}
