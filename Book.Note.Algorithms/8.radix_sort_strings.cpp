/* *
 *    Author:   Akasaka
 *    FileName: 8.radix_sort_strings.cpp
 *    Created:  2019.12.10(UTC+0800) 19.22.26(星期二)
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

void reverse(string& s)
{
    for(int i = 0; i + i < s.length(); i++)
        swap(s[i], s[s.length() - 1 - i]);
}

void radix_sort(string A[], int n)
{
    const char space = ' ';
    int d = 0;
    for(int i = 0; i < n; i++)
        d = max(d, (int)A[i].length());
    for(int i = d - 1; i >= 0; i--)
    {
        vector<string> B(A, A + n);
        vector<int> C(128, 0);
        for(int j = 0; j < n; j++)
        {
            if(A[j].length() > i) C[A[j][i]]++;
            else C[space]++;
        }
        for(int j = 1; j < C.size(); j++)
            C[j] += C[j - 1];
        for(int j = n - 1; j >= 0; j--)
        {
            char x = space;
            if(B[j].length() > i) x = B[j][i];
            C[x]--;
            A[C[x]] = B[j];
        }
    }
}

int main()
{
    string A[16] = {"d", "ca", "b", "bcd", "a", "bd", "bdc"};
    radix_sort(A, 7);
    for(int i = 0; i < 7; i++)
        printf("%s ", A[i].c_str());
    return 0;
}
