/* *
 *    Author:   Akasaka
 *    FileName: 9.randomized_select.cpp
 *    Created:  2019.12.11(UTC+0800) 10.38.10(星期三)
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
#include <ctime>

using namespace std;

int randomized_partition(int A[], int n)
{
    std::swap(A[0], A[rand() % n]);
    int x = A[0];
    int i = 0;
    for(int j = 1; j < n; j++)
        if(A[j] < x)
        {
            i++;
            if(i != j) std::swap(A[i], A[j]);
        }
    if(i != 0) std::swap(A[0], A[i]);
    return i;
}

int randomized_select(int _begin[], int _end[], int k)
{
    int length = _end - _begin;
    if(length == 1) return *_begin;
    int mid = randomized_partition(_begin, length);
    if(k < mid + 1) 
        return randomized_select(_begin, _begin + mid, k);
    else if(k > mid + 1) 
        return randomized_select(_begin + mid + 1, _end, k - mid - 1); 
    else return _begin[mid];
};

int main()
{
    unsigned seed = 233;
    //seed=time(nullptr);
    srand(seed);
    int a[16] = {3, 2, 9, 0, 7, 5, 4, 8, 6, 1};
    int x = randomized_select(a, a + 10, 10);
    printf("%d", x);
    return 0;
}
