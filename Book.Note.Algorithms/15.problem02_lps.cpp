/* *
 *    Author:   Akasaka
 *    FileName: 15.promble02_lps.cpp
 *    Created:  2020.04.07(UTC+0800) 16.49.48(星期二)
 * */

#ifdef AKASAKA
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)
#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

namespace test
{
    const int _max = 32;
    int dp[_max][_max];
    
    void lps(string s)
    {
        int n = s.length();
        for(int l = 1; l <= n; l++)
            for(int i = 1; i + l - 1 <= n; i++)
            {
                int j = i + l - 1;
                if(i == j) dp[i][j] = 1;
                else if(s[i - 1] == s[j - 1]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
    }

    void print_lps(const string& s, int i, int j)
    {
        if(i > j) return;
        if(i == j) putchar(s[i - 1]);
        else if(s[i - 1] == s[j - 1])
        {
            putchar(s[i - 1]);
            print_lps(s, i + 1, j - 1);
            putchar(s[j - 1]);
        }
        else if(dp[i][j] == dp[i + 1][j])
            print_lps(s, i + 1, j);
        else print_lps(s, i, j - 1);
    }

    void solve()
    {
        string s = "character";
        lps(s);
        printf("%d\n", dp[1][s.length()]);
        print_lps(s, 1, s.length());
    }
}

int main()
{
    test::solve();
    return 0;
}
