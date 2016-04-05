#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;
using ui = unsigned;

const int MAX = 1000100;
ui cur = 0, t[MAX], _t[MAX], a, b;
int n, m;
long long cnt;

ui nextRand24()
{
    cur = cur * a + b;
    return cur >> 8;
}

void go(int tl, int tr)
{
    if (tl == tr)
    {
        return;
    }
    int tm = (tl + tr) / 2;
    go(tl, tm); 
    go(tm + 1, tr);
    int sz = 0;
    int l = tl;
    int r = tm + 1;
    while (l <= tm || r <= tr)
    {
        if (r <= tr && (l == tm + 1 || (t[r] < t[l])))
        {
            cnt += (tm + 1 - l); 
            _t[sz++] = t[r++];
        }
        else
        {
            _t[sz++] = t[l++];
        }
    }
    for (int i = 0; i < sz; ++i)
    {
        t[tl + i] = _t[i];
    }
}

int main()
{
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; ++i)
    {
        t[i] = nextRand24() % m;
    }
    go(0, n - 1);
    cout << cnt << endl;
    return 0;
}
