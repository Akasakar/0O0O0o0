/* *
 *    Author:   Akasaka
 *    FileName: 1237E.cpp
 *    Created:  2019.11.22(UTC+0800) 20.27.07(星期五)
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

bool isBBST(int x)
{
    int l = x / 2, r = (x - 1) / 2;
    if(x == 1 || x == 2) return true;
    if(l % 2 && r % 2) return false;
    else return isBBST(l) && isBBST(r);
}

int main()
{
    int n;
    scanf("%d", &n);
    int cur = 1, ans = 0;
    while(cur <= n)
    {
        if(cur == n || cur + 1 == n) ans++;
        if(cur & 1) cur = 1 + cur + (cur + 1);
        else cur = 1 + cur + cur;
    }
    printf("%d\n", ans);
    return 0;
}
