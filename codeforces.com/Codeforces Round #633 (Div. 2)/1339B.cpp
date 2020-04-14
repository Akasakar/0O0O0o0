/* *
 *    Author:   Akasaka
 *    FileName: 1339B.cpp
 *    Created:  2020.04.12(UTC+0800) 22.24.45(星期日)
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
#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

#elif EX_STACK
__asm__("movel%0, %%esp\n" :: "r"((char*)malloc(256 << 20) + (256 << 20)));  // GCC
#pragma comment(linker, "/STACK:102400000,102400000")  //Clang

#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

namespace B
{
    const int _max = 1e5 + 10;
    int a[_max];

    void solve()
    {
        int t;
        scanf("%d", &t);
        int n;
        while(t--)
        {
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
                scanf("%d", a + i);
            sort(a, a + n);
            int i = 0;
            int j = n - 1;
            stack<int> s;
            while(i <= j)
            {
                if(i == j) s.push(a[i++]);
                else
                {
                    s.push(a[j--]);
                    s.push(a[i++]);
                }
            }
            printf("%d", s.top());
            s.pop();
            while(!s.empty())
            {
                printf(" %d", s.top());
                s.pop();
            }
            putchar(10);
        }
    }
}

int main()
{
    B::solve();
    return 0;
}
