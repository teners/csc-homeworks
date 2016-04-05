#include <bits/stdc++.h>

/** Begin fast allocation */
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) { }
/** End fast allocation */

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }

const int N = int(1e5);
std::vector<int> vts[N];
std::vector<int> dist(N);
std::vector<bool> used(N, false);
int maxdist = 0;

void dfs(int v, int d)
{
	if (d > maxdist)
	{
		maxdist = d;
	}
    if (used[v])
    {
        return;
    }
    used[v] = true;
    dist[v] = d;
    for (auto x: vts[v])
    {
        dfs(x, d+1);
    }
}

int main() 
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	dist[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		int t;
		std::cin >> t;
		--t;
		vts[t].push_back(i);
	}
	dfs(0, 0);
	std::cout << maxdist << "\n";
	int c = 0;
	for (int i = 0 ; i < n; ++i)
	{
		if (dist[i] == maxdist)
		{
			++c;
		}
	}
	std::cout << c << "\n";
	for (int i = 0 ; i < n; ++i)
	{
		if (dist[i] == maxdist)
		{
			std::cout << i + 1 << " ";
		}
	}
	return 0;
}