/* *
 *    Author:   Akasaka
 *    FileName: 1335E2.cpp
 *    Created:  2020.04.15(UTC+0800) 11.15.40(星期三)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace E2
{
    const int _max = 2e5 + 10;
    const int _sigma = 200 + 10;
    int n;
    int pre[_sigma][_max];

    void solve()
    {
        int t;
        scanf("%d", &t);
        while(t--)
        {
            vector<int> pos[_sigma];

            scanf("%d", &n);
            int a;
            for(int i = 0; i < n; i++)
            {
                scanf("%d", &a);
                for(int x = 1; x < _sigma; x++)
                    pre[x][i + 1] = pre[x][i];
                pre[a][i + 1]++;
                pos[a].push_back(i);
            }

            int ans = 0;
            for(int x = 1; x < _sigma; x++)
            {
                vector<int>& px = pos[x];
                int xsize = px.size();
                ans = max(ans, xsize);
                for(int i = 0; i + i < xsize; i++)
                {
                    int l = px[i] + 1;
                    int r = px[xsize - 1 - i] - 1;
                    if(l > r) continue;
                    for(int k = 1; k < _sigma; k++)
                        ans = max(ans, (i + 1) * 2 + pre[k][r + 1] - pre[k][l]);
                }
            }
            printf("%d\n", ans);
        }
    }
}

int main()
{
    E2::solve();
    return 0;
}
