/* *
 *    Author:   Akasaka
 *    FileName: 1237D.cpp
 *    Created:  2019.11.20(UTC+0800) 21.57.41(星期三)
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

const int _max = 3e5 + 10;

int mono[_max];
int a[_max];

int main()
{
    int n;
    scanf("%d", &n);

    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        a[i + n + n] = a[i + n] = a[i];
        mx = max(mx, a[i]);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(a[i] << 1 < mx) cnt++;
    if(cnt)
    {
        memset(mono, -1, sizeof(mono));
        int front = 0, tail = 1;
        for(int i = 0; i < n; i++)
        {
            if(mono[front] < i) front++;
            if(front == tail) mono[tail++] = i;
            for(int j = mono[tail - 1] + 1; j < 3 * n; j++)
            {
                if(a[j] << 1 < a[mono[front]])
                {
                    printf("%d ", j - i);
                    break;
                }
                else
                {
                    while(tail > front && a[mono[tail - 1]] < a[j]) tail--;
                    mono[tail++] = j;
                }
            }
        }
    }
    else for(int i = 0; i < n; i++) printf("-1 ");
    return 0;
}
