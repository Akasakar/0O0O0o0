/* *
 *    Author:   Akasaka
 *    FileName: 12.binary_search_tree.cpp
 *    Created:  2020.01.13(UTC+0800) 22.32.10(星期一)
 * */

#include <bits/stdc++.h>

using namespace std;

namespace binary_search_tree
{
    struct Node
    {
        int key;
        Node* left;
        Node* right;
        Node* parent;
        Node(int key = 0, Node* parent = 0): key(key), parent(parent), left(0), right(0) {}
    } *Troot;

    void init()
    {
        Node* x0 = Troot = new Node(15);
        Node* x01 = x0->left = new Node(6, x0); 
        Node* x02 = x0->right = new Node(18, x0);

        Node* x011 = x01->left = new Node(3, x01);
        Node* x012 = x01->right = new Node(7, x01);
        Node* x021 = x02->left = new Node(17, x02);
        Node* x022 = x02->right = new Node(20, x02);

        Node* x0111 = x011->left = new Node(2, x011);
        Node* x0112 = x011->right = new Node(4, x011);
        Node* x0122 = x012->right = new Node(13, x012);

        Node* x01221 = x0122->left = new Node(9, x0122);
    }

    void morris_inorder_tree_traversal(Node* root)
    {//morris traversal
        Node* prev = NULL;
        while(root)
        {
            prev = root->left;
            if(prev)
            {
                while(prev->right && prev->right != root)
                    prev = prev->right;
                if(prev->right)
                {
                    prev->right = NULL;
                    printf("%d ", root->key);
                    root = root->right;
                }
                else
                {
                    prev->right = root;
                    root = root->left;
                }
            }
            else
            {
                printf("%d ", root->key);
                root = root->right;
            }
        }
        putchar(10);
    }

    Node* tree_search(Node* x, int key)
    {
        while(x && key != x->key)
        {
            if(key < x->key) x = x->left;
            else x = x->right;
        }
        return x;
    }

    Node* tree_minimum(Node* x)
    {
        while(x->left) x = x->left;
        return x;
    }

    Node* tree_maximum(Node* x)
    {
        while(x->right) x = x->right;
        return x;
    }

    Node* tree_successor(Node* x)
    {
        if(x->right) return tree_minimum(x->right);
        Node* y = x->parent;
        while(y && x == y->right)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }

    Node* tree_predecessor(Node* x)
    {
        if(x->left) return tree_maximum(x->left);
        Node* y = x->parent;
        while(y && x == y->left)
        {
            x = y;
            y = y->parent;
        }
        return y;
    }

    void sucessor_inorder_traversal(Node* root)
    {
        Node* x = tree_minimum(root);
        if(x) printf("%d ", x->key);
        do 
        {
            x = tree_successor(x);
            if(x) printf("%d ", x->key);
        } while(x);
        putchar(10);
    }

    void tree_insert(Node* z)
    {
        Node* x = Troot;
        Node* y = NULL;
        while(x)
        {
            y = x;
            if(z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->parent = y;
        if(y == NULL) Troot = z;
        else if(z->key < y->key) y->left = z;
        else y->right = z;
    }

    void transplant(Node* u, Node* v)
    {
        if(u->parent == NULL)
            Troot = v;
        else if(u == u->parent->left)
            u->parent->left = v;
        else u->parent->right = v;
        if(v) v->parent = u->parent;
    }

    void tree_delete(Node*& z)
    {
        if(z->left == NULL)
            transplant(z, z->right);
        else if(z->right == NULL)
            transplant(z, z->left);
        else
        {
            Node* y = tree_minimum(z->right);
            if(y)
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        delete z;
        z = NULL;
    }

    void dispos(Node*& T)
    {
        if(T)
        {
            dispos(T->left);
            printf("%d ", T->key);
            dispos(T->right);
            delete T;
            T = NULL;
        }
    }
};

int main()
{
    using namespace binary_search_tree;
    int* a = 0;
    printf("%p\n", a);
    init();

    Node* x = tree_search(Troot, 6);
    if(x) printf("success search: %d\n", x->key);
    else puts("fail search");

    Node* y = tree_successor(x);
    if(y) printf("success successor: %d\n", y->key);
    else puts("fail successsor");

    y = tree_predecessor(x);
    if(y) printf("success predecessor: %d\n", y->key);
    else puts("fail predecessor");

    sucessor_inorder_traversal(Troot);
    morris_inorder_tree_traversal(Troot);

    tree_insert(new Node(10));
    tree_delete(x);
    dispos(Troot);
    putchar(10);
    morris_inorder_tree_traversal(Troot);

    return 0;
}
