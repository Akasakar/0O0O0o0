/* *
 *    Author:   Akasaka
 *    FileName: 1335F.cpp
 *    Created:  2020.04.15(UTC+0800) 13.17.52(星期三)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace F
{
    int n, m, lognm;
    vector<string> c, s;
    vector<vector<int> > used, nxt;
    
    void getnxt(int x, int y, int& nx, int& ny)
    {
        if(s[x][y] == 'U') nx = x - 1, ny = y;
        if(s[x][y] == 'R') nx = x, ny = y + 1;
        if(s[x][y] == 'D') nx = x + 1, ny = y;
        if(s[x][y] == 'L') nx = x, ny = y - 1;
    }

    void dfs(int x, int y)
    {
        used[x][y] = 1;
        int nx = -1, ny = -1;
        getnxt(x, y, nx, ny);
        int v = x * m + y;
        int to = nx * m + ny;
        if(!used[nx][ny]) dfs(nx, ny);
        nxt[v][0] = to;
    }

    void solve()
    {
        int t;
        scanf("%d", &t);
        while(t--)
        {
            scanf("%d%d", &n, &m);
            lognm = 0;
            int nm = n * m;
            while((1 << lognm) <= nm) lognm++;
            c = s = vector<string>(n);
            for(auto& it : c) cin >> it;
            for(auto& it : s) cin >> it;

            used = vector<vector<int> >(n, vector<int>(m));
            nxt = vector<vector<int> >(n * m, vector<int>(lognm));
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(!used[i][j]) dfs(i, j);

            for(int deg = 1; deg < lognm; deg++)
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++)
                    {
                        int id = i * m + j;
                        nxt[id][deg] = nxt[nxt[id][deg - 1]][deg - 1];
                    }

            vector<vector<int> > black, white;
            black = white = vector<vector<int> >(n, vector<int>(m));
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                {
                    int v = i * m + j;
                    int to = v;
                    for(int deg = lognm - 1; deg >= 0; deg--)
                        if((nm >> deg) & 1) to = nxt[to][deg];
                    if(c[i][j] == '0') black[to / m][to % m]++;
                    else white[to / m][to % m]++;
                }
            
            int all = 0, good = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                {
                    if(black[i][j])
                    {
                        all++;
                        good++;
                    }
                    else if(white[i][j]) all++;
                }

            printf("%d %d\n", all, good);
        }
    }
}

int main()
{
    F::solve();
    return 0;
}
