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

const int N = 1001;
const int go[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int W, H, ay, ax, by, bx;
int q[2 * N * N][2], qs, qe;
int g[N][N], p[N][N][2], mark[N][N];
std::string s;
std::vector<std::pair<int, int>> ans;

bool bfs() 
{
    p[ax][ay][0] = -1;
    p[ax][ay][1] = -1;
    q[qe][0] 	 = ax;
    q[qe++][1] 	 = ay;
    mark[ax][ay] = 1;
    
    while (qs < qe) 
    {
        int x = q[qs][0];
        int y = q[qs++][1];
        for (int i = 0; i < 4; ++i) 
        {
            int tx = x + go[i][0];
            int ty = y + go[i][1];
            if (tx >= 0 && tx < H && ty >= 0 && ty < W && !mark[tx][ty] && !g[tx][ty]) 
            {
                mark[tx][ty] = 1;
                p[tx][ty][0] = x;
                p[tx][ty][1] = y;
                q[qe][0] 	 = tx;
                q[qe++][1] 	 = ty;
            }
        }
    }
    return mark[bx][by] != 0;
}

int main() {
    scanf("%d %d %d %d %d %d\n", &W, &H, &ay, &ax, &by, &bx);
    for (int i = 0; i < H; ++i) 
    {
        getline(std::cin, s);
        for (int j = 0; j < W; ++j)
            if (s[j] == '*')
                g[i][j] = 1;
    }
    --ax, --ay, --bx, --by;
    if (bfs() == false)
        std::cout << "NO";
    else {
        std::cout << "YES\n";
        for (int i = bx, j = by; i >= 0 && j >= 0;) {
            ans.push_back(std::make_pair(j + 1, i + 1));
            int ti = p[i][j][0];
            int tj = p[i][j][1];
            i = ti;
            j = tj;
        }
    }
    for (int i = ans.size() - 1; i >= 0; --i)
    {
        printf("%d %d ", ans[i].first, ans[i].second);
    }
    return 0;
}