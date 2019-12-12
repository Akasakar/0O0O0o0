/* *
 *    Author:   Akasaka
 *    FileName: 9.select5median.cpp
 *    Created:  2019.12.11(UTC+0800) 15.38.17(星期三)
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

void insertion_sort(int A[], const vector<int>& pos, int n, int d)
{//每次调用，最坏是10次
    for(int j = 1; j < n; j++)
    {
        int key = A[pos[j + d]];
        int i = j - 1;
        while(i >= 0 && A[pos[i + d]] > key)
        {
            A[pos[i + 1 + d]] = A[pos[i + d]];
            i--;
        }
        A[pos[i + 1 + d]] = key;
    }
    //for(int i = 0; i < n; i++)
    //    printf("%d ", A[pos[i + d]]);
}

int select(int A[], const vector<int>& pos)
{//递归找出A[]中5个元素一组的中位数的中位数
    vector<int> idx;
    int cur = 0;
    while(cur + 5 <= pos.size())
    {
        insertion_sort(A, pos, 5, cur);
        idx.push_back(pos[cur + 2]);
        cur += 5;
    }
    int mod = pos.size() - cur;
    if(mod)
    {
        insertion_sort(A, pos, mod, cur);
        idx.push_back(pos[cur + (mod - 1) / 2]);
    }
    //for(int i = 0; i < idx.size(); i++)
    //    printf("%d ", idx[i]);
    //putchar(10);
    if(idx.size() > 1) return select(A, idx);
    else return idx[0];
}

int partition_select(int A[], int n)
{//找出中位数再划分
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
        pos[i] = i;
    int p = select(A, pos);

    std::swap(A[0], A[p]);
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

int select5median(int _begin[], int _end[], int k)
{
    int length = _end - _begin;
    if(length == 1) return *_begin;
    int mid = partition_select(_begin, length);
    if(k < mid + 1)
        return select5median(_begin, _begin + mid, k);
    else if(k > mid + 1)
        return select5median(_begin + mid + 1, _end, k - mid - 1);
    else return _begin[mid];
}

int main()
{
    int a[16] = {3, 5, 1, 6, 2, 8, 4, 7, 9, 10, 11};
    for(int i = 1; i <= 11; i++)
        cout << select5median(a, a + 11, i) << endl;
    return 0;
}
