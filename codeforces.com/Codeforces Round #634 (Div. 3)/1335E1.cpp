/* *
 *    Author:   Akasaka
 *    FileName: 1335E1.cpp
 *    Created:  2020.04.14(UTC+0800) 14.28.39(星期二)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace E1
{
    const int _sigma = 27;
    const int _max = 2010;
    int a[_max];
    int cnt[_sigma][_max];

    int upperbound(int cx[_max], int n, int x)
    {
        int l = 0, r = n;
        while(l < r)
        {
            int m = (l + r) / 2;
            if(cx[m] < x) r = m;
            else l = m + 1;
        }
        return l;
    }

    void solve()
    {
        int t, n;
        scanf("%d", &t);
        while(t--)
        {
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
                scanf("%d", a + i);

            memset(cnt, 0, sizeof(cnt));
            int ans = 0;
            for(int x = 1; x < _sigma; x++)
            {
                for(int i = n - 1; i >= 0; i--)
                {
                    cnt[x][i] = cnt[x][i + 1];
                    if(a[i] == x) cnt[x][i]++;
                }
                ans = max(ans, cnt[x][0]);
            }

            for(int k = 0;k < n; k++)
            {
                int x = a[k];
                int lx = cnt[x][k];
                int tl = lx;
                if(tl & 1) tl--;
                int t2 = lx / 2;
                int t1 = lx + 1 - t2;
                while(tl >= 2 && t1 <= lx && t2 >= 1)
                {
                    int i = upperbound(cnt[x], n, t1);
                    int j = upperbound(cnt[x], n, t2);
                    if(i >= j) continue;
                    for(int y = 1; y < _sigma; y++)
                    {
                        if(y == x) continue;
                        int tmp = cnt[y][i] - cnt[y][j];
                        ans = max(ans, tmp + tl);
                    }
                    tl -= 2;
                    t1++;
                    t2--;
                }
            }
            printf("%d\n", ans);
        }
    }
}

int main()
{
    E1::solve();
    return 0;
}
