/* *
 *    Author:   Akasaka
 *    FileName: 10.left_child_right_sibling.cpp
 *    Created:  2020.01.12(UTC+0800) 16.02.19(星期日)
 * */

#include <bits/stdc++.h>

using namespace std;

namespace left_child_right_sibling
{
    struct Node
    {
        int key;
        Node *parent, *left_child, *right_sibling;
        Node(int key = 0, Node* parent = NULL): key(key), parent(parent), left_child(NULL), right_sibling(NULL) {}
    };
    
    Node* Troot;

    void creat_left(Node* T, int v)
    {
        Node *X = T->left_child;
        X = new Node(v);
    }

    void init()
    {
        Troot = new Node(1);

        Node* x01 = Troot->left_child = new Node(2, Troot);
        Node* x02 = x01->right_sibling = new Node(3, Troot);
        Node* x03 = x02->right_sibling = new Node(4, Troot);

        Node* x011 = x01->left_child = new Node(5, x01);
        Node* x012 = x011->right_sibling = new Node(6, x01);

        Node* x021 = x02->left_child = new Node(7, x02);
        Node* x022 = x021->right_sibling = new Node(8, x02);
        Node* x023 = x022->right_sibling = new Node(9, x02);
        Node* x024 = x023->right_sibling = new Node(10, x02);

        Node* x031 = x03->left_child = new Node(11, x03);

        Node* x0121 = x012->left_child = new Node(12, x012);

        Node* x0231 = x023->left_child = new Node(13, x023);
        Node* x0232 = x0231->right_sibling = new Node(14, x023);
    }

    void dfs(Node* T)
    {
        if(T) printf("%d ", T->key);
        if(T->left_child) dfs(T->left_child);
        if(T->right_sibling) dfs(T->right_sibling);
    }

    void dispos(Node* T)
    {
        if(T)
        {
            dispos(T->right_sibling);
            dispos(T->left_child);
            printf("%d ", T->key);
            delete T;
            T = NULL;
        }
    }
};

int main()
{
    using namespace left_child_right_sibling;
    init();
    dfs(Troot);
    puts("");
    dispos(Troot);
    return 0;
}
