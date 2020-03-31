/* *
 *    Author:   Akasaka
 *    FileName: 15.bottom_up_cut_rod.cpp
 *    Created:  2020.03.31(UTC+0800) 11.11.20(星期二)
 * */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 10;
    vector<int> p({1, 5, 8, 9, 10, 17, 17, 20, 24, 30});
    vector<int> r(n + 1);
    vector<int> s(n + 1);

    for(int i = 1; i <= n; i++)
    {
        r[i] = p[i - 1];
        s[i] = i;
        for(int j = 1; j <= i; j++)
            if(r[i] < r[j] + r[i - j])
            {
                r[i] = r[j] + r[i - j];
                s[i] = j;
            }
    }

    for(int i = 1; i <= n; i++)
    {
        printf("len%d-%d:", i, r[i]);
        for(int j = i; j > 0;j -= s[j])
            printf("%d ", s[j]);
        putchar(10);
    }

    return 0;
}
