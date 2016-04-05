#include <iostream>
#include <cassert>
#include <map>
#include <vector>

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

int main() {
	int x, n, s = 0;
	std::cin >> n;
	std::map<int, int> N;
	for (auto i = 0; i < n; ++i) {
		std::cin >> x;
		N[x] = 1;
	}
	std::cin >> n;
	for (auto i = 0; i < n; ++i) {
		std::cin >> x;
		if (N[x])
			++s;
	}
	std::cout << s;
	return 0;
}
