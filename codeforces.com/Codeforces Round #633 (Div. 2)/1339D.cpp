/* *
 *    Author:   Akasaka
 *    FileName: 1339D.cpp
 *    Created:  2020.04.14(UTC+0800) 21.24.23(星期二)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace D
{
    const int _max = 1e5 + 10;
    vector<int> g[_max];
    bool vis[_max];
    struct Node
    {
        int id, s;
        Node(int i = 0, int s = 0): id(i), s(s) {}
    };

    void bfs(int n)
    {
        int odd = 0;
        int e = n - 1, l = 1, m = 1;
        int u = 1;
        while(g[u].size() != 1) u++;
        int v = g[u][0];
        vis[u] = vis[v] = 1;
        queue<Node> q;
        for(int i = 0; i < g[v].size(); i++)
        {
            u = g[v][i];
            if(vis[u]) continue;
            vis[u] = 1;
            q.push(Node(u, 2));
        }
        while(!q.empty())
        {
            Node tmp = q.front();
            q.pop();
            u = tmp.id;
            if(g[u].size() == 1)
            {
                if(tmp.s & 1) odd = 1;
                l++;
            }
            bool lp = 0;
            for(int i = 0; i < g[u].size(); i++)
            {
                v = g[u][i];
                if(vis[v]) continue;
                vis[v] = 1;
                if(g[v].size() == 1) lp = 1;
                q.push(Node(v, tmp.s + 1));
            }
            m += lp;
        }
        printf("%d %d\n", 1 + odd + odd, e - l + m);
    }

    void solve()
    {
        int n;
        scanf("%d", &n);
        int a, b;
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bfs(n);
    }
}

int main()
{
    D::solve();
    return 0;
}
