/* *
 *    Author:   Akasaka
 *    FileName: 15.matrix_chain_order.cpp
 *    Created:  2020.03.31(UTC+0800) 21.25.10(星期二)
 * */

#include <bits/stdc++.h>

using namespace std;

namespace matrix_chain
{
    const int inf = 0x3f3f3f3f;
    const int _max = 16;
    int n = 6;
    int p[_max] = {30, 35, 15, 5, 10, 20, 25};
    int m[_max][_max];
    int s[_max][_max];

    void matrix_chain_order()
    {
        for(int l = 2; l <= n; l++)
            for(int i = 1; i <= n - l + 1; i++)
            {
                int j = i + l - 1;
                m[i][j] = inf;
                for(int k = i; k < j; k++)
                {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if(q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
    }

    void print_optimal_parens(int i, int j)
    {
        if(i == j) printf("A[%d]", i);
        else
        {
            printf("(");
            print_optimal_parens(i, s[i][j]);
            print_optimal_parens(s[i][j] + 1, j);
            printf(")");
        }
    }

    void print_optimal_parens()
    {
        printf("%d:", m[1][n]);
        print_optimal_parens(1, n);
    }
}

int main()
{
    matrix_chain::matrix_chain_order();
    matrix_chain::print_optimal_parens();
    return 0;
}
