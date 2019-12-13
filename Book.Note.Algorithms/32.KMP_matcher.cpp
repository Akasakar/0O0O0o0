/* *
 *    Author:   Akasaka
 *    FileName: 32.KMP_matcher.cpp
 *    Created:  2019.12.13(UTC+0800) 21.30.20(星期五)
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

void compute_prefix_fuction(char P[], vector<int>& pi)
{
    int m = strlen(P);
    pi.resize(m + 1);
    pi[1] = 0;
    int k = 0;
    for(int q = 2; q <= m; q++)
    {
        while(k > 0 && P[k + 1 - 1] != P[q - 1]) k = pi[k];
        if(P[k + 1 - 1] == P[q - 1]) k++;
        pi[q] = k;
    }
    for(int i = 0; i < pi.size(); i++)
        printf("%d ", pi[i]);
    putchar(10);
}

void KMP_matcher(char T[], char P[])
{
    int n = strlen(T);
    int m = strlen(P);
    vector<int> pi;
    compute_prefix_fuction(P, pi);
    int q = 0;
    for(int i = 0; i < n; i++)
    {
        while(q > 0 && P[q + 1 - 1] != T[i]) q = pi[q];
        printf("%d:%c %c\n", i, P[q + 1 - 1], T[i]);
        if(P[q + 1 - 1] == T[i]) q++;
        printf("q=%d\n", q);
        if(q == m)
        {
            printf("Pattern occurs with shitf %d\n", i - m + 1);
            q = pi[q];
        }
    }
}

int main()
{
    const int _max = 128;
    char T[_max] = "bacbababaabcbababacab";
    char P[_max] = "ababaca";
    KMP_matcher(T, P);
    return 0;
}
