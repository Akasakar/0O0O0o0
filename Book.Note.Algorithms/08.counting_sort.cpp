/* *
 *    Author:   Akasaka
 *    FileName: 8.counting_sort.cpp
 *    Created:  2019.12.10(UTC+0800) 14.09.13(星期二)
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

void counting_sort(int A[], int B[], int n, int k)
{
    vector<int> C(k + 1, 0);
    for(int j = 0; j < n; j++)
        C[A[j]]++;
    for(int i = 1; i <= k; i++)
        C[i] += C[i - 1];
    for(int j = n - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main()
{
    int a[16] = {2, 5, 3, 1, 2, 3, 1, 3};
    int b[16] = {0};
    counting_sort(a, b, 8, 5);
    for(int i = 0; i < 8; i++)
        printf("%d ", b[i]);
    return 0;
}
