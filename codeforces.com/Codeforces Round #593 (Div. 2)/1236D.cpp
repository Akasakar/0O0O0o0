/* *
 *    Author:   Akasaka
 *    FileName: 1236D.cpp
 *    Created:  2019.11.25(UTC+0800) 17.27.27(星期一)
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

const int _max = 1e5 + 10;

vector<int> px[_max], py[_max];

int main()
{
    int n, m, k;
    int x, y;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++)
    {
        scanf("%d%d", &x, &y);
        px[x].push_back(y);
        py[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        px[i].push_back(0);
        px[i].push_back(m + 1);
        sort(px[i].begin(), px[i].end());
    }
    for(int i = 1; i <= m; i++)
    {
        py[i].push_back(0);
        py[i].push_back(n + 1);
        sort(py[i].begin(), py[i].end());
    }

    long long cnt = 1;
    x = y = 1;
    int xl = 0, xr = n + 1, yl = 0, yr = m + 1;
    for(int d = 1; d != 5;)
    {
        if(d == 1)
        {
            int ty = *lower_bound(px[x].begin(), px[x].end(), y);
            ty = min(ty, yr) - 1;
            xl = x;
            if(y < ty)
            {
                cnt += ty - y;
                y = ty;
            }
            int tx = *lower_bound(py[y].begin(), py[y].end(), x);
            tx = min(tx, xr) - 1;
            if(x >= tx) break;
            d = 2;
        }
        else if(d == 2)
        {
            int tx = *lower_bound(py[y].begin(), py[y].end(), x);
            tx = min(tx, xr) - 1;
            yr = y;
            if(x < tx)
            {
                cnt += tx - x;
                x = tx;
            }
            int ty = *(upper_bound(px[x].begin(), px[x].end(), y) - 1);
            ty = max(ty, yl) + 1;
            if(y <= ty) break;
            d = 3;
        }
        else if(d == 3)
        {
            int ty = *(upper_bound(px[x].begin(), px[x].end(), y) - 1);
            ty = max(ty, yl) + 1;
            xr = x;
            if(y > ty)
            {
                cnt += y - ty;
                y = ty;
            }
            int tx = *(upper_bound(py[y].begin(), py[y].end(), x) - 1);
            tx = max(tx, xl) + 1;
            if(x <= tx) break;
            d = 4;
        }
        else if(d == 4)
        {
            int tx = *(upper_bound(py[y].begin(), py[y].end(), x) - 1);
            tx = max(tx, xl) + 1;
            yl = y;
            if(x > tx)
            {
                cnt += x - tx;
                x = tx;
            }
            int ty = *lower_bound(px[x].begin(), px[x].end(), y);
            ty = min(ty, yr) - 1;
            if(y >= ty) break;
            d = 1;
        }
    }
    printf("%s\n", 1LL * n * m == cnt + k ? "Yes" : "No");
    return 0;
}
