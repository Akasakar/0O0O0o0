/* *
 *    Author:   Akasaka
 *    FileName: 1238F1.cpp
 *    Created:  2019.11.07(UTC+0800) 09.25.37(星期四)
 * */

#ifdef AKASAKA

#define DebugIN(x)  freopen(x, "r", stdin)
#define DebugOUT(x) freopen(x, "w", stdout)
#define IN  "./in.in"
#define OUT "./out.out"
#define CLOSE   "CON"   ///close in/out
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)

#include <time.h>
#define TimeStart   clock_t TIME_START = clock()
#define TimeEnd printf("%ld/%ld\n", clock() - TIME_START, CLOCKS_PER_SEC)

#else

#pragma comment(linker, "/STACK:102400000,102400000")
#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define DebugIN(x)
#define DebugOUT(x)
#define IN
#define OUT
#define STOP

#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

const int _max = 3e5 + 10;

struct Node
{
    int from, to;
    Node(int f = 0, int t = 0): from(f), to(t) {}
} edge[_max << 1];

int head[_max];
int d[_max];
int ans;

void addEdge(int x, int y, int id)
{
    edge[id] = Node(head[x], y);
    head[x] = id;
}

int dfs(int u, int pa)
{
    int max1 = 0, max2 = 0;
    for(int i = head[u]; i; i = edge[i].from)
    {
        int& v = edge[i].to;
        if(v == pa) continue;
        max2 = max(max2, dfs(v, u) + d[v]);
        if(max2 >= max1) swap(max1, max2);
        ans = max(ans, max1 + max2 + d[u]);
    }
    return max1;
}

int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int n;
        scanf("%d", &n);

        for(int i = 1; i <= n; i++)
        {
            d[i] = -1;
            head[i] = 0;
        }
        
        int cnt = 1;
        for(int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addEdge(x, y, cnt++);
            addEdge(y, x, cnt++);
            d[x]++;
            d[y]++;
        }

        ans = -1;
        dfs(1, 0);
        printf("%d\n", ans + 2);
    }
    return 0;
}
