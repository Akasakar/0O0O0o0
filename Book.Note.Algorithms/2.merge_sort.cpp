/* *
 *    Author:   Akasaka
 *    FileName: 2.3.merge_sort.cpp
 *    Created:  2019.12.06(UTC+0800) 23.24.58(星期五)
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
#include <vector>

using namespace std;

const int _max = 5e5 + 10;
const int inf = 0x3f3f3f3f;

int a[_max];
long long ans;

void merge(int A[], int mid, int length)
{
    int n1 = mid;
    int n2 = length - mid;
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    for(int i = 0; i < n1; i++)
        L[i] = A[i];
    for(int j = 0; j < n2; j++)
        R[j] = A[j + mid];
    L[n1] = inf;
    R[n2] = inf;
    int i = 0;
    int j = 0;
    for(int k = 0; k < length; k++)
    {
        if(L[i] <= R[j])
            A[k] = L[i++];
        else 
        {
            ans += j + mid - k; //这里统计逆序对
            A[k] = R[j++];
        }
    }
}

void merge_sort(int _begin[], int _end[])
{
    int length = _end - _begin;
    if(length > 1)
    {
        int mid = length >> 1;
        merge_sort(_begin, _begin + mid);
        merge_sort(_begin + mid, _end);
        merge(_begin, mid, length);
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", a + i);
        ans = 0;
        merge_sort(a, a + n);
        printf("%lld\n", ans);
    }
    return 0;
}
