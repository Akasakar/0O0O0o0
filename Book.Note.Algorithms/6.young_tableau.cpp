/* *
 *    Author:   Akasaka
 *    FileName: 6.young_tableau.cpp
 *    Created:  2019.12.09(UTC+0800) 18.57.54(星期一)
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
#include <climits>
#include <cassert>
#include <vector>

namespace Young
{
    struct Point
    {
        int x, y;
        Point(int x, int y): x(x), y(y) {}
        bool operator < (const Point& rhs) const
        {
            if(x == rhs.x) return y < rhs.y;
            else return x < rhs.x;
        }
        bool operator > (const Point& rhs) const
        {
            return rhs < *this;
        }
        bool operator == (const Point& rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }
    };

    struct tables
    {
        std::vector<std::vector<int> > A;
        tables();
        tables(int n): A(std::vector<std::vector<int> >(n, std::vector<int>(n, INT_MAX))){}
        int& operator [] (const Point& o)
        {
            assert(o.x >= 0 && o.x < A.size() && o.y >= 0 && o.y < A[0].size());
            return A[o.x][o.y];
        }
    };

    class Young_tableaus
    {
        private:
            tables A;
        protected:
            int n;
            Point cur;
        public:
            Young_tableaus(): n(0), cur(-1, 0){}
            Young_tableaus(int n): A(n), n(n), cur(-1, 0){}
            void output()
            {
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                        printf("%d ", A[Point(i, j)]);
                    putchar(10);
                }
            }
            void push(int key)
            {
                The_next(cur);
                A[cur] = key;
                Shift_Up(cur);
            }
            void pop()
            {
                std::swap(A[Point(0, 0)], A[cur]);
                A[cur] = INT_MAX;
                The_last(cur);
                Shift_Down(Point(0, 0));
            }
            bool find(int key)
            {
                int d = cur.x + cur.y;
                Point o(std::min(d, n - 1), 0);
                while(o.x >= 0 && o.y < n)
                {
                    if(key < A[o]) o.x--;
                    else if(key > A[o]) o.y++;
                    else return true;
                }
                return false;
            }
            int get_topleft()
            {
                return A[Point(0, 0)];
            }
            bool empty()
            {
                return cur.x < 0;
            }
            bool full()
            {
                return cur > Point(n - 1, n - 1);
            }
        private:
            void Shift_Up(Point o)
            {
                while(true)
                {
                    Point U(o.x - 1, o.y);
                    Point L(o.x, o.y - 1);
                    Point best(o);
                    if(U.x >= 0 && A[best] < A[U]) best = U;
                    if(L.y >= 0 && A[best] < A[L]) best = L;
                    if(best == o) break;
                    std::swap(A[best], A[o]);
                    o = best;
                }
            }
            void Shift_Down(Point o)
            {
                while(true)
                {
                    Point D(o.x + 1, o.y);
                    Point R(o.x, o.y + 1);
                    Point best(o);
                    if(R.y < n && A[R] < A[best]) best = R;
                    if(D.x < n && A[D] < A[best]) best = D;
                    if(best == o) break;
                    std::swap(A[best], A[o]);
                    o = best;
                }
            }
            void The_next(Point& o)
            {
                int d = o.x + o.y + 1;
                if(o.x + 1 >= n) o = Point(d - n + 1, n - 1);
                else if(o.y - 1 < 0) o = Point(0, d);
                else o = Point(o.x + 1, o.y - 1);
            }
            void The_last(Point& o)
            {
                int d = o.x + o.y - 1;
                if(o.x - 1 < 0) o = Point(d, 0);
                else if(o.y + 1 >= n) o = Point(n - 1, d - n + 1);
                else o = Point(o.x - 1, o.y + 1);
            }
    };
}

int main()
{
    int a[16] = {9, 16, 3, 2, 4, 8, 5, 14, 12, 7, 15, 6, 1, 13, 10, 11};
    Young::Young_tableaus Y(4);
    for(int i = 0; i < 9; i++)
        Y.push(a[i]);
    printf("%d\n", Y.find(16));
    Y.output();
    while(!Y.empty())
    {
        printf("%d ", Y.get_topleft());
        Y.pop();
    }
    return 0;
}
