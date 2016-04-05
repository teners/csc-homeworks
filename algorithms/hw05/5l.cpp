#include <bits/stdc++.h>
using namespace std;

/** Fast I/O */
inline int readChar();
inline int readInt();
template <class T> inline void writeInt( T x );
inline int readChar() {
  int c = getchar();
  while (c <= 32)
    c = getchar();
  return c;
}
inline int readInt() {
  int s = 0, c = getchar(), x = 0;
  if (c == '-')
    s = 1, c = getchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return s ? -x : x;
}
template <class T> inline void writeInt( T x ) {
  if (x < 0)
    putchar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    putchar(s[n]);
}
/** End fast I/O */

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

int main() 
{
	int n, m;
	m = readInt();
	n = readInt();
	while (n != 0 || m != 0) 
	{
        if (n == 0 || m == 0) 
        {
            printf("0\n");
            m = readInt();
            n = readInt();
            continue;
        }
		int base[n][m];
		bool used[n][m][n + m];
		int func[n][m][n + m];
        stack<char> st;
		for (int i = 0; i < n; ++i)	
		{
			for (int j = 0; j < m; ++j) 
			{
				base[i][j] = readInt();
				used[i][j][0] = false;
				func[i][j][0] = -10001;
				for (int k = 1; k < n + m; ++k) 
				{
                    func[i][j][k] = 10000;
                    used[i][j][k] = false;
				}
			}
		}

        int max_k = 0;
        int q[3 * n * m * (n + m)];
        int head = 0, tail = 0;
        int x = 0, y = 0, k = 0;
        q[tail] = x;
        ++tail;
        q[tail] = y;
        ++tail;
        q[tail] = k;
        ++tail;

		while (head != tail) 
		{
            x = q[head];
            ++head;
            y = q[head];
            ++head;
            k = q[head];
            ++head;
			if (base[x][y] > func[x][y][k]) 
			{
                if (func[x][y][k + 1] > base[x][y]) 
                {
                    func[x][y][k + 1] = base[x][y];
                }
                max_k = max(max_k, k + 1);
                if (!used[x][y][k + 1]) 
                {
                    used[x][y][k + 1] = true;
                    q[tail] = x;
                    ++tail;
                    q[tail] = y;
                    ++tail;
                    q[tail] = k + 1;
                    ++tail;
                }
			}
			if (x + 1 < n) 
			{
                if (func[x + 1][y][k] >= func[x][y][k]) 
                {
                    func[x + 1][y][k] = func[x][y][k];
                }
                if (!used[x + 1][y][k]) 
                {
                    used[x + 1][y][k] = true;
                    q[tail] = x + 1;
                    ++tail;
                    q[tail] = y;
                    ++tail;
                    q[tail] = k;
                    ++tail;
                }
			}
			if (y + 1 < m) 
			{
                if (func[x][y + 1][k] >= func[x][y][k]) 
                {
                    func[x][y + 1][k] = func[x][y][k];
                }
                if (!used[x][y + 1][k]) 
                {
                    used[x][y + 1][k] = true;
                    q[tail] = x;
                    ++tail;
                    q[tail] = y + 1;
                    ++tail;
                    q[tail] = k;
                    ++tail;
                }
			}
		}

		writeInt(max_k);
		printf("\n");
        int i = n - 1, j = m - 1;
        k = max_k;

        while (i > 0 || j > 0) 
        {
            if (k == 0) 
            {
                while (i) 
                {
                    st.push('D');
                    --i;
                }
                while (j) 
                {
                    st.push('R');
                    --j;
                }
                continue;
            }

            if (func[i][j][k] == base[i][j]) 
            {
                st.push('T');
                --k;
            } 
            else 
            {
                if (i > 0 && func[i][j][k] == func[i - 1][j][k]) 
                {
                    st.push('D');
                    --i;
                } 
                else 
                {
                    st.push('R');
                    --j;
                }
            }
        }

        if (func[i][j][k] == base[i][j])
        {    
        	st.push('T');
        }
        
        while (st.size()) 
        {
            putchar(st.top());
            st.pop();
        }

		printf("\n\n");
		m = readInt();
		n = readInt();
	}
	return 0;
}
