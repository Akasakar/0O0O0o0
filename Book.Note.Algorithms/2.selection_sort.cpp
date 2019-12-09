/* *
 *    Author:   Akasaka
 *    FileName: 2.2.selection_sort.cpp
 *    Created:  2019.12.07(UTC+0800) 12.35.15(星期六)
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

void selection_sort(int _begin[], int _end[])
{
    int length = _end - _begin;
    int *A = _begin;
    for(int i = 0; i < length; i++)
    {
        int key = A[i];
        int k = i;
        for(int j = i + 1; j < length; j++)
            if(key > A[j])
            {
                key = A[j];
                k = j;
            }
        if(i != k) swap(A[i], A[k]);
    }
}

int main()
{
    int a[16] = {6, 3, 5, 1, 8, 2, 10, 9, 4, 7};
    selection_sort(a, a + 10);
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}
