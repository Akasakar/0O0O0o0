/* *
 *    Author:   Akasaka
 *    FileName: 1238E.cpp
 *    Created:  2019.11.04(UTC+0800) 23.01.39(星期一)
 * */

#ifdef AKASAKA

#define DebugIN(x)  freopen(x, "r", stdin)
#define DebugOUT(x) freopen(x, "w", stdout)
#define IN  "./in.in"
#define OUT "./out.out"
#define CLOSE   "CON"   ///close in/out
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)

#include <time.h>
#define TimeStart   clock_t TIME_START = clock()
#define TimeEnd printf("%ld/%ld\n", clock() - TIME_START, CLOCKS_PER_SEC)

#else

#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#pragma comment(linker, "/STACK:102400000,102400000")
#define DebugIN(x)
#define DebugOUT(x)
#define IN
#define OUT
#define STOP

#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

char s[100010];
int cnt[24][32];
int dp[1 << 24];

int main()
{
    int n, m;
    scanf("%d%d%s", &n, &m, s);
    for(int i = 1; i < n; i++)
    {
        cnt[s[i - 1] - 'a'][s[i] - 'a']++;
        cnt[s[i] - 'a'][s[i - 1] - 'a']++;
    }
    int tot = 1 << m;
    int tmp;
    for(int i = 1; i < tot; i++)
        dp[i] = inf;
    for(int k = 0; k < tot; k++)
    {
        tmp = 0;
        for(int i = 0; i < m; i++)
            if(k & 1 << i)
                for(int j = 0; j < m; j++)
                    if(!(k & 1 << j)) tmp += cnt[i][j];
        
        for(int i = 0; i < m; i++)
            if(k & 1 << i)
                dp[k] = min(dp[k], dp[k ^ (1 << i)] + tmp);
    }
    printf("%d\n", dp[tot - 1]);
    return 0;
}
