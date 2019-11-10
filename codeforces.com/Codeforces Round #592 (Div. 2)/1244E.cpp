/* *
 *    Author:   Akasaka
 *    FileName: 1244E.cpp
 *    Created:  2019.11.10(UTC+0800) 12.56.41(星期日)
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

const int _max = 1e5 + 10;

int a[_max];

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    sort(a, a + n);
    long long mi = a[0], ma = a[n - 1];
    for(int i = 1; i < n; i++)
    {
        if(mi >= ma || k == 0) break;
        long long t1 = 1LL * i * (a[i] - a[i - 1]);
        long long t2 = 1LL * i * (a[n - i] - a[n - i - 1]);
        if(t1 <= k) 
        {
            mi = a[i];
            k -= t1;
        }
        else 
        {
            mi += k / i;
            k = 0;
        }
        if(t2 <= k)
        {
            ma = a[n - i - 1];
            k -= t2;
        }
        else 
        {
            ma -= k / i;
            k = 0;
        }

    }
    cout << max(0LL ma - mi) << endl;
    return 0;
}
