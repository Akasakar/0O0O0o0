/* *
 *    Author:   Akasaka
 *    FileName: 1335D.cpp
 *    Created:  2020.04.15(UTC+0800) 00.34.40(星期三)
 * */


#include <bits/stdc++.h>

using namespace std;

namespace D
{
    const int _max = 16;
    char s[_max][_max];

    void solve()
    {
        int t;
        scanf("%d", &t);
        while(t--)
        {
            for(int i = 0; i < 9; i++)
                scanf("%s", s[i]);
            s[0][0] = s[0][1];
            s[1][3] = s[1][4];
            s[2][6] = s[2][7];
            s[3][1] = s[3][2];
            s[4][4] = s[4][5];
            s[5][7] = s[5][8];
            s[6][2] = s[6][3];
            s[7][5] = s[7][6];
            s[8][8] = s[8][0];
            for(int i = 0; i < 9; i++)
                puts(s[i]);
        }
    }
}

int main()
{
    D::solve();
    return 0;
}
