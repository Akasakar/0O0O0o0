/* *
 *    Author:   Akasaka
 *    FileName: 1237C2.cpp
 *    Created:  2019.11.17(UTC+0800) 20.30.30(星期日)
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

#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define DebugOUT(x)
#define DebugIN(x)
#define STOP
#define OUT
#define IN

#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

const int _max = 5e4 + 10;

struct Point
{
    int x, y, z;
    bool operator < (const Point& rhs) const
    {
        if(x != rhs.x) return x < rhs.x;
        else if(y != rhs.y) return y < rhs.y;
        else return z < rhs.z;
    }
};

pair<Point, int> pid[_max];
bool vis[_max];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &pid[i].first.x, &pid[i].first.y, &pid[i].first.z);
        pid[i].second = i + 1;
    }

    sort(pid, pid + n);
    int pos = -1;
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        if(pos >= 0 && pid[i].first.x == pid[pos].first.x && pid[i].first.y == pid[pos].first.y)
        {
            vis[i] = vis[pos] = 1;
            printf("%d %d\n", pid[i].second, pid[pos].second);
            pos = -1;
        }
        else pos = i;
    }
    pos = -1;
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        if(pos >= 0 && pid[i].first.x == pid[pos].first.x)
        {
            vis[i] = vis[pos] = 1;
            printf("%d %d\n", pid[i].second, pid[pos].second);
            pos = -1;
        }
        else pos = i;
    }
    pos = -1;
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        if(pos >= 0)
        {
            vis[i] = vis[pos] = 1;
            printf("%d %d\n", pid[i].second, pid[pos].second);
            pos = -1;
        }
        else pos = i;
    }
    return 0;
}
