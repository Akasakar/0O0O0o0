/* *
 *    Author:   Akasaka
 *    FileName: 1237H.cpp
 *    Created:  2019.11.24(UTC+0800) 17.58.50(星期日)
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

const int _max = 4010;

char a[_max], b[_max], tmp[4];

void reverse(char *s, int p)
{
    for(int i = 0; i + i < p; i++)
        swap(s[i], s[p - i - 1]);
}

int searchStr(const char *s, const char *p, int n)
{
    for(int i = 0; i < n; i += 2)
        if(s[i] == p[0] && s[i + 1] == p[1])
            return i;
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s%s", a, b);
        int n = strlen(a);
        int cnt01 = 0, cnt11 = 0;
        for(int i = 0; i < n; i += 2)
        {
            int ida = (a[i] - '0') << 1 | a[i + 1] - '0';
            int idb = (b[i] - '0') << 1 | b[i + 1] - '0';
            if(ida == 3) cnt11++;
            else if(ida) cnt01++;
            if(idb == 3) cnt11--;
            else if(idb) cnt01--;
        }
        if(cnt01 == 0 && cnt11 == 0)
        {
            vector<int> p;
            for(int i = n - 2; i >= 0; i -= 2)
            {
                int ida = (a[i] - '0') << 1 | a[i + 1] - '0';
                int idb = (b[i] - '0') << 1 | b[i + 1] - '0';
                if(ida == idb) continue;
                ida = (a[1] - '0') << 1 | a[0] - '0';
                if(ida == idb)
                {
                    reverse(a, i + 2);
                    p.push_back(i + 2);

                }
                else
                {
                    tmp[0] = b[i];
                    tmp[1] = b[i + 1];
                    int pos = searchStr(a, tmp, i + 2);
                    if(pos >= 0)
                    {
                        reverse(a, pos + 2);
                        p.push_back(pos + 2);
                        reverse(a, i + 2);
                        p.push_back(i + 2);
                    }
                    else
                    {
                        swap(tmp[0], tmp[1]);
                        pos = searchStr(a, tmp, i + 2);
                        if(pos > 1)
                        {
                            reverse(a, pos + 2);
                            p.push_back(pos + 2);
                            reverse(a, 2);
                            p.push_back(2);
                            reverse(a, i + 2);
                            p.push_back(i + 2);
                        }
                    }
                }
            }
            printf("%lu\n", p.size());
            for(int i = 0; i < p.size(); i++)
                printf("%d ", p[i]);
            putchar(10);
        }
        else puts("-1");
    }
    return 0;
}
