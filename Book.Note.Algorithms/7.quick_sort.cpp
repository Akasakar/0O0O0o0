/* *
 *    Author:   Akasaka
 *    FileName: 7.quick_sort.cpp
 *    Created:  2019.12.09(UTC+0800) 21.08.06(星期一)
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

int sum;

int parition(int A[], int n)
{
    int x = A[0];
    int i = 0;
    for(int j = 1; j < n; j++)
        if(A[j] <= x)
        {
            i++;
            if(i < j) sum++, std::swap(A[i], A[j]);
        }
    if(i != 0) sum++, std::swap(A[0], A[i]);
    return i;
}

void quick_sort(int _begin[], int _end[])
{
    int length = _end - _begin;
    if(length > 1)
    {
        int mid = parition(_begin, length);
        quick_sort(_begin, _begin + mid);
        quick_sort(_begin + mid + 1, _end);
    }
}

int main()
{
    int a[16] = {7, 8, 6, 4, 1, 2, 3, 5};
    quick_sort(a, a + 8);
    printf("%d\n", sum);
    for(int i = 0; i < 8; i++)
        printf("%d ", a[i]);
    return 0;
}
