/* *
 *    Author:   Akasaka
 *    FileName: 1335A.cpp
 *    Created:  2020.04.15(UTC+0800) 00.11.06(星期三)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace A
{
    void solve()
    {
        int t, n;
        scanf("%d", &t);
        while(t--)
        {
            scanf("%d", &n);
            printf("%d\n", (n - 1) >> 1);
        }
    }
}

int main()
{
    A::solve();
    return 0;
}
