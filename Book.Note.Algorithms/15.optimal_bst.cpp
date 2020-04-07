/* *
 *    Author:   Akasaka
 *    FileName: 15.optimal_bst.cpp
 *    Created:  2020.04.06(UTC+0800) 22.33.43(星期一)
 * */

#ifdef AKASAKA
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)
#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

namespace test
{
    const int _max = 16;
    const double inf = DBL_MAX;
    double e[_max][_max];
    double w[_max][_max];
    int root[_max][_max];
    
    void optimal_bst(vector<double> p, vector<double> q, int n)
    {
        for(int i = 1; i <= n + 1; i++)
        {
            e[i][i - 1] = q[i - 1];
            w[i][i - 1] = q[i - 1];
        }

        for(int l = 1; l <= n; l++)
            for(int i = 1; i <= n - l + 1; i++)
            {
                int j = i + l - 1;
                e[i][j] = inf;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                for(int r = i; r <= j; r++)
                {
                    double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    if(t < e[i][j])
                    {
                        e[i][j] = t;
                        root[i][j] = r;
                    }
                }
            }
    }
    // 15.5-1
    void construct_optimal_bst(int i, int j, int pa, bool lr)
    {
        static bool first = 1;
        int& r = root[i][j];
        if(first)
        {
            first = 0;
            printf("k_%d is root\n", r);
        }
        else
        { 
            if(r == 0) printf("d_%d ", i - 1);
            else printf("k_%d ", r);

            if(lr == 0) printf("is the left  child of ");
            else printf("is the right child of ");
            printf("k_%d", pa);
            putchar(10);

            if(r == 0) return;
        }
        construct_optimal_bst(i, r - 1, r, 0);
        construct_optimal_bst(r + 1, j, r, 1);
    }

    void solve()
    {
        vector<double> p({0.00, 0.15, 0.10, 0.05, 0.10, 0.20});
        vector<double> q({0.05, 0.10, 0.05, 0.05, 0.05, 0.10});
        optimal_bst(p, q, 5);
        printf("%lf\n", e[1][5]);
        construct_optimal_bst(1, 5, 0, 0);
        // 15.5-2
        p = vector<double>({0.00,0.04, 0.06, 0.08, 0.02, 0.10, 0.12, 0.14});
        q = vector<double>({0.06,0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05});
        optimal_bst(p, q, 7);
        printf("%lf\n", e[1][7]);
        construct_optimal_bst(1, 7, 0, 0);
    }
}

int main()
{
    test::solve();
    return 0;
}
