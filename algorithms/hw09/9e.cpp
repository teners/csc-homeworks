#include <bits/stdc++.h>

std::vector<int> d;
std::vector<std::vector<int>> g;
std::set<std::pair<int, std::pair<std::string, int>>> b;
std::vector<std::string> f;

int main()
{
	int n;
	scanf("%d\n", &n);
	f.resize(n);
	g.resize(n);
	d.assign(n, 0);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> f[i];
        while (true)
        {
            char c;
            int x;
            scanf("%c", &c);
            if (c == ' ')
            {
                scanf("%d", &x);
                g[x].push_back(i);
                ++d[i];
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        b.insert(make_pair(d[i], make_pair(f[i], i)));
    }
    while (b.size())
    {
        int v = b.begin()->second.second;
        std::cout << f[v] << "\n";
        b.erase(b.begin());
        for (int i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            b.erase(make_pair(d[to], make_pair(f[to], to)));
            --d[to];
            b.insert(make_pair(d[to], make_pair(f[to], to)));
        }
    }
	return 0;
}
