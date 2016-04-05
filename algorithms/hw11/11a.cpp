#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5);
int n, m, s, e;
long long d[N];
vector<int> c[N], w[N];

bool relax( long long &a, long long b ) 
{
  if (a <= b) return 0;
  a = b;
  return 1;
}

int main() 
{
	scanf("%d%d%d%d", &n, &m, &s, &e);
	--s, --e;
	for (int i = 0; i < m; ++i)
	{
		int a, b, x;
		scanf("%d%d%d", &a, &b, &x);
		--a, --b;
		c[a].push_back(b);
		w[a].push_back(x);
	}
	long long x = (long long)1e18;
	for (int i = 0; i < n; ++i)
	{
		d[i] = x;
	}
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while(q.size())
	{
		int v = q.front();
		q.pop();
		int size = c[v].size();
		for (int i = 0; i < size; ++i)
		{
			if (relax(d[c[v][i]], d[v] + w[v][i]))
			{
				q.push(c[v][i]);
			}
		}
	}
	printf("%lld ", d[e]);
	return 0;
}