/* *
 *    Author:   Akasaka
 *    FileName: 8.radix_sort.cpp
 *    Created:  2019.12.10(UTC+0800) 14.50.35(星期二)
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

int ith_digit(int x, int i, int r)
{
    int m = ((1 << r) - 1) << (i * r);
    return (x & m) >> (i * r);
}

void radix_sort(int A[], int n, int b, int r)
{
    for(int i = 0; i < b / r; i++)
    {
        vector<int> B(A, A + n);
        vector<int> C(1 << r, 0);
        for(int j = 0; j < n; j++)
            C[ith_digit(B[j], i, r)]++;
        for(int j = 1; j < C.size(); j++)
            C[j] += C[j - 1];
        for(int j = n - 1; j >= 0; j--)
        {
            C[ith_digit(B[j], i, r)]--;
            A[C[ith_digit(B[j], i, r)]] = B[j];
        }
    }
}

int main()
{
    int l = 1 << 23;
    int r = 1 << 24;
    int d = r - l;
    int size = 1e6;
    int *a = new int[size];
    for(int i = 0; i < size; i++)
        a[i] = rand() % r;
    radix_sort(a, size, 24, 6);
    bool ok = 1;
    for(int i = 0; i < size; i++)
        if(a[i] < a[i - 1]) 
        {
            printf("%d %d\n", a[i - 1], a[i]);
            ok = 0;break;
        }
    printf("%d", ok);
    delete[] a;
    return 0;
}
