/* *
 *    Author:   Akasaka
 *    FileName: 15.lis_length.cpp
 *    Created:  2020.04.06(UTC+0800) 01.31.36(星期一)
 * */

#ifdef AKASAKA
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)
#endif // AKASAKA

#include <bits/stdc++.h>

using namespace std;

namespace test
{
    const int _max = 16;
    int a[_max] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    // O(n^2)
    void lis_length_15_4_5(int n)
    {
        vector<int> dp(_max);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
                if(a[i] > a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    // O(nlog_n)
    void lis_length_15_4_6(int n)
    {
        if(n == 0) return;
        vector<int> dp;
        dp.push_back(a[0]); //维护一个尾元素候选序列
        for(int i = 1; i < n; i++)
        {
            if(a[i] > dp.back()) dp.push_back(a[i]);
            else *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }
        for(int i = 0; i < dp.size(); i++)
            printf("%d ", dp[i]);
    }

    void solve()
    {
        lis_length_15_4_5(16);
        lis_length_15_4_6(16);
    }
}

int main()
{
    test::solve();
    return 0;
}
