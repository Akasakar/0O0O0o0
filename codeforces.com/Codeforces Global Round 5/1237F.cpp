/* *
 *    Author:   Akasaka
 *    FileName: 1237F.cpp
 *    Created:  2019.11.23(UTC+0800) 21.15.42(星期六)
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

const int _max = 3610;
const int mod = 998244353;

bool px[_max], py[_max];
int A[_max], C[_max][_max];
int f[_max][_max], g[_max][_max];

void init()
{
    A[0] = 1;
    for(int i = 1; i < _max; i++)
        A[i] = 1LL * A[i - 1] * i % mod;
    for(int i = 0; i < _max; i++)
    {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i -1][j - 1] + C[i - 1][j]) % mod;
    }
}

int main()
{
    init();
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    for(int i = 0; i < n; i++)
    {
        int r[2], c[2];
        scanf("%d%d%d%d", r, c, r + 1, c + 1);
        px[r[0]] = px[r[1]] = true;
        py[c[0]] = py[c[1]] = true;
    }

    int sumx = h, sumy = w;
    for(int i = 1; i <= h; i++) sumx -= px[i];
    for(int j = 1; j <= w; j++) sumy -= py[j];
    for(int i = 0; i <= h; i++) f[i][0] = 1;
    for(int i = 2; i <= h; i++)
    {
        for(int j = 1; j + j <= sumx; j++)
        {
            if(!px[i] && !px[i - 1]) 
                f[i][j] = (f[i - 1][j] + f[i - 2][j - 1]) % mod;
            else f[i][j] = f[i - 1][j];
        }
    }
    for(int i = 0; i <= w; i++) g[i][0] = 1;
    for(int i = 2; i <= w; i++)
    {
        for(int j = 1; j + j <= sumy; j++)
        {
            if(!py[i] && !py[i - 1])
                g[i][j] = (g[i - 1][j] + g[i - 2][j - 1]) % mod;
            else g[i][j] = g[i - 1][j];
        }
    }
    int ans = 0;
    for(int i = 0; i + i <= sumx; i++)
        for(int j = 0; j + j <= sumy; j++)
            ans = (ans + 1LL * f[h][i] * g[w][j] % mod * C[sumx - i - i][j] % mod * C[sumy - j - j][i] % mod * A[i] % mod * A[j] % mod) % mod;
    printf("%d\n", ans);
    return 0;
}
