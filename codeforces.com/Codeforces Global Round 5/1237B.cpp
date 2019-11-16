/* *
 *    Author:   Akasaka
 *    FileName: 1237B.cpp
 *    Created:  2019.11.16(UTC+0800) 20.09.48(星期六)
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

const int _max = 1e5 + 10;

int a[_max], b[_max];

int main()
{
    int n, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        a[x] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        b[a[x]] = i;
    }

    int pos = 0, ans = 0;
    for(int i = 1; i <= n; i++)
        if(b[i] > pos)
        {
            ans += b[i] - pos - 1;
            pos = b[i];
        }

    printf("%d\n", ans);
    return 0;
}
