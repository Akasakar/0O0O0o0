/* *
 *    Author:   Akasaka
 *    FileName: 1335B.cpp
 *    Created:  2020.04.15(UTC+0800) 00.15.42(星期三)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace B
{
    void solve()
    {
        int t;
        scanf("%d", &t);
        int n, a, b;
        while(t--)
        {
            scanf("%d%d%d", &n, &a, &b);
            for(int i = 0; i < n; i++)
                putchar('a' + i % b);
            putchar(10);
        }
    }
}

int main()
{
    B::solve();
    return 0;
}
