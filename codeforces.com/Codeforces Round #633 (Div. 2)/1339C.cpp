/* *
 *    Author:   Akasaka
 *    FileName: 1339C.cpp
 *    Created:  2020.04.12(UTC+0800) 22.50.50(星期日)
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

namespace B
{
    const int _max = 1e5 + 10;
    long long a[_max];

    void solve()
    {
        int t;
        scanf("%d", &t);
        int n;
        while(t--)
        {
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
                scanf("%lld", a + i);
            int d = 0;
            int p = 0;
            int i = 0;
            while(p < n && i < n)
            {
                while(p + 1 < n && a[p] <= a[p + 1]) p++;
                i = p + 1;
                while(i < n && a[p] >= a[i])
                {
                    int tmp = a[p] - a[i];
                    if(d < tmp) d = tmp;
                    i++;
                }
                p = i;
            }
            int x = 0;
            while(d)
            {
                d >>= 1;
                x++;
            }
            printf("%d\n", x);
        }
    }
}

int main()
{
    B::solve();
    return 0;
}
