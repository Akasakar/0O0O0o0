/* *
 *    Author:   Akasaka
 *    FileName: 94.Binary_Tree_Inorder_Traversal.cpp
 *    Created:  2020.01.10(UTC+0800) 14.24.15(星期五)
 * */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stn;
        TreeNode* T = root;
        while(T || !stn.empty())
        {
            while(T)
            {
                stn.push(T);
                T = T->left;
            }
            T = stn.top();
            stn.pop();
            ans.emplace_back(T->val);
            T = T->right;
        }
        return ans;
    }
};

int main()
{
    TreeNode* Troot;
    Troot = new TreeNode(5);

    Troot->left = new TreeNode(1);
    Troot->right = new TreeNode(9);

    Troot->left->right = new TreeNode(3);
    Troot->right->left = new TreeNode(6);
    Troot->right->right = new TreeNode(11);

    Troot->left->right->left = new TreeNode(2);
    Troot->left->right->right = new TreeNode(4);
    Troot->right->left->right = new TreeNode(8);
    Troot->right->right->left = new TreeNode(10);
    
    Troot->right->left->right->left = new TreeNode(7);

    vector<int> x = Solution().inorderTraversal(Troot);
    for(int i = 0; i < x.size(); i++)
        printf("%d ", x[i]);
    return 0;
}
