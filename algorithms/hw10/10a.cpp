#include <bits/stdc++.h>
#include <cassert>

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
inline void operator delete ( void * ) noexcept { }
/** End fast allocation */

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) noexcept { assert(0); }


std::vector<std::vector<int>> g;
std::vector<char> used;
int n, s, t;

int main() 
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> n >> s >> t;
	--s, --t;
	std::queue<int, std::list<int>> q; 
	q.push(s);
	
	used.resize(n, 0);
	g.resize(n);
	for (int i = 0; i < n; ++i)
	{
		g[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			std::cin >> g[i][j];
		}
	}

	used[s] = 1;
	std::vector<int> d(n, 0), p(n);
	p[s] = -1;
	
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < n; ++i)
		{
			if (!g[v][i])
			{
				continue;
			}
			else
			{
				auto to = i;
				if (!used[to])
				{
					used[to] = 1;
					q.push(to);
					d[to] = d[v] + 1;
					p[to] = v;
				}
			}
		}
	}
	std::cout << (used[t] ? d[t] : 0);
	
	return 0;
}