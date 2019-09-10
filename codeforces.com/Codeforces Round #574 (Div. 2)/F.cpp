/* *
 *    Author:   Akasaka
 *    FileName: F.cpp
 *    Created:  2019.09.10(UTC+0800) 14.10.54(星期二)
 * */

#define Akasaka

#ifdef Akasaka

#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

#define DebugIN(x)  freopen(x, "r", stdin)
#define DebugOUT(x) freopen(x, "w", stdout)
#define IN  "./in.in"
#define OUT "./out.out"
#define CLOSE   "CON"   ///close in/out
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)

#include <ctime>
#define TimeStart   clock_t TIME_START = clock()
#define TimeEnd printf("%ld/%ld",clock() - TIME_START,CLOCKS_PER_SEC)

#else

#pragma comment(linker, "/STACK:102400000,102400000")
#define DebugIN(x)
#define DebugOUT(x)
#define IN
#define OUT
#define STOP

#endif // Akasaka


#include <bits/stdc++.h>

using namespace std;

const int _max = 1e6 + 10;

typedef pair<int, int> Point;
typedef Point Vector;

Point p[_max];
Vector a[_max];
int L[_max], R[_max];
Point b[_max];
vector<int> g[_max];
map<Vector, int> vis;
int ans[_max];
int nk;

Vector reduce(int x, int y)
{
    int g = __gcd(abs(x), abs(y));
    if(g)
    {
        x /= g;
        y /= g;
    }
    return Vector(x, y);
}

int c[_max];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    while(x <= nk)
    {
        c[x] += v;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ret = 0;
    while(x >= 1)
    {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int ki;
        scanf("%d", &ki);
        for(int j = 0; j < ki; j++)
            scanf("%d%d", &p[j].first, &p[j].second);
        L[i] = nk + 1;
        for(int j = 0; j < ki; j++)
            a[++nk] = reduce(p[(j + 1) % ki].first - p[j].first, p[(j + 1) % ki].second - p[j].second);
        R[i] = nk;
    }

    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        b[i].first = L[l];
        b[i].second = R[r];
        g[R[r]].push_back(i);
    }

    for(int i = 1; i <= nk; i++)
    {
        if(vis[a[i]]) add(vis[a[i]], -1);
        vis[a[i]] = i;
        add(i, 1);
        for(int j = 0; j < g[i].size(); j++)
        {
            int k = g[i][j];
            ans[k] = query(b[k].second) - query(b[k].first - 1);
        }
    }

    for(int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);

    return 0;
}
