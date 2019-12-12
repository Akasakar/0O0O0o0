/* *
 *    Author:   Akasaka
 *    FileName: 2.1.insertion_sort.cpp
 *    Created:  2019.12.05(UTC+0800) 21.15.49(星期四)
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


#include <cstdio>

void Insertion_Sort(int begin[], int end[])
{
    int length = end - begin;
    int *A = begin;
    for(int j = 1; j < length; j++)
    {
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

int main()
{
    int a[6] = {5, 2, 4, 6, 1, 3};
    Insertion_Sort(a, a + 6);
    for(int i = 0; i < 6; i++)
        printf("%d ", a[i]);
    return 0;
}
