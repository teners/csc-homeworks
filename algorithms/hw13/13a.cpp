#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

long long t[4000100], n, k, l, r;
char c;

long long sum (int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v << 1, tl, tm, l, min(r,tm))
		+ sum ((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update (int v, int tl, int tr, int pos, int new_val)
{
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v << 1, tl, tm, pos, new_val);
		else
			update ((v << 1) + 1, tm + 1, tr, pos, new_val);
		t[v] = t[v << 1] + t[(v << 1) + 1];
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; ++i)
    {
        cin >> c >> l >> r;
        --l, --r;
        if (c == 'A')
        {
            ++r;
            update(1, 0, n - 1, l, r);
        }
        else
            cout << sum(1, 0, n - 1, l, r) << endl;
    }
	return 0;
}
