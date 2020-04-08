/* *
 *    Author:   Akasaka
 *    FileName: 15.problem03_bitonic_tours.cpp
 *    Created:  2020.04.07(UTC+0800) 20.03.31(星期二)
 * */

#ifdef AKASAKA
#define STOP printf("Press Enter key to continue..."); fgetc(stdin)
#endif // AKASAKA


#include <bits/stdc++.h>

using namespace std;

namespace test
{
    struct Point
    {
        int x, y;
        Point(int x = 0, int y = 0): x(x), y(y) {}
    };

    double dis(Point a, Point b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    const int _max = 16;
    double dp[_max][_max];

    void bitonic_tours(vector<Point>& p)
    {
        int n = p.size();
        for(int i = 1; i <= n; i++)
            dp[n][i] = dis(p[i - 1], p[n - 1]);
        for(int i = n - 1; i >= 1; i--)
            for(int j = 1; j <= i; j++)
                dp[i][j] = min(dp[i + 1][j] + dis(p[i - 1], p[i]), dp[i + 1][i] + dis(p[j - 1], p[i]));
    }

    void solve()
    {
        vector<Point> p({Point(0, 6), Point(1, 0), Point(2, 3), \
                Point(5, 4), Point(6, 1), Point(7, 5), Point(8, 2)});
        bitonic_tours(p);
        printf("%lf\n", dp[1][1]);
    }
}

int main()
{
    test::solve();
    return 0;
}
