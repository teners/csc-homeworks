#include <bits/stdc++.h>

const int MAXN = 1000;
const int MAXM = 200000;

int to[MAXM], next[MAXM], current[MAXN], used[MAXN];
int n, m, count, tcount, a, b, size;
char c;

int dfs(int v)
{
    int ans = 1;
    used[v] = tcount;
    for (int i = current[v]; i != -1; i = next[i])
    {
        if (used[to[i]] != tcount)
        {
            ans += dfs(to[i]);
        }
    }
    return ans;
}

void add(int a, int b)
{
    to[size] = b;
    next[size] = current[a];
    current[a] = size++;
}

void del(int a, int b)
{
    if (to[current[a]] == b)
    {
        current[a] = next[current[a]];
    }
    else
    {
        int i;
        for (i = current[a]; i != -1; i = next[i])
        {
            if (to[next[i]] == b)
            {
                break;
            }
        }
        if (i != -1)
        {
            next[i] = next[next[i]];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        current[i] = -1;
    }
    while (m--)
    {
        std::cin >> c >> a >> b;
        if (c == 'F')
        {
            add(a - 1, b - 1);
            if (a != b)
            {
                add(b - 1, a - 1);
            }
            ++count;
        }
        else
        {
            del(a - 1, b - 1);
            if (a != b)
            {
                del(b - 1, a - 1);
            }
            --count;
        }
        if (count == n - 1)
        {
            ++tcount;
            if (dfs(0) == n)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}