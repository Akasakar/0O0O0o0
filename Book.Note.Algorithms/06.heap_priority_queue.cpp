/* *
 *    Author:   Akasaka
 *    FileName: 6.heap_priority_queue.cpp
 *    Created:  2019.12.08(UTC+0800) 21.53.31(星期日)
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

class Heap_priority_queue
{
    private:
        vector<int> A;
    protected:
        int size;
        int length;
    public:
        Heap_priority_queue(): A(vector<int>(1)), size(0), length(1) {}
        void push(int key)
        {
            size++;
            if(length <= size)
            {
                length++;
                A.push_back(0);
            }
            A[size] = key;
            Push_Up(size);
        }
        void pop()
        {
            swap(A[1], A[size]);
            size--;
            Push_Down(1);
        }
        int top()
        {
            return A[1];
        }
        bool empty()
        {
            return size < 1;
        }
    private:
        void Push_Up(int o)
        {
            int pa = o >> 1;
            while(o > 1 && A[pa] < A[o])
            {
                swap(A[pa], A[o]);
                o = pa;
                pa >>= 1;
            }
        }
        void Push_Down(int o)
        {
            while(true)
            {
                int l = o << 1;
                int r = l + 1;
                int largest = o;
                if(l <= size && A[l] > A[largest]) largest = l;
                if(r <= size && A[r] > A[largest]) largest = r;
                if(largest == o) break;
                swap(A[o], A[largest]);
                o = largest;
            }
        }
        void Build_heap()
        {
            for(int i = size >> 1; i; i--)
                Push_Down(i);
        }
};

int main()
{
    Heap_priority_queue Q;
    Q.push(4);
    Q.push(1);
    Q.push(3);
    Q.push(2);
    Q.push(16);
    Q.push(9);
    Q.push(10);
    Q.push(14);
    Q.push(8);
    Q.push(7);
    while(!Q.empty())
    {
        printf("%d ", Q.top());
        Q.pop();
    }
    return 0;
}
