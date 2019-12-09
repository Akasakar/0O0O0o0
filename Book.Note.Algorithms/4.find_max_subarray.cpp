/* *
 *    Author:   Akasaka
 *    FileName: 4.find_max_subarray.cpp
 *    Created:  2019.12.07(UTC+0800) 19.00.59(星期六)
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

int Find_Max_Crossing_SubArray(int A[], int& low, int mid, int& high)
{
    int sum = 0;
    int left_sum = INT_MIN;
    int max_left = mid;
    for(int i = mid - 1; i >= low; i--)
    {
        sum += A[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    int right_sum = INT_MIN;
    int max_right = mid;
    for(int i = mid; i < high; i++)
    {
        sum += A[i];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }
    low = max_left, high = max_right + 1;
    return left_sum + right_sum;
}

int Find_Maximum_SubArray(int A[], int& low, int& high)
{
    if(low + 1 >= high) return A[low];
    else
    {
        int mid = (low + high) >> 1;
        int left_low = low, left_high = mid;
        int left_sum = Find_Maximum_SubArray(A, left_low, left_high);
        int right_low = mid, right_high = high;
        int right_sum = Find_Maximum_SubArray(A, right_low, right_high);
        int cross_left = low, cross_right = high;
        int cross_sum = Find_Max_Crossing_SubArray(A, cross_left, mid, cross_right);
        int max_sum = 0;
        if(left_sum >= right_sum && left_sum >= cross_sum)
            low = left_low, high = left_high, max_sum = left_sum;
        else if(right_sum >= left_sum && right_sum >= cross_sum)
            low = right_low, high = right_high, max_sum = right_sum;
        else low = cross_left, high = cross_right, max_sum = cross_sum;
        return max_sum;
    }
}

int main()
{
    int a[16] = {-13, -3, -25, -20, -3, -16, -23, -18, -20, -7, -12, -5, -22, -15, -4, -7};
    int l = 0, r = 16;
    int sum = Find_Maximum_SubArray(a, l, r);
    printf("%d %d %d\n", sum, l, r);

    int dp[16] = {13};
    for(int i = 1; i < 16; i++)
    {
        dp[i] = max(a[i], dp[i - 1] + a[i]);
        printf("%d ", dp[i]);
    }
    return 0;
}
