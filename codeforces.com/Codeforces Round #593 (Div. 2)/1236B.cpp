/* *
 *    Author:   Akasaka
 *    FileName: 1236B.cpp
 *    Created:  2019.11.25(UTC+0800) 10.28.39(星期一)
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

const int mod = 1e9 + 7;

int qpow(int x, int k)
{
    int ret = 1;
    while(k)
    {
        if(k & 1) ret = 1LL * ret * x % mod;
        x = 1LL * x * x % mod;
        k >>= 1;
    }
    return ret;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", qpow((qpow(2, m) - 1), n));
    return 0;
}
