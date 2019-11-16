/* *
 *    Author:   Akasaka
 *    FileName: 1237A.cpp
 *    Created:  2019.11.11(UTC+0800) 19.52.21(星期一)
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

const int _max = 13845 + 10;

int a[_max];

int main()
{
    int n;
    scanf("%d", &n);

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        if(a[i] & 1)
        {
            if(a[i] > 0) cnt1++;
            else if(a[i] < 0) cnt2++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(a[i] & 1)
        {
            if(a[i] > 0 && cnt1 > cnt2)
            {
                cnt1 -= 2;
                a[i] += 1;
            }
            if(a[i] < 0 && cnt2 > cnt1)
            {
                cnt2 -= 2;
                a[i] -= 1;
            }
        }

        printf("%d\n", a[i] / 2);
    }
    return 0;
}
