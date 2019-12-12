/* *
 *    Author:   Akasaka
 *    FileName: 32.rabin_karp_matcher.cpp
 *    Created:  2019.12.12(UTC+0800) 14.36.48(星期四)
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

int mp[128];

bool cmp(char P[], char T[], int s, int m)
{
    for(int i = 0; i < m; i++)
        if(P[i] != T[i + s]) return false;
    return true;
}

void rabin_karp_matcher(char T[], char P[], int d, int q)
{
    int n = strlen(T);
    int m = strlen(P);
    int h = 1;
    for(int i = 1; i < m; i++)
        h = (d * h) % q;
    int p = 0;
    int t = 0;
    for(int i = 0; i < m; i++)
    {
        p = (d * p + mp[P[i]]) % q;
        t = (d * t + mp[T[i]]) % q;
    }

    for(int s = 0; s <= n - m; s++)
    {
        if(p == t)
        {
            if(cmp(P, T, s, m))
                printf("Pattern occurs with shift %d\n", s);
            else printf("fake shift %d\n", s);
        }
        if(s < n - m)
            t = ((d * (t - mp[T[s]] * h % q + q) % q) % q + mp[T[s + m]]) % q;
    }
}

int main()
{
    for(int i = '0'; i <= '9'; i++)
        mp[i] = i - '0';
    char T[128] = "3141592653589793";
    char P[128] = "26";
    rabin_karp_matcher(T, P, 10, 11);
    return 0;
}
