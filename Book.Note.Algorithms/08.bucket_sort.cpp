/* *
 *    Author:   Akasaka
 *    FileName: 8.bucket_sort.cpp
 *    Created:  2019.12.10(UTC+0800) 16.32.43(星期二)
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

void bucket_sort(double A[], int n)
{
    vector<vector<double> > B(n, vector<double>());
    for(int i = 0; i < n; i++)
        B[int(n * A[i])].push_back(A[i]);
    for(int i = 0; i < n; i++)
    {
        vector<double>& a = B[i];
        for(int j = 1; j < a.size(); j++)
        {
            double key = a[j];
            int k = j - 1;
            while(k >= 0 && a[k] > key)
            {
                a[k + 1] = a[k];
                k--;
            }
            a[k + 1] =  key;
        }
    }
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < B[i].size(); j++)
            A[k++] = B[i][j];
    }
}

int main()
{
    double a[16] = {0.79, 0.13, 0.16, 0.64, 0.39, 0.20, 0.89, 0.53, 0.71, 0.42};
    bucket_sort(a, 10);
    for(int i = 0; i < 10; i++)
        printf("%lf ", a[i]);
    return 0;
}
