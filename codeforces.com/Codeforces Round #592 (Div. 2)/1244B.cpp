/* *
 *    Author:   Akasaka
 *    FileName: 1244B.cpp
 *    Created:  2019.11.07(UTC+0800) 17.16.58(星期四)
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


#include <bits/stdc++.h>

using namespace std;

char s[1010];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d%s", &n, s);
        int p1 = n, p2 = -1;
        for(int i = 0; i < n; i++)
            if(s[i] == 49)
            {
                p1 = min(p1, i);
                p2 = max(p2, i);
            }
        printf("%d\n", max(max(n - p1, p2 + 1) << 1, n));
    }
    return 0;
}
