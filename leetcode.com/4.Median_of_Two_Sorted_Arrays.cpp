/* *
 *    Author:   Akasaka
 *    FileName: 4.Median_of_Two_Sorted_Arrays.cpp
 *    Created:  2019.12.11(UTC+0800) 17.29.18(星期三)
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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = m;
        while(l <= r)
        {
            int i = (l + r) >> 1;
            int j =  (m + n + 1 - i - i) >> 1;
            if(i > l && nums1[i - 1] > nums2[j]) r = i - 1;
            else if(i < r && nums2[j - 1] > nums1[i]) l = i + 1;
            else
            {
                int L;
                if(i == 0) L = nums2[j - 1];
                else if(j == 0) L = nums1[i - 1];
                else L = max(nums1[i - 1], nums2[j - 1]);
                if((m + n) & 1) return L;

                int R;
                if(i == m) R = nums2[j];
                else if(j == n) R = nums1[i];
                else R = min(nums1[i], nums2[j]);

                return (L + R) * 0.5;
            }
        }
    }
};

int main()
{
    vector<int> a({2});
    vector<int> b({1, 3});
    cout << Solution().findMedianSortedArrays(a, b) << endl;
    return 0;
}
