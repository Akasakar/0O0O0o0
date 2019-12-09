/* *
 *    Author:   Akasaka
 *    FileName: 6.heap_sort.cpp
 *    Created:  2019.12.08(UTC+0800) 21.40.37(星期日)
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

void push_down(int A[], int size, int o)
{
    while(true)
    {
        int l = o << 1;
        int r = l + 1;
        int largest = o;
        if(l <= size && A[l] > A[largest]) largest = l;
        if(r <= size && A[r] > A[largest]) largest = r;
        if(largest == o) break;
        swap(A[o], A[largest]);
        o = largest;
    }
}

void heap_sort(int _begin[], int _end[])
{
    int size = _end - _begin - 1;
    int *A = _begin;
    for(int i = size >> 1; i; i--)
        push_down(A, size, i);
    for(int i = size; i > 1; i--)
    {
        swap(A[1], A[i]);
        size--;
        push_down(A, size, 1);
    }
}

int main()
{
    int a[16] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heap_sort(a, a + 11);
    for(int i = 1; i <= 10; i++)
        printf("%d ", a[i]);
    return 0;
}
