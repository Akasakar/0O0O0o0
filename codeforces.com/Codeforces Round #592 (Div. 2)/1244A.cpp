/* *
 *    Author:   Akasaka
 *    FileName: 1244A.cpp
 *    Created:  2019.11.07(UTC+0800) 16.36.25(星期四)
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


#include <cstdio>

using namespace std;

int div(int a, int b)
{
    return (a + b - 1) / b;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int x, y;
        x = div(a, c);
        y = div(b, d);
        if(x + y > k) puts("-1");
        else printf("%d %d\n", x, y);
    }
    return 0;
}
