/* *
 *    Author:   Akasaka
 *    FileName: D.cpp
 *    Created:  2019.10.17(UTCCST) 10.42.51(星期四)
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

const int _max = 3e5 + 10;

int n;
char s[_max];

int main()
{
    scanf("%d%s", &n, s);

    long long ans = 0;
    int pre = 0;
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && s[i] != s[i - 1])
        {
            ans += i - pre;
            pre = i;
        }
        else if(i > 0 && pre > 0)
            ans++;
    }

    printf("%I64d\n", 1LL * n * (n - 1) / 2 - ans);
    return 0;
}
