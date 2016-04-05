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
inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }
/** End fast allocation */


const int N = 20000;
std::vector<std::pair<int, int>> vts[N];	
std::vector<bool> used(N, false);
int t, tin[N], fup[N];
std::vector<int> br;

void dfs(int v, int p = -1)
{
	used[v] = true;
	tin[v] = fup[v] = t++;
    for (auto x: vts[v])
    {
        if (x.first != p)
        {
        	if (!used[x.first])
        	{
        		dfs(x.first, v);
        		fup[v] = std::min(fup[v], fup[x.first]);
        		if (fup[x.first] > tin[v])
        		{
        			br.push_back(x.second);
        		}
        	}
        	else
        	{
        		fup[v] = std::min(fup[v], tin[x.first]);
        	}
        }
    }
}

int main() 
{
	std::ios_base::sync_with_stdio(0);
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int s, t;
		std::cin >> s >> t;
		--s, --t;
		vts[s].push_back(std::make_pair(t, i + 1));
		vts[t].push_back(std::make_pair(s, i + 1));
	}
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			dfs(i);
		}
	}
	std::cout << br.size() << "\n";
	std::sort(br.begin(), br.end());
	for (auto i : br)
	{
		std::cout << i << " ";
	}
	return 0;
}