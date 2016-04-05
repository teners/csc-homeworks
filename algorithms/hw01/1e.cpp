#include <iostream>
int main()
{
    std::ios::sync_with_stdio(0);
    int n, m, k;
    std::cin >> n >> m >> k;
    int a[n][m], b[m][k], c[n][k];
    for (int i = 0; i < n; ++i)
    {
        int *temp = a[i];
        for (int j = 0; j < m; ++j)
        {
            std::cin >> temp[j];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int *temp = b[i];
        for (int j = 0; j < k; ++j)
        {
            std::cin >> temp[j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            int *A = a[i];
            register int C = 0;
            for (int l = 0; l < m; ++l)
            {
                C += A[l] * b[l][j];
            }
            c[i][j] = C;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
