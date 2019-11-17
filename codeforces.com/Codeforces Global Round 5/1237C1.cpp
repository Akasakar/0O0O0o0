/* *
 *    Author:   Akasaka
 *    FileName: 1237C1.cpp
 *    Created:  2019.11.16(UTC+0800) 21.28.11(星期六)
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

const int _max = 2000 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3f;

struct Point
{
    int x, y, z;
} p[_max];

long long length2(Point a, Point b)
{
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y) + 1LL * (a.z - b.z) * (a.z - b.z);
}

bool vis[_max];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);

    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        long long dis = inf;
        int pos = i + 1;
        for(int j = i + 1; j < n; j++)
        {
            if(vis[j]) continue;
            if(dis > length2(p[i], p[j]))
            {
                pos = j;
                dis = length2(p[i], p[j]);
            }
        }
        vis[i] = vis[pos] = true;

        printf("%d %d\n", i + 1, pos + 1);
    }
    return 0;
}
