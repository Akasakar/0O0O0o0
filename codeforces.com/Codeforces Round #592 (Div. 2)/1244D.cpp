/* *
 *    Author:   Akasaka
 *    FileName: 1244D.cpp
 *    Created:  2019.11.10(UTC+0800) 09.46.00(星期日)
 * */
 
#ifdef AKASAKA
 
#define IN  "./in.in"
#define OUT "./out.out"
#define CLOSE   "CON"   ///close in/out
#define DebugIN(x)  freopen(x, "r", stdin)
#define DebugOUT(x) freopen(x, "w", stdout)
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)
#define TimeStart   clock_t TIME_START = clock()
#define TimeEnd printf("%ld/%ld\n", clock() - TIME_START, CLOCKS_PER_SEC)
 
#elif EX_STACK
__asm__("movel%0, %%esp\n" :: "r"((char*)malloc(256 << 20) + (256 << 20)));  // GCC
#pragma comment(linker, "/STACK:102400000,102400000")  //Clang
#else
 
#define IN
#define OUT
#define STOP
#define DebugIN(x)
#define DebugOUT(x)
#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
 
#endif // AKASAKA
 
 
#include <bits/stdc++.h>
 
using namespace std;
 
const int _max = 1e5 + 10;
 
vector<int> g[_max];
int c[4][_max];
int d[6][_max];
int cnt;
 
long long dfs(int u, int pa)
{
    long long ret = c[d[cnt][u]][u];
    for(int i = 0; i < g[u].size(); i++)
    {
        int& v = g[u][i];
        if(v == pa) continue;
        d[cnt][v] = 3 - d[cnt][u] - d[cnt][pa];
        ret += dfs(v, u);
    }
    return ret;
}
 
int main()
{
    int n;
    scanf("%d", &n);
    for(int k = 0; k < 3; k++)
        for(int i = 0; i < n; i++)
            scanf("%d", c[k] + i);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for(int i = 0; i < n; i++)
        if(g[i].size() > 2)
        {
            puts("-1");
            return 0;
        }
 
    int pos = 0;
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            if(i == j) continue;
            d[cnt][0] = i;
            d[cnt][g[0][0]] = j;
            long long tmp = dfs(g[0][0], 0) + dfs(0, g[0][0]);
            if(tmp < ans)
            {
                ans = tmp;
                pos = cnt;
            }
            cnt++;
        }
 
    printf("%I64d\n%d", ans, d[pos][0] + 1);
    for(int i = 1; i < n; i++)
        printf(" %d", d[pos][i] + 1);
    putchar(10);
    return 0;
}
