/* *
 *    Author:   Akasaka
 *    FileName: 1335C.cpp
 *    Created:  2020.04.15(UTC+0800) 00.20.26(星期三)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace C
{
    const int _max = 2e5 + 10;
    int cnt[_max];

    void solve()
    {
        int t;
        scanf("%d", &t);
        while(t--)
        {
            int n;
            scanf("%d", &n);

            memset(cnt, 0, sizeof(cnt));
            set<int> s;
            int ans = 0;
            int a;
            for(int i = 0; i < n; i++)
            {
                scanf("%d", &a);
                s.insert(a);
                cnt[a]++;
                ans = max(ans, cnt[a]);
            }
            if(ans == s.size()) ans = s.size() - 1;
            else if(ans > s.size()) ans = s.size();
            printf("%d\n", ans);
        }
    }
}

int main()
{
    C::solve();
    return 0;
}
