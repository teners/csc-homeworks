#include <bits/stdc++.h>
using namespace std;

const int N = 200; 

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
	int n, a, b;
	scanf("%d", &n);
	int x[N], y[N];
	vector<pair<int, pair<int, int>>> dist;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			dist.push_back(make_pair(((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), make_pair(i, j)));
		}
	}
	sort(dist.begin(), dist.end());
	DSU dsu(n);
	vector<pair<double, pair<int, int>>> tree(n - 1);
	double sum = 0.0;
	for (int i = 0; i < n - 1; ++i)
	{
		int f, s, it = -1;
		do 
		{
			++it;
			f = dist[it].second.first;
			s = dist[it].second.second;
		}
		while (dsu.check(f, s));
		
		dsu.join(f, s);
		tree[i] = make_pair(sqrt(dist[it].first), make_pair(f, s));
		sum += tree[i].first;
	}
	printf("%f\n%d\n", sum, n-1);
	for (int i = 0; i < n - 1; ++i)
	{
		printf("%d %d\n", tree[i].second.first + 1, tree[i].second.second + 1);
	}
	return 0;
}