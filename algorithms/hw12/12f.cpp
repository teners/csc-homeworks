#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5);

class DSU
{
public:
    vector<int> parent;
    vector<int> anc;
    vector<int> neg;
    DSU(int n): parent(2 * n), anc(2 * n), neg(2 * n)
    {
    	for(int i=0; i<n; i++)
		{
			parent[i] = neg[n + i] = i;
			parent[n + i] = neg[i] = n + i;
			anc[i] = anc[n + i] = 0;
		}
    }
    inline void join(int a, int b)
    {
    	a = get(a);
        b = get(b);
        if (a != b)
        {
            if (anc[a] < anc[b])
                swap(a, b);
            parent[b] = a;
            if (anc[a] == anc[b])
                ++anc[a];
        }
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
	int n, m, a, b, s = 0;
	scanf("%d%d", &n, &m);
	DSU dsu(n);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &a, &b);
		--a, --b;
		if (dsu.check(a, b) || s)
		{
			printf("0");
			s = 1;
		}
		else
		{
		    dsu.join(a, dsu.neg[b]);
		    dsu.join(dsu.neg[a], b);
		    dsu.neg[dsu.parent[b]] = dsu.parent[a];
		    dsu.neg[dsu.parent[a]] = dsu.parent[b];
		    printf("1");
		}
	}
	return 0;
}

