/* *
 *    Author:   Akasaka
 *    FileName: A.cpp
 *    Created:  2019.10.10(UTCCST) 10.34.44(星期四)
 * */

#define Akasaka

#ifdef Akasaka

#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

#define DebugIN(x)  freopen(x, "r", stdin)
#define DebugOUT(x) freopen(x, "w", stdout)
#define IN  "./in.in"
#define OUT "./out.out"
#define CLOSE   "CON"   ///close in/out
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)

#include <ctime>
#define TimeStart   clock_t TIME_START = clock()
#define TimeEnd printf("%ld/%ld",clock() - TIME_START,CLOCKS_PER_SEC)

#else

#pragma comment(linker, "/STACK:102400000,102400000")
#define DebugIN(x)
#define DebugOUT(x)
#define IN
#define OUT
#define STOP

#endif // Akasaka


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    long long x, y;
    while(t--)
    {
        scanf("%I64d%I64d", &x, &y);
        if(x - y > 1) puts("YES");
        else puts("NO");
    }
    return 0;
}
