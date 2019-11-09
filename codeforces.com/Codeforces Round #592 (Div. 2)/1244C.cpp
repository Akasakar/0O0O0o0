/* *
 *    Author:   Akasaka
 *    FileName: 1244C.cpp
 *    Created:  2019.11.09(UTC+0800) 22.12.22(星期六)
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

int main()
{
    long long n, p;
    int w, d;
    cin >> n >> p >> w >> d;
    
    long long x, y;
    x = p / w;
    for(y = 0; y < w; y++)
        if((y * d - p % w) % w == 0)
        {
            x -= (y * d - p % w) / w;
            break;
        }
    if(x >= 0 && y < w && x + y <= n)
        cout << x << ' ' << y << ' ' << n - x - y << endl;
    else cout << "-1" << endl;
    return 0;
}
