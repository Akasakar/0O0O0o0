/* *
 *    Author:   Akasaka
 *    FileName: 10.nonrecursive_dfs_Tree.cpp
 *    Created:  2020.01.12(UTC+0800) 17.09.45(星期日)
 * */

#include <bits/stdc++.h>

using namespace std;

namespace nonrecursive_dfs_Tree
{
    struct Node {
        int key;
        Node *parent;
        Node *left;
        Node *right;
        Node(int x) : key(x), parent(NULL), left(NULL), right(NULL) {}
        Node(int x, Node* p): key(x), parent(p), left(NULL), right(NULL) {}
    };

    Node* Troot;

    void init()
    {
        Troot = new Node(5);

        Node* x01 = Troot->left = new Node(1, Troot);
        Node* x02 = Troot->right = new Node(9, Troot);

        Node* x012 = x01->right = new Node(3, x01);
        Node* x021 = x02->left = new Node(6, x02);
        Node* x022 = x02->right = new Node(11, x02);

        Node* x0121 = x012->left = new Node(2, x012);
        Node* x0122 = x012->right = new Node(4, x012);
        Node* x0212 = x021->right = new Node(8, x021);
        Node* x0221 = x022->left = new Node(10, x022);

        Node* x02121 = x0212->left = new Node(7, x0212);
    }

    void nonrecursive_dfs()
    {
        Node* prev = NULL;
        Node* root = Troot;

        while(root)
        {
            if(prev == root->parent)
            {
                printf("%d ", root->key);
                prev = root;
                if(root->left) root = root->left;
                else if(root->right) root = root->right;
                else root = root->parent;
            }
            else if(prev == root->left && root->right)
            {
                prev = root;
                root = root->right;
            }
            else
            {
                prev = root;
                root = root->parent;
            }
        }
        putchar(10);
    }

    void dispos(Node* T)
    {
        if(T)
        {
            printf("%d ", T->key);
            dispos(T->left);
            dispos(T->right);
            delete T;
            T = NULL;
        }
    }
};

int main()
{
    nonrecursive_dfs_Tree::init();
    nonrecursive_dfs_Tree::nonrecursive_dfs();
    nonrecursive_dfs_Tree::dispos(nonrecursive_dfs_Tree::Troot);
    return 0;
}
