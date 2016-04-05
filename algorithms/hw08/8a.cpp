#include <map>
#include <iostream>
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
inline void operator delete ( void * ) { }
/** End fast allocation */

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }

inline int readInt() {
  int s = 0, c = getchar(), x = 0;
  if (c == '-')
    s = 1, c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return s ? -x : x;
}

template <class T> 
inline void writeInt( T x ) {
  if (x < 0)
    putchar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    putchar(s[n]);
  putchar(' ');
}

int main()
{
	std::map<int, int> mp;
	int n, m;
	n = readInt();
	m = readInt();
	for (int i = 0; i < m; i++)
	{
		int t;
		t = readInt();
		mp[t]++;
		t = readInt();
		mp[t]++;
	}
	for (int i = 1; i <= n; i++)
	{
		writeInt(mp[i]);
	}
	return 0;
}