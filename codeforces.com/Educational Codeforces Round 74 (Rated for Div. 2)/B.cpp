/* *
 *    Author:   Akasaka
 *    FileName: B.cpp
 *    Created:  2019.10.10(UTCCST) 11.09.45(星期四)
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

const int _max = 1e5 + 10;

int q;
int n, r;
int x[_max];

int main()
{
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &n, &r);
        for(int i = 0; i < n; i++)
            scanf("%d", x + i);
        sort(x, x + n);
        n = unique(x, x + n) - x;

        int ans = 0, i = 0;
        while(i < n)
        {
            ans++;
            n--;
            while(i < n && x[i] <= ans * r) i++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
