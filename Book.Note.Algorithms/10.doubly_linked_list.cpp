/* *
 *    Author:   Akasaka
 *    FileName: 10.doubly_linked_list.cpp
 *    Created:  2020.01.02(UTC+0800) 23.16.04(星期四)
 * */

#include <bits/stdc++.h>

using namespace std;

namespace doubly_linked_list
{
    struct Node
    {
        int key;
        Node *next, *prev;
        Node(int key = 0, Node* next = NULL, Node* prev = NULL): key(key), next(next), prev(prev) {}
    }*Lnil;

    void init()
    {
        Lnil = new Node();
        Lnil->next = Lnil;
        Lnil->prev = Lnil;
    }

    Node* creat_element(int key)
    {
        return new Node(key);
    }

    void List_Insert(Node* x)
    {   //插入到表头
        x->next = Lnil->next;
        Lnil->next->prev = x;
        Lnil->next = x;
        x->prev = Lnil;
    }

    Node* List_Search(int key)
    {
        Node* x = Lnil->next;
        while(x != Lnil && x->key != key) x = x->next;
        return x;
    }

    void List_Delete(Node* x)
    {
        if(x == Lnil) return;
        x->prev->next = x->next;
        x->next->prev = x->prev;
        delete x;
    }

    void clear()
    {
        Node* x = Lnil->next;
        while(x != Lnil)
        {
            Node* tmp = x;
            x = x->next;
            List_Delete(tmp);
        }
        delete Lnil;
    }

    void output()
    {
        Node* x = Lnil->next;
        while(x != Lnil)
        {
            printf("%d->", x->key);
            x = x->next;
        }
        puts("");
    }
};

int main()
{
    using namespace doubly_linked_list;
    init();
    List_Insert(creat_element(1));
    List_Insert(creat_element(2));
    List_Insert(creat_element(3));
    output();
    List_Delete(List_Search(0));
    output();
    clear();
    return 0;
}
