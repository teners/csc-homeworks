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
//std::vector<char> used;
int n; //, s, t;

int main() 
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n;
	
	g.resize(n);
	for (int i = 0; i < n; ++i)
	{
		g[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			std::cin >> g[i][j];
		}
	}

	for (int k = 0; k < n; ++k)
	{
		auto tmp = g[k];
		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				g[i][j] = std::min(g[i][j], g[i][k] + tmp[j]);
			}
		}
	}
	
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << g[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	return 0;
}