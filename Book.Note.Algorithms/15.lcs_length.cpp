/* *
 *    Author:   Akasaka
 *    FileName: 15.lcs_length.cpp
 *    Created:  2020.04.01(UTC+0800) 23.49.42(星期三)
 * */

#include <bits/stdc++.h>

using namespace std;

namespace lcs_test
{
    const int _max = 16;
    int b[_max][_max];
    int c[_max][_max];

    void lcs_length(string X, string Y)
    {
        int m = X.length();
        int n = Y.length();
        for(int i = 1; i <= m; i++)
            c[i][0] = 0;
        for(int j = 0; j <= n; j++)
            c[0][j] = 0;

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                if(X[i - 1] == Y[j - 1])
                {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = 0;
                }
                else if(c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 1;
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 2;
                }
            }
    }

    void print_lcs(const string& X, int i, int j)
    {
        if(i == 0 || j == 0) 
            return;
        if(b[i][j] == 0)
        {
            print_lcs(X, i - 1, j - 1);
            printf("%c", X[i - 1]);
        }
        else if(b[i][j] == 1)
            print_lcs(X, i - 1, j);
        else print_lcs(X, i, j - 1);
    }

    void solve()
    {
        char X[] = "ABCBDAB";
        char Y[] = "BDCABA";
        int m = strlen(X);
        int n = strlen(Y);
        lcs_length(X, Y);
        print_lcs(X, m, n);
        printf(":len=%d", c[m][n]);
    }
}

int main()
{
    lcs_test::solve();
    return 0;
}
