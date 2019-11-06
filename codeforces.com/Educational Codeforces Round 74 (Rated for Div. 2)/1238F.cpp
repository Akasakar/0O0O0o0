/* *
 *    Author:   Akasaka
 *    FileName: 1238F.cpp
 *    Created:  2019.11.06(UTC+0800) 19.28.12(星期三)
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


#include <iostream>

using namespace std;

const int _max = 3e5 + 10;

struct Node
{
    int from, to;
    Node(int f = 0, int t = 0): from(f), to(t) {}
} edge[_max << 1];

int idx[_max];
int d[_max];
int ans, p;

void addEdge(int a, int b, int i)
{
    edge[i] = Node(idx[a], b);
    idx[a] = i;
}

void dfs(int x, int pa, int dis)
{
    if(dis > ans)
    {
        p = x;
        ans = dis;
    }
    for(int i = idx[x]; i; i = edge[i].from)
    {
        int& y = edge[i].to;
        if(y == pa) continue;
        dfs(y, x, dis + d[y]);
    }
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
            idx[i] = 0;
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
        
        ans = -2;
        p = 0;
        dfs(1, 0, d[1]);
        ans = -2;
        dfs(p, 0, d[p]);
        printf("%d\n", ans + 2);
    }
    return 0;
}
