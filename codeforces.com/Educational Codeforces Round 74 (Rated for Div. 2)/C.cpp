/* *
 *    Author:   Akasaka
 *    FileName: C.cpp
 *    Created:  2019.10.15(UTCCST) 09.57.26(星期二)
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

const int _max = 2e5 + 10;

int q;
int h, n;
int p[_max], dp[_max];

int main()
{
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &h, &n);
        for(int i = 0; i < n; i++)
            scanf("%d", p + i);
        
        memset(dp, 0, sizeof(dp));
        if(p[1] != 1) dp[1] = 1;
        for(int i = 2; i < n; i++)
        {
            if(p[i] + 1 == p[i - 1]) dp[i] = min(dp[i - 1] + 1, dp[i - 2]);
            else dp[i] = dp[i - 1] + 1;
            if(p[i] == 1)
            {
                dp[i] = dp[i - 1];
                if(p[i - 1] == 2)
                    dp[i] = min(dp[i - 1], dp[i - 2]);
            }
        }

        printf("%d\n", dp[n - 1]);
    }
    return 0;
}
