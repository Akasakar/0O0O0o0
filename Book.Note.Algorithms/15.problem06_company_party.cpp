/* *
 *    Author:   Akasaka
 *    FileName: 15.problem06_company_party.cpp
 *    Created:  2020.04.08(UTC+0800) 21.43.55(星期三)
 * */

#ifdef AKASAKA
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)
#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

/*
Sample Input:
5
2 3 5 4 4
0 2 2 3
2 1 1
1 1 4
3 0
4 0

6
20 3 5 4 5 30
0 2 2 3
2 1 1
3 1 4
1 0
4 1 5
5 0

Sample Output:
13
53
*/

namespace test
{
    const int _max = 16;
    int n;
    int a[_max];
    vector<int> g[_max];
    int d[_max][2];
    
    int dp(int u, bool st)
    {
        int& ans = d[u][st];
        if(ans) return ans;
        if(st)
        {
            for(int i = 0; i < g[u].size(); i++)
                ans += dp(g[u][i], false);
            ans += a[u];
        }
        else 
        {
            for(int i = 0; i < g[u].size(); i++)
                ans += max(dp(g[u][i], false), dp(g[u][i], true));
        }
        return ans;
    }

    void solve()
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", a + i);
        for(int i = 0; i < n; i++)
        {
            int u, vi, x;
            scanf("%d%d", &u, &vi);
            for(int k = 0; k < vi; k++)
            {
                scanf("%d", &x);
                g[u].push_back(x);
            }
        }
        printf("%d\n", max(dp(0, 0), dp(0, 1)));
    }
}

int main()
{
    test::solve();
    return 0;
}
