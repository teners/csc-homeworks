#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ui = unsigned int;

const ui n = (1ll << 24);
const long long M = (1ll << 32);
int m, q, a, b;
ui cur = 0, x[n], ans;

ui nextRand()
{
    cur = cur * a + b;
    return cur >> 8;
}

void makeFirst()
{
    unsigned int add = nextRand();
    unsigned int l = nextRand();
    unsigned int r = nextRand();
    if (l > r) 
    {
        swap(l, r);
    }
    x[l] += add;
    if (r + 1 < n)
    {
        x[r + 1] -= add;
    }
}

void makeSecond()
{
    unsigned int l = nextRand();
    unsigned int r = nextRand();
    if (l > r)
    {
        swap(l, r);
    }
    ans += (x[r] - (l ? x[l - 1] : 0));
}

int main()
{
    cin >> m >> q >> a >> b;
    while (m--)
    {
        makeFirst();
    }
    ui y = 0;
    for (int i = 0; i < n; ++i)
    {
        y += x[i];
        x[i] = y + (i ? x[i - 1] : 0);
    }
    while (q--)
    {
        makeSecond();
    }
    cout << ans << endl;
    return 0;
}
