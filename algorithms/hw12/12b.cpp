#include <bits/stdc++.h>
using namespace std;

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
    ios_base::sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	vector<int> qu(q * 3);
	for (int i = 0; i < q; ++i)
	{
		string t;
		int x, y;
		cin >> t >> x >> y;
		qu[i * 3 + 0] = (t[0] == 'a' ? 0 : 1);
		qu[i * 3 + 1] = x - 1;
		qu[i * 3 + 2] = y - 1;
	}
	DSU dsu(n);
	vector<string> ans;
	for (int i = q - 1; i >= 0; --i)
	{
		if (qu[i * 3] == 0)
		{
			ans.push_back(dsu.check(qu[i * 3 + 1], qu[i * 3 + 2]) ? string("YES\n") : string("NO\n"));
		}
		else
		{
			dsu.join(qu[i * 3 + 1], qu[i * 3 + 2]);
		}
	}
	for (auto i = ans.rbegin(); i != ans.rend(); ++i)
		cout << *i;
	return 0;
}
