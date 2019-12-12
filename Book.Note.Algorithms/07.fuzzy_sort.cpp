/* *
 *    Author:   Akasaka
 *    FileName: 7.fuzzy_sort.cpp
 *    Created:  2019.12.10(UTC+0800) 10.01.04(星期二)
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

struct Seg
{
    int a, b;
    Seg(int a = 0, int b = 0): a(a), b(b) {}
};

bool intersects(const Seg& A, const Seg& B)
{
    return A.a <= B.b && A.b >= B.a;
}

bool before(const Seg& A, const Seg& B)
{
    return A.b < B.a;
}

void output(Seg A[], int length)
{
    puts("#");
    for(int i = 0; i < length; i++)
        printf("[%d %d] ", A[i].a, A[i].b);
    putchar(10);
}

Seg partition(Seg A[], int length)
{
    Seg x = A[0];   //这里随机化一下，就满足算法导论7.6问a了

    //主元区间缩小
    for(int i = 1; i < length; i++)
        if(intersects(x, A[i]))
        {
            if(x.a < A[i].a) x.a = A[i].a;
            if(x.b > A[i].b) x.b = A[i].b;
        }

    //将相交区间，且严格小于主元的放在主元前面，依赖before函数
    int s = 0;
    for(int i = 1; i < length; i++)
        if(before(A[i], x))
        {
            s++;
            if(s != i) std::swap(A[s], A[i]);
        }
    if(s != 0) std::swap(A[0], A[s]);

    //去除相交的区间
    int t = s + 1;
    int i = length - 1;
    while(t <= i)
    {
        if(intersects(A[i], x))
        {
            if(t != i) std::swap(A[t], A[i]);
            t++;
        }
        else i--;
    }

    //[0-s)即是严格小于主元的，[t-length]即是严格大于主元的。
    //当大量区间重叠时，显然递归树高度急剧下降，复杂度变为O(n)。
    return Seg(s, t);
}

void fuzzy_sort(Seg _begin[], Seg _end[])
{
    int length = _end - _begin;
    if(length > 1)
    {
        Seg mid = partition(_begin, length);
        fuzzy_sort(_begin, _begin + mid.a);
        fuzzy_sort(_begin + mid.b, _end);
    }
}

int main()
{
    Seg a[16] = {Seg(2, 4), Seg(0, 1), Seg(3, 5), Seg(-1, -2), Seg(0, 99)};
    output(a, 5);
    fuzzy_sort(a, a + 5);
    output(a, 5);
    return 0;
}
