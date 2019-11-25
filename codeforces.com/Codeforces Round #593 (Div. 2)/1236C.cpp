/* *
 *    Author:   Akasaka
 *    FileName: 1236C.cpp
 *    Created:  2019.11.25(UTC+0800) 15.17.18(星期一)
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

const int _max = 310;

int a[_max][_max];

int main()
{
    int n;
    scanf("%d", &n);
    int idx = 1;
    for(int j = 0; j < n; j++)
    {
        if(j & 1) for(int i = n - 1; i >= 0; i--) a[i][j] = idx++;
        else for(int i = 0; i < n; i++) a[i][j] = idx++;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d", a[i][0]);
        for(int j = 1; j < n; j++)
            printf(" %d", a[i][j]);
        putchar(10);
    }
    return 0;
}
