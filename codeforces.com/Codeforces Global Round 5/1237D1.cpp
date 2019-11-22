/* *
 *    Author:   Akasaka
 *    FileName: 1237D1.cpp
 *    Created:  2019.11.22(UTC+0800) 10.22.57(星期五)
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

int a[_max], c[_max];

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
    memset(c, -1, sizeof(c));
    if(cnt)
    {
        deque<int> dq;
        for(int i = 0; i < n; i++)
        {
            if(!dq.empty() && dq.front() < i) dq.pop_front();
            if(dq.empty()) dq.push_back(i);
            for(int j = dq.back() + 1; j < 3 * n; j++)
            {
                if(a[j] << 1 < a[dq.front()])
                {
                    c[i] = j - i;
                    break;
                }
                while(!dq.empty() && a[dq.back()] < a[j]) dq.pop_back();
                dq.push_back(j);
            }
        }
    }

    printf("%d", c[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", c[i]);
    return 0;
}
