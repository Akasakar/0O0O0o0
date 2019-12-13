/* *
 *    Author:   Akasaka
 *    FileName: 32.finite_automaton_matcher.cpp
 *    Created:  2019.12.12(UTC+0800) 23.29.19(星期四)
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

int delta[16][128];

bool is_suffix(char P[], int k, int q, char a)
{
    if(k < 0) return true;
    if(P[k] != a) return false;
    for(int i = k - 1; i >= 0; i--)
        if(P[i] != P[q--]) return false;
    return true;
}

void compute_transition_function(char P[], vector<char> sigma)
{
    int m = strlen(P);
    for(int q = 0; q <= m; q++)
    {
        for(int i = 0; i < sigma.size(); i++)
        {
            char& a = sigma[i];
            int k = min(m, q + 1);
            while(!is_suffix(P, k - 1, q - 1, a)) k--;
            delta[q][a] = k;
        }
    }
}

void finite_automaton_matcher(char T[], int m)
{
    int n = strlen(T);
    int q = 0;
    for(int i = 0; i < n; i++)
    {
        q = delta[q][T[i]];
        if(q == m)
            printf("Pattern occurs with shift %d\n", i + 1 - m);
    }
}

int main()
{
    char T[128] = "aaababaabaababaab";
    char P[128] = "ababbabbababbababbabb";
    char S[128] = "ab";
    int slen = strlen(S);
    int m = strlen(P);
    vector<char> sigma(S, S + slen);
    compute_transition_function(P, sigma);
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j < slen; j++)
            printf("%d ", delta[i][j + 'a']);
        putchar(10);
    }
    //finite_automaton_matcher(T, strlen(P));
    return 0;
}
