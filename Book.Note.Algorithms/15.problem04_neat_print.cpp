/* *
 *    Author:   Akasaka
 *    FileName: 15.problem04_neat_print.cpp
 *    Created:  2020.04.08(UTC+0800) 14.29.29(星期三)
 * */

#ifdef AKASAKA
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)
#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

/* *
 * dp[i] 表示前i个单词的最小代价
 * cost[i][j] 表示第i-j个单词在一行时产生的代价，-1表示超出一行
 * dp[i] = min{dp[k] + cost[k + 1][i]} (1 <= k < i)
 * */

namespace test
{
    const int _max = 32;
    const int inf = 0x3f3f3f3f;
    int dp[_max];
    int cost[_max][_max];

    void neat_print(int M, vector<int>& s)
    {
        M++;
        int n = s.size();
        vector<int> pre(n + 1);
        for(int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + s[i] + 1;
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++)
            {
                int c = max(-1, M - (pre[j] - pre[i - 1]));
                cost[i][j] = c * c * c;
            }

        for(int i = 1; i < n; i++)
        {
            dp[i] = inf;
            for(int k = 0; k < i; k++)
                if(cost[k + 1][i] >= 0)
                    dp[i] = min(dp[i], dp[k] + cost[k + 1][i]);
        }

        dp[n] = inf;
        for(int k = 0; k < n; k++)
            if(cost[k + 1][n] >= 0)
                dp[n] = min(dp[n], dp[k]);
    }

    void print_neat(vector<int>& s, int n)
    {
        static bool ok = 1;
        if(n <= 0) return;
        if(ok)
        {
            ok = 0;
            int k = n - 1;
            for(; k >= 0; k--)
                if(dp[n] == dp[k])
                    break;
            print_neat(s, k);
            for(; k < n; k++)
                printf("%d ", s[k]);
            putchar(10);
            return;
        }
        int k = n - 1;
        for(; k >= 0; k--)
            if(cost[k + 1][n] >= 0 && dp[n] == dp[k] + cost[k + 1][n])
            {
                print_neat(s, k);
                break;
            }
        for(; k < n; k++)
            printf("%d ", s[k]);
        putchar(10);
    }

    void solve()
    {
        int M = 8;
        //vector<int> s({3, 3, 2, 4, 2, 5, 5, 1, 3, 2});
        vector<int> s({4, 3, 2, 6, 4, 2, 3, 6});
        neat_print(M, s);
        printf("%d\n", dp[s.size()]);
        print_neat(s, s.size());
    }
}

int main()
{
    test::solve();
    return 0;
}
