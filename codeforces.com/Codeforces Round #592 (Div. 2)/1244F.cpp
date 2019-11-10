/* *
 *    Author:   Akasaka
 *    FileName: 1244F.cpp
 *    Created:  2019.11.10(UTC+0800) 22.59.32(星期日)
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

#define IN
#define OUT
#define STOP
#define DebugIN(x)
#define DebugOUT(x)
#define CPP std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

const int _max = 2e5 + 10;

char s[_max];
int dl[_max], dr[_max];

void invWB(char& c)
{
    if(c == 'W') c = 'B';
    else c = 'W';
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);

    int p = -1;
    for(int i = 0; i < n; i++)
        if(s[i] == s[(i + 1) % n])
        {
            p = i + 1;
            break;
        }
    if(p == -1)
    {
        if(k & 1) for(int i = 0; i < n; i++) invWB(s[i]);
    }
    else 
    {
        for(int i = 0; i < n; i++)
        {
            int pl = (p + i) % n;
            int pr = (p - i + n) % n;
            if(s[pl] != s[(pl - 1 + n) % n] && s[pl] != s[(pl + 1) % n])
                dl[pl] = dl[(pl - 1 + n) % n] + 1;
            if(s[pr] != s[(pr + 1) % n] && s[pr] != s[(pr - 1 + n) % n])
                dr[pr] = dr[(pr + 1) % n] + 1;
        }
        for(int i = 0; i < n; i++)
        {
            if(dl[i] < dr[i])
            {
                if(k >= dl[i]) s[i] = s[(i - dl[i] + n) % n];
                else if(k & 1) invWB(s[i]);
            }
            else
            {
                if(k >= dr[i]) s[i] = s[(i + dr[i]) % n];
                else if(k & 1) invWB(s[i]);
            }
        }
    }

    printf("%s\n", s);
    return 0;
}
