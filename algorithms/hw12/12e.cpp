#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5);

class DSU
{
public:
    vector<int> parent;
    DSU(int n): parent(n)
    {
    	for(int i=0; i<n; i++)
		{
			parent[i] = i;
		}
    }
    inline void join(int a, int b)
    {
    	parent[get(b)] = get(a);
    }
    inline int get(int a)
    {
    	return a == parent[a] ? a : parent[a] = get(parent[a]);
    }
    inline bool check(int a, int b)
    {
    	return get(a) == get(b);
    }
};

int main()
{
	int n, m, a, b, w;
	scanf("%d%d", &n, &m);
	vector <pair <int, pair <int, int>>> v(m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &w);
		v[i] = make_pair(w, make_pair(a - 1, b - 1));
	}
	sort(v.begin(), v.end());
	DSU dsu(n);
	long long sum = 0;
	int lim = n - 1;
	for (int i = 0; i < m; ++i)
	{
	    if (lim == 0)
                break;
		auto p = v[i].second;
		if (!dsu.check(p.first, p.second))
		{
			sum += v[i].first;
			dsu.join(p.first, p.second);
			--lim;

		}
	}
	printf("%lld", sum);
	return 0;
}
