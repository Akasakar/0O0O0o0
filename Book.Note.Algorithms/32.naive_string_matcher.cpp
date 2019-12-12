/* *
 *    Author:   Akasaka
 *    FileName: 32.naive_string_matcher.cpp
 *    Created:  2019.12.12(UTC+0800) 10.51.50(星期四)
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

bool cmp(char P[], char T[], int s, int m)
{
    for(int i = 0; i < m; i++)
        if(P[i] != T[s + i]) return false;
    return true;
}

void naive_string_matcher(char T[], char P[])
{
    int n = strlen(T);
    int m = strlen(P);
    for(int s = 0; s <= n - m; s++)
        if(cmp(P, T, s, m))
            printf("Pattern occus with shift %d\n", s);
}

int main()
{
    char T[16] = "acaabaa";
    char P[16] = "aab";
    naive_string_matcher(T, P);
    return 0;
}
