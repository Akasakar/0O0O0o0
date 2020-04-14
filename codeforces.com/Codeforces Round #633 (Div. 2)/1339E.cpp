/* *
 *    Author:   Akasaka
 *    FileName: 1339E.cpp
 *    Created:  2020.04.12(UTC+0800) 23.56.53(星期日)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace E
{
    int f[3][4] = {
        {0, 3, 1, 2},
        {0, 1, 2, 3},
        {0, 2, 3, 1}
    };

    long long tbp(long long x, int k)
    {
        long long ans = 0, p = 1;
        while(x)
        {
            ans += f[k][x % 4] * p;
            x >>= 2;
            p <<= 2;
        }
        return ans;
    }

    void solve()
    {
        int t;
        scanf("%d", &t);
        long long n;
        while(t--)
        {
            scanf("%lld", &n);
            long long x = 1;
            while(x <= (n >> 2)) x <<= 2;
            x = x + (n - x) / 3;
            printf("%lld\n", tbp(x, n % 3));
        }
    }
}

int main()
{
    E::solve();
    return 0;
}
