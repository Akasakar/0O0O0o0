/* *
 *    Author:   Akasaka
 *    FileName: 1244G.cpp
 *    Created:  2019.11.11(UTC+0800) 14.40.42(星期一)
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

const int _max = 1e6 + 10;

int a[_max], b[_max];

void reorder(int s, int n, int p)
{
    for(int i = n - 1; i >= 0; i--)
        b[i + s] = a[(i- p + n) % n + s];
    for(int i = n - 1; i >= 0; i--)
        a[i + s] = b[i + s];
}

int main()
{
    int n;
    long long k, sum = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        a[i] = n - i;
        sum += a[i];
    }
    k -= sum;
    if(k >= 0)
    {
        for(int p = 0; p < n; p++)
        {
            int tmp = n - p - p - 1;
            if(k < tmp || tmp < 0)
            {
                reorder(0, n, p);
                if(tmp > 0)
                {
                    reorder(p, k + p + 1, 1);
                    sum += k;
                }
                break;
            }
            k-= tmp;
            sum += tmp;
        }
        printf("%I64d\n", sum);
        for(int i = 0; i < n - 1; i++)
            printf("%d ", n - i);
        printf("1\n");
        for(int i = 0; i < n - 1; i++)
            printf("%d ", a[i]);
        printf("%d\n", a[n - 1]);
    }
    else puts("-1");
    return 0;
}
