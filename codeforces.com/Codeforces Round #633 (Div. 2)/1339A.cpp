/* *
 *    Author:   Akasaka
 *    FileName: 1339A.cpp
 *    Created:  2020.04.12(UTC+0800) 21.58.55(星期日)
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
#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

#elif EX_STACK
__asm__("movel%0, %%esp\n" :: "r"((char*)malloc(256 << 20) + (256 << 20)));  // GCC
#pragma comment(linker, "/STACK:102400000,102400000")  //Clang

#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

namespace A
{
    void solve()
    {
        int t;
        scanf("%d", &t);
        int n;
        while(t--)
        {
            scanf("%d", &n);
            printf("%d\n", n);
        }
    }
}

int main()
{
    A::solve();
    return 0;
}
