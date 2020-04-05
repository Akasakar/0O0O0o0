/* *
 *    Author:   Akasaka
 *    FileName: 15.lcs_length.cpp
 *    Created:  2020.04.01(UTC+0800) 23.49.42(星期三)
 * */

#include <bits/stdc++.h>

using namespace std;

namespace test
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
                    b[i][j] = 3;
                }
                else if(c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 2;
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 1;
                }
            }
    }

    void print_lcs(const string& X, int i, int j)
    {
        if(i == 0 || j == 0) 
            return;
        if(b[i][j] == 3)
        {
            print_lcs(X, i - 1, j - 1);
            printf("%c", X[i - 1]);
        }
        else if(b[i][j] == 2) print_lcs(X, i - 1, j);
        else print_lcs(X, i, j - 1);
    }

    void print_lcs_01(const string& X, int i, int j)
    {
        if(i == 0 || j == 0) return;
        print_lcs(X, i - (b[i][j] >> 1), j - (b[i][j] & 1));
        if(b[i][j] == 3) printf("%c", X[i - 1]);
    }
    // 15.4-2
    void print_lcs_15_4_2(const string& X, int i, int j)
    {
        if(i == 0 || j == 0)
            return;
        if(c[i][j] == c[i - 1][j - 1] + 1)
        {
            print_lcs_15_4_2(X, i - 1, j - 1);
            printf("%c", X[i - 1]);
        }
        else if(c[i][j] == c[i - 1][j])
            print_lcs_15_4_2(X, i - 1, j);
        else print_lcs_15_4_2(X, i, j - 1);
    }
    // 15.4-3
    int dp(const string& X, const string& Y, int i, int j)
    {
        if(i == 0 || j == 0) return 0;
        int& a = c[i][j];
        if(a != 0) return a;
        if(X[i - 1] == Y[j - 1]) a = dp(X, Y, i - 1, j - 1) + 1;
        else a = max(dp(X, Y, i - 1, j), dp(X, Y, i, j - 1));
        return a;
    }
    // 15.4-4
    void lcs_length_15_4_4(string X, string Y)
    {
        int m = X.length();
        int n = Y.length();
        if(m < n)
        {
            swap(X, Y);
            swap(m, n);
        }
        // 2 * n
        vector<vector<int> > c(2, vector<int>(n + 1));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                if(X[i - 1] == Y[j - 1])
                    c[i & 1][j] = c[i & 1 ^ 1][j - 1] + 1;
                else c[i & 1][j] = max(c[i & 1 ^ 1][j], c[i & 1][j - 1]);
            }
        printf("%d\n", c[m & 1][n]);
        // 1 * n
        vector<int> last(n + 1);    //第i-1行表
        int cur;                    //(i, j)
        for(int i = 1; i <= m; i++)
        {
            int old = 0;            //(i, j - 1)
            for(int j = 1; j <= n; j++)
            {
                if(X[i - 1] == Y[j - 1]) cur = last[j - 1] + 1;
                else cur = max(old, last[j]);
                last[j - 1] = old;  //维护last
                old = cur;          //更新(i, j - 1)
            }
            last[n] = old;
        }
        printf("%d\n", cur);
    }

    void solve()
    {
        char X[] = "ABCBDAB";
        char Y[] = "BDCABA";
        int m = strlen(X);
        int n = strlen(Y);
        //lcs_length(X, Y);
        //print_lcs_15_4_2(X, m, n);
        lcs_length_15_4_4(X, Y);
        printf(":len=%d", c[m][n]);
    }
}

int main()
{
    test::solve();
    return 0;
}
