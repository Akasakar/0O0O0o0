/* *
 *    Author:   Akasaka
 *    FileName: 23.Merge_k_Sorted_Lists.cpp
 *    Created:  2019.12.08(UTC+0800) 22.40.20(星期日)
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Heap_priority_queue
{
    private:
        std::vector<ListNode*> A;
        bool (*compare)(const ListNode*, const ListNode*);
    protected:
        int size;
        int length;
    public:
        Heap_priority_queue(): A(std::vector<ListNode*>(1)), size(0), length(1) {}
        Heap_priority_queue(bool (*cmp)(const ListNode*, const ListNode*)): A(std::vector<ListNode*>(1)), size(0), length(1), compare(cmp) {}
        void push(ListNode* key)
        {
            size++;
            if(length <= size)
            {
                length++;
                A.push_back(NULL);
            }
            A[size] = key;
            Push_Up(size);
        }
        void pop()
        {
            std::swap(A[1], A[size]);
            size--;
            Push_Down(1);
        }
        ListNode* top()
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
            while(o > 1 && compare(A[o], A[pa]))
            {
                std::swap(A[pa], A[o]);
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
                if(l <= size && compare(A[l], A[largest])) largest = l;
                if(r <= size && compare(A[r], A[largest])) largest = r;
                if(largest == o) break;
                std::swap(A[o], A[largest]);
                o = largest;
            }
        }
};
using namespace std;
class Solution {
public:
    static bool cmp(const ListNode* a, const ListNode *b)
    {
        return a->val < b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        Heap_priority_queue Q(cmp);
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode *tmp = lists[i];
            while(tmp != NULL)
            {
                Q.push(tmp);
                tmp = tmp->next;
            }
        }
        ListNode ans(0);
        ListNode *x = &ans;
        while(!Q.empty())
        {
            x->next = Q.top();
            x = x->next;
            Q.pop();
        }
        x->next = NULL;
        return ans.next;
    }
};

int main()
{
    ListNode a(-2);
    a.next = new ListNode(-1);
    a.next->next = new ListNode(-1);
    a.next->next->next = new ListNode(-1);
    vector<ListNode*> A;
    A.push_back(&a);
    A.push_back(NULL);
    for(int i = 0; i < A.size(); i++)
    {
        ListNode *x = A[i];
        while(x != NULL)
        {
            printf("%d ", x->val);
            x = x->next;
        }
        putchar(10);
    }
    Solution s;
    ListNode *x = s.mergeKLists(A);
    while(x != NULL)
    {
        printf("%d ", x->val);
        x = x->next;
    }
    return 0;
}
